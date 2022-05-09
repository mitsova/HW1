#include "Warehouse.h"

void Warehouse::deallocate()
{
	delete[] this->products;
}

void Warehouse::resize()
{
	Product* newProducts = new Product[capacity * 2];
	if (!newProducts)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	this->capacity *= 2;
	for (size_t i = 0; i < this->size; ++i)
	{
		newProducts[i] = this->products[i];
	}

	this->deallocate();
	this->products = newProducts;
}

void Warehouse::copy(const Warehouse& other)
{
	this->products = new Product[other.capacity];
	if (!products)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	for (size_t i = 0; i < other.size; ++i)
	{
		this->products[i] = other.products[i];
	}

	this->size = other.size;
	this->capacity = other.capacity;
}

Warehouse::Warehouse()
{
	this->products = new Product[2];
	if (!products)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	this->capacity = 2;
	this->size = 0;
}

Warehouse::Warehouse(const Warehouse& other)
{
	this->copy(other);
}

Warehouse& Warehouse::operator=(const Warehouse& other)
{
	if (this != &other)
	{
		this->deallocate();
		this->copy(other);
	}

	return *this;
}

Warehouse::~Warehouse()
{
	this->deallocate();
}

Warehouse::Warehouse(const Product* products, size_t size, size_t capacity)
{
	this->products = new Product[capacity];
	if (!products)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	for (size_t i = 0; i < size; ++i)
	{
		this->products[i] = products[i];
	}
	
	this->size = size;
	this->capacity = capacity;
}

//TODO: fix quantities
std::ostream& operator<<(std::ostream& out, const Warehouse& warehouse)
{
	for (size_t i = 0; i < warehouse.size; ++i)
	{
		out << warehouse.products[i];
		out << "------------------------------------------" << std::endl;
	}

	return out;
}

//TODO: finish the date stuff
void Warehouse::addProduct(const Product& product)
{
	if (this->size == capacity)
	{
		this->resize();
	}

	this->products[this->size++] = product;
}

void Warehouse::showChanges(const Date startDate, const Date endDate)
{
	for (size_t i = 0; i < this->size; ++i)
	{
		if (startDate <= this->products[i].getEntryDate() && this->products[i].getEntryDate() <= endDate)
		{
			std::cout << this->products[i];
		}

		if (startDate <= this->products[i].getExportDate() && this->products[i].getExportDate() <= endDate)
		{
			std::cout << this->products[i];
		}

		std::cout << "---------------------" << std::endl;
	}
}

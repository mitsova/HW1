#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Product.h"
class Warehouse
{
private:
	Product* products;
	size_t size;
	size_t capacity;

	void deallocate();
	void copy(const Warehouse& other);
	void resize();

public:
	Warehouse();
	Warehouse(const Product* products, size_t size, size_t capacity);
	Warehouse(const Warehouse& other);
	Warehouse& operator = (const Warehouse& other);
	~Warehouse();
	
	void addProduct(const Product& product);
	Product& exportProduct(const MyString name, const int quantity);
	void showChanges(const Date startDate, const Date endDate);
	void cleanUp(const Date date);

	friend std::ostream& operator << (std::ostream& out, const Warehouse& warehouse);
};

#endif

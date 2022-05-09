#include "Product.h"
#include <assert.h>

Product::Product()
	:name("<unknown>"), manufacturer("<unknown>"), entryDate(Date()), expirationDate(Date()), quantity(0), location(Location()), isExported(false),exportDate(Date()) {}


Product::Product(const MyString name, const MyString manufacturer, const Date entryDate, const Date expirationDate, const int quantity, const Location location)
	: name(name), manufacturer(manufacturer), entryDate(entryDate), expirationDate(expirationDate), quantity(quantity), location(location), isExported(false), exportDate(Date())
{
	assert(entryDate < expirationDate);
}

Product::Product(const MyString name, const MyString manufacturer, const Date entryDate, const Date expirationDate, const int quantity, const MyString description, const Location location)
	: name(name), manufacturer(manufacturer), entryDate(entryDate), expirationDate(expirationDate), quantity(quantity), description(description), location(location), isExported(false), exportDate(Date())
{
	assert(entryDate < expirationDate);
}

Date Product::getEntryDate() const
{
	return this->entryDate;
}

Date Product::getExportDate() const
{
	return this->exportDate;
}

void Product::setExportDate(const Date exportDate)
{
	this->exportDate = exportDate;
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
	out <<"We have " << product.quantity <<
		" of " << product.name << " by " << 
		product.manufacturer << ". " << 
		"The product came in on " << product.entryDate << 
		" and will expire on " << product.expirationDate << ". " <<
		"It is located at index " << product.location.index() << ", on shelf " <<
		product.location.shelf() << " and section " << product.location.section() << 
		"." << std::endl;

	return out;
}

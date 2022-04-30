#ifndef PRODUCT_H
#define PRODUCT_H

#include "Date.h"
#include "Location.h"
#include "MyString.h"
class Product
{
private:
	MyString  name;
	Date expirationDate;
	Date entryDate;
	MyString manufacturer;
	int quantity;
	//Description is optional.
	MyString description;
	Location location;

public:
	Product(const char* name,const Date expirationDate, const Date entryDate, const char* manufacturer, const int quantity, const char* description, const Location location);

	Product(const char* name,const Date expirationDate, const Date entryDate, const char* manufacturer, const int quantity, const Location location);

	//TODO: getters for some things maybe
	//TODO: OUTPUT operator
	//maybe comparison operators?
};

#endif
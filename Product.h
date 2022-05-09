#ifndef PRODUCT_H
#define PRODUCT_H

#include "Date.h"
#include "Location.h"
#include "MyString.h"
class Product
{
private:
	MyString  name;
	Date entryDate;
	Date expirationDate;
	MyString manufacturer;
	int quantity;
	//Description is optional.
	MyString description;
	Location location;
	bool isExported;
	Date exportDate;
	
public:
	Product();
	
	Product(const MyString name, const MyString manufacturer, const Date entryDate, const Date expirationDate, const int quantity, const MyString description, const Location location);

	Product(const MyString name, const MyString manufacturer, const Date entryDate, const Date expirationDate, const int quantity, const Location location);

	//TODO: getters for some things maybe
	Date getEntryDate() const;
	Date getExportDate() const;

	void setExportDate(const Date exportDate);
	
	friend std::ostream& operator << (std::ostream& out, const Product& product);
};

#endif
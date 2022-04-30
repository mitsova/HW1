#include "Product.h"

Product::Product(const char* name, const Date expirationDate, const Date entryDate, const char* manufacturer, const int quantity, const Location location)
	: name(name), expirationDate(expirationDate), entryDate(entryDate), manufacturer(manufacturer), quantity(quantity), location(location) {}

Product::Product(const char* name, const Date expirationDate, const Date entryDate, const char* manufacturer, const int quantity, const char* description, const Location location)
	: name(name), expirationDate(expirationDate), entryDate(entryDate), manufacturer(manufacturer), quantity(quantity), description(description), location(location){}


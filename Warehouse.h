#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Product.h"
class Warehouse
{
private:
	Product** products;
	size_t size;
	size_t capacity;

	void deallocate();
	void copy();

	//TODO: finish
	//TODO: big four
public:
	void addProduct(const Product& product);
	Product& printProduct(const char* name, const int quantity);
	void showChanges(const Date startDate, const Date endDate);
	void cleanUp(const Date date);

	friend std::ostream& operator << (std::ostream& out, const Warehouse& time);
};

#endif

#include "Location.h"


#include <iostream>
#include <stdexcept>

const unsigned int MAX_SECTION = 20;
const unsigned int MAX_SHELF = 10;
const unsigned int MAX_INDEX = 30;

Location::Location(unsigned int section, unsigned int shelf, unsigned int index)
{
	if (index >= MAX_INDEX)
	{
		shelf++;
	}

	if (shelf >= MAX_SHELF)
	{
		section++;
	}

	if (section >= MAX_SECTION)
	{
		std::cout << "Not enough space in the warehouse!";
	}
	
	this->section = section;
	this->shelf = shelf;
	this->index = index;
}

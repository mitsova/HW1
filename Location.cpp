#include "Location.h"


#include <iostream>
#include <stdexcept>

static const unsigned int MAX_SECTION = 20;
static const unsigned int MAX_SHELF = 10;
static const unsigned int MAX_INDEX = 30;

Location::Location()
	: m_index(0), m_shelf(0), m_section(0) {}


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

	this->m_section = section;
	this->m_shelf = shelf;
	this->m_index = index;
}

unsigned Location::index() const
{
	return this->m_index;
}

unsigned Location::section() const
{
	return this->m_section;
}

unsigned Location::shelf() const
{
	return this->m_shelf;
}

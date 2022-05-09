#ifndef LOCATION_H
#define LOCATION_H

class Location
{
private:
	unsigned int m_section;
	unsigned int m_shelf;
	unsigned int m_index;

public:
	Location();
	Location(unsigned int section, unsigned int shelf, unsigned int index);
	unsigned int section() const;
    unsigned int shelf() const;
    unsigned int index() const;
};

#endif

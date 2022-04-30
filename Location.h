#ifndef LOCATION_H
#define LOCATION_H

class Location
{
private:
	unsigned int section;
	unsigned int shelf;
	unsigned int index;

public:
	//Location(); //Should this be allowed? Probably not :/
	Location(unsigned int section, unsigned int shelf, unsigned int index);
};

#endif

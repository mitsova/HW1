#ifndef DATE_H
#define DATE_H

#include <cstdint>

#include "MyString.h"

class Date
{
private:
    std::uint8_t m_day;
    std::uint8_t m_month;
    std::uint16_t m_year;

    void printNumberWithLeadingZero(unsigned int number) const;

public:
	Date();
    Date(unsigned int day, unsigned int month, unsigned int year);

    unsigned int day() const;
    unsigned int month() const;
    unsigned int year() const;

    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;
	bool operator<=(const Date& other) const;

    void print() const;

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

#endif

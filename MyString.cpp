#include <iostream>
#include <cstring>
#include <cassert>

#include "MyString.h"

#pragma warning(disable : 4996)

MyString::MyString()
{
	this->string = nullptr;
	this->size = 0;
}

void MyString::copy(const MyString& other)
{
	if (other.string)
	{
		char* buffer = new (std::nothrow) char[other.size];
		if (!buffer)
		{
			std::cout << "Memory problem" << std::endl;
			return;
		}

		strcpy(buffer, other.string);

		this->string = buffer;
		this->size = other.size;
	}
	else
	{
		this->string = nullptr;
		this->size = 0;
	}
}

MyString::MyString(const MyString& other)
{
	this->copy(other);
}


MyString::MyString(const char* string)
{
	if (string)
	{
		std::size_t size = strlen(string);
		this->string = new char[size + 1];

		strcpy(this->string, string);
		this->size = size;
	}
	else
	{
		this->string = nullptr;
		this->size = 0;
	}
}

void MyString::clear()
{
	this->deallocate();

	this->string = nullptr;
	this->size = 0;
}

void MyString::deallocate()
{
	delete[] this->string;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}

	return *this;
}

MyString::~MyString()
{
	this->clear();
}

bool MyString::empty() const
{
	return this->size == 0;
}

std::size_t MyString::getSize() const
{
	return this->size;
}

char& MyString::operator[](std::size_t index)
{
	assert(index < this->size);

	return this->string[index];
}

const char& MyString::operator[](std::size_t index) const
{
	assert(index < this->size);

	return this->string[index];
}

bool MyString::operator==(const MyString& other) const
{
	if (this->size != other.size)
	{
		return false;
	}

	return strcmp(this->string, other.string) == 0;
}

bool MyString::operator<(const MyString& other) const
{
	if (this->empty() && !other.empty())
	{
		return true;
	}

	if (other.empty() && !this->empty())
	{
		return false;
	}

	return strcmp(this->string, other.string) < 0;
}

MyString& MyString::operator+=(char ch)
{
	if (ch == '\0')
	{
		return *this;
	}

	std::size_t newSize = this->size + 1;
	char* newString;
	try {
		newString = new char[newSize + 1];
	}
	catch (std::exception)
	{
		throw std::runtime_error("Memory problem");
	}

	if (!this->empty())
	{
		strcpy(newString, this->string);
	}

	newString[this->size] = ch;
	newString[newSize] = '\0';

	this->clear();
	this->string = newString;
	this->size = newSize;

	return *this;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (!this->string)
	{
		*this = other;
		return *this;
	}

	if (other.string)
	{
		std::size_t newSize = this->size + other.size;

		char* newString;
		try {
			newString = new char[newSize + 1];
		}
		catch (std::exception)
		{
			throw std::runtime_error("Memory problem");
		}

		strcpy(newString, this->string);
		strcat(newString, other.string);
		newString[newSize] = '\0';

		this->clear();
		this->string = newString;
		this->size = newSize;
	}

	return *this;
}

MyString MyString::operator+(char ch) const
{
	MyString result = *this;
	result += ch;

	return result;
}

MyString MyString::operator+(const MyString& other) const
{
	MyString result = *this;
	result += other;

	return result;
}
std::ostream& operator << (std::ostream& out, const MyString& string)
{
	for (std::size_t i = 0; i < string.size; i++)
	{
		out << string.string[i];
	}

	return out;
}
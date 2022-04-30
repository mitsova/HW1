#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
class MyString
{
private:
	char* string;
	std::size_t size;

	void copy(const MyString& other);
	void deallocate();

public:
	MyString();
	MyString(const char* string);
	MyString(const MyString& other);
	
	MyString& operator = (const MyString& other);
	
	MyString& operator += (char ch);
	MyString& operator += (const MyString& other);
	
	MyString operator + (char ch) const;
	MyString operator + (const MyString& other) const;
	
	bool operator == (const MyString& other) const;
	bool operator < (const MyString& other) const;

	char& operator [] (std::size_t index);
	const char& operator [] (std::size_t index) const;

	void clear();

	bool empty() const;

	std::size_t getSize() const;

	~MyString();

	friend std::ostream& operator << (std::ostream& out, const MyString& string);
};

#endif

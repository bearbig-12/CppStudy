#pragma once
#include <iostream>
class String
{
private:
	char* mString;
	int mS_Length;
public:
	String();
	String(int Length);
	String(const char* string);

	String(const String& string);
	~String();

	void Print();

	String operator=(const String& string);
	friend String operator+(const String& s1, const String& s2);
	String operator +(const String& string);
	String operator +=(const String& string);
	char& operator [](int index);
	friend std::ostream& operator << (std::ostream& os, const String st);

	int GetLength() const 
	{ 
		return mS_Length; 
	} 
	const char* GetString() const
	{
		return mString;
	}

};


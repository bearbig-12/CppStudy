#include "String.h"
#include <iostream>
String::String() 
{
	mS_Length = 0;
	mString = new char[mS_Length + 1]{'\0'};
	
}
String::String(int Length) : mS_Length{Length}
{
	mString = new char[mS_Length + 1];
	for (int i = 0; i < mS_Length; ++i)
	{
		mString[i] = '\0';
	}
}
String::String(const char* string)
{
	mS_Length = 0;
	while (string[mS_Length] != '\0')
	{
		mS_Length++;
	}

	mString = new char[mS_Length + 1];

	for (int i = 0; i < mS_Length; ++i)
	{
		mString[i] = string[i];
	}
	mString[mS_Length] = '\0';
}

String::String(const String& string)
{
	this->mS_Length = string.mS_Length;

	this->mString = new char[this->mS_Length + 1];

	for (int i = 0; i < mS_Length; ++i)
	{
		this->mString[i] = string.mString[i];
	}
	this->mString[this->mS_Length] = '\0';

}

String::~String()
{
	delete[] mString;
	mString = nullptr;
	mS_Length = 0;
}

void String::Print()
{
	std::cout << mString << std::endl;
}

String String::operator=(const String& string)
{
	if (this == &string)
	{
		return *this;
	}
	delete this->mString;
	this->mS_Length = string.GetLength();

	this->mString = new char[mS_Length + 1];
	for (int i = 0; i < mS_Length; ++i)
	{
		mString[i] = string.mString[i];
	}
	mString[mS_Length] = '\0';
	return *this;
}

String String::operator+(const String& string)
{
	int Result_Length{ mS_Length + string.GetLength() };
	String result( Result_Length );
	int i, s1_index, s2_index;
	i = s1_index = s2_index = 0;

	while (mString[s1_index] != '\0')
	{
		result.mString[i++] = mString[s1_index++];
	}
	while (string.mString[s2_index] != '\0')
	{
		result.mString[i++] = string.mString[s2_index++];
	}
	result.mString[Result_Length] = '\0';

	return result;
}

String String::operator+=(const String& string)
{
	String result = (*this) + string;
	*this = result;
	return *this;
}

char& String::operator[](int index)
{
	return mString[index];
}


String operator+(const String& s1, const String& s2)
{
	int Result_Length{ s1.GetLength() + s2.GetLength() };
	String result{ Result_Length };
	int i, s1_index, s2_index;
	i = s1_index = s2_index = 0;

	while (s1.mString[s1_index] != '\0')
	{
		result.mString[i++] = s1.mString[s1_index++];
	}
	while (s2.mString[s2_index] != '\0')
	{
		result.mString[i++] = s2.mString[s2_index++];
	}
	result.mString[Result_Length] = '\0';
	return result;
}

std::ostream& operator<<(std::ostream& os, const String st)
{
	os << st.GetLength() << '\t' << ":" << '\t' << st.mString << std::endl;
	return os;
}

#include "String.h"
#include <iostream>
String::String() : mString {}, mS_Length{}
{
	mString = new char[mS_Length + 1]{};
}
String::String(int Length) : mString{}, mS_Length{Length}
{
	mString = new char[mS_Length + 1]{};
	for (int i = 0; i < mS_Length; ++i)
	{
		mString[i] = ' ';
	}
	mString[mS_Length] = '\0';
}
String::String(const char* string) : mString{}, mS_Length{}
{
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

}

void String::Print()
{
	std::cout << mString << std::endl;
}

String& String::operator=(const String& string)
{
	int Other_length{ 0 };
	this->mS_Length = this->GetLength(this->mString);
	Other_length = string.GetLength(string.mString);

	if (this->mS_Length < Other_length)
	{
		delete mString;
		mString = new char[Other_length + 1]{};
	}
	
	for (int i = 0; i < Other_length; ++i)
	{
		mString[i] = string.mString[i];
	}
	mString[Other_length] = '\0';

	return *this;
}

String& String::operator+=(const String& string)
{
	*this = (*this) + string;
	return *this;
}

char& String::operator[](int index)
{
	return mString[index];
}


int String::GetLength(const String& string)
{
	int length = 0;
	while (string.mString[length] != '\0')
	{
		length++;
	}
	return length;
}

char* String::GetString() const
{
	return this->mString;
}

String operator+(const String& s1, const String& s2)
{
	int Result_Length{ s1.GetLength(s1.mString) + s2.GetLength(s2.mString) };
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

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << "Text : " << st.GetString() << '\t' << "Length : " << st.GetLength(st.mString) << std::endl;
	return os;
}

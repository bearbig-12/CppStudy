#pragma once
class String
{
private:
	char* mString;
public:
	String(const char* string);
	~String();
	void Print();
};


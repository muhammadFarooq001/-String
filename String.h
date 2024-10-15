#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String
{
	char* data;
	int size;
	int getStringLength(const char* src)const;
	void copyString(char* destination, const char* source);
	void memCopy(void* dest, void* src, int byteCnt);
	int getNoLength(long long int temp);
	void mySwap(char* a, char* b);
public:
	String(const String& str);
	String();
	String(const char c);
	String(const char* str);
	String(String&& other);
	~String();
	String& operator=(const String& str);
	void operator += (const String& str);
	String operator + (const String& str)const;
	char& operator[](int ind);
	void operator()(const int count = 0, ...);
	friend String operator+(const char* ch, String str);
	friend istream& operator>>(istream& input, String& s);
	friend ostream& operator<<(ostream& print, String& s);
	void input();
	char& at(int index);
	const char& at(int index)const;
	bool isEmpty()const;
	int getLength()const;
	int getSize()const;
	void display()const;
	int find(const String& subStr, const int start = 0)const;
	void insert(const int index, const String& subStr);
	void remove(const int index, const int count = 1);
	int replace(const String& old, const String& newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int newSize);
	void shrink();
	int compare(const String& s2)const;
	String left(const int count);
	String right(const int count);
	long long int convertToInteger()const;
	float convertToFloat()const;
	String concatenate(const String& s2)const;
	void concatEqual(const String& s2);
	void setNumber(const long long int num);
};
#endif // !1

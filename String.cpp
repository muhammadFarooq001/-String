#include"String.h"
void String::operator()(const int count, ...)
{
	if (count == 0)
	{
		return;
	}
	String* str = new String[count];
	va_list list;
	__crt_va_start(list, count);
	for (int i = 0; i < count; i++)
	{
		str[i] = __crt_va_arg(list, const char*);
		int ind;
		do
		{
			ind = find(str[i]);
			if (ind != -1)
			{
				remove(ind, str[i].getLength());
			}
		} while (ind != -1);
	}
	__crt_va_end(list);
	delete[]str;
}
String operator+(const char* ch, String str)
{
	String plus{ ch };
	plus += str;
	return plus;
}
String String::concatenate(const String& s2)const
{
	if (s2.isEmpty())
	{
		return *this;
	}
	String cnt;
	cnt.reSize(getLength() + s2.getLength() + 1);
	cnt.copyString(cnt.data, data);
	cnt.copyString(cnt.data + getLength(), s2.data);
	return cnt;
}
float String::convertToFloat()const
{
	if (isEmpty())
	{
		exit(0);
	}
	float num = 0;
	int i = 0;
	while (data[i] != '.')
	{
		num = (num * 10) + data[i] - '0';
		i++;
	}
	int div = 1;
	i = i + 1;
	while (data[i] != '\0')
	{
		num = (num * 10) + data[i] - '0';
		i++;
		div = div * 10;
	}
	return num / div;
}
int String::getNoLength(long long int temp)
{
	int len = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	return len;
}
void String::setNumber(const long long int num)
{
	this->~String();
	if (num < 0)
	{
		int len = getNoLength(num);
		size = len + 2;
		data = new char[size];
		data[0] = '-';
		long long int temp = num;
		for (int i = len; i > 0; i--)
		{
			data[i] = ((temp % 10) + '0');
			temp = temp / 10;
		}
		data[len] = '\0';
	}
	else
	{
		int len = getNoLength(num);
		size = len + 1;
		data = new char[size];
		long long int temp = num;
		for (int i = len - 1; i >= 0; i--)
		{
			data[i] = ((temp % 10) + '0');
			temp = temp / 10;
		}
		data[len] = '\0';
	}
}
void String::concatEqual(const String& s2)
{
	if (s2.isEmpty())
	{
		return;
	}
	reSize(getLength() + s2.getLength() + 1);
	int len = getLength();
	copyString(&data[len], s2.data);
}
long long int String::convertToInteger()const
{
	if (isEmpty())
	{
		exit(0);
	}
	int k = 0;
	while (data[k] != '\0')
	{
		if ((data[k] < '0' && data[k] > '9'))
		{
			//cout << "wrong string";
			exit(0);
		}
		k++;
	}
	int num = 0;
	int i = 0;
	bool negative = false;
	if (data[0] == '-')
	{
		i = 1;
		negative = true;
	}
	while (data[i] != '\0' && data[i] != '.')
	{
		num = (num * 10) + (data[i] - '0');
		i++;
	}
	if (negative)
	{
		return num = num * -1;
	}
	return num;
}
void String::trimLeft()
{
	if (isEmpty())
	{
		return;
	}
	int i = 0;
	while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
	{
		i = i + 1;
	}
	copyString(data, &data[i]);
}
void String::trimRight()
{
	if (isEmpty())
	{
		return;
	}
	int length = getLength();
	while (data[length - 1] == ' ' || data[length - 1] == '\n' || data[length - 1] == '\t')
	{
		length--;
	}
	data[length] = '\0';
}
String String::left(const int count)
{
	if (isEmpty() || count <= 0 || count > getLength())
	{
		String s{ '\0' };
		return s;
	}
	String str{ *this };
	str.data[count] = '\0';
	str.shrink();
	return str;
}
String String::right(const int count)
{
	String str{ '\0' };
	if (isEmpty() || count <= 0 || count > getLength())
	{
		return str;
	}
	str.reSize(count + 1);
	str.copyString(str.data, &data[getLength() - count]);
	return str;
}
void String::trim()
{
	if (isEmpty())
	{
		return;
	}
	trimLeft();
	trimRight();
}
void String::remove(int index, int count)
{
	if (isEmpty())
	{
		return;
	}
	copyString(&data[index], &data[index + count]);
}
void String::copyString(char* destination, const char* source)
{
	if (destination == nullptr)
	{
		return;
	}
	if (source == nullptr || source[0] == '\0')
	{
		return;
	}
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
int String::getStringLength(const char* src)const
{
	if (src == nullptr)
	{
		return 0;
	}
	int count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	return count;
}
void String::memCopy(void* dest, void* src, int byteCnt)
{
	const char* s = (const char*)src;
	char* d = (char*)dest;
	for (int i = 0; i < byteCnt; i++)
	{
		d[i] = s[i];
	}
}
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c) :String()
{
	if (c == '\0')
	{
		size = 1;
		data = new char[size];
		data[0] = c;
		return;
	}
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';
}
String::String(const char* str) :String()
{
	if (str == nullptr || str[0] == '\0')
	{
		return;
	}
	int len = getStringLength(str);
	size = len + 1;
	data = new char[size];
	copyString(data, str);
}
String::String(const String& str)
{
	if (str.isEmpty())
	{
		return;
	}
	size = str.getSize();
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = str.data[i];
	}
}
String::String(String&& other)
{
	data = other.data;
	size = other.size;
	other.data = nullptr;
	other.size = 0;
}
char& String::at(const int index)
{
	if (index<0 || index>size)
	{
		exit(0);
	}
	return data[index];
}
const char& String::at(const int index)const
{
	if (index<0 || index>size)
	{
		exit(0);
	}
	return data[index];
}
void String::input()
{
	this->~String();
	size = 5;
	data = new char[size];
	char ch;
	int i = 0;
	while (cin.get(ch) && ch != '\n')
	{
		if (i == (size - 2))
		{
			reSize(size * 2);
		}
		data[i] = ch;
		i++;
		data[i + 1] = '\0';
	}
	data[i] = '\0';
	shrink();
}
void String::insert(const int index, const String& subStr)
{
	if (isEmpty())
	{
		return;
	}
	int destLength = getLength();
	int srcLength = subStr.getLength();
	reSize(destLength + srcLength + 1);
	int j = getSize() - 1;
	int i = destLength;
	while (i >= index)
	{
		data[j] = data[i];
		j--;
		i--;
	}
	int m = index;
	for (int i = 0; i < subStr.getLength(); i++)
	{
		data[m] = subStr.data[i];
		m++;
	}
}
ostream& operator<<(ostream& print, String& s)
{
	if (s.isEmpty())
	{
		return print;
	}
	print << s.data;
	return print;
}
istream& operator>>(istream& input, String& s)
{
	s.~String();
	s.size = 5;
	s.data = new char[s.size];
	char ch;
	int i = 0;
	while (input.get(ch) && ch != EOF)
	{
		if (i == (s.size - 2))
		{
			s.reSize(s.size * 2);
		}
		s.data[i] = ch;
		i++;
		s.data[i + 1] = '\0';
	}
	s.data[i] = '\0';
	s.shrink();
	return input;
}
void String::reSize(int newSize)
{
	char* temp = new char[newSize];
	copyString(temp, data);
	this->~String();
	data = temp;
	size = newSize;
}
int String::getSize()const
{
	return size;
}
void String::display()const
{
	if (isEmpty())
	{
		return;
	}
	cout << data;
}
String::~String()
{
	delete[]data;
	size = 0;
	data = nullptr;
}
int String::getLength()const
{
	if (data == nullptr)
	{
		return 0;
	}
	return getStringLength(data);
}
bool String::isEmpty()const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}
char& String::operator[](int ind)
{
	if (ind >= 0 && ind < size)
	{
		return data[ind];
	}
	exit(0);
}
int String::find(const String& subStr, const int start)const
{
	if (subStr.data == nullptr || subStr.data[0] == '\0')
	{
		return -1;
	}
	int i = start;
	while (data[i] != '\0')
	{
		if (data[i] == subStr.data[0])
		{
			int index = i, j = 0, count = i;
			while ((subStr.data[j] != '\0') && (data[count] == subStr.data[j]))
			{
				count = count + 1;
				j = j + 1;
			}
			if (subStr.data[j] == '\0')
			{
				return index;
			}
		}
		i = i + 1;
	}
	return -1;
}
int String::compare(const String& s2)const
{
	if (s2.isEmpty())
	{
		exit(0);
	}
	int i = 0;
	while (data[i] != '\0' && s2.data[i] != '\0' && data[i] == s2.data[i])
	{
		i++;
	}
	int res = data[i] - s2.data[i];
	if (res > 0)
	{
		return 1;
	}
	else if (res < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
String String::operator + (const String& str)const
{
	if (str.isEmpty())
	{
		return (*this);
	}
	String cnt;
	cnt.reSize(getLength() + getStringLength(str.data) + 1);
	cnt.copyString(cnt.data, data);
	cnt.copyString(&cnt.data[getLength()], str.data);
	return cnt;
}
void String::shrink()
{
	if (isEmpty())
	{
		return;
	}
	reSize(getLength() + 1);
}
void String::mySwap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void String::makeUpper()
{
	if (isEmpty())
	{
		return;
	}
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
		i++;
	}
}
void String::makeLower()
{
	if (isEmpty())
	{
		return;
	}
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
		i++;
	}
}
//String::operator BigNumber()
//{
// cout << "\ntypecast";
// BigNumber num;
// num.setNumber(this->data);
// return num;
//}
void String::reverse()
{
	if (isEmpty())
	{
		return;
	}
	int len = getLength();
	int k = len - 1;
	for (int i = 0; i < len / 2; i++)
	{
		mySwap(&data[i], &data[k]);
		k--;
	}
}
void String::operator += (const String& str)
{
	if (str.isEmpty())
	{
		return;
	}
	reSize(getLength() + str.getSize());
	cout << "khgfd";
	copyString(&data[getLength()], str.data);
}
String& String::operator = (const String& str)
{
	if (this == &str)
	{
		return*this;
	}
	this->~String();
	if (str.isEmpty())
	{
		return *this;
	}
	size = str.getSize();
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = str.data[i];
	}
	return *this;
}
int String::replace(const String& old, const String& newSubStr)
{
	if (isEmpty())
	{
		return 0;
	}
	if (newSubStr.isEmpty())
	{
		return 0;
	}
	int cnt = 0;
	int ind = 0;
	do
	{
		ind = find(old, ind);
		if (ind != -1)
		{
			remove(ind, old.getLength());
			insert(ind, newSubStr);
			cnt++;
		}
	} while (ind != -1);
	return cnt;
}

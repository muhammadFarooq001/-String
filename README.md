Custom String Class in C++
Overview
This project provides a custom implementation of a String Class in C++. The class mimics the behavior of standard C++ string handling functions, but with custom functionality and memory management. The goal of this project is to enhance understanding of object-oriented programming, memory management, and operator overloading in C++.

Features
Dynamic Memory Management: The custom string class uses dynamic memory allocation to manage string data, with proper handling of memory allocation and deallocation.
Operator Overloading: The class supports common string operations such as concatenation (+), comparison (==, !=), assignment (=), and subscript indexing ([]).
Constructors:
Default constructor
Copy constructor
Constructor from const char*
Destructor: Properly handles memory cleanup to prevent memory leaks.
Length Calculation: Method to compute the length of the string.
String Concatenation: Provides a method to concatenate two strings.
Substring Extraction: Allows extracting a substring from a given position and length.
String Comparison: Supports lexicographical comparison of strings.
Additional Utility Functions: Other functions such as clearing the string, checking if it’s empty, etc.
Class Methods
Public Methods
Constructor:

String() — Default constructor that initializes an empty string.
String(const char* str) — Constructor that initializes the string from a C-style string.
String(const String& other) — Copy constructor that creates a deep copy of another string object.
Destructor:

~String() — Destructor that frees the allocated memory.
Length:

size_t length() const — Returns the length of the string.
Concatenation:

String operator+(const String& other) — Concatenates two strings.
Comparison:

bool operator==(const String& other) const — Checks if two strings are equal.
bool operator!=(const String& other) const — Checks if two strings are not equal.
Assignment:

String& operator=(const String& other) — Assigns one string to another using deep copy.
Subscript:

char& operator[](size_t index) — Provides access to characters in the string.

Private Members
char* data_ — A pointer to the dynamically allocated array that holds the string characters.
size_t length_ — The length of the string.

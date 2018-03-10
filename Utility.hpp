/******************************************************************
** Author: Artem Slivka
** Date: 06/24/17
** Description: Utility.hpp is the header file for library
**				Utility (Input validation and other misc functions).
******************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//List of library functions
//Checking string input for valid format
bool isInteger(const string input);
//bool isUnsignInt(const string input);
bool isDouble(const string input);
bool isAChar(const string input);
bool isString(const string input);
bool isValidValue(string dataType, string input);		//Checks if the value is valid based on datatype, input string

//Getter functions for valid output
string getInput(string dataType);						//Used for getting input to be checked for validity
int getInteger();										//Returns valid signed integer value
//int getUnsignInt();									//Returns valid unsigned integer value
double getDouble();										//Returns valid double value
char getAChar();
string getString();
int getIntegerRange(int low, int high);
double getDoubleRange(double low, double high);

//Misc
//bool arraySearch(const string input, string search);
string removeAllSpaces(string input);
int simpleRand(int min, int max);
int advancedRand(int min, int max);
void testInput(string dataType, string testCases[], int size);

#endif
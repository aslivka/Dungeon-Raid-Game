/******************************************************************
** Author: Artem Slivka
** Date : 06/24/17
** Description : Utility.cpp is the function implementation file
**				 for library Utility. This library allows the
**				 user to check input. It also allows other
**				 miscellanious functions like random num generation.
******************************************************************/
#include "Utility.hpp"

/*********************************************************************
** Description:		This function supervizes the number validation
**					process. Based on datatype, it will check if the
**					string has valid characters for that type.
**					If it does, it will return the value as a string.
**					If the input is not a valid value, it asks the user
**					to enter another, valid value.
*********************************************************************/
string getInput(string dataType)
{
	bool validVal = false;
	string typeDesc;		//type description
	string input;	       //keyboard input saved as string

	//Setting appropriate type descriptions
	if (dataType == "int")
	{
		typeDesc = "integer";
	}
	else if (dataType == "dbl")
	{
		typeDesc = "double";
	}
	else if (dataType == "achar")
	{
		typeDesc = "alpha char";
	}
	else if (dataType == "string")
	{
		typeDesc = "string";
	}
	
		//Storing input into a string
		getline(cin, input);
		validVal = isValidValue(dataType, input);

		//Making the user re-enter a valid value if the first try 
		//was an invalid value.
		while(validVal == false)
		{
			cout << "Error! Invalid value." << endl;
			cout << "Enter new " << typeDesc << " value." << endl;
			getline(cin, input);
			validVal = isValidValue(dataType, input);
		}

	return input;
}

/*********************************************************************
** Description:		This function checks if the entered value is an
**					valid. It returns true if it is, false
**					if not. Parameter is the value datatype.
*********************************************************************/
bool isValidValue(string dataType, string input)
{
	bool validVal = false;

	if (dataType == "int")
	{
		validVal = isInteger(input);
	}
	else if (dataType == "dbl")
	{
		validVal= isDouble(input);
	}

	else if (dataType == "achar")
	{
		validVal = isAChar(input);
	}

	else if (dataType == "string")
	{
		validVal = isString(input);
	}
	return validVal;
}

/*********************************************************************
** Description:		This function checks if the entered number is an
**					integer(signed). It returns true if it is, false
**					if not integer.
*********************************************************************/
bool isInteger(const string input)
{
	//It's easier during implementation to assume the num is integer, then
	//check for cases where this condition is violated
	bool intValue = true;
	unsigned int strLen = input.length();

	//Checking the first digit:  has to be 0-9 or -
	//Negation of  0-9 or - = num is outside 0-9 and != -
	//2nd way: if ((input[0] < 48) || (input[0] > 57))
	if ((isdigit(input[0]) == false) && input[0] != '-')
	{
		intValue = false;
	}
	//Case: 0 good int
	//Case: 01 not int
	if (input[0] == '0' && strLen > 1)
	{
		intValue = false;
	}
	//Checking next digits: has to be 0-9 only
	for (unsigned int j = 1; j < strLen; j++)
	{
		//2nd way: if ((input[j] < 48) || (input[j] > 57))
		if (isdigit(input[j]) == false)
		{
			intValue = false;
		}
	}

	return intValue;
}

/*********************************************************************
** Description:		This function checks if the entered number is an
**					integer(unsigned). It returns true if it is, false
**					if not integer.
*********************************************************************/
//bool isUnsignInt(const string input)
//{
//	//It's easier during implementation to assume the num is integer, then
//	//check for cases where this condition is violated
//	bool intValue = true;
//	unsigned int strLen = input.length();
//
//	//Checking the first digit:  has to be 0-9
//	//Negation of  0-9 = num is outside 0-9 
//		
//	if (isdigit(input[0]) == false)
//	{
//		intValue = false;
//	}
//
//	//Case: 0 good int
//	//Case: 01 not int
//	if (input[0] == '0' && strLen > 1)
//	{
//		intValue = false;
//	}
//
//	//Checking next digits: has to be 0-9 only
//	for (unsigned int j = 1; j < strLen; j++)
//	{
//		if (isdigit(input[j]) == false)
//		{
//			intValue = false;
//		}
//	}
//
//	return intValue;
//}

/*********************************************************************
** Description:		This function checks if the entered number is an
**					number with a decimal point(either float or double).
**					It returns true if it is, false if not.
*********************************************************************/
bool isDouble(const string input)
{
	bool dblValue = true;
	unsigned int strLen = input.length();
	int DecPoint = 0;

		//First digit
		if ((input[0] != '-') && (isdigit(input[0]) == false))
		{
			dblValue = false;
		}
		//Checking the rest of the string characters for digits or
		//1 decimal point
		for (unsigned int j = 1; j < strLen; j++)
		{
			if (input[j] == '.')
			{
				DecPoint++;
			}
			else if (isdigit(input[j]) == false)
			{
				dblValue = false;
			}
		}
		//If the number has multiple decimal points and the other characters are digits
		if ((DecPoint > 1 && dblValue == true))
		{
			dblValue = false;
		}
		//If the number is positive, small, no decimal point
		if (input[0] == '0' && strLen > 1 && DecPoint == 0)
		{
			dblValue = false;
		}
		//If the number is negative, small, no decimal point
		if (input[0] == '-' && input[1] == '0' && DecPoint == 0)
		{
			dblValue = false;
		}

	return dblValue;
}

/*********************************************************************
** Description:		This function checks if the entered value is an
**					alphabetic character. It returns true if it is, 
**					false if not.
*********************************************************************/
bool isAChar(const string input) 
{
	//It's easier during implementation to assume the value is char, then
	//check for cases where this condition is violated
	bool charValue = true;

	//Removing whitespaces from string
	//input = removeAllSpaces(input);
	unsigned int strLen = input.length();
	
	if (strLen != 1 || isalpha(input[0]) == false)
	{
		charValue = false;
	}

	return charValue;
}

/*********************************************************************
** Description:		This function checks if the entered value is an
**					string. It returns true if it is,
**					false if not.
*********************************************************************/
bool isString(const string input)
{
	//It's easier during implementation to assume the value is string, then
	//check for cases where this condition is violated
	bool stringValue = true;

	//Removing whitespaces from string
	//input = removeAllSpaces(input);
	unsigned int strLen = input.length();

	//If string is of length 1, should contain an alpha char
	if (strLen == 1)
	{
		if (isalpha(input[0]) == false)
		{
			stringValue = false;
		}
	}

	//if string length is > 1;
	else if (strLen > 1)
	{
		int numNoChar = 0;
		for (unsigned int j = 0; j < strLen; j++)
		{
			if (isalpha(input[j]) == false)
			{
				numNoChar++;
			}
		}
		
		if (static_cast<unsigned int>(numNoChar) == strLen)
		{ 
			stringValue = false;
		}
	}
	return stringValue;
}

/*********************************************************************
** Description:		This function starts the process of getting valid
**					signed integer from the user. It then returns 
**					the value.
*********************************************************************/
int getInteger()
{
	int validVal;
	validVal = stoi(getInput("int"));
	return validVal;
}


/*********************************************************************
** Description:		This function starts the process of getting valid
**					double value from the user. It then returns
**					the value.
*********************************************************************/
double getDouble()
{
	double validVal;
	validVal = stod(getInput("dbl"));
	return validVal;
}

/*********************************************************************
** Description:		This function returns a valid alphabetic  char
**					value
*********************************************************************/
char getAChar()
{
	char validVal;
	string inputString = getInput("achar");
	validVal = inputString[0];
	
	return validVal;
}

/*********************************************************************
** Description:		This function returns a valid string
**					value
*********************************************************************/
string getString()
{
	string validVal;
	string inputString = getInput("string");
	validVal = inputString;

	return validVal;
}
/*********************************************************************
** Description:		This function starts the process of getting valid
**					signed integer from the user, within specific range.
**					It then returns	the value.
*********************************************************************/
int getIntegerRange(int low, int high)
{
	int validVal;
	validVal = stoi(getInput("int"));

	while (validVal < low || validVal > high)
	{
		cout << "Error! Value outside valid range";
		cout << " (From " << low << " to " << high << ")" <<  endl;
		cout << "Enter new integer value." << endl;
		validVal = stoi(getInput("int"));
	} 
	return validVal;
}

/*********************************************************************
** Description:		This function starts the process of getting valid
**					double from the user, within specific range.
**					It then returns	the value.
*********************************************************************/
double getDoubleRange(double low, double high)
{
	double validVal;
	validVal = stod(getInput("dbl"));

	while (validVal < low || validVal > high)
	{
		cout << "Error! Value outside valid range";
		cout << " (From " << low << " to " << high << ")" << endl;
		cout << "Enter new double value." << endl;
		validVal = stod(getInput("dbl"));
	}
	return validVal;
}

/*********************************************************************
** Description:		This function searches an input string for specific
**					string. It returns true if string is found, false
**					if not found.
*********************************************************************/
//bool arraySearch(const string inputString, string searchString)
//{
//	for (unsigned int i = 0; i < searchString.length(); i++)
//	{
//		for (unsigned int j = 0; j < inputString.length(); j++)
//		{
//			if (inputString[j] == searchString[i])
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}

/*********************************************************************
** Description:		This function removes all whitespace from a 
**					string.
*********************************************************************/
string removeAllSpaces(string input)
{
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	return input;
}
/*********************************************************************
** Description:		This function generates a random number in a 
**					specified range					string.
*********************************************************************/
int advancedRand(int min, int max)
{
	using namespace std::chrono;
	using Clock = system_clock;
	auto point1 = Clock::now();

	auto duration = point1.time_since_epoch();
	auto timeNow = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

	srand(static_cast<unsigned int>(timeNow));
	int randomVal = (rand() % (max - min + 1)) + min;
	
	return randomVal;
}

/*********************************************************************
** Description:		This function generates a random number in a
**					specified range. Simple randomization.
*********************************************************************/
int simpleRand(int min, int max)
{
	//Initializing srand function once per program execution
	static int x = 0;
	if (x == 0)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		x++;
	}

	int randomVal = (rand() % (max - min + 1)) + min;

	return randomVal;
}

/*********************************************************************
** Description:		This function generates a random double number in a
**					specified range. Simple randomization.
*********************************************************************/
//double simpleRand(double min, double max)
//{
//	double randomVal = static_cast<double>(fmod(rand(), (max - min + 1)) + min) / 10;
//
//	return randomVal;
//}

/*********************************************************************
** Description:		This function tests all cases for a specific
**					data type, input cases as string array.
*********************************************************************/
void testInput(string dataType, string testCases[], int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Case " << i + 1 << ": ";
		if (isValidValue(dataType, testCases[i]) == true)
		{
			cout << "pass" << endl;
		}

		else
		{
			cout << "fail" << endl;
		}
	}

}
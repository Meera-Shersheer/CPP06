/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:23:42 by mshershe          #+#    #+#             */
/*   Updated: 2026/07/07 14:56:58 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int count(std::string str, char c )
{
	size_t i = 0;
	int ocurrance = 0;
	
	while (i < str.length())
	{
		if (str[i] == c) 
			ocurrance++;
		i++;	
	}
	return (ocurrance);
}

ScalarConverter::ScalarConverter()
{
}



ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}


	
ScalarConverter::~ScalarConverter()
{
}


void ScalarConverter::convert(const std::string& str)
{
	Type type = INVALID;
	
	if (str.empty())
		return ;
	//detect the literal type
	if (str == "-inff" || str == "+inff" || str == "inff"|| \
		str == "nanf" || str == "-inf" || str == "+inf" || \
		str == "nan" || str == "inf")
			type = PESUDO;
	/*else if (str.length() == 1)
	{
		if (!isdigit(str[0]))
			type = CHAR;
		else
			type = INT;
	}
	else if(str.find('.') == std::string::npos)
	{
		if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
			type = INVALID;
		else if (str.length() >= 1)
			type = INT;
			
		for (size_t i = 1; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
				type = INVALID;
		}
	}
	else
	{
		if (count(str, '.') > 1 || count(str, 'f') > 1)
			type = INVALID;
		else if(str.find('f') != std::string::npos)
		{		
			if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
				type = INVALID;
			else if(str.find('f') == str.length()-1)
			{
				if (str.find('f') - 1 == str.find('.') )
					type = INVALID;
				else
					type = FLOAT;
			}
			else
				type = INVALID;
		}
		else if (str.find('.') != str.length()-1)
			type = DOUBLE;
		// check the limits for char  after conversion 
		if (type == CHAR)
		{
			// if (str < std::numeric_limits<char>::min() ||
			// 	str > std::numeric_limits<char>::max())
			// {
			// }
		}
		

		// check the limits for the numerical types after conv
		
	}*/

	

switch (type)
{
    case CHAR:
        std::cout << "CHAR" << std::endl;
        break;

    case INT:
        std::cout << "INT" << std::endl;
        break;

    case FLOAT:
        std::cout << "FLOAT" << std::endl;
        break;

    case DOUBLE:
        std::cout << "DOUBLE" << std::endl;
        break;

    case PESUDO:
        std::cout << "PSEUDO" << std::endl;
        break;

    case INVALID:
        std::cout << "INVALID" << std::endl;
        break;

    default:
        std::cout << "Unknown type" << std::endl;
        break;
}
	
	
}




//scientific notations 1.5e-5
//check limits of int an ...
//1.a
//1.2x
//ab.12
//3.-4
// a digit
// one . (decimal point)
// one optional leading + or -
// one trailing f (for float only)


/*
std::cout << std::numeric_limits<int>::min() << std::endl;
std::cout << std::numeric_limits<int>::max() << std::endl;

std::numeric_limits<char>::min();
std::numeric_limits<char>::max();

std::numeric_limits<float>::lowest();
std::numeric_limits<float>::max();

std::numeric_limits<double>::lowest();
std::numeric_limits<double>::max();

*/

/*
scan the string once 
and record the number of dots, fs, sign and digits
*/
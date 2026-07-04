/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:23:42 by mshershe          #+#    #+#             */
/*   Updated: 2026/07/04 14:43:16 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

	//check negatives
	Type type = INVALID;
	/////////dtect part, add the pesuedos 
	if (str.empty())
	{
		return ;
	}
	//detect the literal type
	if (str == "-inff" || str == "+inff" || str == "inff"|| \
		str == "nanf" || str == "-inf" || str == "+inf" || \
		str == "nan" || str == "inf")
	{
			//pesudo s
			type = PESUDO;
		
	}
	else if (str.length() == 1)
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
			
		for (int i = 1; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
			{
				type = INVALID;
				//return an error
			}
		}
	}
	else
	{
		if(str.find('f') != std::string::npos)
		{		
			if (str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
				type = INVALID;
			else if(str.find('f') == str.length()-1)
			{
				//it is a float
				type = FLOAT;
			}
			else
			{

				type = INVALID;
			}
		
		}
		else
			type = DOUBLE;
	}

	

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

    case PSEUDO:
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

//detect 's'
//scientific notations 1.5e-5
//multiple fs and multiple dots 
//.3
//.f
// 5.

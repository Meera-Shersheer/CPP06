/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:23:42 by mshershe          #+#    #+#             */
/*   Updated: 2026/07/04 03:20:53 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}



ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	return (*this);
}


	
ScalarConverter::~ScalarConverter()
{
}


void ScalarConverter::convert(const std::string& str)
{
	/////////dtect part, add the pesuedos 
	if (str.empty())
	{
		return ;
	}
	//detect the literal type
	if (str.length() == 1)
	{
		if (!isdigit(str[0]))
		{
				//this a char
		}
		else
		{
			// int 
		}
	
	}
	else if(str.find('.') == std::string::npos)
	{
		//int
		for (int i = 0; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
			{
				//return an error
			}
		}
	}
	else
	{
		if(str.find('f') != std::string::npos)
		{
			if(str.find('f') == str.length()-1)
			{
				//it is a float
			}
			else
			{

				//error
			}
		}
			
		// it is adouble
	}

	
	
	
}
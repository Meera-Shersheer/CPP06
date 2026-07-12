/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:23:42 by mshershe          #+#    #+#             */
/*   Updated: 2026/07/12 15:46:11 by mshershe         ###   ########.fr       */
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

static Type detect_type(const std::string& str)
{
	Type type = INVALID;
	size_t len = str.length();
	int sign = 0;
	int sign_out_pf_place = 0;
	size_t num_digits = 0;
	size_t num_dots = 0;
	size_t num_fs = 0;
	
	if (str.empty())
		return ;
	//detect the literal type
	if (str == "-inff" || str == "+inff" || str == "inff"|| \
		str == "nanf" || str == "-inf" || str == "+inf" || \
		str == "nan" || str == "inf")
			type = PESUDO;
	else
	{
		size_t i = 0;
		if (str[0] == '+')
			sign = 1;
		else if (str[0] == '-')
			sign = -1;
		while(i < len)
		{
			if (isdigit(str[i]))
				num_digits++;
			else if (str[i] == 'f')
				num_fs++;
			else if (str[i] == '.')
				num_dots++;
			else if ((str[i] == '+' || str[i] == '-') && i != 0)
					sign_out_pf_place = 1;
			i++;
		}
		if (num_dots > 1 || num_fs > 1 || sign_out_pf_place)
			type = INVALID;
		else if (len == 1 && num_digits == 0)
			type = CHAR;
		else if (len == num_digits || (len - 1 == num_digits && sign != 0))
			type = INT;
		else if ((num_digits == len - 2 || (len - 3 == num_digits && sign != 0)) && num_fs == 1)
		{
			if(str.find('f') == str.length()-1)
			{
				if ((num_dots == 1 && str.find('f') - 1 != str.find('.')) || num_dots == 0)
					type = FLOAT;
			}
			else
				type = INVALID;
		}
		else if ((num_digits == len -1 || (len - 2 == num_digits && sign != 0)) && num_dots == 1)
		{
			if (str.find('.') != str.length()-1)
				type = DOUBLE;
			else
				type = INVALID;
		}
	}
	return (type);
}




static void print(t_conv *convertor)
{

}

void ScalarConverter::convert(const std::string& str)
{
	Type type = detect_type(str);
	int out_of_scope = 0;
	t_conv convertor;
	
	//convert based on the actual type 
	if (type == CHAR)
	{
		if (str[0] >= std::numeric_limits<char>::min() ||
			str[0] <= std::numeric_limits<char>::max())
		{
			convertor.value_c = str[0];
			convertor.value_int = static_cast<int>(convertor.value_c);
			convertor.value_f = static_cast<float>(convertor.value_c);
			convertor.value_d = static_cast<double>(convertor.value_c);
			//convert to other forms 
			//print
		}
		else
			out_of_scope = 1;
			
	}
	else if (type == INT)
	{

		long res = std::strtol(str.c_str(), NULL, 10);
		if (res >= std::numeric_limits<int>::min() ||
			res <= std::numeric_limits<int>::max())
		{
			convertor.value_int = res;
			convertor.value_c = static_cast<char>(convertor.value_int);
			convertor.value_f = static_cast<float>(convertor.value_int);
			convertor.value_d = static_cast<double>(convertor.value_int);
			//convert to other forms 
			//print 
		}
		else
			out_of_scope = 1;
	}
	else if (type == DOUBLE)
	{
		double res = std::strtod(str.c_str(), NULL);
		if (res >= std::numeric_limits<double>::lowest() ||
			res <= std::numeric_limits<double>::max())
		{
			convertor.value_d = res;
			convertor.value_c = static_cast<char>(convertor.value_d);
			convertor.value_int = static_cast<int>(convertor.value_d);
			convertor.value_f = static_cast<float>(convertor.value_d);
			//convert to other forms 
			//print
		}
		else
			out_of_scope = 1;
	}
	else if (type == FLOAT)
	{
		float res = static_cast<float>(std::strtod(str.c_str(), NULL));
		if (res >= std::numeric_limits<float>::lowest() ||
			res <= std::numeric_limits<float>::max())
		{
			convertor.value_f = res;
			convertor.value_c = static_cast<char>(convertor.value_f);
			convertor.value_int = static_cast<int>(convertor.value_f);
			convertor.value_d = static_cast<double>(convertor.value_f);
			//convert to other forms 
			//print
		}
		else
			out_of_scope = 1;
	}
	else if (type == PESUDO)
	{
		
	}

	/*

		// check the limits for the numerical types after conv
		
	}*/

	/*
	after detecting the type we convert the string into the actual type 
	then the static cast is used to convert the other types.
	char
	int
	float
	double

	int value = std::atoi(str.c_str());
	long value = std::strtol(str.c_str(), NULL, 10);
	double value = std::strtod(str.c_str(), NULL);
	float value = static_cast<float>(std::strtod(str.c_str(), NULL));
	
	*/

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

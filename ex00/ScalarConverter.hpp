/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:23:49 by mshershe          #+#    #+#             */
/*   Updated: 2026/07/07 14:30:21 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(const std::string& str);
};

typedef enum 
{
	CHAR, //0
	INT, //1
	FLOAT, //2
	DOUBLE, //3
	PESUDO, //4 
	INVALID //5
}Type;

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:36:38 by mshershe          #+#    #+#             */
/*   Updated: 2026/07/05 01:46:46 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{ 
	if (argc == 1)
		std::cout << "no paramters where passed to convert" << std::endl;
	else
	{
		int i = 1;
		while (i < argc)
		{
			ScalarConverter::convert(argv[i]);
			std::cout << "------------------------------------------------" << std::endl;
			i++;
		}
	}
	return 0;
	
}
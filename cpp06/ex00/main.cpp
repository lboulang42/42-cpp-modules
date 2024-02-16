/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:06:01 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 13:29:54 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int argc, char **argv )
{
    float f = 0.53f;
    std::cout << "f" << f << std::endl;
	if (argc == 2)
		ScalarConverter test (argv[1]);
	else
		std::cout << "ScalarConverter :: Need 1 Argument for this program\n";
}
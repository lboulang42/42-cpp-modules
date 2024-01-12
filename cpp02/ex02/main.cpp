/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:16 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/12 17:40:26 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*fixed point calculator => */
/*https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html*/

int	main(void)
{
	
	{
		//subject.pdf
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	// {
	// 	//Les 6 opérateur de comparaison : >, <, >=, <=, == et !=
	// 	std::cout << "testing logical operators" << std::endl<< std::endl;
	// 	Fixed same_A(12);
	// 	Fixed same_B(12);
	// 	Fixed same_C(12.0f);

	// 	Fixed diff_A(12.12f);
	// 	Fixed diff_B(-13.13f);
	// 	Fixed diff_C(13);

	// 	if (diff_A > diff_B)
	// 		std::cout << "diff_A > diff_B" << std::endl;
	// 	if (diff_A < diff_B)
	// 		std::cout << "diff_A > diff_B" << std::endl;
	// 	if (diff_A >= diff_C)
	// 		std::cout << "diff_A >= diff_C" << std::endl;
	// 	if (diff_A <= diff_B)
	// 		std::cout << "diff_A <= diff_B" << std::endl;
	// 	if (diff_A == diff_C)
	// 		std::cout << "diff_A == diff_C" << std::endl;
	// 	if (same_A == same_C)
	// 		std::cout << "same_A == same_C" << std::endl;
	// 	if (same_A != same_B)
	// 		std::cout << "same_A != same_B" << std::endl;
	// 	if (diff_B != diff_C)
	// 		std::cout << "diff_B != diff_C" << std::endl;
	// }
	// {
	// 	//Les 4 opérateurs de arithmétiques : +, -, *, et /
	// 	std::cout << "tesLes 4 opérateurs de arithmétiques : +, -, *, et /" << std::endl << std::endl;
	// 	Fixed float_A(5.05f);
	// 	Fixed float_B(2.02f);
	// 	Fixed int_A(12);
	// 	Fixed int_B(-13);

	// 	std::cout << "float_A value = " << float_A << " float_B value = " << float_B << std::endl << std::endl;

	// 	std::cout << "float_A + float_B = " << float_A + float_B << std::endl;
	// 	std::cout << "float_A - float_B = " << float_A - float_B << std::endl;
	// 	std::cout << "float_A * float_B = " << float_A * float_B << std::endl;
	// 	std::cout << "float_A / float_B = " << float_A / float_B << std::endl << std::endl;

	// 	std::cout << "int_A value = " << int_A << " int_B value = " << int_B << std::endl<< std::endl;

	// 	std::cout << "int_A + int_B = " << int_A + int_B << std::endl;
	// 	std::cout << "int_A - int_B = " << int_A - int_B << std::endl;
	// 	std::cout << "int_A * int_B = " << int_A * int_B << std::endl;
	// 	std::cout << "int_A / int_B = " << int_A / int_B << std::endl<< std::endl;

	// 	std::cout << "float_A value = " << float_A << " int_B value = " << int_B << std::endl<< std::endl;

	// 	std::cout << "float_A + int_B = " << float_A + int_B << std::endl;
	// 	std::cout << "float_A - int_B = " << float_A - int_B << std::endl;
	// 	std::cout << "float_A * int_B = " << float_A * int_B << std::endl;
	// 	std::cout << "float_A / int_B = " << float_A / int_B << std::endl<< std::endl;
	// }
	// {
	// 	//pre/post incrementation/decrementation
	// 	Fixed a;
	// 	std::cout << "value a : " << a << std::endl;
	// 	std::cout << "value a pre-incr: " << ++a << std::endl;
	// 	std::cout << "value a : " << a << std::endl;
	// 	std::cout << "value a post-incr: " << a++ << std::endl;
	// 	std::cout << "value a : " << a << std::endl;
	// 	std::cout << "value a : " << a << std::endl;
	// 	std::cout << "value a pre-decr: " << --a << std::endl;
	// 	std::cout << "value a : " << a << std::endl;
	// 	std::cout << "value a post-decr: " << a-- << std::endl;
	// 	std::cout << "value a : " << a << std::endl;
	// }
	// {
	// 	//min max avec et sans const
	// 	Fixed const const_A(12);
	// 	Fixed const const_B(13);
	// 	Fixed A(12);
	// 	Fixed B(13);
	// 	std::cout << "min(const_A, const_B) = " << Fixed::min(const_A,const_B) << std::endl;
	// 	std::cout << "max(const_A, const_B) = " << Fixed::max(const_A,const_B) << std::endl;
	// 	std::cout << "min(A, B) = " << Fixed::min(A, B) << std::endl;
	// 	std::cout << "max(A, B) = " << Fixed::max(A, B) << std::endl;
	// 	std::cout << "min(const_A, B) = " << Fixed::min(const_A,B) << std::endl;
	// 	std::cout << "max(const_A, B) = " << Fixed::max(const_A,B) << std::endl;
	// }

}
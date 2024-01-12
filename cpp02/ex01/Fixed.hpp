/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:14 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/11 19:08:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  public:
	/*Constructeur par defaut*/
	Fixed(void);
	/*Constructeur de recopie*/
	Fixed(Fixed const &src);
	Fixed(const int value);
	Fixed(const float value);

	/*Surcharge de l'operateur d'affectation=*/
	Fixed &operator=(Fixed const &rhs);


	/*Destructeur*/
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

  private:
	int _fixedvalue;                      //valeur en virgule fixe
	static const int _fractionalBits = 8; //bits de la partie fractionnaire
};

std::ostream &operator<<(std::ostream &ouputstream, Fixed const &rhs);

#endif

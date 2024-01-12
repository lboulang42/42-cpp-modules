/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:14 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/12 17:20:47 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
  public:
	/*Constructeur par defaut*/
	Fixed(void);
	/*Constructeur de recopie*/
	Fixed(Fixed const &src);
	Fixed(const int value);
	Fixed(const float value);
	/*Destructeur*/
	~Fixed(void);
		
	/*operators comparaison*/
	Fixed &operator=(Fixed const &rhs);
	bool operator>(Fixed const &rhs);
	bool operator<(Fixed const &rhs);
	bool operator>=(Fixed const &rhs);
	bool operator<=(Fixed const &rhs);
	bool operator==(Fixed const &rhs);
	bool operator!=(Fixed const &rhs);

	/*operators arithmetique*/
	Fixed operator+(Fixed const &rhs);
	Fixed operator-(Fixed const &rhs);
	Fixed operator*(Fixed const &rhs);
	Fixed operator/(Fixed const &rhs);

	/*pre-incrementation*/
	Fixed &operator++(void);
	/*post-incrementation*/
	Fixed operator++(int);
	
	/*pre-decrementation*/
	Fixed &operator--(void);
	/*post-decrementation*/
	Fixed operator--(int);
	
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);	
	
	bool operator<(Fixed const &rhs) const;


	int 				getRawBits(void) const;
	void				setRawBits(int const raw);
	float 				toFloat(void) const;
	int 				toInt(void) const;

  private:
	int					_fixedvalue;//valeur en virgule fixe
	static const int	_fractionalBits = 8;//bits de la partie fractionnaire
};


std::ostream &operator<<(std::ostream &ouputstream, Fixed const &rhs);

#endif
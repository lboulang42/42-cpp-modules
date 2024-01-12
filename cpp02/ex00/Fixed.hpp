/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:14 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/11 16:26:00 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  public:
	/*Constructeur par defaut*/
	Fixed(void);
	/*Constructeur de recopie*/
	Fixed(Fixed const &src);
	/*Surcharge de l'operateur d'affectation=*/
	Fixed &operator=(Fixed const &rhs);
	/*Destructeur*/
	~Fixed(void);

	int 				getRawBits(void) const;
	void				setRawBits(int const raw);

  private:
	int					_fixedvalue;
	static const int	_fractionalBits = 8;
};

#endif

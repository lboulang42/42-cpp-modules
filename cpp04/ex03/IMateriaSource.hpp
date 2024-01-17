/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:16:53 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 18:26:23 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource
{
  public:
	virtual ~IMateriaSource(){};
	virtual void learnMateria(AMateria *src) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
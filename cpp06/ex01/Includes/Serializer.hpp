/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:37:29 by mmourdal          #+#    #+#             */
/*   Updated: 2024/02/16 15:19:26 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstring>
# include <climits>
# include <stdint.h>

typedef struct Data
{
	std::string name;
	int integer;
	float decimal;
} Data;

class Serializer
{
	public:
		Serializer ( void );
		~Serializer ( void );
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif
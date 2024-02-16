/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:21:18 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 18:28:25 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main ( void )
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Base *b = generate();
		identify(b);
		identify(*b);
		delete b;
	}
	return (0);
}
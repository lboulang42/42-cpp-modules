/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:38 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 18:29:10 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}

Base::~Base()
{
}

/*randomly instanciates A, B or C and returns the instance as a Base pointer.*/
Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
    {
        std::cout << "generated returned a : A" << std::endl;
		return (new A);
    }
	else if (i == 1)
    {
        std::cout << "generated returned a : B" << std::endl;
		return (new B);
    }
	else
    {
        std::cout << "generated returned a : C" << std::endl;   
		return (new C);
    }
}

/*dynamic cast to ptr*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        return ((void)(std::cout << "A" << std::endl));
	if (dynamic_cast<B*>(p))
        return ((void)(std::cout << "B" << std::endl));
	if (dynamic_cast<C*>(p))
        return ((void)(std::cout << "C" << std::endl));
}

/*dynamic cast to addr*/
void identify(Base &p)
{
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
	catch ( std::exception &error )
	{
	};
    
    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
	catch ( std::exception &error )
	{
	};
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch ( std::exception &error )
	{
	};
	
}

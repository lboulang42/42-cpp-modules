/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:42:16 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/18 20:50:47 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int	main(void)
{
    
    //subject
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    
    {
        IMateriaSource* src = new MateriaSource();
        AMateria *tmp = new Ice();
        src->learnMateria(tmp);
        
        ICharacter* me = new Character("me");
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);
        me->use(0, *bob);
        me->use(1, *bob);
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);
        me->equip(new Ice());
        me->equip(new Ice());
        me->equip(new Ice());
        me->equip(new Ice());
        AMateria *icetmp = new Ice();
        me->equip(icetmp);
        delete icetmp;
        delete bob;
        delete me;
        delete src;
    }
    return 0;
}

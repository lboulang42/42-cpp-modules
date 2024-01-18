/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:42:16 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/17 23:40:12 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Complétez la définition de la classe AMateria suivante et implémentez les fonctions
membres nécessaires.
	// class AMateria
	// {
	//     protected:
	//         ...
	//     public:
	//         AMateria(std::string const & type);
	//         ...
	//         std::string const & getType() const; //Returns the materia type
	//         virtual AMateria* clone() const = 0;
	//         virtual void use(ICharacter& target);
	// };


Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.
Utilisez leur noms en minuscules ("ice" pour Ice,
		"cure" pour Cure) comme types. Bien
sûr,
	leur fonction membre clone() retournera une nouvelle instance de même type (en
clonant une Materia Ice, on obtient une autre Materia Ice).


Pour ce qui est de la fonction membre use(ICharacter&), elle affichera :
• Ice : "* shoots an ice bolt at <name> *"
• Cure : "* heals <name>’s wounds *"
<name> est le nom du Character (personnage) passé en paramètre. N’affichez pas les
chevrons (< et >).


Quand on assigne une Materia à une autre, copier son type n’a pas
grand intérêt.


Créez la classe concrète Character qui implémentera l’interface suivante :

	// class ICharacter
	// {
	//       public:
	//       virtual ~ICharacter() {}
	//       virtual std::string const & getName() const = 0;
	//       virtual void equip(AMateria* m) = 0;
	//       virtual void unequip(int idx) = 0;
	//       virtual void use(int idx, ICharacter& target) = 0;
	// };

Le Character a un inventaire de 4 items,
	soit 4 Materias maximum. À la construction,
l’inventaire est vide. Les Materias sont équipées au premier emplacement vide trouvé,
	soit
dans l’ordre suivant : de l’emplacement 0 au 3. Dans le cas où on essaie d’ajouter une
Materia à un inventaire plein,
	ou d’utiliser/retirer une Materia qui n’existe pas, ne faites
rien (cela n’autorise pas les bugs pour autant). La fonction membre unequip() ne doit
PAS delete la Materia !

Occupez-vous des Materias laissées au sol par votre personnage comme
vous le sentez. Vous pouvez enregistrer l’adresse avant d’appeler
unequip(), ou autre, du moment que vous n’avez pas de fuites de
mémoire.


La fonction membre use(int,
		ICharacter&) utilisera la Materia de l’emplacement[idx],
et passera la cible en paramètre à la fonction AMateria::use.

L’inventaire de votre personnage devra pouvoir contenir n’importe
quel type d’objet AMateria.

Votre Character doit comporter un constructeur prenant son nom en paramètre.
Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Character doit être profonde. Ainsi,
	lors d’une copie, les Materias du Character doivent être
delete avant que les nouvelles ne les remplacent dans l’inventaire. Bien évidemment,
	les
Materias doivent aussi être supprimées à la destruction d’un Character.


Créez la classe concrète MateriaSource qui implémentera l’interface suivante :

		// class IMateriaSource
		// {
			// public:
			// virtual ~IMateriaSource() {}
			// virtual void learnMateria(AMateria*) = 0;
			// virtual AMateria* createMateria(std::string const & type) = 0;
		// };

• learnMateria(AMateria*)
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.
• createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu.


En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi,
	vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.

*/

/*resume



Character :
	Implemente ICharacter, 




*/

#include "AMateria.hpp"//done
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
int	main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}


/*
// AMateria *ice = new Ice();
	// AMateria *cure = new Cure();
	// std::cout << "ice type : " << ice->getType() << std::endl;
	// std::cout << "cure type : " << cure->getType() << std::endl;

	// AMateria *ice2 = ice->clone();
	// AMateria *cure2 = cure->clone();
	// std::cout << "ice2 type : " << ice2->getType() << std::endl;
	// std::cout << "cure2 type : " << cure2->getType() << std::endl;

	// delete ice2;
	// delete ice;
	// delete cure;
	// delete cure2;

	// IMateriaSource	*src;
	// ICharacter		*me;
	// 	AMateria *tmp;
	// ICharacter		*bob;
	// 	delete bob;
	// 	delete me;
	// 	delete src;

	// AMateria *ice = new Ice();
	// std::string a = ice->getType();
	// std::cout << a << std::endl;
	// ICharacter		*me = new Character("me");
	// ICharacter		*otherone = new Character("otherone");
	//  AMateria *cure = new Cure();
	// me->equip(ice);
	// me->equip(cure);
	// std::cout << "getname : " << me->getName() << std::endl;
	// me->use(1, *otherone);
	// // ICharacter		*bob;
	// // delete			bob;
	// // delete			me;
	// // delete			src;
	// // src = new MateriaSource();
	// // src->learnMateria(new Ice());
	// // src->learnMateria(new Cure());
	// // me = new Character("me");
	// // tmp = src->createMateria("ice");
	// // me->equip(tmp);
	// // tmp = src->createMateria("cure");
	// // me->equip(tmp);
	// // bob = new Character("bob");
	// // me->use(0, *bob);
	// // me->use(1, *bob);
	// delete ice;
	// delete me;
	// return (0);
	{
		IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << "TEST1";
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << "TEST2";
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		std::cout << "TEST3";
		me->use(0, *bob);
		std::cout << "TEST4";
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}

*/
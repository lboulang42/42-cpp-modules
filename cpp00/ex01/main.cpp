/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:04 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 18:36:55 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*

Bienvenue dans les années 80 et leur incroyable technologie ! Concevez un programme
qui se comporte comme un répertoire pas si incroyable que ça.
Vous devez implémenter deux classes :
    - PhoneBook
        ◦ Représente le répertoire.
        ◦ Contient un tableau de contacts.
        ◦ Peut enregistrer 8 contacts maximum. 
        Si l’utilisateur tente d’ajouter un 9ème contact, remplacez le plus ancien par celui-ci.
        ◦ Notez que l’allocation dynamique est interdite.
    - Contact
        ◦ Représente un contact dans le répertoire.

Dans votre code, l’objet répertoire doit être une instance de la classe PhoneBook.
Même chose pour les objets contacts, qui doivent être chacun une instance de la classe Contact.

Vous êtes libre de concevoir vos classes comme vous le sentez. Par contre, ayez1
en tête que ce qui est toujours utilisé dans une classe est privé, et que ce qui peut l’être
en dehors est public.

Le programme accepte les entrées suivantes : ADD, SEARCH et EXIT.
    • ADD : enregistrer un nouveau contact
        ◦ Si l’utilisateur entre cette commande, remplir une par une les informations du nouveau contact.
        Une fois tous les champs complétés, le nouveau contact est ajouté au répertoire.
        ◦ Un contact possède les champs suivants : first name, last name, nickname (surnom), phone number (numéro de téléphone),
        et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne peuvent être vides.
    • SEARCH : affiche le contact demandé
        ◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
        first name, last name et nickname.
        ◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
        par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
        de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
        un point (’.’).
        ◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
        Sinon, affichez les informations du contact, une par ligne.
    • EXIT
        ◦ Le programme quitte et les contacts sont perdus à jamais !
    • Toute autre entrée est ignorée.
    
Une fois la commande correctement exécutée, le programme attend à nouveau une
    entrée. Il prend fin lorsque l’utilisateur entre EXIT.
    Donnez un nom cohérent à votre exécutable.

*/

int main(void)
{
    PhoneBook repertoire;
    std::string cmd;
    while (cmd != "EXIT")
    {
        std::cout << "Please Input Command" << std::endl;
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            return (1);
        if (cmd == "ADD")
            repertoire.add(); 
        if (cmd == "SEARCH")
            repertoire.search();
    }
    std::cout << "Exiting Phone Book !" << std::endl;
    return 0;
}
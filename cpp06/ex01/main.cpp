/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:21:18 by lboulang          #+#    #+#             */
/*   Updated: 2024/02/16 15:21:18 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Serializer.hpp"

int main ( void )
{
	Serializer serialize;
	Data data;
    Data *data_ptr = NULL;
	uintptr_t ptr = 0;


    data.name = "Leo";
    data.integer = 42;
    data.decimal = -42.42;
	std::cout << "Data of data : " << std::endl;
	std::cout << "Name : " << data.name << std::endl; 
	std::cout << "Age : " << data.integer << std::endl;
    std::cout << "decimal : " << data.decimal << std::endl;

	std::cout << "uintptr_t value before serialize : " << ptr << std::endl;
	ptr = serialize.serialize(&data);
	std::cout << "uintptr_t value after serialize : " << ptr << std::endl;

	std::cout << "Memory adress of data : " << &data << std::endl;
	std::cout << "Memory adress of data_ptr before deserialize data in data_two : " << data_ptr << std::endl;
	data_ptr = serialize.deserialize(ptr);
	std::cout << "Memory adress of data_ptr after deserialize data in data_ptr : " << data_ptr << std::endl;

	std::cout << "Data of data_ptr : " << std::endl;
	std::cout << "string : " << data_ptr->name << std::endl; 
	std::cout << "integer : " << data_ptr->integer << std::endl;
    std::cout << "decimal : " << data_ptr->decimal << std::endl;
}

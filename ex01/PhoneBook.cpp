/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:54:14 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/26 14:38:09 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	_idx = 0;
}

PhoneBook::~PhoneBook( void ) {
}

void	PhoneBook::addContact(std::string first_name, std::string last_name, \
		std::string nickname, std::string phonenumber, std::string secret) {

	_contacts[_idx % 8].setFirstName(first_name);
	_contacts[_idx % 8].setLastName(last_name);
	_contacts[_idx % 8].setNickname(nickname);
	_contacts[_idx % 8].setPhoneNumber(phonenumber);
	_contacts[_idx % 8].setDarkestSecret(secret);
	_idx++;
}

int	PhoneBook::getLength(void) {

	if (_idx > 7)
		return (8);
	return ((_idx % 8));
}

Contact	PhoneBook::getContact(size_t idx) {

	return (_contacts[idx]);
}

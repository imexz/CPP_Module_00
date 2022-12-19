/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:13:41 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 16:21:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact( void ) {
}

std::string	Contact::getFirstName(void) {

	return (_first_name);
}

bool	Contact::setFirstName(std::string first_name) {

	_first_name = first_name;
	return (true);
}

std::string	Contact::getLastName(void) {

	return (_last_name);
}

bool	Contact::setLastName(std::string last_name) {

	_last_name = last_name;
	return (true);
}

std::string	Contact::getNickname(void) {

	return (_nickname);
}

bool	Contact::setNickname(std::string nickname) {

	_nickname = nickname;
	return (true);
}

std::string	Contact::getPhoneNumber(void) {

	return (_phone_number);
}

bool	Contact::setPhoneNumber(std::string phone_number) {

	_phone_number = phone_number;
	return (true);
}

std::string	Contact::getDarkestSecret(void) {

	return (_darkest_secret);
}

bool	Contact::setDarkestSecret(std::string darkest_secret) {

	_darkest_secret = darkest_secret;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:15:55 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/26 14:33:10 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printer.hpp"

Printer::Printer(void) {
}

Printer::~Printer(void) {
}

void	Printer::printStart(void) {

	_printNl();
	_printStrNl("Whatchu Talkin' 'Bout, Willis?");
}

void	Printer::printCommandPrompt(void) {

	_printNl();
	_printStrNl("Please enter one of the listed commands");
	_printStrNl("[ ]ADD    [ ]SEARCH    [ ]EXIT");
	_printNl();
}

void	Printer::printCommandSelection(e_commands command) {

	switch (command) {
		case ADD:
			_printNl();
			break ;
		case SEARCH:
			_printNl();
			break ;
		case EXIT:
			_printNl();
			break ;
		default:
			_printStrNl("Invalid command");
			_printNl();
	}
}

void	Printer::printInputRequestFirstName(void) {

	_printStrNl("Please enter the First Name:");
}

void	Printer::printInputRequestLastName(std::string first_name) {

	_printStr("Please enter the Last Name of ");
	_printStr(first_name);
	_printStrNl(":");
}

void	Printer::printInputRequestNickname(std::string first_name) {

	_printStr("Please enter the nickname of ");
	_printStr(first_name);
	_printStrNl(":");
}

void	Printer::printInputRequestPhonenumber(std::string first_name) {

	_printStr("Please enter the phonenumber of ");
	_printStr(first_name);
	_printStrNl(":");
}

void	Printer::printInputRequestDarkestSecret(std::string first_name) {

	_printStr("Please enter the darkest secret of ");
	_printStr(first_name);
	_printStrNl(":");
}

void	Printer::printInputRequestIndex(void) {

	_printStrNl("Please enter an index number:");
	_printNl();
}

void	Printer::printInputRequestAlpaSpaceError(void) {

	_printStrNl("Invalid input: Only alphabetical characters and space allowed");
}

void	Printer::printInputRequestAlNumError(void) {

	_printStrNl("Invalid input: Only alphanumerical characters and space allowed");
}

void	Printer::printInputRequestIndexError(int idx) {

	_printStr("Invalid input: Allowed Index from 0 to ");
	std::cout << idx << std::endl;
}

void	Printer::printInputRequestNumSignError(void) {

	_printStrNl("Invalid input: Only sign and numerical characters allowed");
}

void	Printer::printSuccessAdd(std::string first_name, std::string last_name) {

	_printNl();
	_printStr("Successfully added contact ");
	_printStr(first_name);
	_printStr(" ");
	_printStrNl(last_name);
}

void	Printer::printEnd(void) {

	_printStrNl("I'll be back!");
}

void	Printer::_printStr(std::string str) {

	std::cout << str;
}

void	Printer::_printStrSetWidth(std::string str, int width) {

	std::cout << std::setw(width) << str;
}

void	Printer::_printStrNl(std::string str) {

	std::cout << str << std::endl;
}

void	Printer::_printNl(void) {

	std::cout << std::endl;
}

std::string	Printer::_formatStr(std::string str) {

	size_t		len;

	len = str.length();
	if (len > 10) {
		str.resize(9);
		str.push_back('.');
	}
	return (str);
}

std::string	Printer::_getRowElement(PhoneBook book, size_t i, enum e_column column) {

	std::string	content;

	switch (column)
	{
		case FIRST_NAME:
			content = book.getContact(i).getFirstName();
			return (_formatStr(content));
		case LAST_NAME:
			content = book.getContact(i).getLastName();
			return (_formatStr(content));
		case NICKNAME:
			content = book.getContact(i).getNickname();
			return (_formatStr(content));
		default:
			content = std::to_string(i);
			return (content);
	}
}

void	Printer::_printRow(PhoneBook book, size_t length) {

	size_t	i;

	i = 0;
	while (i < length) {
		_printStrNl("╠══════════╬══════════╬══════════╬══════════╣");
		_printStr("║");
		_printStrSetWidth(_getRowElement(book, i, INDEX), 10);
		_printStr("║");
		_printStrSetWidth(_getRowElement(book, i, FIRST_NAME), 10);
		_printStr("║");
		_printStrSetWidth(_getRowElement(book, i, LAST_NAME), 10);
		_printStr("║");
		_printStrSetWidth(_getRowElement(book, i, NICKNAME), 10);
		_printStrNl("║");
		i++;
	}
	_printStrNl("╚══════════╩══════════╩══════════╩══════════╝");
}

bool	Printer::listAvailableContacts(PhoneBook book) {

	_printStrNl("╔══════════╦══════════╦══════════╦══════════╗");
	_printStrNl("║     index║first name║ last name║  nickname║");
	if (book.getLength() == 0) {
		_printStrNl("║══════════╩══════════╩══════════╩══════════║");
		_printStrNl("║              Empty PhoneBook              ║");
		_printStrNl("╚═══════════════════════════════════════════╝");
		return (false);
	}
	else {
		_printRow(book, book.getLength());
	}
	return (true);
}

void	Printer::displayContact(Contact contact) {

	std::string	first_name;

	first_name = contact.getFirstName();
	if (first_name.empty()) {
		_printNl();
		_printStrNl("Empty contact");
		return ;
	}
	_printNl();
	_printStrNl("First Name: ");
	_printStrNl(contact.getFirstName());
	_printNl();
	_printStrNl("Last Name: ");
	_printStrNl(contact.getLastName());
	_printNl();
	_printStrNl("Nickname: ");
	_printStrNl(contact.getNickname());
	_printNl();
	_printStrNl("Phonenumber: ");
	_printStrNl(contact.getPhoneNumber());
	_printNl();
	_printStrNl("DarkestSecret: ");
	_printStrNl(contact.getDarkestSecret());
	_printNl();
}

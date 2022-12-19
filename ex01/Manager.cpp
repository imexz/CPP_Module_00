/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:15:52 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/26 14:35:53 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Manager.hpp"

Manager::Manager(void) {
}

Manager::~Manager(void) {
}

void	Manager::start(void) {

	e_commands	command;

	_printer.printStart();
	do {
		_printer.printCommandPrompt();
		command = _scanner.scanCommand();
		_printer.printCommandSelection(command);
		if (command == ADD)
			addNewContact();
		else if (command == SEARCH)
			searchContacts();
	} while (command != EXIT);
	_printer.printEnd();
	return ;
}

void	Manager::addNewContact(void) {

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phonenumber;
	std::string secret;

	_printer.printInputRequestFirstName();
	while (!_scanner.scanAlpha(&first_name)) {
		_printer.printInputRequestAlpaSpaceError();
		_printer.printInputRequestFirstName();
	}
	_printer.printInputRequestLastName(first_name);
	while (!_scanner.scanAlpha(&last_name)) {
		_printer.printInputRequestAlpaSpaceError();
		_printer.printInputRequestLastName(first_name);
	}
	_printer.printInputRequestNickname(first_name);
	while (!_scanner.scanAlNum(&nickname)) {
		_printer.printInputRequestAlNumError();
		_printer.printInputRequestNickname(first_name);
	}
	_printer.printInputRequestPhonenumber(first_name);
	while (!_scanner.scanNum(&phonenumber)) {
		_printer.printInputRequestNumSignError();
		_printer.printInputRequestPhonenumber(first_name);
	}
	_printer.printInputRequestDarkestSecret(first_name);
	while (!_scanner.scanAlNum(&secret)) {
		_printer.printInputRequestAlNumError();
		_printer.printInputRequestDarkestSecret(first_name);
	}
	_book.addContact(first_name, last_name, nickname, phonenumber, secret);
	_printer.printSuccessAdd(first_name, last_name);
}

void	Manager::searchContacts(void) {

	int	idx;

	if (_printer.listAvailableContacts(_book)) {
		_printer.printInputRequestIndex();
		idx = _scanner.scanIdx();
		while (std::cin.fail() || idx >= _book.getLength()) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			_printer.printInputRequestIndexError(_book.getLength() - 1);
			_printer.printInputRequestIndex();
			idx = _scanner.scanIdx();
		}
		_printer.displayContact(_book.getContact(idx));
	}
}

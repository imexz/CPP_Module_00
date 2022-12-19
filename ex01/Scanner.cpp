/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scanner.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:58:34 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 23:35:17 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scanner.hpp"

Scanner::Scanner(void) {
}

Scanner::~Scanner(void) {
}

e_commands	Scanner::scanCommand(void) {

	std::string	str;

	str = _scan();
	if (!str.compare("ADD"))
		return (ADD);
	else if (!str.compare("SEARCH"))
		return (SEARCH);
	else if (!str.compare("EXIT"))
		return (EXIT);
	else
		return (FAILURE);
}

bool	Scanner::scanAlpha(std::string *name) {

	*name = _scan();
	if (!StaticUtils::isAlphaSpace(*name))
		return (false);
	*name = StaticUtils::trimWhitespace(*name);
	if (name->empty())
		return (false);
	return (true);
}

bool	Scanner::scanAlNum(std::string *name) {

	*name = _scan();
	if (!StaticUtils::isAlNum(*name))
		return (false);
	*name = StaticUtils::trimWhitespace(*name);
	if (name->empty())
		return (false);
	return (true);
}

bool	Scanner::scanNum(std::string *number) {

	*number = _scan();
	*number = StaticUtils::trimWhitespace(*number);
	if (number->empty())
		return (false);
	if (!StaticUtils::isNum(*number))
		return (false);
	return (true);
}

int	Scanner::scanIdx(void) {

	int	idx;

	std::cin >> idx;
	if (!std::cin.fail())
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (idx);
}

std::string	Scanner::_scan(void) {

	std::string	str;

	std::getline(std::cin, str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:27:04 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 16:24:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StaticUtils.hpp"

std::string	StaticUtils::toLower(std::string str) {

	size_t	i;

	for (i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
	return (str);
}

std::string	StaticUtils::toUpper(std::string str) {

	size_t	i;

	for (i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	return (str);
}

bool	StaticUtils::isAlpha(std::string str) {

	size_t	found;

	str = toLower(str);
	found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
	if (found != std::string::npos)
		return (false);
	return (true);
}

bool	StaticUtils::isAlphaSpace(std::string str) {

	size_t	found;

	str = toLower(str);
	found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
	if (found != std::string::npos)
		return (false);
	return (true);
}

bool	StaticUtils::isNum(std::string str) {

	size_t	found;

	found = str.find_first_not_of("0123456789");
	if (found != std::string::npos)
		return (false);
	return (true);
}

bool	StaticUtils::isNumSign(std::string str) {

	size_t	found;

	found = str.find_first_not_of("0123456789-+");
	if (found != std::string::npos)
		return (false);
	return (isNum(str.erase(0, 1)));
}

bool	StaticUtils::isAlNum(std::string str) {

	size_t	found;

	str = toLower(str);
	found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789 ");
	if (found != std::string::npos)
		return (false);
	return (true);
}

static bool	isSpace(char c) {

	switch (c) {
		case ' ':
		case '\t':
		case '\v':
		case '\r':
		case '\f':
		case '\n':
			return (true);
		default:
			return (false);
	}
}

std::string	StaticUtils::trimWhitespace(std::string str) {

	for (size_t i = 0; i < str.length(); i++) {
		if (!isSpace(str[i]))
		{
			str.erase(0, i);
			break ;
		}
	}
	for (size_t i = str.length(); i > 0; i--) {
		if (!isSpace(str[i - 1]))
		{
			str.erase(i, std::string::npos);
			break ;
		}
	}
	return (str);
}

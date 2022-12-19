/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:49:59 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/24 23:57:57 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact {

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:

	Contact (void);
	~Contact (void);

	std::string	getFirstName(void);
	bool		setFirstName(std::string first_name);
	std::string	getLastName(void);
	bool		setLastName(std::string last_name);
	std::string	getNickname(void);
	bool		setNickname(std::string nickname);
	std::string	getPhoneNumber(void);
	bool		setPhoneNumber(std::string phone_number);
	std::string	getDarkestSecret(void);
	bool		setDarkestSecret(std::string darkest_secret);
};

#endif // ******************************************************* CONTACT_HPP //

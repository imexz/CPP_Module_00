/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:49:56 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/26 14:38:02 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {

	private:

		Contact		_contacts[8];
		size_t		_idx;

	public:

		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(std::string first_name, std::string last_name, \
			std::string nickname, std::string phonenumber, std::string secret);
		int		getLength(void);
		Contact	getContact(size_t idx);
};

#endif // ***************************************************** PHONEBOOK_HPP //

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:52:25 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 16:22:27 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_HPP
# define MANAGER_HPP

#include "PhoneBook.hpp"
#include "Printer.hpp"
#include "Scanner.hpp"

class	Manager {

	private:

		PhoneBook	_book;
		Printer		_printer;
		Scanner		_scanner;

		void	addNewContact(void);
		void	searchContacts(void);

	public:

		Manager(void);
		~Manager(void);

		void	start(void);
};

#endif // ******************************************************* MANAGER.HPP //

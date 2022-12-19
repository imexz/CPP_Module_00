/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:59:09 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/26 13:52:16 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

# include "enum.hpp"
# include "PhoneBook.hpp"
# include <iomanip>

class	Printer {

	private:

		void		_printStr(std::string str);
		void		_printStrSetWidth(std::string str, int width);
		void		_printStrNl(std::string str);
		void		_printNl(void);
		std::string	_getRowElement(PhoneBook book, size_t i, enum e_column column);
		void		_printRow(PhoneBook book, size_t length);
		std::string	_formatStr(std::string str);

	public:

		Printer(void);
		~Printer(void);

		void	printStart(void);
		void	printCommandPrompt(void);
		void	printCommandSelection(e_commands command);
		void	printInputRequestFirstName(void);
		void	printInputRequestLastName(std::string first_name);
		void	printInputRequestNickname(std::string first_name);
		void	printInputRequestPhonenumber(std::string first_name);
		void	printInputRequestDarkestSecret(std::string first_name);
		void	printInputRequestIndex(void);
		void	printInputRequestAlpaSpaceError(void);
		void	printInputRequestAlNumError(void);
		void	printInputRequestNumSignError(void);
		void	printInputRequestIndexError(int length);
		void	printSuccessAdd(std::string first_name, std::string last_name);
		bool	listAvailableContacts(PhoneBook book);
		void	displayContact(Contact contact);
		void	printEnd(void);
};

#endif // ******************************************************* PRINTER_HPP //

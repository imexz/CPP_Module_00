/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scanner.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:58:37 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 22:21:33 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_HPP
# define SCANNER_HPP

# include <string>
# include <iostream>
# include "enum.hpp"
# include "StaticUtils.hpp"

class Scanner {

	private:

		std::string	_scan(void);

	public:

		Scanner(void);
		~Scanner(void);

		e_commands	scanCommand(void);
		bool		scanAlpha(std::string *name);
		bool		scanAlNum(std::string *name);
		bool		scanNum(std::string *number);
		int			scanIdx(void); // infinity loop when entering chars
};

#endif // ******************************************************* SCANNER_HPP //

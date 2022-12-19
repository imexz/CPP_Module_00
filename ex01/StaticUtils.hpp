/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:22:59 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 16:21:37 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATICUTILS_HPP
# define STATICUTILS_HPP

# include <string>
# include <iostream>

class StaticUtils {

	private:

	public:

		static std::string	toLower(std::string str);
		static std::string	toUpper(std::string str);
		static bool			isAlpha(std::string str);
		static bool			isAlphaSpace(std::string str);
		static bool			isNum(std::string str);
		static bool			isNumSign(std::string str);
		static bool			isAlNum(std::string str);
		static std::string	trimWhitespace(std::string str);
};

#endif // *************************************************** STATICUTILS_HPP //

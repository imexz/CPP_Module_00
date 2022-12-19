/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:44:22 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/22 20:47:36 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	toUpper(char *cstr)
{
	std::string	str (cstr);
	size_t		i;

	for (i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	std::cout << str;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc >= 2)
	{
		i = 1;
		while (i < argc)
			toUpper(argv[i++]);
		std::cout << std::endl;
	}
	return (0);
}

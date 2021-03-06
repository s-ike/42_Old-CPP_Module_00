/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:08:10 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/08 14:58:13 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define NO_ARG 1

int	main(int argc, char **argv)
{
	if (argc == NO_ARG)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string	str = argv[i];

			for (size_t j = 0; str[j]; ++j)
				std::cout << static_cast<char>(toupper(str[j]));
		}
		std::cout << std::endl;
	}
}

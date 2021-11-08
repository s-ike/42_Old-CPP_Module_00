/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:33:08 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/08 10:56:32 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class Phonebook
{
	const static int	_max = 8;
	const static int	_width = 10;
	size_t				_idx;
	Contact				_contacts[_max];

	void	put_command_list() const;
	bool	add_mode();
	void	add(
		const std::string &first_name,
		const std::string &last_name,
		const std::string &nickname,
		const std::string &phone_number,
		const std::string &darkest_secret);
	bool	search_mode();
	void	put_address_list();

public:
	Phonebook();
	void	routine();
};

#endif

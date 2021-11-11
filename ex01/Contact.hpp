/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:05:59 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/11 11:14:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_num;
	std::string	_darkest_secret;

public:
	Contact();
	Contact(
		const std::string &first_name,
		const std::string &last_name,
		const std::string &nickname,
		const std::string &phone_num,
		const std::string &darkest_secret);
	std::string	first_name() const;
	std::string	short_first_name() const;
	std::string	last_name() const;
	std::string	short_last_name() const;
	std::string	nickname() const;
	std::string	short_nickname() const;
	std::string	phone_number() const;
	std::string	darkest_secret() const;
};

#endif

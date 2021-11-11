/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:37:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/11 11:24:15 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

Contact::Contact()
	:
	_first_name(""),
	_last_name(""),
	_nickname(""),
	_phone_num(""),
	_darkest_secret("")
{}

Contact::Contact(
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname,
	const std::string &phone_num,
	const std::string &darkest_secret)
	:
	_first_name(first_name),
	_last_name(last_name),
	_nickname(nickname),
	_phone_num(phone_num),
	_darkest_secret(darkest_secret)
{}

std::string	Contact::first_name() const
{
	return _first_name;
}

std::string	Contact::last_name() const
{
	return _last_name;
}

std::string	Contact::nickname() const
{
	return _nickname;
}

std::string	Contact::phone_number() const
{
	return _phone_num;
}

std::string	Contact::darkest_secret() const
{
	return _darkest_secret;
}

std::string	Contact::to_short(const std::string &str)
{
	if (str.size() <= 10)
		return str;
	return str.substr(0, 9) + ".";
}

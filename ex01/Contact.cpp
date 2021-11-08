/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:37:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/08 10:37:03 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	:
	_idx(0),
	_first_name(""),
	_last_name(""),
	_nickname(""),
	_phone_num(""),
	_darkest_secret("")
{}

Contact::Contact(
	int idx,
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname,
	const std::string &phone_num,
	const std::string &darkest_secret)
	:
	_idx(idx),
	_first_name(first_name),
	_last_name(last_name),
	_nickname(nickname),
	_phone_num(phone_num),
	_darkest_secret(darkest_secret)
{}

int	Contact::idx() const
{
	return _idx;
}

std::string	Contact::first_name() const
{
	return _first_name;
}

std::string	Contact::short_first_name() const
{
	if (_first_name.size() <= 10)
		return _first_name;
	return _first_name.substr(0, 9) + ".";
}

std::string	Contact::last_name() const
{
	return _last_name;
}

std::string	Contact::short_last_name() const
{
	if (_last_name.size() <= 10)
		return _last_name;
	return _last_name.substr(0, 9) + ".";
}

std::string	Contact::nickname() const
{
	return _nickname;
}

std::string	Contact::short_nickname() const
{
	if (_nickname.size() <= 10)
		return _nickname;
	return _nickname.substr(0, 9) + ".";
}

std::string	Contact::phone_number() const
{
	return _phone_num;
}

std::string	Contact::darkest_secret() const
{
	return _darkest_secret;
}

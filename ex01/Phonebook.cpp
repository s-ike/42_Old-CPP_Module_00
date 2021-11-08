/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:44:22 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/08 10:56:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def_color.h"
#include "Phonebook.hpp"

/* ************************************************************************** */
/*   private                                                                  */
/* ************************************************************************** */

void	Phonebook::put_command_list() const
{
	std::cout << COLOR_CYAN "Enter [ADD, SEARCH, EXIT]." COLOR_RESET << std::endl;
}

bool	Phonebook::add_mode()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_num;
	std::string	secret;

	std::cout << "first name:" << std::endl;
	if (!getline(std::cin, first_name))
		return false;
	std::cout << "last name:" << std::endl;
	if (!getline(std::cin, last_name))
		return false;
	std::cout << "nickname:" << std::endl;
	if (!getline(std::cin, nickname))
		return false;
	std::cout << "phone number:" << std::endl;
	if (!getline(std::cin, phone_num))
		return false;
	std::cout << "darkest secret:" << std::endl;
	if (!getline(std::cin, secret))
		return false;
	add(first_name, last_name, nickname, phone_num, secret);
	return true;
}

void	Phonebook::add(
		const std::string &first_name,
		const std::string &last_name,
		const std::string &nickname,
		const std::string &phone_num,
		const std::string &secret)
{
	if (_idx == SIZE_MAX)
	{
		std::cout << COLOR_RED "Reached the limit." COLOR_RESET << std::endl;
		return;
	}
	_contacts[_idx % _max] = Contact(_idx + 1, first_name, last_name, nickname, phone_num, secret);
	++_idx;
}

bool	Phonebook::search_mode()
{
	put_address_list();
	return true;
}

void	Phonebook::put_address_list()
{
	std::cout
		<< std::setw(_width) << "INDEX"
		<< '|'
		<< std::setw(_width) << "FIRST NAME"
		<< '|'
		<< std::setw(_width) << "LAST NAME"
		<< '|'
		<< std::setw(_width) << "NICKNAME"
		<< std::endl;

	int	end = _idx < _max ? _idx : _max;
	for (int i = 0; i < end; ++i)
	{
		std::cout
			<< std::setw(_width) << std::right << _contacts[i].idx()
			<< '|'
			<< std::setw(_width) << std::right << _contacts[i].short_first_name()
			<< '|'
			<< std::setw(_width) << std::right << _contacts[i].short_last_name()
			<< '|'
			<< std::setw(_width) << std::right << _contacts[i].short_nickname()
			<< std::endl;
	}

}

/* ************************************************************************** */
/*   public                                                                   */
/* ************************************************************************** */

Phonebook::Phonebook()
	: _idx(0)
{}

void	Phonebook::routine()
{
	std::string	command;

	do
	{
		put_command_list();
		if (!getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			if (!add_mode())
				break;
		}
		else if (command == "SEARCH")
			search_mode();
	} while (command != "EXIT");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:44:22 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/09 21:36:39 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "def_color.h"
#include "Phonebook.hpp"

/* ************************************************************************** */
/*   private                                                                  */
/* ************************************************************************** */

void	Phonebook::display_command_list() const
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
	_contacts[_idx % _max] = Contact(_idx % _max + 1, first_name, last_name, nickname, phone_num, secret);
	++_idx;
}

bool	Phonebook::search_mode()
{
	display_address_list();
	return contact_mode();
}

void	Phonebook::display_address_list()
{
	std::cout
		<< std::setw(_width) << std::right << "INDEX"
		<< '|'
		<< std::setw(_width) << std::right << "FIRST NAME"
		<< '|'
		<< std::setw(_width) << std::right << "LAST NAME"
		<< '|'
		<< std::setw(_width) << std::right << "NICKNAME"
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

bool	Phonebook::contact_mode() const
{
	if (_idx == 0)
		return true;

	std::string	input;

	std::cout << COLOR_CYAN "Enter index number." COLOR_RESET << std::endl;
	if (!getline(std::cin, input))
		return false;
	else if (!is_valid_input(input))
	{
		std::cout << COLOR_RED "Invalid input." COLOR_RESET << std::endl;
		return true;
	}
	else if (!is_valid_range(input))
	{
		std::cout << COLOR_RED "Out of index range." COLOR_RESET << std::endl;
		return true;
	}
	else
		display_contact(atoi(input.c_str()));
	return true;
}

bool	Phonebook::is_valid_input(const std::string &input) const
{
	for (size_t i = 0; input[i]; ++i)
	{
		if (!isdigit(input[i]))
			return false;
		if (i == SIZE_MAX)
			return false;
	}
	return true;
}

bool	Phonebook::is_valid_range(const std::string &input) const
{
	const int	idx = atoi(input.c_str());
	const int	range = _idx < _max ? _idx : _max;

	if (idx < 1 || range < idx)
		return false;
	return true;
}

void	Phonebook::display_contact(int idx) const
{
	--idx;
	std::cout
		<< std::setw(16) << std::right << "first name: " << std::flush
		<< _contacts[idx].first_name() << '\n'
		<< std::setw(16) << std::right << "last name: " << std::flush
		<< _contacts[idx].last_name() << '\n'
		<< std::setw(16) << std::right << "nickname: " << std::flush
		<< _contacts[idx].nickname() << '\n'
		<< std::setw(16) << std::right << "phone number: " << std::flush
		<< _contacts[idx].phone_number() << '\n'
		<< std::setw(16) << std::right << "darkest secret: " << std::flush
		<< _contacts[idx].darkest_secret()
		<< std::endl;
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
		display_command_list();
		if (!getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			if (!add_mode())
				break;
		}
		else if (command == "SEARCH")
			if (!search_mode())
				break;
	} while (command != "EXIT");

}

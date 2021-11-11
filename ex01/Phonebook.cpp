/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:44:22 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/11 11:39:03 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
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
	const std::string	field_name[] = {
		"first name:", "last name:", "nickname:", "phone number:", "darkest secret:"};
	std::string	field_contents[sizeof(field_name) / sizeof(field_name[0])];

	for (unsigned i = 0; i < sizeof(field_name) / sizeof(field_name[0]); i++)
	{
		std::cout << field_name[i] << std::endl;
		if (!getline(std::cin, field_contents[i]))
			return false;
	}
	add(field_contents[0], field_contents[1], field_contents[2], field_contents[3], field_contents[4]);
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
	_contacts[_idx % _max] = Contact(first_name, last_name, nickname, phone_num, secret);
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
			<< std::setw(_width) << std::right << i + 1
			<< '|'
			<< std::setw(_width) << std::right << Contact::to_short(_contacts[i].first_name())
			<< '|'
			<< std::setw(_width) << std::right << Contact::to_short(_contacts[i].last_name())
			<< '|'
			<< std::setw(_width) << std::right << Contact::to_short(_contacts[i].nickname())
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

	std::stringstream	sst;
	int					n;

	sst << input;
	sst >> n;
	if (sst.fail())
	{
		std::cout << COLOR_RED "Invalid input." COLOR_RESET << std::endl;
		return true;
	}
	else if (!is_valid_range(n))
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

bool	Phonebook::is_valid_range(int input_n) const
{
	const int	range = _idx < _max ? _idx : _max;

	if (input_n < 1 || range < input_n)
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

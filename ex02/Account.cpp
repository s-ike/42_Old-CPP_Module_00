/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:54:59 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/09 21:01:41 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

/* ************************************************************************** */
/*   static variables                                                         */
/* ************************************************************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* ************************************************************************** */
/*   public                                                                   */
/* ************************************************************************** */

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

// [19920104_091532] index:0;amount:42;created
Account::Account( int initial_deposit )
	:
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
}

// [19920104_091532] index:7;amount:8942;closed
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
		<< std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	std::cout << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

// // [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:";
	if (withdrawal <= checkAmount())
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		std::cout << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
		return true;
	}
	std::cout << "refused" << std::endl;
	return false;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

/* ************************************************************************** */
/*   private                                                                  */
/* ************************************************************************** */

void	Account::_displayTimestamp( void )
{
#ifndef TEST
	time_t		current = time(NULL);
	struct tm	*timer = localtime(&current);

	std::cout << '['
		<< timer->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << timer->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << timer->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << timer->tm_hour
		<< std::setw(2) << std::setfill('0') << timer->tm_min
		<< std::setw(2) << std::setfill('0') << timer->tm_sec
		<< "] ";
#endif
}

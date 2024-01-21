/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:59:22 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/21 16:09:32 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:"
		<< initial_deposit << ";created" << std::endl;
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:"
		<< _amount << ";closed" << std::endl;
}

static int		Account::getNbAccounts( void )
{
	return(this->_nbAccounts);
}

static int		Account::getTotalAmount( void )
{
	return(this->_totalAmount);
}

static int		Account::getNbDeposits( void )
{
	return(this->_totalNbDeposits);
}

static int		Account::getNbWithdrawals( void )
{
	return(this->_totalNbWithdrawals);
}

static void		Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
		 << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}





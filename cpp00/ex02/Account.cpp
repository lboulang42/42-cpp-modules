/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:34:56 by lboulang          #+#    #+#             */
/*   Updated: 2024/01/10 19:00:39 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <sys/time.h>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
Not needed, but required by the subject
*/
int Account::getNbAccounts(void)
{
	return (0);
}

/*
Not needed, but required by the subject
*/
int Account::getTotalAmount(void)
{
	return (0);
}

/*
Not needed, but required by the subject
*/
int Account::getNbDeposits(void)
{
	return (0);
}

/*
Not needed, but required by the subject
*/
int Account::getNbWithdrawals(void)
{
	return (0);
}

/*
Not needed, but required by the subject
*/
int Account::checkAmount(void) const
{
	return (0);
}

/*
Destroy the account, print the index, the amount and the status of the account (closed);
*/
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

/* Display timestamp using C gettimeofday */
void Account::_displayTimestamp(void)
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	std::cout << "[" << time_now.tv_sec << "_" << time_now.tv_usec << "] ";
}

/*
Print :
	- the current time,
	- the index of the account,
	- the amount of the account,
	- the number of deposits of the account,
	- the number of withdrawals of the account
*/
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

/*
Return bool on withdrawal success or failure;
Print index, previous amount;
If withdrawal forbidden, print refused and return false;
else withdraw it from the account, update the global infos and print it
*/
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";

	/*If withdrawal forbidden, print refused and return false*/
	if (_amount < withdrawal)
		return (std::cout << "withdrawal:refused" << std::endl, false);

	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return (true);
}

/*
Add deposit to the account amount; update the global infos; print the infos;
*/
void Account::makeDeposit(int deposit)
{
	/* Update Account amount, nbDeposits, totalAmount, totalNbDeposits */
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	/* Print deposit and account infos*/
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

/*
Print :
	- the number of accounts,
	- the total amount of deposits,
	- the total amount of withdrawals
	- the total amount of deposits;
*/
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

/*
Constructor for Account class, initial_deposit is added to amount;
Set the account index to the current nbAccounts;
Update the totalAmount;

Prints the index, the amount and the status of the account (created);
*/
Account::Account(int initial_deposit)
{
	/*Update Account Infos*/
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;

	/*Print Account Infos*/
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
}

/*
Never Called, not used but required by the subject;
By default if initial_deposit is not provided, I set it to 0;
*/
Account::Account(void)
{
	int initial_deposit = 0;
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;

	/*Print Account Infos*/
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
}
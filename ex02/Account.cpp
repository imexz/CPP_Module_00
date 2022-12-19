/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 09:30:03 by mstrantz          #+#    #+#             */
/*   Updated: 2022/01/25 16:06:18 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {

	_nbAccounts++;
	this->_accountIndex = _nbAccounts - 1;
	_displayTimestamp();
	std::cout   << "index:"
				<< this->_accountIndex
				<< ";"
				<< "amount:"
				<< this->_amount
				<< ";"
				<< "created"
				<< std::endl;
}

Account::Account(int initial_deposit) {

	_amount = initial_deposit;
	_nbAccounts++;
	this->_accountIndex = _nbAccounts - 1;
	_displayTimestamp();
	std::cout   << "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";created"
				<< std::endl;
	_totalAmount += initial_deposit;
}

Account::~Account(void) {

	_displayTimestamp();
	std::cout   << "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";closed"
				<< std::endl;
	_nbAccounts--;
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {

	_displayTimestamp();
	std::cout   << "accounts:"
				<< getNbAccounts()
				<< ";total:"
				<< getTotalAmount()
				<< ";deposits:"
				<< getNbDeposits()
				<< ";withdrawals:"
				<< getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit(int deposit) {

	int	p_amount;

	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	p_amount = _amount + deposit;
	_displayTimestamp();
	std::cout   << "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< _amount
				<< ";deposits:"
				<< deposit
				<< ";amount:"
				<< p_amount
				<< ";nb_deposits:"
				<< _nbDeposits
				<< std::endl;
	_amount = p_amount;

}

bool	Account::makeWithdrawal(int withdrawal) {

	int	p_amount;

	if (_amount - withdrawal < 0) {
		_displayTimestamp();
		std::cout   << "index:"
					<< _accountIndex
					<< ";p_amount:"
					<< _amount
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	else {
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		p_amount = _amount - withdrawal;
		_displayTimestamp();
		std::cout   << "index:"
					<< _accountIndex
					<< ";p_amount:"
					<< _amount
					<< ";withdrawal:"
					<< withdrawal
					<< ";amount:"
					<< p_amount
					<< ";nb_withdrawals:"
					<< _nbWithdrawals
					<< std::endl;
		_amount = p_amount;
	}
	return (true);
}

int	Account::checkAmount(void) const {
	return (_amount > 0);
}

void	Account::displayStatus(void) const {

	_displayTimestamp();
	std::cout   << "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";deposits:"
				<< _nbDeposits
				<< ";withdrawals:"
				<< _nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp(void) {

	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
	std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900)
			<< std::setw(2) << utc_tm.tm_mon
			<< std::setw(2) << utc_tm.tm_mday << "_"
			<< std::setw(2) << utc_tm.tm_hour
			<< std::setw(2) << utc_tm.tm_min
			<< std::setw(2) << utc_tm.tm_sec << "] ";
}

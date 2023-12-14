#pragma once
#include "Transaction.h"
Transaction::Transaction(Customer Client): Client(Client) {}
void Transaction::TransferMoneyToAnotherPerson(Customer Recipient)
{
	int Sum;
	std::cout << "Specify the amount of money you want to transfer\n";
	std::cin >> Sum;
	int IndexOfFirstAccount, IndexOfSecondAccount;
	std::cout << "Enter the account number of the first user";
	std::cin >> IndexOfFirstAccount;
	while (Sum > Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash())
	{
		std::cerr << "Error. You don't have enough money! Type again.";
		std::cin >> Sum;
	}
	std::cout << "Enter the account number of the second user";
	std::cin >> IndexOfSecondAccount;
	Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash() -= Sum;
	Recipient.GetCheckingAccountFromList(IndexOfSecondAccount).GetCash() += Sum;
}
void Transaction::TransferMoneyToAMobilePhoneNumber(size_t MobilePhoneNumber)
{
	int Sum;
	std::cout << "Specify the amount of money you want to transfer";
	std::cin >> Sum;
	int IndexOfFirstAccount;
	std::cout << "Enter the account number of the user";
	std::cin >> IndexOfFirstAccount;
	while (Sum > Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash())
	{
		std::cerr << "Error. You don't have enough money! Type again.";
		std::cin >> Sum;
	}
	Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash() -= Sum;
}
void Transaction::MakeADepositWithInterest()
{
	int Sum;
	std::cout << "Enter the amount you want to invest\n";
	std::cin >> Sum;
	double DepositRate;
	std::cout << "Enter the interest rate\n";
	std::cin >> DepositRate;
	Client.AddSavingsAccount(DepositRate);
}
void Transaction::WithdrawMoney()
{
	int Sum;
	std::cout << "Specify the amount of money you want to withdraw\n";
	std::cin >> Sum;
	int IndexOfFirstAccount;
	std::cout << "Enter the account number of the user";
	std::cin >> IndexOfFirstAccount;
	while (Sum > Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash())
	{
		std::cerr << "Error. You don't have enough money! Type again.";
		std::cin >> Sum;
	}
	Client.GetCheckingAccountFromList(IndexOfFirstAccount).GetCash() -= Sum;
}
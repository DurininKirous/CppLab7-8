#include "menu.h"
#include "Customer.h"
#include "Transaction.h"
void menu(int NumberOfUsers, Customer* ListOfUsers)
{
	printf("----------------------------\n");
	printf("%4sWelcome to our bank!%4s\n","","");
	printf("----------------------------\n");
	printf("See the functionality:\n");
	printf("1 - show all users\n");
	printf("2 - show all accounts of one user\n");
	printf("3 - find a user\n");
	printf("4 - add a new user\n");
	printf("5 - add an account to user\n");
	printf("6 - transfer money from one user to another\n");
	printf("7 - transfer money from a user to a phone number\n");
	printf("8 - invest money at an interest rate\n");
	printf("9 - withdraw money\n");
	printf("10 - compare two accounts\n");
	printf("11 - exit\n");
	int Action;
	std::cin >> Action;
	switch (Action)
	{
	case 1:
	{
		if (NumberOfUsers == 0)
		{
			std::cout << "There are no users! But you can add them\n";
			menu(NumberOfUsers, ListOfUsers);
		}
		else
		{
			for (int i = 0; i < NumberOfUsers; i++)
			{
				ListOfUsers[i].Print();
			}
		}
		std::cout << "Type Go to continue\n";
		std::string Choice;
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 2:
	{
		std::string Name;
		std::cout << "Enter the name\n";
		std::cin >> Name;
		bool HaveFound = false;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				HaveFound = true;
				for (int j = 0; j < ListOfUsers[i].GetNumberOfCheckingAccounts(); j++)
				{
					ListOfUsers[i].GetListOfCheckingAccounts()[j].Print();
				}
				for (int j = 0; j < ListOfUsers[i].GetNumberOfSavingsAccounts(); j++)
				{
					ListOfUsers[i].GetListOfSavingsAccounts()[j].Print();
				}
			}
		}
		if (HaveFound == false)
		{
			std::cout << "There are no users with such name\n";
			menu(NumberOfUsers, ListOfUsers);
		}
		std::cout << "Type Go to continue\n";
		std::string Choice;
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 3:
	{
		std::string Name;
		std::cout << "Enter the name\n";
		std::cin >> Name;
		bool HaveFound = false;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				HaveFound = true;
				ListOfUsers[i].Print();
			}
		}
		if (HaveFound == false)
		{
			std::cout << "There are no users with such name\n";
			menu(NumberOfUsers, ListOfUsers);
		}
		std::cout << "Type Go to continue\n";
		std::string Choice;
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 4:
	{
		Customer* NewList = new Customer[NumberOfUsers + 1];
		if (NumberOfUsers != 0)
		{
			for (int i = 0; i < NumberOfUsers; i++)
			{
				NewList[i] = ListOfUsers[i];
			}
		}
		std::string FirstName;
		std::cout << "Enter the First Name\n";
		std::cin >> FirstName;
		std::string LastName;
		std::cout << "Enter the Last Name\n";
		std::cin >> LastName;
		int Password;
		std::cout << "Enter the Password\n";
		std::cin >> Password;
		Customer NewUser(FirstName, LastName, Password, 0, 0);
		NewList[NumberOfUsers] = NewUser;
		delete[] ListOfUsers;
		ListOfUsers = NewList;
		NumberOfUsers += 1;
		std::cout << "The user has been successfully added! Type Go to continue\n";
		std::string Choice;
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 5:
	{
		std::string Name;
		bool found = false;
		std::cout << "Type the Name of User\n";
		std::cin >> Name;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				found = true;
				std::cout << "Which type of account do you want to add? (Checking/Savings)\n";
				std::cin >> Name;
				while (Name != "Checking" && Name != "Savings")
				{
					std::cout << "I don't understand! Enter the type again.\n";
					std::cin >> Name;
				}
				if (Name == "Checking")
				{
					ListOfUsers[i].AddCheckingAccount();
				}
				else if (Name == "Savings")
				{
					ListOfUsers[i].AddSavingsAccount();
				}
				break;
			}
		}
		std::string Choice;
		if (!(found))
		{
			std::cerr << "The specified user does not exist. Type Go to continue\n";
			std::cin >> Choice;
			while (Choice != "Go") { std::cin >> Choice; }
			menu(NumberOfUsers,ListOfUsers);
			return;
		}
		std::cout << "The account has been successfully added! Type Go to continue\n";
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 6:
	{
		std::string FirstName;
		std::string SecondName;
		bool FirstFound=false;
		bool SecondFound = false;
		std::cout << "Enter the name of sender\n";
		std::cin >> FirstName;
		std::cout << "Enter the name of recipient\n";
		std::cin >> SecondName;
		int FirstIndex;
		int SecondIndex;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == FirstName)
			{
				FirstIndex = i;
				FirstFound = true;
			}
			if (ListOfUsers[i].GetName() == SecondName)
			{
				SecondIndex = i;
				SecondFound = true;
			}
		}
		std::string Choice;
		if (!(SecondFound && FirstFound))
		{
			std::cerr << "At least one specified user is missing from the list. Type Go to continue\n";
			std::cin >> Choice;
			while (Choice != "Go") { std::cin >> Choice; }
			menu(NumberOfUsers, ListOfUsers);
			return;
		}
		Transaction Transfer(ListOfUsers[FirstIndex]);
		Transfer.TransferMoneyToAnotherPerson(ListOfUsers[SecondIndex]);
		std::cout << "The operation was completed successfully! Type Go to continue\n";
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 7:
	{
		std::string Name;
		bool found = false;
		std::cout << "Enter the name of sender\n";
		std::cin >> Name;
		int Index;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				Index = i;
				found = true;
			}
		}
		std::string Choice;
		if (!(found))
		{
			std::cerr << "The specified user does not exist. Type Go to continue\n";
			std::cin >> Choice;
			while (Choice != "Go") { std::cin >> Choice; }
			menu(NumberOfUsers, ListOfUsers);
			return;
		}
		size_t MobilePhoneNumber;
		std::cout << "Enter the mobile phone number\n";
		std::cin >> MobilePhoneNumber;
		Transaction Transfer(ListOfUsers[Index]);
		Transfer.TransferMoneyToAMobilePhoneNumber(MobilePhoneNumber);
		std::cout << "The operation was completed successfully! Type Go to continue\n";
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 8:
	{
		std::string Name;
		bool found = false;
		std::cout << "Enter the name of the contributor\n";
		std::cin >> Name;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				Transaction Invest(ListOfUsers[i]);
				Invest.MakeADepositWithInterest();
				found = true;
				break;
			}
		}
		if (!(found))
		{
			std::cerr << "The specified user does not exist. Type Go to continue\n";
			std::string Choice;
			std::cin >> Choice;
			while (Choice != "Go") { std::cin >> Choice; }
			menu(NumberOfUsers, ListOfUsers);
			return;
		}
	}
	case 9:
	{
		std::string Name;
		bool found = false;
		std::cout << "Enter the name of user\n";
		std::cin >> Name;
		int Index;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == Name)
			{
				Index = i;
				found = true;
			}
		}
		std::string Choice;
		if (!(found))
		{
			std::cerr << "The specified user does not exist. Type Go to continue\n";
			std::cin >> Choice;
			while (Choice != "Go") { std::cin >> Choice; }
			menu(NumberOfUsers, ListOfUsers);
			return;
		}
		Transaction Transfer(ListOfUsers[Index]);
		Transfer.WithdrawMoney();
		std::cout << "The operation was completed successfully! Type Go to continue\n";
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);
	}
	case 10:
	{
		std::string FirstName;
		std::string SecondName;
		bool FirstFound = false;
		bool SecondFound = false;
		std::cout << "Enter the name of first user\n";
		std::cin >> FirstName;
		std::cout << "Enter the name of second user\n";
		std::cin >> SecondName;
		int FirstIndex;
		int SecondIndex;
		for (int i = 0; i < NumberOfUsers; i++)
		{
			if (ListOfUsers[i].GetName() == FirstName)
			{
				FirstIndex = i;
				FirstFound = true;
			}
			if (ListOfUsers[i].GetName() == SecondName)
			{
				SecondIndex = i;
				SecondFound = true;
			}
		}
		std::string Choice;
		if (!(SecondFound && FirstFound))
		{
			std::cerr << "At least one specified user is missing from the list. Type Go to continue\n";
			std::cin >> Choice;
			while (Choice != "Go") { std::cin >> Choice; }
			menu(NumberOfUsers, ListOfUsers);
			return;
		}
		std::cout << "Which types of accounts do you want to compare?(Checking/Savings)\n";
		std::cin >> Choice;
		while (Choice != "Checking" && Choice != "Savings")
		{
			std::cout << "I don't understand! Enter the type again.\n";
			std::cin >> Choice;
		}
		int FirstAccount;
		int SecondAccount;
		if (Choice == "Checking")
		{
			std::cout << "Enter the number of first account\n";
			std::cin >> FirstAccount;
			std::cout << "Enter the number of second account\n";
			std::cin >> SecondAccount;
			if (ListOfUsers[FirstIndex].GetCheckingAccountFromList(FirstAccount) == ListOfUsers[SecondIndex].GetCheckingAccountFromList(SecondAccount))
			{
				std::cout << "They are equal!\n";
			}
			else
			{
				std::cout << "They aren't equal!\n";
			}

		}
		else if (Choice == "Savings")
		{
			std::cout << "Enter the number of first account\n";
			std::cin >> FirstAccount;
			std::cout << "Enter the number of second account\n";
			std::cin >> SecondAccount;
			if (ListOfUsers[FirstIndex].GetSavingsAccountFromList(FirstAccount) == ListOfUsers[SecondIndex].GetSavingsAccountFromList(SecondAccount))
			{
				std::cout << "They are equal!\n";
			}
			else
			{
				std::cout << "They aren't equal!\n";
			}
		}
		std::cout << "The operation was completed successfully! Type Go to continue\n";
		std::cin >> Choice;
		while (Choice != "Go") { std::cin >> Choice; }
		menu(NumberOfUsers, ListOfUsers);

	}
	case 11:
		std::cout << "Goodbye!\n";
		return;		
	default:
		std::cout << "There is no operation with such number! Try again.\n";
		menu(NumberOfUsers, ListOfUsers);
		break;
	}
}

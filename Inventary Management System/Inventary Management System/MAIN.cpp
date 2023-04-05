

#include<iostream>
#include<fstream>
#include"Admin.h"
#include"SK.h"
#include"customer.h"
using namespace std;
void loggedIN();
void AdminLoggedIn(Admin& obj);
void main() 
{

	system("pause");

	int choice2 = 0;
	int choice3 = 0;
	int choice = 0;// to get choice for menue
	bool exit = true;//for exit case
	//loop to display main menue
	while (exit)
	{
		MAIN:
		system("CLS");
		// displaying main menue
		cout << "       ==============| MENUE |============\n\n\n" ;
		cout << "           1.Admin Section\n\n";
		cout << "           2.Shopkeeper Section\n\n";
		cout << "           3.Customer Section\n\n";
		cout << "           4.Exit\n\n";
		cout << "Enter Your Choice : ";
		try
		{
			cin >> choice;
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int a)
		{
			cout << "Wrong Input Enter again " << endl;
			cin.clear();
			cin.ignore();
			system("pause");
			goto MAIN;
		}


		switch (choice)
		{
		case 1:
			string * u_n; string* pas;
			u_n = new string; pas = new string;
		admin:
			cout << "==========| LOG IN |===========" << endl << endl;
			cin.ignore();
			cout << "Enter UserName: "; getline(cin, *u_n);
			cout << "Enter Password: "; getline(cin, *pas);

			Admin* Adm;
			Adm = new Admin(*u_n,*pas);
			if (Adm->logIn())
			{
				system("pause");
				AdminLoggedIn(*Adm);
			}
			system("pause");
			break;
		case 2:

		log:
			system("cls");
			cout << "       ==============| SHOPKEEPER MENUE |============\n\n\n";
			cout << "             1.LOG IN\n\n";
			cout << "             2.Register To System\n\n";
			cout << "             3.Return to Main Menue\n\n";
			cout << "         Enter Your Choice : ";
			try
			{
				cin >> choice2;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int a)
			{
				cout << "Wrong Input Enter again " << endl;
				cin.clear();
				cin.ignore();
				system("pause");
				goto log;
			}
			switch (choice2)
			{
			case 1:
				string *un;
				un = new string;
				string *pas;
				pas = new string;
				cin.ignore();
				cout << "Enter User Name : ";
				getline(cin,*un);
				cout << "Enter Password: ";
				getline(cin,*pas);
				Sign_In *object;
				object = new Sign_In(*un, *pas);
				if (object->checkData("ShopKeeper.txt"))
				{
					system("pause");
					loggedIN();
					goto log;
				}
				system("pause");
				goto log;
				break;
			case 2:
				RegToSystem * obj;
				obj = new RegToSystem;
				cin >> *obj;
				obj->write_to_file("ShopKeeper.txt","SKcount.txt");
				goto log;
				break;
			case 3:
				goto MAIN;
				break;
			default:
				cout << "Invalid Choice Entered" << endl;
				system("pause");
				goto log;
				break;
			}
			break;
		case 3:
			cus:
			system("cls");
			cout << "       ==============| CUSTOMER MENUE |============\n\n\n";
			cout << "             1.LOG IN\n\n";
			cout << "             2.Register To System\n\n";
			cout << "             3.Return to Main Menue\n\n";
			cout << "         Enter Your Choice : ";
			try
			{
				cin >> choice3;
				if (cin.fail())
				{
					throw 1;
				}
			}
			catch (int a)
			{
				cout << "Wrong Input Enter again " << endl;
				cin.clear();
				cin.ignore();
				system("pause");
				goto cus;
			}

			switch (choice3)
			{
			case 1:
				string * un;
				un = new string;
				string* pas;
				pas = new string;
				cin.ignore();
				cout << "Enter User Name : ";
				getline(cin, *un);
				cout << "Enter Password: ";
				getline(cin, *pas);
				customer* custmr;
				custmr = new customer(*un, *pas);
				if (custmr->customer_Sign())
				{

					char ch;
					string g;
					int P, s, q;
					cout << "Please select the Product:" << endl;
					cout << "-------------------Menu-----------------" << endl;
					ifstream f("Products.txt");
					if (f.is_open())

						while (!f.eof())
						{
							f.get(ch);
							cout << ch;
						}


					else {
						cout << "ERROR:no file opened.";
					}
					cout << endl;
					cin >> P;
					cout << "-----------------------Thanks for slection----------------------" << endl;
					cout << "TO add in the cart Please type 1:";
					cin >> s;
					switch (s)
					{
					case 1:
					{
						cout << "-----------------Thanks to add in the cart--------------------------" << endl;
						cout << "For Check Out Please re-entered 1" << endl;
						cin >> q;

						cout << "------------Please enter address-----------" << endl;
						ofstream MyFile("address.txt");
						getline(cin,g);
						MyFile << g;
						MyFile.close();
						cout << "Thanks for Shopping Your Product is on the way" << endl;
						break;
					}
					default:
						cout << "Please select the valid option" << endl;


					}
					system("pause");
					goto cus;
				}
				system("pause");
				goto log;
				break;
			case 2:
				customer * obj;
				obj = new customer;
				obj->customer_Reg();

				goto cus;
				break;
			case 3:
				goto MAIN;
				break;
			}


			system("pause");
			break;
		
		case 4:
			exit = false;
			cout << "            Exited!          " << endl;
			break;
		default:
			cout << "Invalid Input! Try Again " << endl;
			system("pause");
			break;
		}
	}
	
}
//Function to hold ShopKeeper menue
void loggedIN() {
	shopkeeper:
	system("CLS");
	int choice = 0;
	cout << "       ==============| SHOPKEEPER MENUE |============\n\n\n";
	cout << "             1.ADD NEW PRODUCT\n\n";
	cout << "             2.EDIT PRODUCT DETAILS\n\n";
	cout << "             3.VIEW PRODUCT\n\n";
	cout << "             4.Back\n\n";
	A:
	cout << "    Enter Your Choice : ";
	try
	{
		cin >> choice;
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int a)
	{
		cout << "Wrong Input Enter again " << endl;
		cin.clear();
		cin.ignore();
		system("pause");
		goto shopkeeper;
	}

	switch (choice)
	{
	case 1:
		addProduct* obj;
		obj = new addProduct;
		obj->getCatagory();
		cin >> *obj;
		goto shopkeeper;
		break;
	case 2:
		editProduct * edit;
		edit = new editProduct;
		edit->InputData();
		edit->EditData();
		goto shopkeeper;
		break;
	case 3:
		ViewProduct * p;
		p = new ViewProduct;
		p->showProducts();
		goto shopkeeper;
		break;
	case 4:
		break;
	default:
		cout << "Wrong choice Enter again(1,2,3) " << endl;
		goto A;
		break;
	}
}
// Fuction To Handle Admin menue
void AdminLoggedIn(Admin &obj) 
{
Admin:
	//system("pause");
	system("CLS");
	int choice = 0;
	cout << "       ==============| ADMIN MENUE |============\n\n\n";
	cout << "             1.ADD NEW Shop Keeper\n\n";
	cout << "             2.ADD NEW Customer\n\n";
	cout << "             3.ADD NEW PRODUCT\n\n";
	cout << "             4.EDIT SHOPKEEPER DETAILS\n\n";
	cout << "             5.EDIT CUSTOMER DETAILS\n\n";
	cout << "             6.EDIT PRODUCT DETAILS\n\n";
	cout << "             7.VIEW PRODUCT\n\n";
	cout << "             8.DELETE PRODUCT\n\n";
	cout << "             9.DELETE SHOP KEEPER\n\n";
	cout << "             10.DELETE CUSTOMER\n\n";
	cout << "             0.Back\n\n";
B:
	cout << "    Enter Your Choice : ";
	try
	{
		cin >> choice;
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int a)
	{
		cout << "Wrong Input Enter again " << endl;
		cin.clear();
		cin.ignore();
		system("pause");
		goto B;
	}

	switch (choice)
	{
	case 1:
		obj.RegSK();
		goto Admin;
		break;
	case 2:
		obj.RegCS();
		goto Admin;
		break;
	
	case 3:
		obj.ADD_Product();
		goto Admin;
		break;
	case 4:
		obj.editSK();
		goto Admin;
		break;
	case 5:
		obj.editCS();
		goto Admin;
		break;
	
	case 6:
		obj.edit_product();
		goto Admin;
		break;
	case 7:
		obj.View_product();
		goto Admin;
		break;
	case 8:
		obj.deleteProduct();
		goto Admin;
		break;
	case 9:
		obj.deleteShopkeeper();
		goto Admin;
		break;
	case 10:
		obj.deleteCustomer();

	case 0:
		break;
	default:
		cout << "Wrong choice Enter again(1,2,3,4,5,6) " << endl;
		goto B;
		break;
	}


}
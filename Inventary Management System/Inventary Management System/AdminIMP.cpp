#include"Admin.h"
Admin::Admin() {

}
Admin::Admin(string u_n,string pass): log_In(u_n,pass) {}
bool Admin::logIn() 
{
	bool log_status=log_In.checkData("Admin.txt");
	return log_status;
}
void Admin::RegSK() {
	cin >> Add_SK;
	Add_SK.write_to_file("ShopKeeper.txt","SKcount.txt");
}
void Admin::ADD_Product() 
{
	Add_Product.getCatagory();
	cin >> Add_Product;

}
void Admin::edit_product()
{
	edit.InputData();
	edit.EditData();
}
void Admin::View_product()
{
	View.showProducts();
}
void Admin::RegCS()
{
	cin >> Add_CS;
	Add_CS.write_to_file("Customer.txt", "CScount.txt");
}
void Admin::deleteProduct()
{
	deleteP.InputData();
	string New_name, New_colour, New_size, New_des;
	int New_stock;
	ifstream inFile;
	ofstream outFile;
	int temp_id = 0;

	bool not_found = true;
re:
	outFile.open("Temp1.txt");
	inFile.open("Products.txt");
	if (!inFile.is_open()) {
		cout << "Cannot opoen File" << endl;

	}
	else
	{
		string rem_str, tempName, tempSize, tempColour, tempDes;
		int tempstock;
		while (!inFile.eof())
		{
			inFile >> temp_id;
			inFile >> tempstock;
			inFile >> tempName;
			inFile >> tempColour;
			inFile >> tempSize;
			inFile.ignore();
			getline(inFile, tempDes);
			if (!inFile.eof())
			{

				if (temp_id == deleteP.getSearch_key() && deleteP.getSearch_name() == tempName)
				{
					cout << "          Product Deleted" << endl;
					system("pause");
					not_found = false;
				}
				else
				{
					outFile << setw(2) << setfill('0') << temp_id << endl
						<< setw(4) << setfill('0') << tempstock << endl << tempName << endl
						<< tempColour << endl << tempSize << endl << tempDes << endl;
				}
			}
		}
		if (not_found)
		{
			inFile.close();
			outFile.close();
			cout << "Product Not Found, (Enter Valid Catagory or Or Name)" << endl;
			cout << "Try Again " << endl;
			system("pause");
			deleteP.InputData();
			goto re;
			system("pause");
		}
		inFile.close();
		outFile.close();
	}
	remove("Products.txt");
	rename("Temp1.txt", "Products.txt");
}
void Admin::editSK()
{
	edit_SK.edit("ShopKeeper.txt");
	remove("ShopKeeper.txt");
	rename("TEMP.txt", "ShopKeeper.txt");
	system("pause");
}

void Admin::editCS()
{
	edit_CS.edit("Customer.txt");
	remove("Customer.txt");
	rename("TEMP.txt", "Customer.txt");
	system("pause");
}

void Admin::deleteShopkeeper()
{
	edit_SK.deleteData("ShopKeeper.txt");
	remove("ShopKeeper.txt");
	rename("TEMP.txt", "ShopKeeper.txt");
	system("pause");

}

void Admin::deleteCustomer() {
	edit_CS.deleteData("Customer.txt");
	remove("Customer.txt");
	rename("TEMP.txt", "Customer.txt");
	system("pause");
}
// ==============================EDIT DATA==============================//

Edit_DATA::Edit_DATA() {
	tempId = 0 ;
	border = "\0";
	temp_name = "\0";
	temp_username = "\0";
	temp_Mail = "\0";
	temp_password = "\0";
	temp_regdate = "\0";
	temp_Gender = "\0";
	temp_BloodG = "\0";
	temp_contactNum = "\0";
	temp_add = "\0";
}

//to edit data
void Edit_DATA::edit(string filename)
{

	string F_NAME, L_NAME, U_NAME, PASS, EMAIL, CONTACT;
	ifstream inFile;
	ofstream outFile;
	int id;

	bool notFound = true;
wId:
	cout << "  Enter ID to Edit Details : ";
	try
	{
		cin >> id;
		if (cin.fail() || id < 1)
		{
			throw 1;
		}
	}
	catch (int a)
	{
		cin.clear();
		cin.ignore();
		cout << "Wrong ID Entered Try Again ";
		goto wId;
	}
	outFile.open("TEMP.txt");
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "cannot open file" << endl;

	}
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, border);

			getline(inFile, temp_name);
			inFile >> tempId;
			inFile.ignore();
			getline(inFile, temp_username);
			getline(inFile, temp_Mail);
			getline(inFile, temp_password);
			getline(inFile, temp_regdate);
			getline(inFile, temp_Gender);
			getline(inFile, temp_BloodG);
			getline(inFile, temp_contactNum);
			getline(inFile, temp_add);
			if (!inFile.eof())
			{
				if (id == tempId)
				{
					cin.ignore();
					cout << "Enter New First Name : ";

					getline(cin, F_NAME);
					cout << "Enter New Last Name : ";

					getline(cin, L_NAME);
					cout << "Enter New User Name : ";
					getline(cin, U_NAME);
					cout << "Enter New Mail : ";
					getline(cin, EMAIL);
					cout << "Enter New Password : ";
					getline(cin, PASS);
					cout << "Enter New Contact : ";
					getline(cin, CONTACT);
					//writing updated data
					outFile << border << endl;
					outFile << F_NAME << " " << L_NAME << endl;
					outFile << setw(4) << setfill('0') << tempId << endl;
					outFile << U_NAME << endl;
					outFile << EMAIL << endl;
					outFile << PASS << endl;
					outFile << temp_regdate << endl;
					outFile << temp_Gender << endl;
					outFile << temp_BloodG << endl;
					outFile << CONTACT << endl;
					outFile << temp_add << endl;

					cout << "      Data updated" << endl;
					notFound = false;
					system("pause");
				}
				else
				{
					outFile << border << endl;
					outFile << temp_name << endl;
					outFile << setw(4) << setfill('0') << tempId << endl;
					outFile << temp_username << endl;
					outFile << temp_Mail << endl;
					outFile << temp_password << endl;
					outFile << temp_regdate << endl;
					outFile << temp_Gender << endl;
					outFile << temp_BloodG << endl;
					outFile << temp_contactNum << endl;
					outFile << temp_add << endl;
				}
			}
		}
		if (notFound)
		{
			cout << "ShopKeeper Not found" << endl;
			system("pause");
		}

	}
	inFile.close();
	outFile.close();
}



void Edit_DATA::deleteData(string filename)
{
	ifstream inFile;
	ofstream outFile;
	int id;

	bool notFound = true;
wId:
	cout << "  Enter ID to Edit Details : ";
	try
	{
		cin >> id;
		if (cin.fail() || id < 1)
		{
			throw 1;
		}
	}
	catch (int a)
	{
		cin.clear();
		cin.ignore();
		cout << "Wrong ID Entered Try Again ";
		goto wId;
	}
	outFile.open("TEMP.txt");
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "cannot open file" << endl;

	}
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, border);

			getline(inFile, temp_name);
			inFile >> tempId;
			inFile.ignore();
			getline(inFile, temp_username);
			getline(inFile, temp_Mail);
			getline(inFile, temp_password);
			getline(inFile, temp_regdate);
			getline(inFile, temp_Gender);
			getline(inFile, temp_BloodG);
			getline(inFile, temp_contactNum);
			getline(inFile, temp_add);
			if (!inFile.eof())
			{
				if (id == tempId)
				{
					cout << "      Data Deleted" << endl;
					notFound = false;
					system("pause");
				}
				else
				{
					outFile << border << endl;
					outFile << temp_name << endl;
					outFile << setw(4) << setfill('0') << tempId << endl;
					outFile << temp_username << endl;
					outFile << temp_Mail << endl;
					outFile << temp_password << endl;
					outFile << temp_regdate << endl;
					outFile << temp_Gender << endl;
					outFile << temp_BloodG << endl;
					outFile << temp_contactNum << endl;
					outFile << temp_add << endl;
				}
			}
		}
		if (notFound)
		{
			cout << "ShopKeeper Not found" << endl;
			system("pause");
		}

	}
	inFile.close();
	outFile.close();
}
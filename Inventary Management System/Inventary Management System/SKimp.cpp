#include"SK.h"
ShopKeeper::ShopKeeper() {

}
//-----------------------------------RegToSystem--------------------------------------------//
int RegToSystem::SK_id = 0;
RegToSystem :: RegToSystem() {
	Fname = "\0";
	Lname = "\0";
	username = "\0";
	Mail = "\0";
	password = "\0";
	reg_date = { 0,0,0 };
	Gender = "\0";
	Blood_G = "\0";
	contactNum = "\0";
	add = { 0,0, "\0" ,"\0", "\0","\0" };
	//SK_id++;
}
RegToSystem :: ~RegToSystem() {
	//destructor
}

void RegToSystem::generate_Id(string fileName,string count) 
{
	int prev=0;
	ifstream readpre;
	readpre.open(count);
	readpre >> prev;
	SK_id = 1;
	SK_id += prev;
	readpre.close();
	ofstream write_count;
	write_count.open(count, ios::out);
	write_count << SK_id;
	write_count.close();
	ofstream File;
	File.open(fileName, ios::app);
	

	File << setw(4) << setfill('0') << SK_id;

	File << endl;
	File.close();

}
void RegToSystem::write_to_file(string filename,string count) {
	//////////////////Writing Data To file /////////////////
	ofstream outFile;
	//opening file
	outFile.open(filename, ios::app);
	if (!outFile.is_open())
	{
		cout << "Cannot Open File !" << endl;
	}
	else
	{
		outFile << "=========================  " << endl;
		outFile << Fname << " " << Lname << endl;
		generate_Id(filename,count);
		outFile << username << endl;
		outFile << Mail << endl;
		outFile << password << endl;
		outFile << reg_date.D << "/" << reg_date.M << "/" << reg_date.Y << endl;
		outFile << Gender << endl;
		outFile << Blood_G << endl;
		outFile << contactNum << endl;
		outFile << add.houseNumber << "," << add.streetNumber << "," << add.Block << ","
			<< add.city << "," << add.Province << "," << add.Country << endl;
		cout << "You are Successfully Registered" << endl;
		system("pause");
	}

}
 istream& operator >> (istream& input, RegToSystem& obj) {
	 //Buffer
	 cin.ignore();
	 cout << "Enter First Name : ";
	getline(input, obj.Fname);

	cout << "Enter Last Name : ";
	getline(input, obj.Lname);
	cout << "Enter user name : ";
	getline(input, obj.username);
	cout << "Enter Your Mail : ";
	getline(input, obj.Mail);
	cout << "Enter Your Password : ";
	getline(input, obj.password);
	cout << "Enter Registeration Date " << endl;
	wDay:
	cout << "Enter DAY : ";
	try
	{
       input >> obj.reg_date.D;
	   if (input.fail() || (obj.reg_date.D < 1 || obj.reg_date.D > 31))
	   {
		   throw 1;
	   }
	   wMonth:
	   cout << "Enter Month : ";
	   try 
	   {
		   input >> obj.reg_date.M;
		   if (input.fail() || (obj.reg_date.M < 1 || obj.reg_date.M > 12))
		   {
			   throw 1;
		   }
	   wYear:
		   cout << "Enter Year : ";
		   try
		   {
			   input >> obj.reg_date.Y;
			   if (input.fail())
				   throw 1;
		   }
		   catch (int c)
		   {
			   cout << "Wrong Year Entered Try Again" << endl;
			   input.clear();
			   input.ignore();
			   goto wYear;
		   }



	   }
	   catch (int b) {
		   cout << "Wrong Month Entered Try Again ";
		   input.clear();
		   input.ignore();
		   goto wMonth;
	   }

	}
	catch (int a)
	{
		cout << "Wrong Day Entered Try Again :";
		input.clear();
		input.ignore();
		goto wDay;
	}
	cin.ignore();
	cout << "Enter Your Gender : ";
	getline(input,obj.Gender);
	cout << "Enter Your Blood Group : ";
	getline(input,obj.Blood_G);
	cout << "Enter Your Contact Number : ";
	getline(input,obj.contactNum);
	cout << "           Enter Your Address Below " << endl;
	wHouse:
	cout << "House Number : ";
	try
	{
		input >> obj.add.houseNumber;
		if (input.fail())
			throw 1;
	}
	catch (int d)
	{
		cout << "Wrong House Number Entered Try Again" << endl;
		input.clear();
		input.ignore();
		goto wHouse;
	}
	wStreet:
	cout << "Street Number : ";
	try
	{
		input >> obj.add.streetNumber;
		if (input.fail())
			throw 1;
	}
	catch (int d)
	{
		cout << "Wrong Street Number Entered Try Again" << endl;
		input.clear();
		input.ignore();
		goto wStreet;
	}
	

	cin.ignore();
	cout << "Block :";
	getline(input, obj.add.Block);
	cout << "City : ";
	getline(input, obj.add.city);
	cout << "Province : ";
	getline(input, obj.add.Province);
	cout << "Country :";
	getline(input, obj.add.Country);

	//obj.write_to_file("ShopKeeper.txt");
	return input;
}
 //            Stters defination
 void RegToSystem::setFname(string fn){
	 Fname = fn;
	 }
 void RegToSystem::setLname(string ln) {
	 Lname = ln;
 }
 void RegToSystem::setUsername(string un) {
	 username = un;
 }
 void RegToSystem::setMail(string mail) {
	 Mail = mail;
 }
 void RegToSystem::setPassword(string pass) {
	 password = pass;
 }
 void RegToSystem::setRegDate(Date d) {
	 reg_date.D = d.D; reg_date.M = d.M; reg_date.Y = d.Y;
 }
 void RegToSystem::setGender(string g) {
	 Gender = g;
 }
 void RegToSystem::setBloodG(string B) {
	 Blood_G = B;
 }
 void RegToSystem::setContact(string cn) {
	 contactNum = cn;
 }
 void RegToSystem::setAddress(Address ad) {
	 add.houseNumber = ad.houseNumber; add.streetNumber = ad.streetNumber;
	 add.Block = ad.Block; add.city = add.Block; add.city = ad.city;
	 add.Province = ad.Province; add.Country = ad.Country;
 }
 //                 getters defibation
 string RegToSystem::getFname()const {
	 return Fname;
 }
 
 string RegToSystem::getLname()const {
	 return Lname;
 }
 string RegToSystem::getUsername()const {
	 return username;
 }
 string RegToSystem::getMail()const {
	 return Mail;
 }
 string RegToSystem::getPassword()const {
	 return password;
 }
 Date RegToSystem::getRegDate()const {
	 return reg_date;
 }
 string RegToSystem::getGender()const {
	 return Gender;
 }
 string RegToSystem::getBloodG()const {
	 return Blood_G;
 }
 string RegToSystem::getContact()const {
	 return contactNum;
 }
Address RegToSystem::getAddress()const {
	 return add;
 }

Sign_In::Sign_In() {
	u_name = "\0";
	password = "\0";
}
Sign_In::Sign_In(string un, string pas) {
	u_name = un;
	password = pas;
}

Sign_In::~Sign_In()
{
 //destructor
}

bool Sign_In::checkData(string fileName)
{
	ifstream user;
	ifstream pass;

	ofstream tempFile;

	string tempu_n;
	string temppas;
	//vriables to check data found or not
	bool username = false;
	bool password = false;

	user.open(fileName, ios::in);
	if (!user.is_open())
	{
		cout << "Error! File cannot be opened! " << endl;
	}
	else
	{
		while (!user.eof())
		{
			user >> tempu_n;
			if (tempu_n == u_name)
			{
				username = true;
				user.close();
			}
		}
		pass.open(fileName, ios::in);
		while (!pass.eof())
		{
			pass >> temppas;
			if (temppas == this->password)
			{
				password = true;
				pass.close();
			}
		}
		//check both found or not 
		if (username && password)
		{
			cout << "Sccessfully Loged In To System " << endl;
			//string data in file
			tempFile.open("readme.txt", ios::app);
			tempFile << "UserName: " << u_name << endl;
			tempFile << "Password: " << this->password << endl;
			return true;
		}
		else
		{
			cout << "UserName or password not found, Try again or Try Register to system  " << endl;
			return false;
		}
	}
}
//--------------------------------------------addProduct-------------------------------//
addProduct::addProduct() {
	sel_cat = 0;
	name = "\0";
	size = "\0";
	colour = "\0";
}
addProduct::~addProduct()
{
	//destructor
}
int addProduct::getCatagory() {
a:
	system("cls");
	cout << "=========|Catagories|========" << endl;
	cout << "        1.Sports" << endl;
	cout << "        2.Garments" << endl;
	cout << "        3.Eatables" << endl;
	cout << "        4.Medicines" << endl;
	cout << "        5.Fashion" << endl;
	
	cout << "Enter Your Choice between (1,2,3,4,5) : " ;
	int choice;
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
		goto a;
	}
	
	
	
	switch (choice)
	{
	case 1:
		sel_cat = choice;
		return sel_cat;
		break;
	case 2:
		sel_cat = choice;
		return sel_cat;
		break;
	case 3:
		sel_cat = choice;
		return sel_cat;
		break;
	case 4:
		sel_cat = choice;
		return sel_cat;
		break;
	case 5:
		sel_cat = choice;
		return sel_cat;
		break;
	default:
		cout << "Wrong Choice " << endl;
		goto a;
		break;
	}

}

istream& operator >> (istream& input, addProduct& obj) {
	//Buffer
	cin.ignore();
	stk:
	cout << "Enter the product Quantity: ";
	try
	{
		input >> obj.product_quantity;
		if (input.fail() || obj.product_quantity < 1)
			throw 1;
	}
	catch (int a) {
		input.clear();
		input.ignore();
		cout << "Wrong Stock Entered Enter Again ";
		goto stk;
	}
	input.ignore();
	cout << "Enter Name of product : ";
	getline(input, obj.name);

	cout << "Enter Description of product : ";
	getline(input, obj.description);

	cout << "Enter Product Size(small,mediam,large) : ";
	getline(input, obj.size);
	cout << "Enter Colour of product : ";
	getline(input, obj.colour);
	
	obj.WriteToFile();
	return input;
}
void addProduct::WriteToFile() 
{
	ofstream outFile;
	outFile.open("Products.txt",ios::app);
	outFile << setw(2) << setfill('0') << sel_cat << endl
		<< setw(4) << setfill('0') << product_quantity << endl
		<< name << endl
		<< colour << endl
		<< size << endl
		<< description << endl;
	outFile.close();

}

//---------------------Edit Product----------------------------//
editProduct::editProduct() {
	Search_key = 0;
	Search_name = "\0";
}
editProduct::~editProduct()
{
	//destructor
}
void editProduct::InputData()
{
	
	CATA:
	system("CLS");
	cout << "=========| Catagories |========" << endl;
	cout << "       Enter 01 Sports" << endl;
	cout << "       Enter 02 Garments" << endl;
	cout << "       Enter 03 Eatables" << endl;
	cout << "       Enter 04 Medicines" << endl;
	cout << "       Enter 05 Fashion" << endl;
	
	
	try
	{
		cout << "Enter What Catagory You want to edit : "; cin >> Search_key;
		if (cin.fail())
		{
			throw 1;
		}
		cout << "Enter Name of Product you want to Edit : "; 
		cin.ignore();
		getline(cin,Search_name);
	}
	catch (int a)
	{
		cout << "Wrong Input Enter again " << endl;
		cin.clear();
		cin.ignore();
		system("pause");
		goto CATA;
	}
}

int editProduct::getSearch_key()const {
	return Search_key;
}

string editProduct::getSearch_name()const {
	return Search_name;
}

void editProduct::EditData()
{
	string New_name, New_colour, New_size, New_des;
	int New_stock;
	ifstream inFile;
	ofstream outFile;
	int temp_id = 0;

	bool not_found = true;
	retry:
	outFile.open("Temp.txt");
	inFile.open("Products.txt");
	if (!inFile.is_open()) {
		cout << "Cannot opoen File" << endl;

	}
	else
	{
		string rem_str, tempName , tempSize , tempColour, tempDes;
		int tempstock;
		while (!inFile.eof())
		{
			inFile >> temp_id;
			inFile >> tempstock;
			inFile.ignore();
			getline(inFile,tempName);
			getline(inFile,tempColour);
			getline(inFile, tempSize);
			getline(inFile, tempDes);
			if (!inFile.eof())
			{

				if (temp_id == Search_key && Search_name == tempName)
				{
					int ch = 0;
					update:
					system("cls");
					cout << "               1 For New Stock " << endl << endl;
					cout << "               2 For New Name " << endl << endl;
					cout << "               3 For New Colour " << endl << endl;
					cout << "               4 For New Size " << endl << endl; 
					cout << "               5 For New Description" << endl << endl;
					cout << "               Enter Your Choice Which You want to Change : ";
					

					try
					{
						cin >> ch;
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
						goto update;
					}

					switch (ch)
					{
					
					case 1:
					stock:
						try {
							cout << "Enter New Stock:"; cin >> New_stock;
							if (cin.fail()||New_stock<1)
							{
								throw 1;
							}
						}
						catch (int a) 
						{
							cin.clear();
							cin.ignore();
							cout << "Wrong Stock Entered Enter Again" << endl;
							goto stock;
						}
						outFile << setw(2) << setfill('0') << Search_key << endl
							<< setw(4) << setfill('0') << New_stock << endl << tempName << endl
							<< tempColour << endl << tempSize << endl << tempDes << endl;

						break;
					case 2:
						cout << "Enter New Name:"; 
						cin.ignore();
						getline(cin,New_name);
						outFile << setw(2) << setfill('0') << Search_key << endl
							<< setw(4) << setfill('0') << tempstock << endl << New_name << endl
							<< tempColour << endl << tempSize << endl << tempDes << endl;
						break;
					case 3:
						cout << "Enter New Colour:"; 
						cin.ignore();
						getline(cin,New_colour);
						outFile << setw(2) << setfill('0') << Search_key << endl
							<< setw(4) << setfill('0') << tempstock << endl << tempName << endl
							<< New_colour << endl << tempSize << endl << tempDes << endl;
						break;
					case 4:
						cout << "Enter New Size:"; 
						cin.ignore();
						getline(cin, New_size);
						outFile << setw(2) << setfill('0') << Search_key << endl
							<< setw(4) << setfill('0') << tempstock << endl << tempName << endl
							<< tempColour << endl << New_size << endl << tempDes << endl;
						break;


					case 5:
						cout << "Enter New Description :"; cin.ignore(); getline(cin, New_des);
						outFile << setw(2) << setfill('0') << Search_key << endl
							<< setw(4) << setfill('0') << tempstock << endl << tempName << endl
							<< tempColour << endl << tempSize << endl << New_des << endl;
						break;
					default:

						cout<<"Invalid Choice ";
						break;
					}
					not_found = false;
					cout << "        Record Updated!" << endl;
					system("pause");					
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
			InputData();
			goto retry;
			system("pause");
		}

	}
	inFile.close();
	outFile.close();
	remove("Products.txt");
	rename("Temp.txt", "Products.txt");
	
}
//                        View Product                      //
ViewProduct::ViewProduct() {
	product_key = 0;
}
ViewProduct::~ViewProduct() {
	//destructor
}
void ViewProduct::showProducts()
{
	ifstream showFile;
	cata:
	system("CLS");
	cout << "=========|Catagories|========" << endl;
	cout << "       Enter 01 Sports" << endl;
	cout << "       Enter 02 Garments" << endl;
	cout << "       Enter 03 Eatables" << endl;
	cout << "       Enter 04 Medicines" << endl;
	cout << "       Enter 05 Fashion" << endl;
	cout << "Enter What Catagory You want to see : "; 
	
	try
	{
		cin >> product_key;
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
		goto cata;
	}

	showFile.open("Products.txt");
	int tempKey;
	string tempName , tempSize , tempColour, tempDes;
		int tempstock;
	if (!showFile.is_open())
	{
		cout << "cannot open products file " << endl;
	}
	else
	{
		while (!showFile.eof())
		{
			showFile >> tempKey;
			showFile >> tempstock;
			showFile.ignore();
			getline(showFile, tempName);
			getline(showFile, tempColour);
			getline(showFile, tempSize);
			getline(showFile, tempDes);
			if (!showFile.eof())
			{
				if (tempKey==product_key)
				{
					cout << "Key" << "  Stock" << "  Name" << " Colour" << " Size" << "  Description" << endl << endl;
					cout << setw(2) << setfill('0')<< tempKey << "  " << setw(4) << setfill('0')  << tempstock << "   " << tempName << " "
						 << " " << tempColour << " " << tempSize << " "  << tempDes << endl << endl;
				}

			}



		}
		system("pause");
	}

}
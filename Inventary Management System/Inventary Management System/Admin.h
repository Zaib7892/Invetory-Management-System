#include"SK.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;
class Edit_DATA 
{
protected:
	int tempId;
	string border;
	string temp_name;
	string temp_username;
	string temp_Mail;
	string temp_password;
	string temp_regdate;
	string temp_Gender;
	string temp_BloodG;
	string temp_contactNum;
	string temp_add;
public:
	Edit_DATA();
	void edit(string);
	void deleteData(string);
};

class Admin {
private:
	Sign_In log_In;
	RegToSystem Add_SK;
	RegToSystem Add_CS;
	addProduct Add_Product;
	editProduct edit;
	ViewProduct View;
	editProduct deleteP;
	Edit_DATA edit_SK;
	Edit_DATA edit_CS;
public:
	Admin();
	Admin(string u_n, string pass);
	bool logIn();
	void RegSK();
	void RegCS();
	void ADD_Product();
	void edit_product();
	void editSK();
	void editCS();
	void View_product();
	void deleteProduct();
	void deleteShopkeeper();
	void deleteCustomer();

};


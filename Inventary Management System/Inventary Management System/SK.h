#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;
//structure for address
struct Address {
	int houseNumber;
	int streetNumber;
	string Block;
	string city;
	string Province;
	string Country;
};
//structure for date
struct Date
{
	int D;
	int M;
	int Y;
};

class ShopKeeper {
public:
	ShopKeeper();
};
//class toregister to sysytem
class RegToSystem : public ShopKeeper {
	
private:
	string Fname;
	string Lname;
	static int SK_id;
	string username;
	string Mail;
	string password;
	Date reg_date;
	string Gender;
	string Blood_G;
	string contactNum;
	Address add;
protected:
	int cnt;
public:
	// constructor of RegToSystem 
	RegToSystem();
	//destructor of RegToSystem 
	~RegToSystem();
	
	// generating id
	void generate_Id(string,string);
	//                       Setters                         //
	void setFname(string fn);
	void setLname(string ln);
	void setUsername(string un);
	void setMail(string mail);
	void setPassword(string pass);
	void setRegDate(Date d);
	void setGender(string g);
	void setBloodG(string B);
	void setContact(string cn);
	void setAddress(Address ad);
	//                Getters                      //
	string getFname()const;
	string getLname() const;
	string getUsername() const;
	string getMail() const;
	string getPassword()const;
	Date getRegDate() const;
	string getGender() const;
	string getBloodG()const;
	string getContact() const;
	Address getAddress() const;
	void write_to_file(string,string);
	//for input 
	friend istream& operator >> (istream& input,RegToSystem &obj);
	
};

class Sign_In {
private:
	string u_name;
	string password;
public:
	Sign_In();
	Sign_In(string, string);
	~Sign_In();

	bool checkData(string);
};

class addProduct
{
public:
	addProduct();
	~addProduct();
	int getCatagory();
	friend istream& operator >> (istream& input, addProduct& obj);
	void WriteToFile();
protected:
	int sel_cat;
	int product_quantity;
	string name;
	string description;
	string size;
	string colour;
	static int P_Id;

};
class editProduct {
protected:
	int Search_key;
	string Search_name;
public:
	editProduct();
	~editProduct();
	void InputData();
	void EditData();
	//getters
	int getSearch_key() const;
	string getSearch_name() const;

};

class ViewProduct
{
protected:
	int product_key;
public:
	ViewProduct();
	~ViewProduct();
	void showProducts();
};
#include<iostream>
#include<string>
#include<fstream>
#include"SK.h"
using namespace std;

class customer
{ protected:
	RegToSystem reg_customer;
	Sign_In c_sign;
public:
	customer();
	customer(string u_n, string pas);
	void customer_Reg();
	bool customer_Sign();
};

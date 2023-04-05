#include"customer.h"
customer::customer()
{

}
customer::customer(string u_n,string pas):c_sign(u_n,pas) {}
void customer::customer_Reg() 
{
	cin >> reg_customer;
	reg_customer.write_to_file("Customer.txt", "CScount.txt");
}
bool customer::customer_Sign()
{
	bool sign_status = c_sign.checkData("Customer.txt");
	return sign_status;
}
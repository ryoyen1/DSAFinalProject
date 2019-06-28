#ifndef CONTACTS_H
#define CONTACTS_H
#include <string>
#include <iostream>
#include <fstream>




using namespace std;

class Contacts
{
	private:

		string Fname;
		string Lname;
		string address;
		string phonenumber;
		
	public:
		Contacts(){
            this->Fname = "";
            this->Lname = "";
            this->address = "";
            this->phonenumber = "";
		}
		
		Contacts(string Fname, string Lname, string address, string phonenumber){
			this->Fname = Fname;
			this->Lname = Lname;
			this->address = address;
			this->phonenumber = phonenumber;
		}
		
	//Getter setter
	void setFname(string Fname){
		this->Fname = Fname;
	}	
	string getFname(){
		return Fname;
	}
	
	
	void setLname(string Lname){
		this->Lname = Lname;
	}
	string getLname(){
		return Lname;
	}
	
	
	void setAddress(string address){
		this->address = address;
	}
	string getAddress(){
		return address;
	}
	
	
	void setPhonenumber(string phonenumber){
		this->phonenumber = phonenumber;
	}
	string getPhonenumber(){
		return phonenumber;
	}











};

#endif

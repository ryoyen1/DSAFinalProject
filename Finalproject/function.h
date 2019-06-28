#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <iomanip>
#include <iostream>
#include "Contacts.h"

using namespace std;
//Table function (row)
template <typename T> void printElement(T t, const int& width){
	const char separator = ' ';
	cout << left << setw(width) << setfill(separator) << t;
}

//Table function (row)
void printdetails(Contacts contact, int index){
	const int a = 4;
	const int firstnamewidth = 20;
	const int lastnamewidth = 20;
	const int addresswidth = 60;
	const int phonenumberwidth = 20;
	
	printElement(index+1, a);
	printElement(contact.getFname(), firstnamewidth);
	printElement(contact.getLname(), lastnamewidth);
	printElement(contact.getAddress(), addresswidth);
	printElement(contact.getPhonenumber(),phonenumberwidth);
	cout << "\n";
}

void printheaderdetails(){
	const int a = 4;
	const int firstnamewidth = 20;
	const int lastnamewidth = 20;
	const int addresswidth = 60;
	const int phonenumberwidth = 12;

	printElement("No. ",a);
	printElement("First name: ",firstnamewidth);
	printElement("Last name: ",lastnamewidth);
	printElement("Address: ",addresswidth);
	printElement("Phone number: ",phonenumberwidth);
	cout << "\n\n";
}

#endif

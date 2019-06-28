#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Contacts.h"
#include "function.h"
#include <time.h>
#include <fstream>

using namespace std;

class Menu{
	public:
        string Fname, Lname, address,phonenumber;
        Contacts contact;
        vector<Contacts *> matching;
        vector<Contacts> Cbook;
        void menuUI();
        bool del(string key);
        void writefile();
        void readfile();
};
void Menu::writefile(){
    ofstream contactfile;
    string fn,ln,a,p;

    contactfile.open("contactlist.txt");
    for (int i = 0; i < Cbook.size();i++){
        Fname = Cbook[i].getFname();
        Lname = Cbook[i].getLname();
        phonenumber = Cbook[i].getPhonenumber();
        address = Cbook[i].getAddress();
        contactfile << Fname << "  " << Lname << "  " << address << "  " << phonenumber << endl;
    }
}

void Menu::readfile(){
    ifstream inFile("contactlist.txt");		// Read the contact book file
        if(inFile.fail()) 			// Checking whether the file is error
        {
            cerr<<"Error opening file"<<endl;
            exit(1);
        }

        if(inFile.is_open())
        {
            while(inFile >> Fname  >> Lname >> address >> phonenumber )		// Reading every line and every new variable and set it as name, phone, address, email
            {
                Contacts con(Fname,Lname,address,phonenumber);
                Cbook.push_back(con);
            }
            inFile.close();
        }
        else
        {
            cout<< "File is not opened" <<endl;
        }
    }



bool Menu::del(string key){
    for (vector<Contacts>::iterator strItr = this->Cbook.begin(); strItr != this->Cbook.end(); ++strItr){
        if (strItr->getFname() == key) {
            this->Cbook.erase(strItr);
            return true;
        }
    }
    return false;
}

void Menu::menuUI() {
    system("cls");
    time_t login = time(0);
    char *strDt = ctime(&login);
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//      //////////  //////////// ////        /// /////////// ////////// ////////// ///////////    //" << endl;
    cout << "//      ///         ///      /// /// ///     ///     ///     ///    /// ///            ///        //" << endl;
    cout << "//      ///         ///      /// ///   ///   ///     ///     ////////// ///            ///        //" << endl;
    cout << "//      ///         ///      /// ///     /// ///     ///     ///    /// ///            ///        //" << endl;
    cout << "//      //////////  //////////// ///        ////     ///     ///    /// //////////     ///        //" << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Welcome to the Contact Book. Current time : " << strDt;
    while (true) {
        int choice;
        cout << "What do you want do?\n [1]. Add to the ContactBook\n [2]. Search the Contactbook\n [3]. View all\n [4]. Edit\n [5]. Delete\n [6]. Save\n [7]. Read\n [8]. Exit";
        cin >> choice;
        cout << endl;
        while(!cin){
            cout << "Please input the available options" << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }

        switch (choice) {
            case (1): {
                cout << "Enter First Name: ";
                cin.get();
                getline(cin, Fname);
                cout << "Enter Last Name: ";
                getline(cin, Lname);
                cout << "Enter an Address: ";
                getline(cin, address);
                cout << "Enter a Phone number: ";
                cin >> phonenumber;
                while (!cin) {
                    cout << "Please input a number" << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> phonenumber;
                }
                cin.get();

                if (&Cbook[0] == NULL) {
                    Contacts contact(Fname, Lname, address, phonenumber);
                    Cbook.push_back(contact);
                } else {
                    bool check = false;
                    for (int i = 0; i < Cbook.size(); i++) {
                        if (Cbook[i].getFname() == Fname) {
                            cout
                                    << "The Contact you want to add is already listed in the book. You can edit it in the Edit menu."
                                    << endl;
                            check = true;
                        }
                    }

                    if (check == false) {
                        Contacts contact(Fname, Lname, address, phonenumber);
                        Cbook.push_back(contact);
                    }
                }
                cout << "You have added " << Fname << " to the Contact List" << endl;
                break;
            }
            case (2): {
                if (&Cbook[0] == NULL) {
                    cout << "No contacts available to show.\n";
                } else {
                    int search;
                    cout << "Search based on: \n [1]. First name\n [2]. Last name";
                    cin >> search;
                    vector<Contacts *> matching;

                    if (search == 1) {    //First name
                        string findname;
                        cout << "Enter the First name you want to search: ";
                        cin.get();
                        getline(cin, findname);
                        transform(findname.begin(), findname.end(), findname.begin(), ::tolower);
                        for (int i = 0; i < Cbook.size(); i++) {
                            string comparison = Cbook[i].getFname();
                            transform(comparison.begin(), comparison.end(), comparison.begin(), ::tolower);
                            size_t found = comparison.find(findname);
                            if (found != string::npos) {
                                matching.push_back(&Cbook[i]);
                            }
                        }
                    }
                    if (search == 2) {
                        string findname;
                        cout << "Enter the Last name you want to search: ";
                        cin.get();
                        getline(cin, findname);
                        transform(findname.begin(), findname.end(), findname.begin(), ::tolower);
                        for (int i = 0; i < Cbook.size(); i++) {
                            string comparison = Cbook[i].getLname();
                            transform(comparison.begin(), comparison.end(), comparison.begin(), ::tolower);
                            size_t found = comparison.find(findname);
                            if (found != string::npos) {
                                matching.push_back(&Cbook[i]);
                            }
                        }
                    }
                    if (&matching[0] == NULL) {
                        cout << "No results found. Please try again.\n";
                    } else {
                        printheaderdetails();
                        for (int i = 0; i < matching.size(); i++) {
                            printdetails(*matching[i], i);
                        }
//
                    }
                }

            }
                break;
            case (3): {
                if (&Cbook[0] == NULL) {
                    cout << "No contacts available to show.\n";
                } else {
                    printheaderdetails();
                    for (int i = 0; i < Cbook.size(); i++) {
                        printdetails(Cbook[i], i);
                    }
                    cout << endl;
                }
                break;
            }
            case (4): {
                if (&Cbook[0] == NULL) {
                    cout << "No contacts available.\n";
                } else {
                    int search;
                    cout << "Search for a contact to edit by\n[1]. First name\n[2]. Last name\n";;
                    cin >> search;
                    vector<Contacts *> matching;

                    if (search == 1) {    //First name
                        string findname;
                        cout << "Enter the First name you want to search: ";
                        cin.get();
                        getline(cin, findname);
                        transform(findname.begin(), findname.end(), findname.begin(), ::tolower);
                        for (int i = 0; i < Cbook.size(); i++) {
                            string comparison = Cbook[i].getFname();
                            transform(comparison.begin(), comparison.end(), comparison.begin(), ::tolower);
                            size_t found = comparison.find(findname);
                            if (found != string::npos) {
                                matching.push_back(&Cbook[i]);
                            }
                        }
                    }
                    if (search == 2) {
                        string findname;
                        cout << "Enter the Last name you want to search: ";
                        cin.get();
                        getline(cin, findname);
                        transform(findname.begin(), findname.end(), findname.begin(), ::tolower);
                        for (int i = 0; i < Cbook.size(); i++) {
                            string comparison = Cbook[i].getLname();
                            transform(comparison.begin(), comparison.end(), comparison.begin(), ::tolower);
                            size_t found = comparison.find(findname);
                            if (found != string::npos) {
                                matching.push_back(&Cbook[i]);
                            }
                        }
                    }
                    if (&matching[0] == NULL) {
                        cout << "No results found. Please try again.\n";
                    } else {
                        printheaderdetails();
                        for (int i = 0; i < matching.size(); i++) {
                            printdetails(*matching[i], i);
                        }
                        cout << "Pick by number:\n";
                        int op;
                        cin >> op;
                        cout << "You have selected " << matching[op - 1]->getFname() << " "
                             << matching[op - 1]->getLname()
                             << ". \nWhat do you want to edit?\n[1] First name\n[2] Last name\n[3] Address\n[4] Phone number\n";
                        int choose;
                        cin >> choose;
                        if (choose == 1) {
                            string input;
                            cout << "Enter new First name: ";
                            cin >> input;
                            Cbook[op-1].setFname(input);
                            cout << "Update succesful" << endl;
                        }
                        if (choose == 2){
                            string input2;
                            cout << "Enter new Last name: ";
                            cin >> input2;
                            Cbook[op-1].setLname(input2);
                            cout << "Update succesful" << endl;
                        }
                        if (choose == 3){
                            string input3;
                            cout << "Enter new address: ";
                            cin >> input3;
                            Cbook[op-1].setAddress(input3);
                            cout << "Update succesful" << endl;
                        }
                        if (choose == 4){
                            string input4;
                            cout << "Enter new Phone number: ";
                            cin >> input4;
                            while (!cin) {
                                cout << "Please enter a number: ";
                                cin.clear();
                                cin.ignore();
                                cin >> input4;
                            }
                            Cbook[op-1].setPhonenumber(input4);
                            cout << "Update succesful" << endl;
                        }
                        cout << endl;

                }

                    }
                }break;
                case(5): {
                    if (&Cbook[0] == NULL) {
                        cout << "No contacts available to show.\n";
                    }else {
                        printheaderdetails();
                        for (int i = 0; i < Cbook.size(); i++) {
                            printdetails(Cbook[i], i);
                        }
                            string delinput;
                            cout << endl;
                            cout << "Which contact do you want to delete?\n";
                            cout << "Type in the Name of the contact to delete it:\n";
                            cin >> delinput;
                            cout << "Are you sure?[1] Yes | [2] No |\n";
                            int choicedelete;
                            cin >> choicedelete;
                            if (choicedelete == 1) {
                                del(delinput);
                            }
                            if (choicedelete == 2){
                                break;
                            }

                    }

                }
                case(6):{
                    writefile();
                    break;
                }
                case(7):{
                    readfile();
                    break;
                }
                case(8):{
                    exit(0);
                }

            }
        }
    }




#endif

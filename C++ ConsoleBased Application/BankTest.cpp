#include <iostream>
#include <iomanip>
#include "Bank.h"
using namespace std;

//Home page with options
void HomePage(){
	//setw spaceing right
	cout << setw(70) <<"Welcome to my Console Bank Application" << endl;
	cout << "Plese select your path: " << endl;
	cout << "1) Open Account" << endl;
	cout << "2) Close Account" << endl;
	cout << "3) List All Account" << endl;
	cout << "4) Withdraw Money" << endl;
	cout << "5) Deposit Money" << endl;
	cout << "6) Exit" << endl;
}

int main(){
	Account account[10];	//Size of array of account object
	int choice;				
	int i{1};
	int found{0};
	int accNo;	
	
	do{
		HomePage();
		cout << "\n\nEnter Choice: ";		//Prompt User
		cin >> choice;			//Obtain User input
		switch(choice){
			
			case 1:
				system("cls");		//Clear Screen
				account[i].openAccount(i);		
				i++;
				break;
				
				
			case 2:
				system("cls");
				cout << "\nEnter your Account Number: ";
            	cin >> accNo;
            	for (i = 1; i <= 9; i++) {
                	found = account[i].Search(accNo);		//Validate if account exist
                	if (found) {
                    	for(int i=accNo; i< 9; ++i){
							account[i] = account[i+1];
							cout << "\nYou have successfully deleted your account\n";
							break;
						}
                    	break;
                	}
            	}
            	if (!found)
                	cout << "Account Not Found" << endl;
            	break;
            	
            	
			case 3:
				system("cls");
				for (i = 1; i <= 9; i++) {
					if(account[i].getAccNumber() != 0)
						account[i].listAllAccount();		
            	}
            	break;
            	
            	
			case 4:
				system("cls");
				cout << "\nEnter your Account Number to Withdraw Money: ";		//Prompt
            	cin >> accNo;				//Obtain User Input
            	for (i = 1; i <= 9; i++) {
                	found = account[i].Search(accNo);
                	if (found) {
                    	account[i].withdrawal();			
                    	break;
                	}
            	}
            	if (!found)
                	cout << "Account Not Found" << endl;
            	break;
            	
            	
			case 5:
				system("cls");
				cout << "\nEnter your Account Number to Deposit Money: ";
            	cin >> accNo;
            	for (i = 1; i <= 9; i++) {
                	found = account[i].Search(accNo);
                	if (found) {
                    	account[i].deposit();
                    	break;
                	}
            	}
            	if (!found)
                	cout << "Account Not Found" << endl;
            	break;
            	
            	
			case 6:	
				system("cls");
				cout << "\nThank You For Banking With Us";
				break;
				
				
		}
	}
	while(choice != 6);	
}

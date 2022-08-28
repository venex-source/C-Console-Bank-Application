//Account class to open an account 
#include <string>

class Account{
	public:
		//Setters
		void setfirstName(){
			//Validate that the user name is greater than 0 characters
			std::string fname;		
			std::cout << "Enter Your First Name: ";
			std::cin >> fname;
			if(fname.length() > 0)
				firstName = fname;
		}
		
		void setlastName(){
			//Validate that the user name is greater than 0 characters
			std::string lname;
			std::cout << "Enter Your Last Name: ";
			std::cin >> lname;
			if(lname.length() > 0)
				lastName = lname;
		}
		
		void setBalance(){
			//Validate that the initial balance is greater than 0; if not
			//data member balance keeps it's default initial value of 0 
			unsigned int initBalance;
			std::cout << "Enter Initial Balance: ";
			std::cin >> initBalance;
			if(initBalance > 0){			//if initial value is valid
				balance = initBalance;		//assign it to balance
			}
		}
		
		void setAccNumber(int i){
			accNumber = i;		//assign account number
		}
		
		//Getters
		std::string getfirstName() const{
			return firstName;
		}
		
		std::string getlastName() const{
			return lastName;
		}
		
		int getBalance() const{
			return balance; 
		}
		
		int getAccNumber() const{
			return accNumber; 
		}
		
		//Function to open account
		void openAccount(int i){
			//set user datails
			setfirstName();		
			setlastName();
			setAccNumber(i);
			setBalance();
		
			AccountDetail();
		}
		
		//Function to display user data
		void listAllAccount(){
			std::cout << "\nName: " << getfirstName() << " "<< getlastName();
			std::cout << "\nAccount Number: " << getAccNumber();
			std::cout << "\nInitial Balance: $" << getBalance() << std::endl;
		}
		
		//Function to display data after user has created account
		void AccountDetail(){
			std::cout << "\nCongratulations your account has been created \n";
			listAllAccount();	 
		}
		
		//Function to deposit money
		void deposit(){
			int amount;
			std::cout << "\nEnter amount to deposit: ";
			std::cin >> amount;
			if(amount > 0){
				balance += amount;
				std::cout << "You just deposited $" << amount << " to your balance\n";
			}
			else
				std::cout << "Deposit amount is too small \n";
		}
		
		//Function to withdraw money
		void withdrawal(){
			int amount;
			std::cout << "\nEnter amount to withdraw: ";
			std::cin >> amount;
			if(balance >= amount && amount != 0){
				balance -= amount;
				std::cout << "You just withdrew $" << amount << " from your balance\n";
			}
			else
				std::cout << "Withdrawal amount exceeds account balance \n";
		}
		
		//Fuction to check if account exist
		int Search(int accoNum){
			if(accNumber == accoNum && accoNum != 0){
				return (1); 
			}
			else{
				return (0);
			}
		}
		
	private:
		std::string firstName;		
		std::string lastName;
		unsigned int accNumber{0};		//data member with default initial value
		unsigned int balance{0};		//account balance data member 
		
};

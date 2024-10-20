#include<iostream>
#include<string>

using namespace std;

class BankAccount //bank account class definition
{
    private:
       static int total_no_of_accounts;//keep track of total no of accounts.
       
       int accountNumber; //data members.
       string accountHolder;
       double balance;

public:
	//Parametrized Constructor assigning values.  and account number would be given in sequence starting from 1. 
    BankAccount(string accountHolder = "N/A", double balance = 0.0) : accountHolder(accountHolder), balance(balance), accountNumber(++total_no_of_accounts)
	{
	                       this->accountHolder = accountHolder;// use this because arguments are of same name as data members.
	                       this->balance = balance;// use this because arguments are of same name as data members.
	}
	
	friend class BankManager;

    void deposit_amount(double dm)//add deposit amount in current balance . 'dm' stands for deposit amount.
	{
        balance += dm;
    }

    void withdraw_amount(double wm) //subtract withdrawl amount from current balance. 'wm' stands for withdrawl amount.
	{
        if (balance >= wm) // condition check either withdrawl amount is less then current balance.
		{
            balance -= wm;
            
            cout<<"Withdrawal is Successful."<<endl;
        } 
		else// if condition fails.
		{
            cout<<"Insufficient Amount for withdrawl!"<<endl;
        }
    }

    double Get_Balance() const // getter function will return balance.
	{
        return balance;
    }

    int Get_Account_number() const // getter function will return account number.
	{
        return accountNumber;
    }

    static int Get_total_no_of_accounts()// staic function will return total number of contacts.
	{
        return total_no_of_accounts;
    }

    string Get_Account_Holder() const // getter function will return account holder name.
	{
        return accountHolder;
    }

    void transferFunds(BankAccount& Account, double am)//function will an object of bank account class, and also amount to transfer.
	{
        withdraw_amount(am);//check if tranfer amount can be withdraw or not.
        
        
        if (balance >=am ) // check if the balance is sufficient after withdrawal.
		{
            Account.deposit_amount(am);// If withdrawal was successful, deposit the amount into the receipient account.
            cout<<"Transfer Successful"<<endl;
        } 
		else // If withdrawal failed due to insufficient balance.
		{
            cout<<"Transfer failed due to Insufficient balance."<<endl;
        }
    }

};

int BankAccount::total_no_of_accounts = 0;

class BankManager //definition of bank manager class.
{
private:
    BankAccount* B1[100]; // Array of pointers to BankAccount objects and limit of total account creation is 100.
    int count; // Keep track of the number of accounts

public:
    BankManager():count(0){}// default value of count is set to 0.
    
    // function definition will take argument as account holder name and initial balnce otherwise it set to default values.
    void Create_Account(string holder_name = "N/A", double initial_balance = 0.0) 
	{
        if (count < 100)// condition check if accounts are less then the limit of 100
		{
			//then dynamically allocating bank account object and calling parametrized constructor.
            B1[count++] = new BankAccount(holder_name, initial_balance);
            
            cout<<"Account is Created Successfully."<<endl;
        } 
		else //if condition fails so means that total limit of account creation is reached.
		{
            cout<<"Can't create more Accounts as Limit is reached!"<<endl;
        }
    }

    void Delete_Account(int an)// definition of function delete will take as argument the account number and then delete account. 
	{
        for (int i = 0; i<count; i++)//loop will iterate through no of contacts made till now.
		{
			//check if account number enter by user match with account number stored. 
            if (B1[i]->Get_Account_number()==an) 
			{
                delete B1[i];//if condition is true then delete the specafic account object. 
                
                for (int j=i; j<count-1; j++)//this loop will move the array and fill the gap made by delete account object.
				{
                    B1[j] = B1[j + 1];
                }
                    count--;//decrease the value of count.
                    
                    cout<<"Account Deleted ."<<endl;
            }   
            else
			{
				cout<<"Account Number not found!" << endl;
			}
        } 
    }

    BankAccount* Find_Account(int an) //find a bank account by account number and return a pointer to it.
	{
        for (int i = 0; i<count;i++) 
		{
			//check if account number enter by user match with account number stored
            if (B1[i]->Get_Account_number() == an) 
			{
                return B1[i]; // if condition is true then return the current bank account object
            }
            
        }
        return NULL;// either return null pointer to it.
    }

    void Display_all_Accounts() const // function will display the details of accounts.
	{
        if (count == 0) //condition check if count is still 0 means no account created.
		{
            cout<<"No Accounts Found!"<<endl;
        }
        else//condition falls as there account exist.
        {
        	
        for(int i = 0; i<count; i++)//loop will display details. 
		{
            cout<<"Account "<<i + 1<<" details:"<<endl;
            cout<<"Account Number: "<<B1[i]->Get_Account_number()<<endl;
            cout << "Account Holder: "<<B1[i]->Get_Account_Holder()<<endl;
            cout << "Balance: "<<B1[i]->Get_Balance()<<endl;
            cout<<endl;
        }
       }
    }
       ~BankManager()
       {
       	   for (int i = 0; i < count; i++) {
                  delete B1[i]; //deallocate memory for separate BankAccount objects
             }
	   }
};

int main() 
{	
    BankManager BM1;// object of BankManger class.
    
    int account_Number;
    string Name;
    double Amount;
    
    int choice;

    do // loop for menu driven program
	{
        cout<<"\n***Weclcome to Bank Management System***"<<endl;
        cout<<"\tPress[1]. Create Account"<<endl;
        cout<<"\tPress[2]. Deposit Amount"<<endl;
        cout<<"\tPress[3]. Withdraw Amount"<<endl;
        cout<<"\tPress[4]. Transfer Funds"<<endl;
        cout<<"\tPress[5]. Find Account"<<endl;
        cout<<"\tPress[6]. Delete Account"<<endl;
        cout<<"\tPress[7]. Display All Accounts"<<endl;
        cout<<"\tPress[0]. Exit"<<endl;
        cout<<"\n";
        
        cout<<"Enter your choice: ";//prompt user to enter choice from above menu.
        cin>>choice;

        switch(choice) 
		
		{
			
        case 1: // this case wll execute for Creation of an Account.
	                          
	            //prompt user to enter their name.              
                cout<<"Enter account holder name: ";
                cin>>Name;
                
                //prompt user to enter their balance.   
                cout<<"Enter Initial Balance: ";
                cin>>Amount;
                
                BM1.Create_Account(Name,Amount);//pass value as arguments to create account function.
                break;
                
        case 2: // this case wll execute for Deposit of Amount.
		    {
		    	//prompt user to enter their account number.   
                cout<<"Enter account number: ";
                cin>>account_Number;
                
                //prompt user to enter their amount that is deposited.
                cout<<"Enter amount to deposit: ";
                cin>>Amount;
                
                //pass value as argument to find account function so that first check the account with the specific account number exists.
                BankAccount* BA = BM1.Find_Account(account_Number);
                
                if (BA != NULL)// condition check that if account is found.
				{
                    BA->deposit_amount(Amount);//call to deposit amount function.
                    
                    cout<<"Deposit successful!"<<endl;
                    
                } 
				else //if conditon fails.
				{
                    cout<<"Account not found."<<endl;
                }
                break;
             }        
            
             
        case 3: // this case wll execute for Deposit of Amount.
              {	
                //prompt user to enter their account number.
                cout<<"Enter account number: ";
                cin>>account_Number;
                
                //prompt user to enter their amount that is withdrawl.
                cout<<"Enter amount to withdraw: ";
                cin>>Amount;
                
                //pass value as argument to find account function so that first check the account with the specific account number exists.
                BankAccount* BA = BM1.Find_Account(account_Number);
                
                if (BA != NULL) // condition check that if account is found.
				{
                    BA->withdraw_amount(Amount);//call to withdrawl amount function.
                } 
				else 
				{
                    cout<<"Account not found."<<endl;
                }
                break;
            }
			
		case 4: // this case wll execute for Balance transfer between Accounts.
		{
			  
               int source_account_number, destination_account_number;
               
               double transfer_amount;
    
                cout<<"Enter Sender Account Number: ";//prompt user to enter sender person account number.
                cin>>source_account_number;
    
                cout<<"Enter Recipient Account Number: ";//prompt user to enter receipiet person account number.
                cin>>destination_account_number;
    
                cout<<"Enter Amount to transfer: ";//prompt user to enter amount to transfer.
                cin>>transfer_amount;
               
                //pass value as argument to find account function so that first check the sender account with the specific account number exists.
                BankAccount* source_account = BM1.Find_Account(source_account_number);
                
                //pass value as argument to find account function so that first check the receipiet account with the specific account number exists.
                BankAccount* destination_account = BM1.Find_Account(destination_account_number);
    
                if (source_account != NULL and destination_account != NULL) // condition check that if source amd receipiet account is found.
			   {
                   source_account->transferFunds(*destination_account, transfer_amount);//call tranfer fund through source account numer and pass receipiet account number and transfer amount as argument.
               } 
			    else 
		     	{
                   cout<<"Neither Sender nor Recipient account number found!"<<endl;
                }
                     break;
               }
               
		case 5: // this case wll execute for finding an Accounts.
		      {
		      	//prompt user to enter account number to find.
                cout<<"Enter account number to find: ";
                cin>>account_Number;
                
                //pass value as argument to find account function so that first check check the account with the specific account number exists..
                BankAccount* BA = BM1.Find_Account(account_Number);
                
                if (BA!= NULL) // condition check that if account is found then call the getter functions to display details.
				{
                    cout<<"Account found."<<endl;
                    cout<<"Account Holder: "<<BA->Get_Account_Holder()<<endl;
                    cout<<"Balance: "<<BA->Get_Balance()<<endl;
                } 
				else //condition fails.
				{
                    cout<<"Account Not found!"<<endl;
                }
                break;
            }
            
		case 6: // this case wll execute for deleting an Accounts.
		       
		        	//prompt user to enter account number to delete.
                cout<<"Enter account number to delete: ";
                cin>>account_Number;
                
                BM1.Delete_Account(account_Number);//calling delete account function.
                
                break;   		   	    
            
        case 7: // this case wll execute for displating an Accounts.
        {
        	BM1.Display_all_Accounts();//calling display account function
            break;
		}        
                
        case 0: //in order to exit the program
		   
                cout << "Exiting Bank Management System" << endl;
                cout << "Thank you for using BMS..." << endl;
                break;
            
            
        default://if user enter invalid inputs.
                cout << "Invalid Input choice. Please enter(0-7)" << endl;
        }
    } 
	while (choice != 0);//until user enter 0.

    return 0;
}

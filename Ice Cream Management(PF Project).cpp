#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
int count=0,count1=0,count2=0;
using namespace std;

struct admin 
{
	string password = "superior";
};
admin Password(admin a , string pasword)
{
    if (a.password == pasword)
    {
    	system("cls");
        cout << "\n\n\tLogin successfully" << endl;
    }
    else
    {
        cout << "\n\n\tInvalid password" << endl;
        cout <<"\tPlease Try Again\n";
        cin >> pasword;
        return Password(a , pasword);
    }	
}	
struct IceCream
{
	string Customer_name;
	string id;
	string ph_no;
	string icecream_name;
	string gender;
	string age;
};

void saveInFile(IceCream s[], int n)
{
    ofstream out;
    out.open("icecreamshop.txt", ios::out | ios::app);
    if (out.fail()) 
	{
        cout << "\nError Opening File." << endl;
        return;
    }

    for (int i = count2; i < n+count2; i++) 
	{
        out << s[i].id << endl;
        out << s[i].Customer_name << endl;
        out << s[i].ph_no << endl;
        out << s[i].gender << endl;
        out << s[i].age << endl;
    }
    count2 = count2+n;
    out.close();
}
int displayStudent(IceCream s[], string n)
{
			int i=0;
			ifstream display;
			display.open("icecreamshop.txt", ios::app | ios::in);
			if(display.fail())
			{
				cout <<"\nError Opening File\n";
				return 0;
			}
			while (!display.eof())
			{
				display >> s[i].id;
				display.ignore();
			   	getline(display, s[i].Customer_name);
			   	getline(display, s[i].ph_no);
			   	display >> s[i].gender;
			   	display >> s[i].age;
   				if ((s[i].id == n))
			    {
			    	 cout <<"\nRequired Student ID Displayed Successfully\n\n";
			    	 cout <<"Customer ID: " << s[i].id << endl;
		      		 cout <<"Customer Name " << s[i].Customer_name << endl;
		      		 cout <<"Phone Number: " << s[i].ph_no << endl;
		      		 cout <<"Gender: " << s[i].gender << endl;
		      		 cout <<"Age: " << s[i].age << endl;
		      		 return 1;
		    	}
		    		i++;
			}
		display.close();
		if (i == 0)
		{
			cout <<"\nSorry! Customer Data Not Displayed\n";
		}
}


bool isAlphabet(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}
bool isValidName(string& ch)
{
	
	for(int i=0; ch[i]!=0; i++)
	{
		char c = ch[i];
		if(!isAlphabet(c) && c != ' ')
		{
			return false;
		}		
	}
	return true;
}

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}
bool isValidDigit(string& ch)
{
	for(int i=0; ch[i]!= 0; i++)
	{
		char c = ch[i];
		if(!isDigit(c))
		{
			return false;
		}
	}
	return true;
}

bool is_Digit(char c)
{
	return (c >= '0' && c <= '9' || c == '+' || c == '-' || c == ' ');
}
bool isValidPhoneNumber(string& ch)
{
	for (int i=0; ch[i] != 0; i++)
	{
		char c = ch[i];
		if(!is_Digit(c)  && c != '+' && c != '-' && c != ' ')
		{
			return false;
		}
	}
	return true;
}
IceCream  inputDetails(IceCream s[],int n)
{
	for (int i=count; i <n+count; i++)
	{
		cout <<i+1 <<" . Customer Details : "<< endl; 
		
		bool valid_name = false;
        do
		{
            cout << "Enter the Customer Name: ";
            cin.ignore();
            getline(cin, s[i].Customer_name);
            valid_name = isValidName(s[i].Customer_name);
            if (!valid_name) 
			{
                cout << "\n\tInvalid input! \n\tName should contain only alphabets. \n\tPlease try again." << endl <<endl;
      		}
        } while (!valid_name);
        
        bool valid_id = false;
        do 
		{
        	cout <<"Enter the Customer ID: ";
			cin >> s[i].id;
			valid_id = isValidDigit(s[i].id);
			if(!valid_id)
			{
				cout << "\n\tInvalid input! \n\tID should contain only digits. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_id);
		
		bool valid_ph = false;
		do
		{
        	cout <<"Enter the customer Phone Number: ";
			cin.ignore();
			getline(cin,s[i].ph_no);
			valid_ph = isValidPhoneNumber(s[i].ph_no);
			if(!valid_ph)
			{
				cout << "\n\tInvalid input! \n\tPhone Number should contain only digits, + and -. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_ph);
		
		bool validGender = false;
		do 
		{
			cout <<"Enter the Customer gender: ";
			cin >> s[i].gender;
			validGender = isValidName(s[i].gender);
			if(!validGender)
			{
				cout << "\n\tInvalid input! \n\tGender should contain only alphabets. \n\tPlease try again." << endl << endl;
			}
		}while(!validGender);
		
		bool validAge = false;
		do
		{
			cout <<"Enter the Customer Age: ";
			cin >> s[i].age;
			validAge = isValidDigit(s[i].age);
			if(!validAge)
			{
				cout << "\n\tInvalid input!\n\\t Age should contain only digits.\n\t Please try again." << endl <<endl;
			}
		}while(!validAge);
		
    }
    
    count =count + n;
    return s[n];
	
}	

int idSearch(IceCream s[], string n)
{
		int i=0;
		 system("cls");
		 ifstream search;
		  search.open("icecreamshop.txt", ios::app |ios::in );
	
		 if (search.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
		   	 
    while (!search.eof())
		  {
		    search >> s[i].id;
			search.ignore();
		   	getline(search, s[i].Customer_name);
		   	getline(search, s[i].ph_no);
		   	search >> s[i].age;
		   	search >> s[i].gender;
			if (s[i].id == n)
	        {
	        	cout <<"\nCongratulation! Customer Data Searched Successfully\n\n";
	            cout <<"ID: " << s[i].id << endl;
	      		cout <<"Name: " << s[i].Customer_name << endl;
	      		cout <<"Phone Number: " << s[i].ph_no << endl;
	      		cout <<"Ice Cream Name: " << s[i].age << endl;
	      		cout <<"Price: " << s[i].gender << endl;
	            return 1;
			}
			i++;
		  }
		  search.close();
		  if (i == 0)
		  {
		  	  cout << "Sorry, ID not found.";
		  }
	}
		  



int dltStudent(IceCream s[], string n)
{
		int i=0;
		 system("cls");
		 ofstream write;
		  write.open("new.txt", ios::app | ios::out );
		  ifstream dlt;
		  dlt.open("icecreamshop.txt", ios::app | ios::in);
		 if (write.fail() || dlt.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
   		 while (!dlt.eof())
		  {
		   	dlt >> s[i].id;
			dlt.ignore();
		   	getline(dlt, s[i].Customer_name);
		   	getline(dlt, s[i].ph_no);
		   	dlt >> s[i].age;
		   	dlt >> s[i].gender;
			if (s[i].id != n)
	        {
	            write << s[i].id << endl;
		        write << s[i].Customer_name << endl;
		        write << s[i].ph_no << endl;
		        write << s[i].age << endl;
		        write << s[i].gender << endl;
			}
				i++;   
		    
		  }
		  dlt.close();
		  write.close();
		  remove("icecreamshop.txt");
		  rename("new.txt", "icecreamshop.txt");
		  if (i != 0)
		  {
		  	count--;
		  	cout <<"\nCongratulation! Data Deleted Successfully.\n\n";
		  	
		  }
		  if (i == 0)
		  {
		  	
		  	  cout << "Sorry, Customer Data not found.";
		  }
	}


int updStudent(IceCream s[], string n)
{
     	IceCream updt;
		 system("cls");
		 int i=0;
		 
		bool valid_name = false;
        do
		{
            cout << "Enter the Customer Name: ";
            cin.ignore();
            getline(cin, updt.Customer_name);
            valid_name = isValidName(updt.Customer_name);
            if (!valid_name) 
			{
                cout << "\n\tInvalid input! \n\tName should contain only alphabets. \n\tPlease try again." << endl <<endl;
      		}
        } while (!valid_name);
        
        bool valid_id = false;
        do 
		{
        	cout <<"Enter the Customer ID: ";
			cin >> updt.id;
			valid_id = isValidDigit(updt.id);
			if(!valid_id)
			{
				cout << "\n\tInvalid input! \n\tID should contain only digits. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_id);
		
		bool valid_ph = false;
		do
		{
        	cout <<"Enter the customer Phone Number: ";
			cin.ignore();
			getline(cin,updt.ph_no);
			valid_ph = isValidPhoneNumber(updt.ph_no);
			if(!valid_ph)
			{
				cout << "\n\tInvalid input! \n\tPhone Number should contain only digits, + and -. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_ph);
		
		bool validGender = false;
		do 
		{
			cout <<"Enter the Customer gender: ";
			cin >> updt.gender;
			validGender = isValidName(updt.gender);
			if(!validGender)
			{
				cout << "\n\tInvalid input! \n\tGender should contain only alphabets. \n\tPlease try again." << endl << endl;
			}
		}while(!validGender);
		
		bool validAge = false;
		do
		{
			cout <<"Enter the Customer Age: ";
			cin >> updt.age;
			validAge = isValidDigit(updt.age);
			if(!validAge)
			{
				cout << "\n\tInvalid input!\n\\t Age should contain only digits.\n\t Please try again." << endl <<endl;
			}
		}while(!validAge);
		 
		 ofstream upd_write;
		 upd_write.open("file.txt", ios::app | ios::out );
		 ifstream update;
		 update.open("icecreamshop.txt", ios::app| ios::in  );
	    
		 if (upd_write.fail() || update.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
		   	 
        while (!update.eof())
		  {
		    update >> s[i].id;
			update.ignore();
		   	getline(update, s[i].Customer_name);
		   	getline(update, s[i].ph_no);
		   	update >> s[i].age;
		   	update >> s[i].gender;
			if (s[i].id != n)
	        {
				upd_write << s[i].id << endl;
		        upd_write << s[i].Customer_name << endl;
		        upd_write << s[i].ph_no << endl;
		        upd_write << s[i].age << endl;
		        upd_write << s[i].gender << endl;
			}
			else 
			{
				upd_write << updt.id << endl;
		        upd_write << updt.Customer_name << endl;
		        upd_write << updt.ph_no << endl;
		        upd_write << updt.age << endl;
		        upd_write << updt.gender << endl;
			}
			i++;
		   	
		}
		  update.close();
		  upd_write.close();
		  remove("icecreamshop.txt");
		  rename("file.txt", "icecreamshop.txt");
		   if( i != 0)
		   {
				cout <<"\nCongratulation! Customer Data Updatede Successfully\n\n"; 
		   }
		  if (i == 0)
		  {
		  	  cout << "Sorry, Customer Data not found.";
		  }
	}




void AllIceCream ()
{
	cout << "\n________________________________ Ice Cream Availability ______________________________ " << endl;
	cout << "\n--------------------Ice Cream flavors available in our centre are----------------------------- " << endl;
	cout << "\n\t\t\t1. Vanilla Flavors" << endl;
	cout << "\t\t\t2. Blackberry Flavors" << endl;
	cout << "\t\t\t3. Pumpkin Flavors" << endl;
	cout << "\t\t\t4. Pineapple Flavors" << endl;
	cout << "\t\t\t5. Raspberry Flavors" << endl;
	cout << "\t\t\t6. Caramel Flavors" << endl;
	cout << "\t\t\t7. Banana Flavors" << endl;
	cout << "\t\t\t8. Orange Flavors" << endl;
	cout << "\t\t\t9. Peach Flavors" << endl;
	cout << "\t\t\t0. Back to Menu" << endl;
	cout << "\n\n-------------------Ice Cream Scoop Range--------------------------------------------" << endl;
	cout << "\t\t\t1.  One-Scoop\t\t 150 " << endl;
	cout << "\t\t\t2.  Two-Scoop\t\t 300 " << endl;
	cout << "\t\t\t3.  Three-Scoop\t\t 450 "  << endl;
	cout << "________________________________________________________________________________________ " << endl;

}


char isValidateChoice(char quantity)
{
	if(quantity >= '1' && quantity <= '3')
	{
		return quantity;
	}
	else
	{
		cout << "\nInvalid Scoop should be between 1 and 3." << endl;
        cout <<"\nPlease Enter Scoop Again : ";
        cin >> quantity;
        return isValidateChoice( quantity);
	}
}

char validateSelectionChoice(char Selection_Choice)
{
	if(Selection_Choice >= '0' && Selection_Choice <='9')
	{
		return Selection_Choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 0 and 9." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> Selection_Choice;
        return validateSelectionChoice(Selection_Choice);
	}
}

void MakeChoice () 
{
	ofstream fout ("Customer Details .txt" ,ios::app) ;
	int  scoop =150 ;
	int _Choice;
	char quantity, Selection_Choice;
	while(true)
	{
	AllIceCream();
	cout << "Make Choice regarding Ice Cream Flavors " << endl ;
	cin >> Selection_Choice ;
	Selection_Choice = validateSelectionChoice(Selection_Choice);
	system("cls");
	switch (Selection_Choice)
	{
	
	    
			case '1':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Vanilla Flavors" << endl;
					fout << "Vanilla Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '2':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Blackberry Flavors" << endl;
					fout << "Blackberry Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '3':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Pumpkin Flavors" << endl;
					fout << "Pumpkin Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '4':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Pineapple Flavors" << endl;
					fout << "Pineapple Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '5':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Raspberry Flavors" << endl;
					fout << "Raspberry Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '6':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Caramel Flavors" << endl;
					fout << "Caramel Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '7':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Banana Flavors" << endl;
					fout << "Banana Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '8':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Orange Flavors" << endl;
					fout << "Orange Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '9':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Ice Cream choosed : " <<  "Peach Flavors" << endl;
					fout << "Peach Flavors " << endl;
					cout << "\nHow much scoop you want: ";
					cin >> quantity;
					quantity = isValidateChoice(quantity);
					cout << "Scoop : " <<   quantity << endl;
					fout << "Scoop : " <<   quantity << endl;
					cout << "Your Payable amount will be " << quantity* scoop  << endl;
					fout << quantity * scoop << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			default:
				{
					cout <<"invalid choice " << endl;
				}
		}
		if(Selection_Choice == '0')
		break;
	}
	    
}


void menu()
{
					
	cout << "Select the following To Continue the Process: " << endl <<endl;
	cout << " 1.  Add: " << endl;
	cout << " 2.  Display : " << endl;
 	cout << " 3.  Search : " << endl;
	cout << " 4.  Update : " << endl;
	cout << " 5.  Delete : " << endl;
	cout << " 6.  Exit : " << endl << endl;
}

void iceCreamMenu()
{
	cout << " 1.  Ice Cream Menu: " << endl;
	cout << " 2.  Make Choice: " << endl;
	cout << " 0.  Back To Menu: " << endl;
}

char validateMainMenuChoice(char choice)
{
	if(choice >= '1' && choice <= '6')
	{
		return choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 1 and 5." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> choice;
        return validateMainMenuChoice(choice);
	}
}
char validateMiniMenuChoice(char choice)
{
	if(choice >= '0' && choice <= '2')
	{
		return choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 0 and 2." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> choice;
        return validateMiniMenuChoice(choice);
	}
}
int main ()
{
	IceCream s[100];

	cout<<endl<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"===   Wellcome to Muqadas shop  ==="<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"====    Muqadas Ice Cream  ===="<<endl;
	cout<<"       "<<"======================================"<<endl;
    
    admin a;
    string pasword, id;
    int n;
    char choice;
    cout <<"Enter the login password: ";
    cin >> pasword;
    Password(a, pasword);
	cout<<" \n\n\nPress Enter to Continue...";
	getch();
	system ("cls");
	
	while (true) 
	{
        menu();
        cout << "Enter the user choice: ";
        cin >> choice;
        choice = validateMainMenuChoice(choice);
        system("cls");

        switch (choice) 
		{
            case '1':
                cout << "Enter the customer index: ";
                cin >> n;
                inputDetails(s, n);
                saveInFile(s, n);
                system("cls");
                while (true) 
				{
                    iceCreamMenu();
                    cout << "Enter the Customer choice: ";
                    cin >> choice;
                    choice = validateMiniMenuChoice(choice);
                    system("cls");
                    switch (choice)
					 {
                        case '1':
                            AllIceCream();
                            break;
                        case '2':
                            MakeChoice();
                            break;
                        case '0':
                            cout << "Back To Main Menu" << endl;
                            break;
                    }
                    if (choice == '0')
                        break;
                }
                break;
            case '2':
                cout << "Enter the customer you want to display: ";
                cin >> id;
                displayStudent(s, id);
                break;

            case '3':
                cout << "Enter the customer id to search: ";
                cin >> id;
                idSearch(s, id);
                break;

            case '4':
                cout << "Enter the customer id to update: ";
                cin >> id;
                updStudent(s, id);
                break;

            case '5':
                cout << "Enter the customer id to delete: ";
                cin >> id;
                dltStudent(s, id);
                break;
            case '6':
				cout <<"\n\nThank You For visiting My Ice Cream Shop." << endl;
				exit(0);

        }
    }
    return 0;
}



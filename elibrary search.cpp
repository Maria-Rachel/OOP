#include<iostream>
using namespace std;
class addebook
{
	int book_id;
	float price;
	string book_name, author;
	public:
		void readvalue()
		{
			cout<<"Enter book id:";
			cin>>book_id;
			cout<<"Enter book name:" ;
			cin>>book_name;
			cout<<"Enter author of the book:" ;
			cin>>author;        
			cout<<"Enter price of the book:";
			cin>>price;
		}
		void displayvalue()
		{
			cout<<"BOOK ID:"<< book_id<<"\n";
			cout<<"BOOK NAME:"<< book_name<<"\n";
			cout<<"BOOK AUTHOR:"<< author <<"\n";
			cout<<"BOOK PRICE:"<< price <<"\n";
		}
};
class search
{
	int book_id;
	float price;
	string book_name, author;
	public:
		void readvalue()
		{
			cout<<"Enter book id:";
			cin>>book_id;
			cout<<"Enter book name:" ;
			cin>>book_name;
			cout<<"Enter author of the book:" ;
			cin>>author;        
			cout<<"Enter price of the book:";
			cin>>price;
		}
		void displayvalue()
		{
			cout<<"BOOK ID:"<< book_id<<"\n";
			cout<<"BOOK NAME:"<< book_name<<"\n";
			cout<<"BOOK AUTHOR:"<< author <<"\n";
			cout<<"BOOK PRICE:"<< price <<"\n";
		}
};
class borrow
{
	int user_id,user_phonenumber,c=0;
	string book_name,user_name,user_email;
	public:
		void readvalue_borrow(int user_id=00, int user_phonenumber=0000000000,string book_name="none",string user_name="none",string user_email="useremail@gmail.com")
		{
			cout<<"Enter user id:";
			cin>>user_id;
			cout<<"Enter user name:" ;
			cin>>user_name;
			cout<<"Enter book name:" ;
			cin>>book_name;
			cout<<"Enter user email:" ;
			cin>>user_email;
			cout<<"Enter user phone number:" ;
			cin>>user_phonenumber;
		}
		void displayvalue_borrow()
		{
			cout<<"USER ID:"<< user_id<<"\n";
			cout<<"USER NAME:"<< user_name<<"\n";
			cout<<"BOOK NAME:"<< book_name<<"\n";
			cout<<"USER EMAIL:"<< user_email<<"\n";
			cout<<"USER PHONE NUMBER:"<< user_phonenumber<<"\n";
		}
};

int main()
{
	int num;
	cout<<"Enter the following values to select the required operation \n";
	cout<<"1. TO ADD EBOOKS TO THE LIBRARY\n";
	cout<<"2. TO BORROW EBOOKS FROM THE LIBRARY\n";    
	cout<<"3. TO SEARCH AN EBOOK FROM THE LIBRARY\n";                                                                                                                                                                         
	cout<<"3. EXIT"<<"\n";
	while (true)
	{
		cout<<"Enter the value: ";
		cin>>num;
		if(num==1)
		{
			addebook book;
			book.readvalue();
			book.displayvalue();
		}
		else if(num==2)
		{
			borrow Y;
			Y.readvalue_borrow();
			Y.displayvalue_borrow();
		}
		else if(num==3)
		{
			cout<<"Thank You";
			break; 
		}
		else
		{
			cout<<"Invalid Choice\n";
		}
	}
	return 0;
}


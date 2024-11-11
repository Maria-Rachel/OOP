#include<iostream>
using namespace std;
class addebook
{
    int book_id, is_borrowed;
    float price;
    string book_name, author;
	public:
	    void setvalues(int b_id = 101, string b_name = "", string auth = "", float pr = 0.00)
	    {
	        book_id = b_id;
	        book_name = b_name;
	        author = auth;
	        price = pr;
	        is_borrowed=0;
	    }
	
	    void displayvalue()
	    {
	    	cout << "Book Added!\n";
	        cout << "BOOK ID: " << book_id << "\n";
	        cout << "BOOK NAME: " << book_name << "\n";
	        cout << "BOOK AUTHOR: " << author << "\n";
	        cout << "BOOK PRICE: " << price << "\n";
	    }
};
class borrow
{
    int user_id, user_phonenumber;
    string book_name, user_name, user_email;
	public:
	    void setvalues_borrow(int u_id = 201, string u_name = "", string b_name = "", string u_email = "user@gmail.com", int u_phone = 0000000000)
	    {
	        user_id = u_id;
	        user_name = u_name;
	        book_name = b_name;
	        user_email = u_email;
	        user_phonenumber = u_phone;
	    }
	
	    void displayvalue_borrow()
	    {
	        cout << "USER ID: " << user_id << "\n";
	        cout << "USER NAME: " << user_name << "\n";
	        cout << "BOOK NAME: " << book_name << "\n";
	        cout << "USER EMAIL: " << user_email << "\n";
	        cout << "USER PHONE NUMBER: " << user_phonenumber << "\n";
	    }
};

int main()
{
	cout<<"ADDING A BOOK TO THE E-LIBRARY"<<"\n";
    addebook book;
     
    book.setvalues(); 
    book.displayvalue();
    
    book.setvalues(100, "Twilight", "Stephenie Meyer", 532.00); 
    book.displayvalue();
    
    
    cout<<"BORROWING A BOOK FROM E-LIBRARY"<<"\n";
	borrow Y;
    Y.setvalues_borrow();
    Y.displayvalue_borrow();
    
	Y.setvalues_borrow(200, "Mary", "Twilight", "mary@gmail.com", 9876543210); 
	Y.displayvalue_borrow();
    return 0;
}


#include <iostream>
using namespace std;

class addebook {
    int book_id;
    float price;
    string book_name, author;

public:
    
    addebook(int b_id = 101, string b_name = "None", string auth = "None", float pr = 0.00) {
        book_id = b_id;
        book_name = b_name;
        author = auth;
        price = pr;
    }


    void displayvalue() {
        cout << "BOOK ID: " << book_id << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "BOOK AUTHOR: " << author << "\n";
        cout << "BOOK PRICE: " << price << "\n";
    }
};

class borrow {
    int user_id, user_phonenumber;
    string book_name, author_name, user_name, user_email;

public:
    
    borrow(int u_id = 201, string u_name = "None", string b_name = "None", 
           string a_name = "None", string u_email = "user@gmail.com", 
           int u_phone = 0000000000) {
        user_id = u_id;
        user_name = u_name;
        book_name = b_name;
        author_name = a_name;
        user_email = u_email;
        user_phonenumber = u_phone;
    }

    void displayvalue_borrow() {
        cout << "USER ID: " << user_id << "\n";
        cout << "USER NAME: " << user_name << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "AUTHOR NAME: " << author_name << "\n";
        cout << "USER EMAIL: " << user_email << "\n";
        cout << "USER PHONE NUMBER: " << user_phonenumber << "\n";
    }
};

int main() {
    addebook book1; 
    book1.displayvalue();

    addebook book2(102, "Twilight", "Stephenie Meyer", 249.99); 
    book2.displayvalue();

    addebook book3(book2);
    book3.displayvalue();
	
				
    borrow user1; 
    user1.displayvalue_borrow();

    borrow user2(202, "Alice", "The Alchemist", "Paulo Coelho", "alice@gmail.com", 9876543210); 
    user2.displayvalue_borrow();

    borrow user3(user2); 
    user3.displayvalue_borrow();

    return 0;
}


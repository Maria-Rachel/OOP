#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;    
const int MAX_BORROWS = 3; 

class addebook {
    int book_id;
    float price;
    string book_name, author;

public:
    
    void addBook(addebook books[], int &book_count) {
        if (book_count < MAX_BOOKS) {
            cout<<"Enter book id:";
			cin>>book_id;
			cout<<"Enter book name:" ;
			cin>>book_name;
			cout<<"Enter author of the book:" ;
			cin>>author;        
			cout<<"Enter price of the book:";
			cin>>price;
   
            books[book_count].book_id = book_id;
            books[book_count].book_name = book_name;
            books[book_count].author = author;
            books[book_count].price = price;

            book_count++;
        } else {
            cout << "Maximum number of books reached.\n";
        }
    }
	
	void displayValues() const {
        cout << "BOOK ID: " << book_id << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "AUTHOR: " << author << "\n";
        cout << "PRICE: " << price << "\n";
    }
    
    void addBook(addebook books[], int &book_count, int b_id, string b_name, string auth, float pr) {
        if (book_count < MAX_BOOKS) {
            
            books[book_count].book_id = b_id;
            books[book_count].book_name = b_name;
            books[book_count].author = auth;
            books[book_count].price = pr;

            book_count++;
        } else {
            cout << "Maximum number of books reached.\n";
        }
    }
};

class borrow {
    int user_id, user_phonenumber;
    string book_name, user_name;

public:
 
    void displayvalue_borrow() const {
        cout << "USER ID: " << user_id << "\n";
        cout << "USER NAME: " << user_name << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "USER PHONE NUMBER: " << user_phonenumber << "\n";
    }

   
    void borrowBook(borrow borrows[], int &borrow_count) {
        if (borrow_count < MAX_BORROWS) {
            cout<<"Enter user id:";
			cin>>user_id;
			cout<<"Enter user name:" ;
			cin>>user_name;
			cout<<"Enter book name:" ;
			cin>>book_name;
			cout<<"Enter user phone number:" ;
			cin>>user_phonenumber;
            
            borrows[borrow_count].user_id = user_id;
            borrows[borrow_count].user_name = user_name;
            borrows[borrow_count].book_name = book_name;
            borrows[borrow_count].user_phonenumber = user_phonenumber;

            borrow_count++;
        } else {
            cout << "Maximum number of borrows reached.\n";
        }
    }

   
    void borrowBook(borrow borrows[], int &borrow_count, int u_id, string u_name, string b_name, int u_phone) {
        if (borrow_count < MAX_BORROWS) {
            
            borrows[borrow_count].user_id = u_id;
            borrows[borrow_count].user_name = u_name;
            borrows[borrow_count].book_name = b_name;
            borrows[borrow_count].user_phonenumber = u_phone;

            borrow_count++;
        } else {
            cout << "Maximum number of borrows reached.\n";
        }
    }
};

int main() {
    addebook books[MAX_BOOKS];
    borrow borrows[MAX_BORROWS];
    int book_count = 0, borrow_count = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Display books\n";
        cout << "4. Display borrowed Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            books[book_count].addBook(books, book_count);  
        } else if (choice == 2) {
            borrows[borrow_count].borrowBook(borrows, borrow_count);  
        } else if(choice==3){
        	for (int i = 0; i < book_count; i++) {
                cout << "\nDisplaying book " << i + 1 << " details:\n";
                books[i].displayValues();
            }
		}else if(choice==4){
			for (int i = 0; i < borrow_count; i++) {
                cout << "\nDisplaying borrow record " << i + 1 << " details:\n";
                borrows[i].displayvalue_borrow();
            }
		}
		else if (choice == 5) {
            cout << "Thank You!\n";
            break;
        } else {
            cout << "Invalid Choice.\n";
        }
    }
    return 0;
}


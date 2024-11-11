#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;    
const int MAX_BORROWS = 3; 

class addebook {
    int book_id;
    float price;
    string book_name, author;

public:
  
    addebook() {
        book_id = 101;
        book_name = "None";
        author = "None";
        price = 0.00;
    }

    
    addebook(int b_id, string b_name, string auth, float pr) {
        book_id = b_id;
        book_name = b_name;
        author = auth;
        price = pr;
    }

   
    void displayvalue() const {
        cout << "BOOK ID: " << book_id << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "BOOK AUTHOR: " << author << "\n";
        cout << "BOOK PRICE: " << price << "\n";
    }

   
    void addBook(addebook books[], int &book_count) {
        if (book_count < MAX_BOOKS) {
            int b_id;
            string b_name, auth;
            float pr;
            cout << "Enter details for book " << book_count + 1 << ":\n";
            cout << "Book ID: ";
            cin >> b_id;
            cout << "Book Name: ";
            cin >> b_name;
            cout << "Author: ";
            cin >> auth;
            cout << "Price: ";
            cin >> pr;
            books[book_count] = addebook(b_id, b_name, auth, pr);  
            book_count++;
        } else {
            cout << "Maximum number of books reached.\n";
        }
    }

    
    void displayBooks(const addebook books[], int book_count) {
        if (book_count == 0) {
            cout << "No books available.\n";
        } else {
            for (int i = 0; i < book_count; i++) {
                cout << "\nDisplaying book " << i + 1 << " details:\n";
                books[i].displayvalue();
            }
        }
    }

   
    string& getBookName() {
        return book_name; 
    }
};

class borrow {
    int user_id, user_phonenumber;
    string book_name, author_name, user_name, user_email;

public:
    
    borrow() {
        user_id = 201;
        user_name = "None";
        book_name = "None";
        author_name = "None";
        user_email = "user@gmail.com";
        user_phonenumber = 0000000000;
    }

   
    borrow(int u_id, string u_name, string b_name, string a_name, string u_email, int u_phone) {
        user_id = u_id;
        user_name = u_name;
        book_name = b_name;
        author_name = a_name;
        user_email = u_email;
        user_phonenumber = u_phone;
    }

   
    void displayvalue_borrow() const {
        cout << "USER ID: " << user_id << "\n";
        cout << "USER NAME: " << user_name << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "AUTHOR NAME: " << author_name << "\n";
        cout << "USER EMAIL: " << user_email << "\n";
        cout << "USER PHONE NUMBER: " << user_phonenumber << "\n";
    }

    
    void borrowBook(borrow borrows[], int &borrow_count) {
        if (borrow_count < MAX_BORROWS) {
            int u_id, u_phone;
            string u_name, b_name, a_name, u_email;
            cout << "Enter user details to borrow a book:\n";
            cout << "User ID: ";
            cin >> u_id;
            cout << "User Name: ";
            cin >> u_name;
            cout << "Book Name: ";
            cin >> b_name;
            cout << "Author Name: ";
            cin >> a_name;
            cout << "User Email: ";
            cin >> u_email;
            cout << "User Phone Number: ";
            cin >> u_phone;
            borrows[borrow_count] = borrow(u_id, u_name, b_name, a_name, u_email, u_phone);  // Pass by value
            borrow_count++;
            cout << "Book borrowed successfully!\n";
        } else {
            cout << "Maximum number of borrow records reached.\n";
        }
    }

    
    void displayBorrows(const borrow borrows[], int borrow_count) {
        if (borrow_count == 0) {
            cout << "No borrow records available.\n";
        } else {
            for (int i = 0; i < borrow_count; i++) {
                cout << "\nDisplaying borrow record " << i + 1 << " details:\n";
                borrows[i].displayvalue_borrow();
            }
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
        cout << "2. Display Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Display Borrow Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        if (choice == 1) {
            books[0].addBook(books, book_count); 
        } else if (choice == 2) {
            books[0].displayBooks(books, book_count);  
        } else if (choice == 3) {
            borrows[0].borrowBook(borrows, borrow_count);  
        } else if (choice == 4) {
            borrows[0].displayBorrows(borrows, borrow_count);  
        } else if (choice == 5) {
            cout << "Thank You!\n";
            break;
        } else {
            cout << "Invalid Choice.\n";
        }
    }
    return 0;
}


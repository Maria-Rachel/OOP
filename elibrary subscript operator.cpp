#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_BORROWS = 3;

class addebook {
    int book_id;
    float price;
    string book_name, author;

public:
    addebook() : book_id(0), price(0.0), book_name(""), author("") {}

    void addBook() {
        cout << "Enter book id: ";
        cin >> book_id;
        cout << "Enter book name: ";
        cin >> book_name;
        cout << "Enter author of the book: ";
        cin >> author;
        cout << "Enter price of the book: ";
        cin >> price;
    }

    void displayBookDetails() {
        cout << "BOOK ID: " << book_id << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "AUTHOR: " << author << "\n";
        cout << "PRICE: " << price << "\n";
    }

    string operator[](int index) const {
        if (index == 0)
            return to_string(book_id);  // Convert int to string
        else if (index == 1)
            return book_name;
        else if (index == 2)
            return author;
        else if (index == 3)
            return to_string(price);  // Convert float to string
        else {
            cout << "Invalid index. Valid indices: 0 (Book ID), 1 (Book Name), 2 (Author), 3 (Price).\n";
            return "";
        }
    }
};

class borrow {
    int user_id, user_phonenumber;
    string book_name, user_name;

    static int total_borrows;

public:
    static void borrowBook(borrow borrows[], int &borrow_count) {
        if (borrow_count < MAX_BORROWS) {
            cout << "Enter user id: ";
            cin >> borrows[borrow_count].user_id;
            cout << "Enter user name: ";
            cin >> borrows[borrow_count].user_name;
            cout << "Enter book name: ";
            cin >> borrows[borrow_count].book_name;
            cout << "Enter user phone number: ";
            cin >> borrows[borrow_count].user_phonenumber;

            borrow_count++;
            total_borrows++;
        } else {
            cout << "Maximum number of borrows reached.\n";
        }
    }

    static void displayTotalBorrows() {
        cout << "Total number of borrows: " << total_borrows << "\n";
    }

    void displayBorrowDetails() const {
        cout << "USER ID: " << user_id << "\n";
        cout << "USER NAME: " << user_name << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "USER PHONE NUMBER: " << user_phonenumber << "\n";
    }
    

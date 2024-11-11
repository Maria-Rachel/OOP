#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_BORROWS = 3;

class Book {
protected:
    int book_id;
    float price;
    string book_name, author;

public:
    void setDetails(int id, string name, string auth, float pr) {
        book_id = id;
        book_name = name;
        author = auth;
        price = pr;
    }

    void displayBookDetails() {
        cout << "BOOK ID: " << book_id << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "AUTHOR: " << author << "\n";
        cout << "PRICE: " << price << "\n";
    }

    string getBookName() { 
        return book_name; 
    }

    string getAuthor() {
        return author; 
    }

    
};

class Ebook : public Book {  
    static int total_books;

public:
    static void addBook(Ebook books[], int &book_count) {
        if (book_count < MAX_BOOKS) {
            int b_id;
            string b_name, auth;
            float pr;

            cout << "\nEnter Book ID: ";
            cin >> b_id; 
            cout << "Enter Book Name: ";
            cin >> b_name; 
            cout << "Enter Author: ";
            cin >> auth; 
            cout << "Enter Price: ";
            cin >> pr; 

            books[book_count].setDetails(b_id, b_name, auth, pr); 
            book_count++;
            total_books++;
        } else {
            cout << "Maximum number of books reached.\n";
        }
    }

    static void displayTotalBooks() {
        cout << "Total number of books: " << total_books << "\n";
    }

    static void searchBook(Ebook books[], int book_count) {
        if (book_count == 0) {
            cout << "No books available.\n";
            return;
        }

        int choice;
        string value;
        cout << "Search by:\n1. Book Name\n2. Author\nEnter choice: ";
        cin >> choice;

        cout << "Enter search value: ";
        cin >> value;

        bool found = false;

        if (choice == 1) { 
            for (int i = 0; i < book_count; i++) {
                if (books[i].getBookName() == value) {
                    cout << "\nBook found:\n";
                    books[i].displayBookDetails();
                    found = true;
                }
            }
        } else if (choice == 2) {  
            for (int i = 0; i < book_count; i++) {
                if (books[i].getAuthor() == value) {
                    cout << "\nBook found:\n";
                    books[i].displayBookDetails();
                    found = true;
                }
            }
        } else {
            cout << "Invalid choice!\n";
            return;
        }

        if (!found) {
            cout << "No book found matching the search query.\n";
        }
    }
};

int Ebook::total_books = 0;

class User {  
    int user_id;
    string user_name;
    int user_phone;

public:
    void setUserDetails(int id, string name, int phone) {
        user_id = id;
        user_name = name;
        user_phone = phone;
    }

    void displayUserDetails(){
        cout << "USER ID: " << user_id << "\n";
        cout << "USER NAME: " << user_name << "\n";
        cout << "USER PHONE NUMBER: " << user_phone << "\n";
    }
};

class Borrow : public User, public Ebook { 
    static int total_borrows;
    string borrowed_book_name;

public:
    static void borrowBook(Borrow borrows[], int &borrow_count, Ebook books[], int book_count) {
        if (borrow_count < MAX_BORROWS) {
            int u_id, u_phone;
            string u_name, b_name;

            cout << "Enter User ID: ";
            cin >> u_id ;
            cout << "Enter User Name: ";
			cin >> u_name ;
			cout << "Enter User Phone Number: ";
			cin >> u_phone;
            borrows[borrow_count].setUserDetails(u_id, u_name, u_phone);

            cout << "Enter Book Name to Borrow: ";
            cin >> b_name;
            bool book_found = false;

            for (int i = 0; i < book_count; i++) {
                if (books[i].getBookName() == b_name) {
                    borrows[borrow_count].borrowed_book_name = b_name;
                    book_found = true;
                    break;
                }
            }

            if (book_found) {
                borrow_count++;
                total_borrows++;
            } else {
                cout << "Book not found!\n";
            }
        } else {
            cout << "Maximum number of borrows reached.\n";
        }
    }

    static void displayTotalBorrows() {
        cout << "Total number of borrows: " << total_borrows << "\n";
    }

    void displayBorrowDetails(){
        displayUserDetails();  
        cout << "BORROWED BOOK NAME: " << borrowed_book_name << "\n";
    }
};

int Borrow::total_borrows = 0;

int main() {
    Ebook books[MAX_BOOKS];   
    Borrow borrows[MAX_BORROWS]; 
    int book_count = 0, borrow_count = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Display Total Books\n";
        cout << "4. Display Total Borrows\n";
        cout << "5. Display All Books\n";
        cout << "6. Search Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Ebook::addBook(books, book_count);
        } else if (choice == 2) {
            Borrow::borrowBook(borrows, borrow_count, books, book_count);
        } else if (choice == 3) {
            Ebook::displayTotalBooks();
        } else if (choice == 4) {
            Borrow::displayTotalBorrows();
        } else if (choice == 5) {
            for (int i = 0; i < book_count; i++) {
                cout << "\nBook " << i + 1 << " Details:\n";
                books[i].displayBookDetails();
            }
        } else if (choice == 6) {
            Ebook::searchBook(books, book_count);
        } else if (choice == 7) {
            cout << "Thank You!\n";
            break;
        } else {
            cout << "Invalid Choice.\n";
        }
    }

    return 0;
}


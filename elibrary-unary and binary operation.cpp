#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;    
const int MAX_BORROWS = 3; 

class addebook {
    int book_id;
    float price;
    string book_name, author;
    static int total_books;

public:

    string getBookName(){
        return book_name;
    }
    static void addBook(addebook books[], int &book_count) {
        if (book_count < MAX_BOOKS) {
            int b_id;
            string b_name, auth;
            float pr;

            cout << "Enter Book ID, Name, Author, Price: ";
            cin >> b_id >> b_name >> auth >> pr;

            books[book_count].book_id = b_id;
            books[book_count].book_name = b_name;
            books[book_count].author = auth;
            books[book_count].price = pr;

            book_count++;
            total_books++;
        } else {
            cout << "Maximum number of books reached.\n";
        }
    }

    
    static void displayTotalBooks() {
        cout << "Total number of books: " << total_books << "\n";
    }


    void displayBookDetails(){
        cout << "BOOK ID: " << book_id << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "AUTHOR: " << author << "\n";
        cout << "PRICE: " << price << "\n";
    }

   
    addebook operator++() {  
        price *= 1.10;  
        return *this ;
    }

    addebook operator--() {  
        price *= 0.90;  
        return *this;
    }

    
    bool operator==(const addebook &other) const { 
        return this->price == other.price;  
    }


    static void modifyBookPrice(addebook books[], int book_count) {
        if (book_count == 0) {
            cout << "No books available to modify.\n";
            return;
        }

        int book_index;
        char choice;
        cout << "Enter the index of the book you want to modify: ";
        cin >> book_index;

        if (book_index < 1 && book_index > book_count) {
            cout << "Invalid book index!\n";
            return;
        }

        cout << "Do you want to increase (i) or decrease (d) the price of the book? (i/d): ";
        cin >> choice;

        if (choice == 'i') {
            ++books[book_index - 1];  
            cout << "Price increased by 10%.\n";
            books[book_index - 1].displayBookDetails();
        } else if (choice == 'd') {
            --books[book_index - 1]; 
            cout << "Price decreased by 10%.\n";
            books[book_index - 1].displayBookDetails();
        } else {
            cout << "Invalid choice!\n";
        }
    }
};


int addebook::total_books = 0;

class borrow {
    int user_id, user_phonenumber;
    string book_name, user_name;

    static int total_borrows;

public:
    
    static void borrowBook(borrow borrows[], int &borrow_count) {
        if (borrow_count < MAX_BORROWS) {
            int u_id, u_phone;
            string u_name, b_name;

            cout << "Enter User ID, Name, Book Name, Phone Number: ";
            cin >> u_id >> u_name >> b_name >> u_phone;

            borrows[borrow_count].user_id = u_id;
            borrows[borrow_count].user_name = u_name;
            borrows[borrow_count].book_name = b_name;
            borrows[borrow_count].user_phonenumber = u_phone;

            borrow_count++;
            total_borrows++;
        } else {
            cout << "Maximum number of borrows reached.\n";
        }
    }

    
    static void displayTotalBorrows() {
        cout << "Total number of borrows: " << total_borrows << "\n";
    }

    
    void displayBorrowDetails(){
        cout << "USER ID: " << user_id << "\n";
        cout << "USER NAME: " << user_name << "\n";
        cout << "BOOK NAME: " << book_name << "\n";
        cout << "USER PHONE NUMBER: " << user_phonenumber << "\n";
    }
};


int borrow::total_borrows = 0;

int main() {
    addebook books[MAX_BOOKS];
    borrow borrows[MAX_BORROWS];
    int book_count = 0, borrow_count = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Display Total Books\n";
        cout << "4. Display Total Borrows\n";
        cout << "5. Display All Books\n";
        cout << "6. Display All books with same price\n";
        cout << "7. Modify Book Price\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addebook::addBook(books, book_count);  
        } else if (choice == 2) {
            borrow::borrowBook(borrows, borrow_count); 
        } else if (choice == 3) {
            addebook::displayTotalBooks();
        } else if (choice == 4) {
            borrow::displayTotalBorrows();
        } else if (choice == 5) {
            
            for (int i = 0; i < book_count; i++) {
                cout << "\nBook " << i+1 << " Details:\n";
                books[i].displayBookDetails();
            }
        } else if (choice == 6) {
            
            for (int i = 0; i < book_count - 1; i++) {
                for (int j = i + 1; j < book_count; j++) {
                    if (books[i] == books[j]) {
                        cout << "Book " << books[i].getBookName() << " and Book " << books[j].getBookName() << " have the same price.\n";
                    }
                }
            }
            
        } else if (choice == 7) {
            
            addebook::modifyBookPrice(books, book_count);
        } else if (choice == 8) {
            cout << "Thank You!\n";
            break;
        } else {
            cout << "Invalid Choice.\n";
        }
    }
    return 0;
}


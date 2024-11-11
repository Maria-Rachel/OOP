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

    friend void showBookDetails(addebook book);

    static void addBook(addebook books[], int &book_count) {
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
};

int addebook::total_books = 0;


void showBookDetails(const addebook &book) {
    cout << "Book ID: " << book.book_id << "\n";
    cout << "Book Name: " << book.book_name << "\n";
    cout << "Author: " << book.author << "\n";
    cout << "Price: " << book.price << "\n";
    cout << "*******";
}

int main() {
    addebook books[MAX_BOOKS];
    int book_count = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display Details of a Specific Book\n";
        cout << "3. Display Total Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addebook::addBook(books, book_count);  
        } else if (choice == 2) {
            int book_index;
            cout << "Enter the index of the book (0 to " << book_count - 1 << "): ";
            cin >> book_index;
            
            if (book_index >= 0 && book_index < book_count) {
                showBookDetails(books[book_index]);  
            } else {
                cout << "Invalid index!\n";
            }
        } else if (choice == 3) {
            addebook::displayTotalBooks();
        } else if (choice == 4) {
            cout << "Thank You!\n";
            break;
        } else {
            cout << "Invalid Choice.\n";
        }
    }

    return 0;
}


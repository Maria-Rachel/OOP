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

    void displayBookDetails(){
        cout << "BOOK ID: " << book_id << "\n"
             << "BOOK NAME: " << book_name << "\n"
             << "AUTHOR: " << author << "\n"
             << "PRICE: " << price << "\n";
    }

    bool operator==(Book &other){
        return this->price == other.price;
    }

    void modifyPrice(char choice) {
        if (choice == 'i')
            price *= 1.10;  
        else if (choice == 'd')
            price *= 0.90;  
    }

    string getBookName() { 
		return book_name; 
	}
    string getAuthor() {
		return author; 
	}
    float getPrice() {
		return price; 
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

            cout << "Enter Book ID, Name, Author, Price: ";
            cin >> b_id >> b_name >> auth >> pr;

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

    static void modifyBookPrice(Ebook books[], int book_count) {
        if (book_count == 0) {
            cout << "No books available to modify.\n";
            return;
        }

        int book_index;
        char choice;
        cout << "Enter the index of the book you want to modify: ";
        cin >> book_index;

        if (book_index < 1 || book_index > book_count) {
            cout << "Invalid book index!\n";
            return;
        }

        cout << "Do you want to increase (i) or decrease (d) the price of the book? (i/d): ";
        cin >> choice;

        books[book_index - 1].modifyPrice(choice);
        books[book_index - 1].displayBookDetails();
    }

    static void searchBook(Ebook books[], int book_count) {
        if (book_count == 0) {
            cout << "No books available.\n";
            return;
        }

        int choice;
        string search_query;
        cout << "Search by:\n1. Book Name\n2. Author\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        cout << "Enter search query: ";
        getline(cin, search_query);

        bool found = false;

        if (choice == 1) { 
            for (int i = 0; i < book_count; i++) {
                if (books[i].getBookName() == search_query) {
                    cout << "\nBook found:\n";
                    books[i].displayBookDetails();
                    found = true;
                }
            }
        } else if (choice == 2) {  
            for (int i = 0; i < book_count; i++) {
                if (books[i].getAuthor() == search_query) {
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


class Borrow : public Ebook {
    int user_id, user_phonenumber;
    string user_name;
    static int total_borrows;

public:
    Borrow() : user_id(0), user_phonenumber(0), user_name("") {}

    static void borrowBook(Borrow borrows[], int &borrow_count) {
        if (borrow_count < 	MAX_BORROWS) {
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
        cout << "USER ID: " << user_id << "\n"
             << "USER NAME: " << user_name << "\n"
             << "BOOK NAME: " << book_name << "\n"
             << "USER PHONE NUMBER: " << user_phonenumber << "\n";
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
        cout << "6. Modify Book Price\n";
        cout << "7. Search Book\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Ebook::addBook(books, book_count);
        } else if (choice == 2) {
            Borrow::borrowBook(borrows, borrow_count);
        } else if (choice == 3) {
            Ebook::displayTotalBooks();
        } else if (choice == 4) {
            Borrow::displayTotalBorrows();
        } else if (choice == 5) {
            for (int i = 0; i < book_count; i++) {
                cout << "\nBook " << i+1 << " Details:\n";
                books[i].displayBookDetails();
            }
        } else if (choice == 6) {
            Ebook::modifyBookPrice(books, book_count);
        } else if (choice == 7) {
            Ebook::searchBook(books, book_count);
        } else if (choice == 8) {
            cout << "Thank You!\n";
            break;
        } else {
            cout << "Invalid Choice.\n";
        }
    }

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    int book_id;
    string book_name;
    string author;
    float price;

public:
    
    void addBook() {
        cout << "\nEnter Book ID: ";
        cin >> book_id;
        cout << "Enter Book Name: ";
        cin >> book_name;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Price: ";
        cin >> price;
    }

    
    virtual void display() {
        cout << "\nDisplaying Book for library:";
        cout << "\nBOOK ID: " << book_id;
        cout<< "\nBOOK NAME: " << book_name;
    	cout << "\nAUTHOR: " << author;
        cout << "\nPRICE: " << price << endl;
    }
};


class Ebook : public Book {
public:
    
    void addBook() {
        cout << "\nEnter Ebook ID: ";
        cin >> book_id;
        cout << "Enter Ebook Name: ";
        cin >> book_name;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Ebook added successfully!" << endl;
    }

    
    void display() {
        cout << "\nDisplaying Ebook:";
        cout << "\nBOOK ID: " << book_id;
        cout << "\nBOOK NAME: " << book_name;
        cout << "\nAUTHOR: " << author;
        cout << "\nPRICE: " << price << " (Ebook)" << endl;
    }
};

int main() {
    Book base_book;       
    Ebook derived_ebook;  
    Book* book_ptr;        


    cout << "Adding a regular book:" << endl;
    base_book.addBook();

   
    cout << "Adding an ebook:" << endl;
    derived_ebook.addBook();

    
    book_ptr = &base_book;
    book_ptr->display();  

    
    book_ptr = &derived_ebook;
    book_ptr->display();  
    return 0;
}


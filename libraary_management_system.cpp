#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Class definition for Borrower
class Borrower {
public:
    string name; // Borrower's name
    string id;   // Borrower's ID (can be extended with more details as needed)

    // Constructor to initialize name and ID
    Borrower(string& name, string& id)
        : name(name), id(id) {}
};

// Class definition for Book
class Book {
public:
    int id;            // Book's unique ID
    string title;      // Title of the book
    string author;     // Author of the book
    string ISBN;       // ISBN of the book
    bool is_checked_out; // Flag indicating if the book is checked out
    time_t checkout_time; // Time when the book was checked out
    Borrower* borrower;   // Pointer to the borrower object who has checked out the book

    // Constructor to initialize book details
    Book(int id, string& title, string& author, string& ISBN)
        : id(id), title(title), author(author), ISBN(ISBN), is_checked_out(false), checkout_time(0), borrower(nullptr) {}

    // Destructor to free memory for borrower object when book is destroyed
    ~Book() {
        delete borrower;
    }
};

// Class definition for Library
class Library {
private:
    vector<Book> books;         // List of books in the library
    vector<Borrower*> borrowers; // List of borrowers in the library

public:
    // Method to add a new book to the library
    void addBook(string& title, string& author, string& ISBN) {
        int new_id = books.size() + 1; // Generate a simple ID for the new book
        books.emplace_back(new_id, title, author, ISBN); // Add the book to the vector of books
        cout << "Book added successfully.\n"; // Display success message
    }

    // Method to add a new borrower to the library
    void addBorrower(string& name, string& id) {
        borrowers.push_back(new Borrower(name, id)); // Create a new Borrower object and add it to the vector of borrowers
        cout << "Borrower added successfully.\n";   // Display success message
    }

    // Method to search for books based on different criteria (Title, Author, ISBN)
    void searchBooks() {
        cout << "\nSearch Books:\n";
        cout << "1. By Title\n";
        cout << "2. By Author\n";
        cout << "3. By ISBN\n";
        int choice;
        cin >> choice;

        string query;
        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore(); // Clear the buffer
                getline(cin, query);
                for (auto& book : books) {
                    if (book.title == query) {
                        displayBook(book);
                    }
                }
                break;

            case 2:
                cout << "Enter author name: ";
                cin.ignore(); // Clear the buffer
                getline(cin, query);
                for (auto& book : books) {
                    if (book.author == query) {
                        displayBook(book);
                    }
                }
                break;

            case 3:
                cout << "Enter ISBN: ";
                cin.ignore(); // Clear the buffer
                getline(cin, query);
                for (auto& book : books) {
                    if (book.ISBN == query) {
                        displayBook(book);
                    }
                }
                break;

            default:
                cout << "Invalid choice.\n";
                break;
        }
    }

    // Method to check out a book to a borrower
    void checkoutBook(int book_id, string& borrower_id) {
        for (auto& book : books) {
            if (book.id == book_id && !book.is_checked_out) { // Check if the book is available for checkout
                for (auto& borrower : borrowers) {
                    if (borrower->id == borrower_id) { // Find the borrower by ID
                        book.is_checked_out = true; // Set the book as checked out
                        book.checkout_time = time(nullptr); // Record checkout time
                        book.borrower = borrower; // Assign borrower to the book
                        cout << "Book checked out successfully to " << borrower->name << ".\n"; // Display success message
                        return;
                    }
                }
                cout << "Borrower not found with ID " << borrower_id << ".\n"; // Display error if borrower not found
                return;
            }
        }
        cout << "Book not available for checkout or ID not found.\n"; // Display error if book not available for checkout
    }

    // Method to return a checked out book
    void returnBook(int book_id) {
        for (auto& book : books) {
            if (book.id == book_id && book.is_checked_out) { // Check if the book is checked out
                book.is_checked_out = false; // Set the book as not checked out
                book.checkout_time = 0; // Reset checkout time
                delete book.borrower; // Clear borrower information
                book.borrower = nullptr;
                cout << "Book returned successfully.\n"; // Display success message
                return;
            }
        }
        cout << "Book not checked out or ID not found.\n"; // Display error if book not checked out
    }

    // Method to calculate fine for an overdue book
    void calculateFine(int book_id) {
        for (auto& book : books) {
            if (book.id == book_id && book.is_checked_out) { // Check if the book is checked out
                time_t now = time(nullptr);
                double days_checked_out = difftime(now, book.checkout_time) / (60 * 60 * 24); // Calculate days checked out

                if (days_checked_out > 14) { // Assuming 14 days is the due period
                    double fine = (days_checked_out - 14) * 100; // ₹100 fine per day overdue
                    cout << "Fine for book ID " << book_id << " is ₹" << fine << "\n"; // Display fine amount
                } else {
                    cout << "No fine. Book returned within due period.\n"; // Display message if no fine
                }
                return;
            }
        }
        cout << "Book not found or not checked out.\n"; // Display error if book not found or not checked out
    }

    // Method to display all books in the library
    void displayBooks() {
        cout << "\nLibrary Books:\n";
        for (auto& book : books) {
            displayBook(book);
        }
    }

    // Method to display all borrowers in the library
    void displayBorrowers() {
        cout << "\nLibrary Borrowers:\n";
        for (auto& borrower : borrowers) {
            cout << "Name: " << borrower->name << ", ID: " << borrower->id << "\n"; // Display borrower name and ID
        }
    }

private:
    // Helper method to display details of a book
    void displayBook(Book& book) {
        cout << "ID: " << book.id << ", Title: " << book.title
             << ", Author: " << book.author << ", ISBN: " << book.ISBN
             << ", Checked Out: " << (book.is_checked_out ? "Yes" : "No"); // Display whether book is checked out

        if (book.is_checked_out) {
            cout << ", Checked Out By: " << book.borrower->name; // Display borrower's name if checked out
        }
        cout << "\n";
    }
};

// Function to display the main menu of the library management system
void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Add Borrower\n";
    cout << "3. Search Books\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. Calculate Fine\n";
    cout << "7. Show Books\n";
    cout << "8. Show Borrowers\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to run the library management system
int main() {
    Library library; // Create a Library object
    int choice;      // Variable to store user's choice from the menu

    while (true) {
        displayMenu(); // Display the main menu
        cin >> choice; // Get user's choice

        switch (choice) {
            case 1: {
                string title, author, ISBN;
                cout << "Enter book title: ";
                cin.ignore(); // Clear input buffer
                getline(cin, title); // Get book title
                cout << "Enter author name: ";
                getline(cin, author); // Get author name
                cout << "Enter ISBN: ";
                getline(cin, ISBN); // Get ISBN
                library.addBook(title, author, ISBN); // Add book to library
                break;
            }
            case 2: {
                string name, id;
                cout << "Enter borrower name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name); // Get borrower name
                cout << "Enter borrower ID: ";
                getline(cin, id); // Get borrower ID
                library.addBorrower(name, id); // Add borrower to library
                break;
            }
            case 3: {
                library.searchBooks(); // Search books in library
                break;
            }
            case 4: {
                int book_id;
                string borrower_id;
                cout << "Enter book ID to check out: ";
                cin >> book_id; // Get book ID to check out
                cout << "Enter borrower ID: ";
                cin.ignore(); // Clear input buffer
                getline(cin, borrower_id); // Get borrower ID
                library.checkoutBook(book_id, borrower_id); // Checkout book
                break;
            }
            case 5: {
                int book_id;
                cout << "Enter book ID to return: ";
                cin >> book_id; // Get book ID to return
                library.returnBook(book_id); // Return book
                break;
            }
            case 6: {
                int book_id;
                cout << "Enter book ID to calculate fine: ";
                cin >> book_id; // Get book ID to calculate fine
                library.calculateFine(book_id); // Calculate fine for overdue book
                break;
            }
            case 7: {
                library.displayBooks(); // Display all books in library
                break;
            }
            case 8: {
                library.displayBorrowers(); // Display all borrowers in library
                break;
            }
            case 9: {
                cout << "Exiting the system.\n"; // Exit the program
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n"; // Display error for invalid menu choice
        }
    }

    return 0;
}
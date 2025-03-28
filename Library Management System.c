#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define maximum limits for books, users, and admins
#define MAX_BOOKS 100
#define MAX_USERS 10
#define MAX_ADMINS 1

// Structure to hold book information
typedef struct {
    char title[100];
    char author[100];
    char section[50];
    int bookID;
    int isBorrowed;
} Book;

// Structure to hold user information
typedef struct {
    char username[50];
    char password[50];
    int borrowedBooks[MAX_BOOKS];
    int borrowedCount;
} User;

// Structure to hold admin information
typedef struct {
    char username[50];
    char password[50];
} Admin;

// Arrays to hold books, users, and admins
Book books[MAX_BOOKS];
User users[MAX_USERS];
Admin admins[MAX_ADMINS] = {{"admin", "admin123"}}; // Default admin credentials

// Counters for the number of books, users, and admins
int bookCount = 0;
int userCount = 0;
int adminCount = 1;

// Function declarations for various operations in the system
int adminLogin();
int userLogin();
void adminDashboard();
void userDashboard();
void createAccount();
void addBook();
void deleteBook();
void displayBooks();
void searchByTitle();
void searchByAuthor();
void displayBooksBySection();
void displayBorrowedBooks();
void addBookToCart();
void checkAvailableBooks();
void printMainScreen();
void printWelcomeScreen();
void printAdminLoginScreen();
void printUserLoginScreen();
void clrscr();
void toLowercase(char* str);
void loadBooksFromFile();
void saveBooksToFile();
void loadUsersFromFile();
void saveUsersToFile();

int main() {
    
    // Load books and users from files at the start of the program
    loadBooksFromFile();
    loadUsersFromFile();

    int choice;
    while (1) {
        printMainScreen(); // Display main menu
        printf("Choose an option: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1: 
                if (adminLogin()) { // Admin login validation
                    printf("Admin Login Successful!\n");
                    clrscr();
                    adminDashboard(); // Admin dashboard
                } else {
                    printf("Invalid Admin credentials.\n");
                }
                break;
            case 2: 
                if (userLogin()) { // User login validation
                    printf("User Login Successful!\n");
                    clrscr();
                    userDashboard(); // User dashboard
                } else {
                    printf("Invalid User credentials.\n");
                }
                break;
            case 3: 
                createAccount(); // Create a new user account
                break;
            case 4: 
                clrscr();
                displayBooks(); // Display all books
                break;
            case 5: 
                clrscr();
                searchByTitle(); // Search books by title
                break;
            case 6: 
                clrscr();
                searchByAuthor(); // Search books by author
                break;
            case 7: 
                clrscr();
                displayBooksBySection(); // Display books by section
                break;
            case 0: 

                // Save books and users before exiting
                saveBooksToFile();
                saveUsersToFile();
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n"); // Invalid choice
        }
    }
    return 0;
}

// Admin login function
int adminLogin() {
    clrscr();
    char username[50], password[50];
    printf("\n================================\n\tAdmin Login Page\n================================\n");
    printf("Enter Admin username: ");
    scanf(" %[^\n]%*c", username); // Input username
    printf("Enter Admin password: ");
    scanf(" %[^\n]%*c", password); // Input password

    // Check if entered credentials match any admin
    for (int i = 0; i < adminCount; i++) {
        if (strcmp(admins[i].username, username) == 0 && strcmp(admins[i].password, password) == 0) {
            return 1; // Successful login
        }
    }
    return 0; // Invalid login
}

// User login function
int userLogin() {
    clrscr();
    char username[50], password[50];
    printf("\n================================\n");
    printf("\tUser Login Page");
    printf("\n================================\n");
    printf("Enter User username: ");
    scanf(" %[^\n]%*c", username); // Input username
    printf("Enter User password: ");
    scanf(" %[^\n]%*c", password); // Input password

    // Check if entered credentials match any user
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Successful login
        }
    }
    return 0; // Invalid login
}

// Function to create a new user account
void createAccount() {
    clrscr();
    if (userCount >= MAX_USERS) { // Check if user limit is reached
        printf("Sorry, user limit reached. Cannot create more accounts.\n");
        return;
    }

    char username[50], password[50];
    printf("\n==================================\n");
    printf("\tCreate User Account");
    printf("\n==================================\n");
        
    printf("Enter new username: ");
    scanf(" %[^\n]%*c", username); // Input new username
    
    // Check if username already exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists. Please choose a different one.\n");
            return;
        }
    }

    printf("Enter new password: ");
    scanf(" %[^\n]%*c", password); // Input new password

    // Store the new user details
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    users[userCount].borrowedCount = 0;// Initialize borrowed books count
    userCount++; // Increment the user count

    printf("\nAccount created successfully! You can now log in.");
    printf("\n__");
    printf("\n\nPress any key to return to MainScreen...");
    getchar();  // Wait for user to press a key
    clrscr();
}

// Admin dashboard function
void adminDashboard() {
    int choice;
    while (1) {
        printf("\n=================================\n");
        printf("\tAdmin Dashboard \n");
        printf("=================================\n");
        printf("1- View all books\n");
        printf("2- Add book\n");
        printf("3- Delete book\n");
        printf("4- Search books by title\n");
        printf("5- Search books by author\n");
        printf("6- Check available books\n");
        printf("0- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get admin choice

        // Handle different admin choices
        switch (choice) {
            case 1: 
                displayBooks(); // Display all books
                printf("\nPress any key to return to Admin Dashboard...");
                getchar();
                getchar();
                break;
            case 2: 
                addBook(); // Add a new book
                printf("\nPress any key to return to Admin Dashboard...");
                getchar();
                break;
            case 3: 
                deleteBook(); // Delete a book
                printf("\nPress any key to return to Admin Dashboard...");
                getchar();
                break;
            case 4: 
                searchByTitle(); // Search books by title
                printf("\nPress any key to return to Admin Dashboard...");
                getchar();
                getchar();
                break;
            case 5: 
                searchByAuthor(); // Search books by author
                printf("\nPress any key to return to Admin Dashboard...");
                getchar();
                getchar();
                break;
            case 6:
                checkAvailableBooks(); // Check available books
                printf("\nPress any key to return to Admin Dashboard...");
                getchar();
                getchar();
                break;
            case 0:
            	clrscr();
                return; // Exit dashboard
            default:
                printf("Invalid choice. Please try again.\n");
        }
        clrscr();
    }
}

// User dashboard function
void userDashboard() {
    int choice;
    while (1) {
        clrscr();
        printf("\n=================================\n\tUser Dashboard \n=================================\n");
        printf("1- Display all books\n");
        printf("2- Search books by title\n");
        printf("3- Search books by author\n");
        printf("4- Display books by section\n");
        printf("5- View borrowed books\n");
        printf("6- Add book to cart\n");
        printf("0- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);// Get user choice

        // Handle user choices
        switch (choice) {
            case 1:
                displayBooks(); // Display all books
                printf("\nPress any key to return to User Dashboard...");
                getchar(); // Wait for user input
                getchar();
                break;
            case 2:
                searchByTitle(); // Search books by title
                printf("\nPress any key to return to User Dashboard...");
                getchar();
                break;
            case 3:
                searchByAuthor(); // Search books by author
                printf("\nPress any key to return to User Dashboard...");
                getchar();
                break;
            case 4:
                displayBooksBySection(); // Display books by section
                printf("\nPress any key to return to User Dashboard...");
                getchar();
                break;
            case 5:
                displayBorrowedBooks(); // View borrowed books
                printf("\nPress any key to return to User Dashboard...");
                getchar();
                getchar();
                break;
            case 6:
                addBookToCart(); // Borrow a book
                printf("\nPress any key to return to User Dashboard...");
                getchar();
                getchar();
                break;
            case 0:
                return; // Exit dashboard
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addBook() {
    clrscr();
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    
    printf("\n=================================\n\tAdd Book in Library \n=================================\n");
    printf("Enter Title: ");
    scanf(" %[^\n]%*c", books[bookCount].title);
    printf("Enter Author: ");
    scanf(" %[^\n]%*c", books[bookCount].author);
    printf("Enter Section (e.g., novel, textbook): ");
    scanf(" %[^\n]%*c", books[bookCount].section);
    books[bookCount].bookID = bookCount + 1;
    books[bookCount].isBorrowed = 0;
    bookCount++;
    printf("Book added successfully.\n");
}

void deleteBook() {
    clrscr();
    int bookID;
    printf("\n=======================================\n\tDelete Book from Library \n=======================================\n");
    printf("Enter Book ID to delete: ");
    scanf("%d", &bookID);

    if (bookID <= 0 || bookID > bookCount) {
        printf("Invalid Book ID.\n");
        return;
    }
    
    for (int i = bookID - 1; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    bookCount--;
    printf("Book deleted successfully.\n");
}

void displayBooks() {
    clrscr();
    printf("\n=====================================\n\tList of Books in Library\n=====================================\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", books[i].bookID);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Section: %s\n", books[i].section);
        printf("Status: %s\n", books[i].isBorrowed ? "Borrowed" : "Available");
        printf("---------------------------------\n");
    }
    if (bookCount == 0) {
        printf("No books available.\n");
    }
}

void searchByTitle() {
    clrscr();
    char title[100];
    printf("\n=================================\n\tSearch by Book Title \n=================================\n");
    printf("Enter Book Title: ");
    scanf(" %[^\n]%*c", title);
    toLowercase(title);

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        char tempTitle[100];
        strcpy(tempTitle, books[i].title);
        toLowercase(tempTitle);
        if (strstr(tempTitle, title)) {
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Section: %s\n", books[i].section);
            printf("Status: %s\n", books[i].isBorrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with that title.\n");
    }
}

void searchByAuthor() {
    clrscr();
    char author[100];
    printf("\n=================================\n\tSearch by Author \n=================================\n");
    printf("Enter Author Name: ");
    scanf(" %[^\n]%*c", author);
    toLowercase(author);

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        char tempAuthor[100];
        strcpy(tempAuthor, books[i].author);
        toLowercase(tempAuthor);
        if (strstr(tempAuthor, author)) {
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Section: %s\n", books[i].section);
            printf("Status: %s\n", books[i].isBorrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by that author.\n");
    }
}

void displayBooksBySection() {
    clrscr();
    char section[50];
    printf("\n=================================\n\tSearch by Section \n=================================\n");
    printf("Enter Section (e.g., novel, textbook): ");
    scanf(" %[^\n]%*c", section);
    toLowercase(section);

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        char tempSection[50];
        strcpy(tempSection, books[i].section);
        toLowercase(tempSection);
        if (strstr(tempSection, section)) {
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Section: %s\n", books[i].section);
            printf("Status: %s\n", books[i].isBorrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found in that section.\n");
    }
}

void addBookToCart() {
    clrscr();
    int bookID;
    printf("\n=======================================\n\tAdd Book to Cart \n=======================================\n");
    printf("Enter Book ID to borrow: ");
    scanf("%d", &bookID);

    if (bookID <= 0 || bookID > bookCount) {
        printf("Invalid Book ID.\n");
        return;
    }

    if (books[bookID - 1].isBorrowed) {
        printf("Sorry, this book is already borrowed.\n");
        return;
    }

    int userIndex;
    printf("Enter your username: ");
    char username[50];
    scanf(" %[^\n]%*c", username);
    
    for (userIndex = 0; userIndex < userCount; userIndex++) {
        if (strcmp(users[userIndex].username, username) == 0) {
            break;
        }
    }

    if (userIndex == userCount) {
        printf("User not found.\n");
        return;
    }

    users[userIndex].borrowedBooks[users[userIndex].borrowedCount] = bookID;
    users[userIndex].borrowedCount++;
    books[bookID - 1].isBorrowed = 1;

    printf("Book added to your borrowed list.\n");
}

void checkAvailableBooks() {
    clrscr();
    printf("\n=====================================\n\tAvailable Books\n=====================================\n");
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isBorrowed) {
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Section: %s\n", books[i].section);
            printf("---------------------------------\n");
        }
    }
}

void saveBooksToFile() {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Error saving books data!\n");
        return;
    }
    fwrite(&bookCount, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), bookCount, file);
    fclose(file);
}

void loadBooksFromFile() {
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        return;
    }
    fread(&bookCount, sizeof(int), 1, file);
    fread(books, sizeof(Book), bookCount, file);
    fclose(file);
}

void saveUsersToFile() {
    FILE *file = fopen("users.dat", "wb");
    if (file == NULL) {
        printf("Error saving users data!\n");
        return;
    }
    fwrite(&userCount, sizeof(int), 1, file);
    fwrite(users, sizeof(User), userCount, file);
    fclose(file);
}

void loadUsersFromFile() {
    FILE *file = fopen("users.dat", "rb");
    if (file == NULL) {
        return;
    }
    
    fread(&userCount, sizeof(int), 1, file);
    fread(users, sizeof(User), userCount, file);
    fclose(file);
}

void clrscr() {
   
    system("cls"); 
    
}

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
void displayBorrowedBooks() {
    clrscr();
    printf("\n==========================\n\tBorrowed Books\n==========================\n");
    for (int i = 0; i < userCount; i++) {
        if (users[i].borrowedCount > 0) {
            printf("User: %s\n", users[i].username);
            for (int j = 0; j < users[i].borrowedCount; j++) {
                int bookID = users[i].borrowedBooks[j];
                printf("Book ID: %d | Title: %s | Author: %s\n",
                       books[bookID - 1].bookID, books[bookID - 1].title, books[bookID - 1].author);
            }
        }
    }
}
void printMainScreen() {
    printf("\n=========================================\n");
    printf("\tWelcome to Library System\n");
    printf("=========================================\n");
    printf("1- Admin Login\n");
    printf("2- User Login\n");
    printf("3- Create User Account\n");
    printf("4- Display all books\n");
    printf("5- Search books by title\n");
    printf("6- Search books by author\n");
    printf("7- Display books by section\n");
    printf("0- Exit\n");
}

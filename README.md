# Library Management System

A simple command-line Library Management System built in C.  
Designed to manage books, users, and administrators.  
This project allows users to borrow books, search for books, and manage user accounts.  
The admin can add or delete books, manage the library, and view borrowed books.

---

## Features

### Admin Features:
- Admin login with credentials.
- Add, delete, and view books.
- Search books by title, author, or section.
- View available and borrowed books.

### User Features:
- User login with credentials.
- View books in the library.
- Search books by title, author, or section.
- Add books to the borrow list (cart).
- View borrowed books.

### User Management:
- Users can create an account.
- Admin manages users.

---

## Project Structure

Library Management System  
├── books.dat                # Stores the list of books in the library.  
├── users.dat                # Stores user information.  
├── LibraryManagementSystem.c # The main C source code file for the system.  
├── README.md                # Project documentation.


# Project documentation.

---

## Requirements

- **C Compiler (GCC)**:  
  To compile and run the C code, you need a C compiler like GCC installed.
  
- **Operating System**:  
  The program has been developed and tested on Windows with Git Bash, but it should work on any operating system with appropriate adjustments for file handling.

---

## Functions Explained

### Admin Functions:
- **Admin Login**: The admin logs in using the username `admin` and password `admin123`. The admin has full access to manage books and view all borrowed books.
- **Add Book**: Admin can add new books to the library with a title, author, and section.
- **Delete Book**: Admin can delete books from the library by specifying the book ID.
- **Search by Title**: Admin can search for books by their title.
- **Search by Author**: Admin can search for books by their author.
- **Check Available Books**: View all books that are available for borrowing.
- **View Borrowed Books**: Admin can see a list of all borrowed books by users.

### User Functions:
- **User Login**: Users can log in using their credentials.
- **View Books**: Users can view all available books in the library.
- **Search by Title/Author/Section**: Users can search for books based on title, author, or section.
- **Add Book to Cart (Borrow)**: Users can add books to their borrowed list if the book is available.
- **View Borrowed Books**: Users can see a list of the books they have borrowed.

### File Handling:
- **books.dat**: Stores the details of books (title, author, section, status).
- **users.dat**: Stores the details of users (username, password, borrowed books).

---

## Example Usage

### Admin Login Example:
1. Admin Login
    ```bash
    Enter Admin username: admin
    Enter Admin password: admin123
    ```

### User Login Example:
2. User Login
    ```bash
    Enter User username: user1
    Enter User password: password123
    ```

### Adding a Book Example:
3. Adding a Book
    ```bash
    Enter Book Title: C Programming
    Enter Book Author: Brian Kernighan
    Enter Section: Programming
    ```

### Borrowing a Book Example:
4. Borrowing a Book
    ```bash
    Enter Book ID to borrow: 1
    ```

---

## Contributing

Feel free to fork this repository and submit a pull request.  
If you encounter any issues, feel free to raise them in the issues section.

---

## License

This project is open-source and available under the MIT License.

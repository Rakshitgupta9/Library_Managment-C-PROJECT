Library Managment in C
The default username and password is a7-a7



This C project is a simple Library Management System (LMS) that allows users to perform various operations such as adding books to the library, searching for books, viewing the list of books, deleting books, updating login credentials, and accessing information about the program. The system uses a binary file ("A7 Lib.bin") to store data persistently.

Here's a brief overview of the main components and functionalities:

1. **File Handling:**
   - The program uses file handling to store and retrieve information about books and login credentials.
   - The file ("A7 Lib.bin") stores details such as book ID, book name, author name, student name, and book issue date.
   - The login credentials (username and password) are stored in the file header.

2. **Data Structures:**
   - The program defines structures for handling dates, file headers, and book information.
   - The `Date` structure is used to store date information.
   - The `sFileHeader` structure contains username and password information.
   - The `s_BooksInfo` structure holds details about a book.

3. **Functions:**
   - Several functions are defined to perform specific tasks, such as printing messages, checking the validity of names, checking leap years, validating dates, adding books, searching for books, viewing books, deleting books, updating credentials, and providing information about the program.

4. **User Authentication:**
   - Users need to log in with a username and password to access the main menu of the library management system.
   - The default login credentials are set in the `init()` function.

5. **Menu-driven Interface:**
   - The main menu allows users to choose from various options, including adding books, searching, viewing, deleting, updating credentials, and accessing information about the program.

6. **About Section:**
   - The program includes an "About" section that provides information about the developer.

7. **Initialization:**
   - The `init()` function initializes the system by creating a binary file if it doesn't exist and setting default login credentials.

8. **Error Handling:**
   - The program performs basic error handling, such as checking if a file exists before attempting to open it.

9. **Looping and Exiting:**
   - The program uses loops to keep the user in the main menu until they choose to exit.

10. **Clearing the Console:**
    - The `system("cls")` function is used to clear the console screen.

11. **Security Considerations:**
    - The program requires a valid username and password for authentication, enhancing security.

It's important to note that this is a console-based application, and it serves as a basic example of a library management system implemented in the C programming language.

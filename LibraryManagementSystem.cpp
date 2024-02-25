#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int bookID;
    char title[100];
    char author[100];
};

struct Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        struct Book newBook;
        printf("Enter book ID: ");
        scanf("%d", &newBook.bookID);
        printf("Enter book title: ");
        getchar(); 
        fgets(newBook.title, sizeof(newBook.title), stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0'; 
        
        printf("Enter book author: ");
        fgets(newBook.author, sizeof(newBook.author), stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0'; 
        
        books[bookCount] = newBook;
        bookCount++;
        printf("Book added successfully.\n");
    } else {
        printf("Database full. Cannot add more books.\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the database.\n");
    } else {
        printf("Book ID\tTitle\t\tAuthor\n");
        for (int i = 0; i < bookCount; ++i) {
            printf("%d\t%s\t%s\n", books[i].bookID, books[i].title, books[i].author);
        }
    }
}

void deleteBook(int bookID) {
    int found = 0;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].bookID == bookID) {
            found = 1;
            for (int j = i; j < bookCount - 1; ++j) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book ID not found. Deletion failed.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3: {
                int bookID;
                printf("Enter book ID to delete: ");
                scanf("%d", &bookID);
                getchar(); 
                deleteBook(bookID);
                break;
            }
            case 4:
                printf("Exited Successfully...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a student
struct Student {
    char rollNumber[20];
    char name[50];
    int age;
    float marks;
};

// Function to add a new student to the database
void addStudent(struct Student *database, int *numStudents) {
    printf("Enter Roll Number: ");
    scanf("%s", database[*numStudents].rollNumber);

    printf("Enter Name: ");
    scanf("%s", database[*numStudents].name);

    printf("Enter Age: ");
    scanf("%d", &database[*numStudents].age);

    printf("Enter Marks: ");
    scanf("%f", &database[*numStudents].marks);

    (*numStudents)++;
    printf("Student added successfully!\n");
}

// Function to display all students in the database
void displayStudents(const struct Student *database, int numStudents) {
    printf("\nStudent Database:\n");
    printf("Roll Number\tName\t\tAge\tMarks\n");

    for (int i = 0; i < numStudents; i++) {
        printf("%s\t\t%s\t\t%d\t%.2f\n",database[i].rollNumber, database[i].name, database[i].age, database[i].marks);
    }
}

int main() {
    // Maximum number of students in the database
    const int maxStudents = 100;

    // Array to store student information
    struct Student studentDB[maxStudents];

    // Variable to keep track of the number of students in the database
    int numStudents = 0;

    int choice;

    do {
        // Display menu
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(studentDB, &numStudents);
                break;
            case 2:
                displayStudents(studentDB, numStudents);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
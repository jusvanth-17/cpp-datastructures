#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char Empid[20];
    char Empname[50];
    int Empage;
    float Salary;
    char Experience[20];
};

// Function to find the index of an employee by ID
int findEmployeeIndex(const struct Employee *database, int numEmployee, const char *empID) {
    for (int i = 0; i < numEmployee; i++) {
        if (strcmp(database[i].Empid, empID) == 0) {
            return i;  
        }
    }
    return -1; 
    }

void addEmployee(struct Employee *database, int *numEmployee) {
    printf("Enter Employee Id: ");
    scanf("%s", database[*numEmployee].Empid);

    printf("Enter Empname: ");
    scanf("%s", database[*numEmployee].Empname);

    printf("Enter Empage: ");
    scanf("%d", &database[*numEmployee].Empage);

    printf("Enter Salary: ");
    scanf("%f", &database[*numEmployee].Salary);
     
    printf("Enter Empexperience: ");
    scanf("%s", database[*numEmployee].Experience);

    (*numEmployee)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(const struct Employee *database, int numEmployee) {
    printf("\nEmployee Database:\n");
    printf("EmployeeId\tEmpname\t\tEmpage\t\tSalary\t\tExperience\n");

    for (int i = 0; i < numEmployee; i++) {
        printf("%s\t\t%s\t\t%d\t%.2f\t%s\n", database[i].Empid, database[i].Empname, database[i].Empage, database[i].Salary, database[i].Experience);
    }
}

void modifyEmployee(struct Employee *database, int numEmployee) {
    char empID[20];
    printf("Enter Employee ID to modify: ");
    scanf("%s", empID);

    int index = findEmployeeIndex(database, numEmployee, empID);
    if (index != -1) {
        printf("Enter new Empname: ");
        scanf("%s", database[index].Empname);

        printf("Enter new Empage: ");
        scanf("%d", &database[index].Empage);

        printf("Enter new Salary: ");
        scanf("%f", &database[index].Salary);

        printf("Enter new Empexperience: ");
        scanf("%s", database[index].Experience);

        printf("Employee details modified successfully!\n");
    } else {
        printf("Employee ID not found!\n");
    }
}

void deleteEmployee(struct Employee *database, int *numEmployee) {
    char empID[20];
    printf("Enter Employee ID to delete: ");
    scanf("%s", empID);

    int index = findEmployeeIndex(database, *numEmployee, empID);
    if (index != -1) {
        for (int i = index; i < *numEmployee - 1; i++) {
            database[i] = database[i + 1];
        }
        (*numEmployee)--;
        printf("Employee details deleted successfully!\n");
    } else {
        printf("Employee ID not found!\n");
    }
}

int main() {
    const int maxEmployee = 100;
    struct Employee EmployeeDB[maxEmployee];
    int numEmployee = 0;
    int choice;

    do {
        printf("\nEmployee Database Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Modify Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(EmployeeDB, &numEmployee);
                break;
            case 2:
                displayEmployees(EmployeeDB, numEmployee);
                break;
            case 3:
                modifyEmployee(EmployeeDB, numEmployee);
                break;
            case 4:
                deleteEmployee(EmployeeDB, &numEmployee);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

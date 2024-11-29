#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "add_employee.h"
#include "delete_employee.h"
#include "display_employees.h"
#include "update_employee.h"
#include "search_employee.h"
#include "sort_by_name.h"
#include "sort_by_department.h"
#include "sort_by_designation.h"
#include "save_and_load_file.h"

typedef enum{
    ADDEMPLOYEE=1,
    DELETEEMPLOYEE,
    DISPLAYEMPLOYEES,
    UPDATEEMPLOYEE,
    SEARCHEMPLOYEE,
    SORTEMPLOYEESBYNAME,
    SORTEMPLOYEESBYDEPARTMENT,
    SORTEMPLOYEESBYDESIGNATION,
    SAVETOFILE,
    EXIT
}menuOption;
int mainMenu() {
    Employee *employees = NULL;
    int count = 0;
    int choice = 0 , id;
    char name[50];

    const char* admin_username = "admin123";
    const char* admin_password = "123admin";
    char ad_username[20];
    char ad_password[20];
    printf("enter admin user name :");
    scanf("%s",ad_username);
    printf("enter admin password :");
    scanf("%s",ad_password);
    if (strcmp(ad_username, admin_username) == 0 && strcmp(ad_password, admin_password) == 0)
    {
        printf("Access granted. Welcome, admin!\n");




        loadFromFile(&employees, &count, "employees.csv");


        while (1) {
            printf("Employee Management System\n");
            printf("1. Add Employee\n");
            printf("2. Delete Employee\n");
            printf("3. Display Employees\n");
            printf("4. Update Employee\n");
            printf("5. Search Employee\n");
            printf("6. Sort Employees by Name\n");
            printf("7. Sort Employees by Department\n");
            printf("8. Sort Employees by Designation\n");
            printf("9. Save\n");
            printf("10.exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch ((menuOption)choice) {
            case ADDEMPLOYEE:
                addEmployee(&employees, &count);
                break;
            case DELETEEMPLOYEE:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(&employees, &count, id);
                break;
            case DISPLAYEMPLOYEES:
                displayEmployees(employees, count);
                break;
            case UPDATEEMPLOYEE:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                updateEmployee(employees, count, id);
                break;
            case SEARCHEMPLOYEE:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchEmployee(employees, count, id);
                break;
            case SORTEMPLOYEESBYNAME:
                sortEmployeesByName(employees, count);
                break;
            case SORTEMPLOYEESBYDEPARTMENT:
                sortEmployeesByDepartment(employees, count);
                break;
            case SORTEMPLOYEESBYDESIGNATION:
                sortEmployeesByDesignation(employees, count);
                break;
            case SAVETOFILE:
                saveToFile(employees, count, "employees.csv");

                break;
            case EXIT:
                free(employees);
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    else
    {
        printf("Invalid username or password. Try again!\n");
        return mainMenu();
    }
}

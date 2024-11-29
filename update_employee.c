#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "delete_employee.h"
#include "display_employees.h"
#include "update_employee.h"
typedef enum{
    NAME=1,
    AGE,
    PHONE,
    EMAIL,
    ADDRESS,
    BASICSALARY,
    HRA,
    DA,
    EXITUPDATE
}updateMenu;
void updateEmployee(Employee *employees, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            int choice;

            while (1) {
                printf("\nUpdating details for Employee ID %d:\n", id);
                printf("1. Name\n");
                printf("2. Age\n");
                printf("3. Phone\n");
                printf("4. Email\n");
                printf("5. Address\n");
                printf("6. Basic Salary\n");
                printf("7. HRA\n");
                printf("8. DA\n");
                printf("9. Exit Update Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch ((updateMenu)choice) {
                case NAME:
                    printf("Enter new name: ");
                    scanf(" %[^\n]", employees[i].name);
                    break;

                case AGE:
                    printf("Enter new age: ");
                    scanf("%d", &employees[i].age);
                    break;

                case PHONE:
                    printf("Enter new phone: ");
                    scanf(" %[^\n]", employees[i].phone);
                    break;

                case EMAIL:
                    printf("Enter new email: ");
                    scanf(" %[^\n]", employees[i].email);
                    break;

                case ADDRESS:
                    printf("Enter new address: ");
                    scanf(" %[^\n]", employees[i].address);
                    break;

                case BASICSALARY:
                    printf("Enter new basic salary: ");
                    scanf("%f", &employees[i].salary.basic_salary);

                    employees[i].salary.net_salary = employees[i].salary.basic_salary +
                                                     employees[i].salary.hra +
                                                     employees[i].salary.da;
                    break;

                case HRA:
                    printf("Enter new HRA: ");
                    scanf("%f", &employees[i].salary.hra);

                    employees[i].salary.net_salary = employees[i].salary.basic_salary +
                                                     employees[i].salary.hra +
                                                     employees[i].salary.da;
                    break;

                case DA:
                    printf("Enter new DA: ");
                    scanf("%f", &employees[i].salary.da);
                    employees[i].salary.net_salary = employees[i].salary.basic_salary +
                                                     employees[i].salary.hra +
                                                     employees[i].salary.da;
                    break;

                case EXITUPDATE:
                    printf("Exiting update menu.\n");
                    return;

                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
                }

                printf("Field updated successfully!\n");
            }
        }
    }

    printf("Employee with ID %d not found.\n", id);
}


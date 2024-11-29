#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "delete_employee.h"
#include "display_employees.h"
void displayEmployees(Employee *employees, int count) {
    printf("Employee List:");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d  \nName: %s  \nage: %d  \nphone: %s  \nemail: %s  \nDepartment: %s  \nDesignation: %s  \nteam: %s  \nproject:%s  \nNet Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].age, employees[i].phone, employees[i].email, employees[i].department.name, employees[i].designation.name, employees[i].team.name, employees[i].project.name, employees[i].salary.net_salary);
    }
}

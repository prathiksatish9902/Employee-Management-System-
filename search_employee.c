#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "delete_employee.h"
#include "display_employees.h"
#include "update_employee.h"
#include "search_employee.h"

void searchEmployee(Employee *employees, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Employee Found: ID: %d, Name: %s, Department: %s, Designation: %s\n",
                   employees[i].id, employees[i].name, employees[i].department.name, employees[i].designation.name);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

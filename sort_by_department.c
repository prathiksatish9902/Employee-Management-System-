#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "delete_employee.h"
#include "display_employees.h"
#include "update_employee.h"
#include "search_employee.h"
#include "sort_by_name.h"
#include "sort_by_department.h"
void sortEmployeesByDepartment(Employee *employees, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(employees[i].department.name, employees[j].department.name) > 0) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    printf("Employees sorted by department.\n");
}

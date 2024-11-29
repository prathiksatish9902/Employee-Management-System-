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
#include "sort_by_designation.h"



void sortEmployeesByDesignation(Employee *employees, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (get_designation_level(employees[i].designation.name) <
                get_designation_level(employees[j].designation.name)) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    printf("Employees sorted by designation hierarchy.\n");
}

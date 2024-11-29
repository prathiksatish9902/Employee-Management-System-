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
#include "save_and_load_file.h"

void saveToFile(Employee *employees, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%f,%f,%f,%f,%s,%d,%s,%d,%s,%d\n",
                employees[i].id, employees[i].name, employees[i].designation.name, employees[i].phone,
                employees[i].email, employees[i].salary.basic_salary, employees[i].salary.hra,
                employees[i].salary.da, employees[i].salary.net_salary, employees[i].department.name,
                employees[i].department.id, employees[i].team.name, employees[i].team.id,
                employees[i].project.name, employees[i].project.id);
    }

    fclose(file);
    printf("Data saved successfully.\n");
}
void loadFromFile(Employee **employees, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for reading");
        return;
    }

    *count = 0;
    while (!feof(file)) {
        Employee temp;
        if (fscanf(file, "%d,%49[^,],%49[^,],%14[^,],%49[^,],%f,%f,%f,%f,%49[^,],%d,%49[^,],%d,%49[^,],%d\n",
                   &temp.id, temp.name, temp.designation.name, temp.phone, temp.email,
                   &temp.salary.basic_salary, &temp.salary.hra, &temp.salary.da, &temp.salary.net_salary,
                   temp.department.name, &temp.department.id, temp.team.name, &temp.team.id,
                   temp.project.name, &temp.project.id) == 15) {
            *employees = realloc(*employees, (*count + 1) * sizeof(Employee));
            (*employees)[*count] = temp;
            (*count)++;
        }
    }

    fclose(file);
    printf("Data loaded successfully.\n");
}



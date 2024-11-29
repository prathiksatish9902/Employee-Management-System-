#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "add_employee.h"
const char *designations[] = {
    "Intern",
    "Junior Developer",
    "Developer",
    "Senior Developer",
    "Team Lead",
    "Manager",
    "Director",
    "Vice President",
    "CEO"
};
const int designation_count = 9;


int get_designation_level(const char *designation) {
    for (int i = 0; i < designation_count; i++) {
        if (strcmp(designations[i], designation) == 0) {
            return i;
        }
    }
    return -1;
}
void addEmployee(Employee **employees, int *count) {
    *employees = realloc(*employees, (*count + 1) * sizeof(Employee));
    Employee *new_employee = &(*employees)[*count];

    printf("Enter employee details:\n");
    printf("Name: ");
    scanf(" %[^\n]", new_employee->name);
    printf("Age: ");
    scanf("%d", &new_employee->age);
    printf("Phone: ");
    scanf(" %[^\n]", new_employee->phone);
    printf("Email: ");
    scanf(" %[^\n]", new_employee->email);
    printf("Address: ");
    scanf(" %[^\n]", new_employee->address);
    printf("ID: ");
    scanf(" %d", &new_employee->id);
    printf("Join Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", new_employee->join_date);
    printf("Choose Designation:\n");
    for (int i = 0; i < designation_count; i++) {
        printf("%d. %s\n", i + 1, designations[i]);
    }
    int designation_choice;
    scanf("%d", &designation_choice);
    if (designation_choice < 1 || designation_choice > designation_count) {
        printf("Invalid choice. Defaulting to 'Intern'.\n");
        strcpy(new_employee->designation.name, "Intern");
    } else {
        strcpy(new_employee->designation.name, designations[designation_choice - 1]);
    }
    printf("Basic Salary: ");
    scanf("%f", &new_employee->salary.basic_salary);
    printf("HRA: ");
    scanf("%f", &new_employee->salary.hra);
    printf("DA: ");
    scanf("%f", &new_employee->salary.da);
    new_employee->salary.net_salary = new_employee->salary.basic_salary + new_employee->salary.hra + new_employee->salary.da;
    printf("Department Name: ");
    scanf(" %[^\n]", new_employee->department.name);
    printf("Department ID: ");
    scanf("%d", &new_employee->department.id);
    printf("Team Name: ");
    scanf(" %[^\n]", new_employee->team.name);
    printf("Team ID: ");
    scanf("%d", &new_employee->team.id);
    printf("Project Name: ");
    scanf(" %[^\n]", new_employee->project.name);
    printf("Project ID: ");
    scanf("%d", &new_employee->project.id);

    (*count)++;
    printf("Employee added successfully!\n");
}

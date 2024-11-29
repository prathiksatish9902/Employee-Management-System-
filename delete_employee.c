#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "delete_employee.h"

void deleteEmployee(Employee **employees, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if ((*employees)[i].id == id)  {
            for (int j = i; j < *count - 1; j++) {
                (*employees)[j] = (*employees)[j + 1];
            }
            (*count)--;
            *employees = realloc(*employees, (*count) * sizeof(Employee));
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

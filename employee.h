#ifndef EMPLOYEE_H
#define EMPLOYEE_H
typedef struct {
    char name[50];
} Designation;

typedef struct {
    float basic_salary;
    float hra;
    float da;
    float net_salary;
} Salary;

typedef struct {
    char name[50];
    int id;
} Department;

typedef struct {
    char name[50];
    int id;
} Team;

typedef struct {
    char name[50];
    int id;
} Project;

typedef struct {
    char name[50];
    int age;
    char phone[15];
    char email[50];
    char address[100];
    int id;
    char join_date[15];
    Designation designation;
    Salary salary;
    Department department;
    Team team;
    Project project;
} Employee;
#endif // EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMPLOYEES 100

typedef struct DataOfficial {
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char sex[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
} DataOfficial;

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

void outputDataOfficial(DataOfficial d, Date date) {
    printf("%s, %s, %s, %s, %d/%d/%d\n", d.surname, d.name, d.sex, d.position, date.day, date.month, date.year);
}

int inputDate(Date* d) {
    printf("Enter day, month, year: ");
    if (scanf("%d %d %d", &d->day, &d->month, &d->year) != 3) {
        printf("Invalid input.\n");
        return 1;
    }
    if (d->day < 1 || d->day > 31 || d->month < 1 || d->month > 12 || d->year < 1) {
        printf("Date out of range.\n");
        return 1;
    }
    return 0;
}

void inputDataOfficial(DataOfficial *d) {
    printf("Enter last name: ");
    scanf("%s", d->surname);

    printf("Enter name: ");
    scanf("%s", d->name);

    while (1) {
        printf("Enter sex (woman/man): ");
        scanf("%s", d->sex);

        if (strcmp(d->sex, "woman") == 0 || strcmp(d->sex, "man") == 0) {
            break;
        } else {
            printf("Invalid input. Please enter 'woman' or 'man'.\n");
        }
    }

    printf("Enter the position of the employee: ");
    scanf("%s", d->position);
}

void findMostCommonPosition(DataOfficial employees[], int n) {
    int max_count = 0;
    char most_common_position[MAX_NAME_LENGTH] = "";
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(employees[i].position, employees[j].position) == 0) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            strcpy(most_common_position, employees[i].position);
        }
    }

    if (max_count > 0) {
        printf("Position with the most employees: %s (count: %d)\n", most_common_position, max_count);
    } else {
        printf("No positions found.\n");
    }
}

void findEmployeesWithSameName(DataOfficial employees[], Date birthdates[], int n) {
    bool found = false;
    bool *checked = calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++) {
        if (checked[i]) {
            continue;
        }

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(employees[i].name, employees[j].name) == 0) {
                count++;
                checked[j] = true;
            }
        }

        if (count > 1) {
            printf("Employees with the name %s:\n", employees[i].name);
            for (int j = 0; j < n; j++) {
                if (strcmp(employees[i].name, employees[j].name) == 0) {
                    outputDataOfficial(employees[j], birthdates[j]);
                }
            }
            found = true;
        }
    }

    free(checked);
    if (!found) {
        printf("No employees with the same name found.\n");
    }
}

void findEmployeesBySurnameLetter(DataOfficial employees[], Date birthdates[], int n, char letter) {
    bool found = false;
    letter = tolower(letter); // щоб не важливо було мала чи велика літера
    printf("Employees with surnames starting with '%c':\n", letter);
    for (int i = 0; i < n; i++) {
        if (tolower(employees[i].surname[0]) == letter) {
            outputDataOfficial(employees[i], birthdates[i]);
            found = true;
        }
    }
    if (!found) {
        printf("No employees found with surnames starting with '%c'.\n", letter);
    }
}

int main() {
    DataOfficial employees[MAX_EMPLOYEES];
    Date birthdates[MAX_EMPLOYEES];
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for employee %d:\n", i + 1);
        inputDataOfficial(&employees[i]);

        printf("Enter birth date:\n");
        if (inputDate(&birthdates[i]) != 0) {
            printf("Failed to input date.\n");
            return 1;
        }
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        outputDataOfficial(employees[i], birthdates[i]);
    }

    printf("\n--- Analysis ---\n");
    findMostCommonPosition(employees, n);
    findEmployeesWithSameName(employees, birthdates, n);

    char letter;
    printf("\nEnter the first letter of the surname to search: ");
    scanf(" %c", &letter);
    findEmployeesBySurnameLetter(employees, birthdates, n, letter);
}

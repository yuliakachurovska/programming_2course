#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100

typedef struct Adress {
    char city[MAX_NAME_LENGTH];
    char street[MAX_NAME_LENGTH];
    int number; // номер будинку
    int apt;    // номер квартири
} Adress;

void outputAdress(Adress data) {
    printf("%s, %s, %d, %d\n", data.city, data.street, data.number, data.apt);
}

void inputAdress(Adress *data) {
    printf("Enter the name of the city: ");
    fgets(data->city, MAX_NAME_LENGTH, stdin); //деякі назви міст чи вулиць містять два слова, тому так
    data->city[strcspn(data->city, "\n")] = '\0';

    printf("Enter the name of the street: ");
    fgets(data->street, MAX_NAME_LENGTH, stdin);
    data->street[strcspn(data->street, "\n")] = '\0';

    printf("Enter the house number: ");
    scanf("%d", &data->number);

    printf("Enter the apartment: ");
    scanf("%d", &data->apt);
}

int main() {
    Adress data;
    inputAdress(&data);
    outputAdress(data);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    double price;
    int minAge;
    int maxAge;
} Toy;

void searchConstructor(const char *inputFile, const char *outputFile, double price, int minAge) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    if (!inFile || !outFile) {
        perror("Failed to open file");
        if (inFile) fclose(inFile);
        if (outFile) fclose(outFile);
        return;
    }

    Toy toy;
    bool found = false;

    while (fscanf(inFile, "%49s %lf %d %d", toy.name, &toy.price, &toy.minAge, &toy.maxAge) == 4) {
        if (strcmp(toy.name, "constructor") == 0 &&
            toy.price == price &&
            toy.minAge >= minAge && toy.maxAge <= 12) {
            printf("Found toy: %s, price: %.2f, age: %d-%d\n", toy.name, toy.price, toy.minAge, toy.maxAge);
            fprintf(outFile, "%s %.2f %d %d\n", toy.name, toy.price, toy.minAge, toy.maxAge);
            found = true;
        }
    }

    if (!found) {
        printf("No constructor toy matching the criteria was found.\n");
        fprintf(outFile, "No constructor toy matching the criteria was found.\n");
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    const char *inputFile = "toys.txt";
    const char *outputFile = "result.txt";

    Toy toys[] = {
        {"ball", 150.0, 3, 8},
        {"doll", 200.0, 4, 10},
        {"constructor", 250.0, 6, 12},
        {"constructor", 300.0, 8, 12}
    };

    FILE *file = fopen(inputFile, "w");
    if (!file) {
        perror("Failed to create file");
    }
    for (int i = 0; i < sizeof(toys) / sizeof(toys[0]); i++) {
        fprintf(file, "%s %.2f %d %d\n", toys[i].name, toys[i].price, toys[i].minAge, toys[i].maxAge);
    }
    fclose(file);

    double searchPrice = 250.0;
    int searchMinAge = 6;
    searchConstructor(inputFile, outputFile, searchPrice, searchMinAge);
}

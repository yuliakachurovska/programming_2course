#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkEqualPositiveNegative(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return false;
    }

    int num, positiveCount = 0, negativeCount = 0;

    while (fscanf(file, "%d", &num) == 1) {
        if (num > 0)
            positiveCount++;
        else if (num < 0)
            negativeCount++;
    }

    fclose(file);
    return positiveCount == negativeCount;
}

void createAlternatingSigns(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    if (!inFile || !outFile) {
        perror("Failed to open file");
        if (inFile) fclose(inFile);
        if (outFile) fclose(outFile);
        return;
    }

    int positives[1000], negatives[1000];
    int posCount = 0, negCount = 0, num;

    while (fscanf(inFile, "%d", &num) == 1) {
        if (num > 0)
            positives[posCount++] = num;
        else if (num < 0)
            negatives[negCount++] = num;
    }
    fclose(inFile);

    int i = 0, j = 0;
    while (i < posCount || j < negCount) {
        if (i < posCount) {
            fprintf(outFile, "%d ", positives[i++]);
        }
        if (j < negCount) {
            fprintf(outFile, "%d ", negatives[j++]);
        }
    }
    fclose(outFile);
}

int main() {
    const char *fileF = "F.txt";
    const char *fileH = "H.txt";
    const char *fileG = "G.txt";

    if (!checkEqualPositiveNegative(fileF)) {
        printf("Data error in the file.\n");
    }

    FILE *inFile = fopen(fileF, "r");
    FILE *tempFile = fopen(fileH, "w");
    if (!inFile || !tempFile) {
        perror("Failed to open file");
        if (inFile) fclose(inFile);
        if (tempFile) fclose(tempFile);
    }

    int num;
    while (fscanf(inFile, "%d", &num) == 1) {
        fprintf(tempFile, "%d ", num);
    }

    fclose(inFile);
    fclose(tempFile);
    createAlternatingSigns(fileH, fileG);
    printf("File %s has been successfully created.\n", fileG);
}

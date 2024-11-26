#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_palindrome(int num) {
    if (num < 0) return false;
    int reversed = 0, original = num;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

void create_file_f(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int num;
    printf("Enter integers (0 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

void build_file_g(const char *file_f, const char *file_g) {
    FILE *file_in = fopen(file_f, "r");
    FILE *file_out = fopen(file_g, "w");
    if (file_in == NULL || file_out == NULL) {
        printf("Error opening file!\n");
        if (file_in) fclose(file_in);
        if (file_out) fclose(file_out);
        return;
    }

    int num;
    while (fscanf(file_in, "%d", &num) == 1) {
        if (is_palindrome(num)) {
            fprintf(file_out, "%d\n", num);
        }
    }

    fclose(file_in);
    fclose(file_out);
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'!\n", filename);
        return;
    }

    int num;
    printf("Contents of '%s':\n", filename);
    while (fscanf(file, "%d", &num) == 1) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}

int main() {
    const char *file_f = "F_3.txt";
    const char *file_g = "G_3.txt";
    create_file_f(file_f);
    build_file_g(file_f, file_g);
    print_file(file_f);
    print_file(file_g);
}
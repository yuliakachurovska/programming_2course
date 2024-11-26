#include <stdio.h>
#include <stdlib.h>
#include<math.h>

//task1
void input_arr(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &arr[i]);
    }
}

void write_arr_to_file(const char *filename, double arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2lf", arr[i]);
        if (i < n - 1) {
            fprintf(file, ", ");
        }
    }

    fclose(file);
}

void read_arr_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void task1() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    input_arr(arr, n);
    const char *filename = "name.txt";
    write_arr_to_file(filename, arr, n);
    printf("Array saved to file.\nReading from file:\n");
    read_arr_from_file(filename);
    free(arr);
}

//task2
void write_arr_to_file2(const char *filename, double arr[], int n, int a) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2lf", arr[i]);
        if (i < n - 1) {
            if(fabs(arr[i]) < a){ ///
                fprintf(file, ", ");
                }
        }
    }

    fclose(file);
}


int read_arr_from_file2(const char *filename, double arr[], int max_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    int i = 0;
    while (fscanf(file, "%lf,", &arr[i]) == 1 && i < max_size) {
        i++;
    }

    fclose(file);
    return i;
}

void task2() {
    int n, a;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter a>0: ");
    scanf("%d", &a);

    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    input_arr(arr, n);
    const char *filename1 = "name1.txt";
    write_arr_to_file(filename1, arr, n);

    double *read_arr = (double *)malloc(n * sizeof(double));
    if (read_arr == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        return;
    }

    int read_count = read_arr_from_file2(filename1, read_arr, n);
    if (read_count == -1) {
        free(arr);
        free(read_arr);
        return;
    }

    const char *filename2 = "name2.txt";
    write_arr_to_file2(filename2, read_arr, read_count, a);

    printf("Array saved to '%s' and read from '%s', then written to '%s'.\n", filename1, filename1, filename2);

    read_arr_from_file(filename2);
    free(arr);
    free(read_arr);

}

int main() {
    task1();
    task2();
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>     

double calculate_area(double x1, double y1, double x2, double y2) {
    return fabs((x2 - x1) * (y2 - y1));
}

void find_largest_rectangle(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int max_id = -1, id;
    double x1, y1, x2, y2;
    double max_area = 0;

    while (fscanf(file, "%d %lf %lf %lf %lf", &id, &x1, &y1, &x2, &y2) == 5) {
        double area = calculate_area(x1, y1, x2, y2);
        if (area > max_area) {
            max_area = area;
            max_id = id;
        }
    }
    fclose(file);
    printf("Rectangle with largest area: ID = %d, Area = %.2lf\n", max_id, max_area);
}

void delete_rectangle(const char *filename, int target_id) {
    FILE *file = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    double x1, y1, x2, y2;
    while (fscanf(file, "%d %lf %lf %lf %lf", &id, &x1, &y1, &x2, &y2) == 5) {
        if (id != target_id) {
            fprintf(temp, "%d %.2lf %.2lf %.2lf %.2lf\n", id, x1, y1, x2, y2);
        }
    }
    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.txt", filename);
}


void replace_rectangle(const char *filename, int target_id, int new_id, double new_x1, double new_y1, double new_x2, double new_y2) {
    FILE *file = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int id;
    double x1, y1, x2, y2;
    while (fscanf(file, "%d %lf %lf %lf %lf", &id, &x1, &y1, &x2, &y2) == 5) {
        if (id == target_id) {
            fprintf(temp, "%d %.2lf %.2lf %.2lf %.2lf\n", new_id, new_x1, new_y1, new_x2, new_y2);
        } else {
            fprintf(temp, "%d %.2lf %.2lf %.2lf %.2lf\n", id, x1, y1, x2, y2);
        }
    }
    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.txt", filename);
}

int main() {
    const char *filename = "rectangles.txt";

    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "1 0 10 10 0\n");
        fprintf(file, "2 2 8 8 2\n");
        fprintf(file, "3 5 6 7 4\n");
        fclose(file);
    }

    printf("Finding rectangle with largest area:\n");
    find_largest_rectangle(filename);

    printf("\nDeleting rectangle with ID = 2:\n");
    delete_rectangle(filename, 2);
    printf("Contents of file after deletion:\n");
    find_largest_rectangle(filename);

    printf("\nReplacing rectangle with ID = 3:\n");
    replace_rectangle(filename, 3, 4, 1, 1, 9, 9);
    printf("Contents of file after replacement:\n");
    find_largest_rectangle(filename);
}

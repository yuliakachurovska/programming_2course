#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define MAX_NAME_LENGTH 100

// 1_а
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

void outputDate(Date d) {
    printf("%d/%d/%d\n", d.day, d.month, d.year);
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

// 1_б
typedef struct Chess_board {
    char vertical;  // літера ('a'-'h')
    unsigned char horisontal;  // цифра (1-8)
} Chess_board;

void output_cell(Chess_board c) {
    printf("%c%d\n", c.vertical, c.horisontal);
}

int input_cell(Chess_board* c) {
    printf("Enter vertical (a-h): ");
    scanf(" %c", &c->vertical);
    printf("Enter horisontal (1-8): ");
    if (scanf("%hhu", &c->horisontal) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if ((c->vertical >= 'a' && c->vertical <= 'h') || (c->vertical >= 'A' && c->vertical <= 'H')) {
        if (c->horisontal >= 1 && c->horisontal <= 8) {
            return 0;
        }
    }
    printf("Cell out of range.\n");
    return 1;
}

// 1_в
typedef struct Vertex {
    long double x;
    long double y;
} Vertex;

void outputVertex(Vertex v) {
    printf("%Lg %Lg\n", v.x, v.y);
}

Vertex inputVertex() {
    Vertex res;
    printf("Enter x, y: ");
    scanf("%Lf %Lf", &res.x, &res.y);
    return res;
}

typedef struct Rectangle {
    Vertex v1;
    Vertex v2;
} Rectangle;

void outputRectangle(const Rectangle* r) {
    outputVertex(r->v1);
    printf("\t");
    outputVertex(r->v2);
}

int inputRectangle(Rectangle* r) {
    printf("Enter first vertex:\n");
    r->v1 = inputVertex();
    printf("Enter second vertex:\n");
    r->v2 = inputVertex();
    return 0;
}

// 1_г
typedef struct Poly {
    unsigned n;
    double* a;
} Poly;

void outputPoly(Poly p) {
    for (int i = 0; i < p.n; i++) {
        printf("%lf*x^%d + ", p.a[i], i);
    }
    printf("%lf*x^%d\n", p.a[p.n], p.n);
}

int inputPoly(Poly* p) {
    printf("Enter degree (n): ");
    if (scanf("%u", &p->n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    p->a = (double*) calloc(p->n + 1, sizeof(double));
    if (!p->a) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i <= p->n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%lf", &p->a[i]) != 1) {
            printf("Invalid input.\n");
            free(p->a);
            return 1;
        }
    }
    return 0;
}

void deletePoly(Poly* p) {
    if (p->a) {
        free(p->a);
        p->a = NULL;
    }
}

//2
bool hitQueen(Chess_board f1, Chess_board f2) {
    return (f1.horisontal == f2.horisontal) ||
           (f1.vertical == f2.vertical) ||
           (abs(f1.vertical - f2.vertical) == abs(f1.horisontal - f2.horisontal));
}

void task2(){
    Chess_board cell1, cell2;
    printf("Input the 1 cell:\n");
    input_cell(&cell1);
    printf("Input the 2 cell:\n");
    input_cell(&cell2);
    output_cell(cell1);
    output_cell(cell2);
    if (hitQueen(cell1, cell2)) {
        printf("The queen can move in one move. \n");
    } else {
        printf("The queen cannot move in one move. \n");
    }
}

//3
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

Date nextDay(Date d) {
    Date next = d;
    next.day++;
    if (next.day > daysInMonth(d.month, d.year)) {
        next.day = 1;
        next.month++;
        if (next.month > 12) {
            next.month = 1;
            next.year++;
        }
    }
    return next;
}

int dayOfWeek(Date d) {
    int m = d.month, y = d.year;
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int dayOfWeek = (d.day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (dayOfWeek + 5) % 7;
}

const char* getDayOfWeekName(int dayOfWeek) {
    const char* days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    return days[dayOfWeek];
}

void task3(){
    Date today;
    printf("Enter day, month, year: ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);
    Date tomorrow = nextDay(today);
    printf("Tomorrow: %d/%d/%d\n", tomorrow.day, tomorrow.month, tomorrow.year);
    int dow = dayOfWeek(today);
    printf("Day of the week: %s\n", getDayOfWeekName(dow));

}

//5
typedef struct {
    char name[MAX_NAME_LENGTH];
    int height;
} Mountain;

Mountain highest(const Mountain* m, int n) {
    Mountain highest_mountain = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i].height > highest_mountain.height) {
            highest_mountain = m[i];
        }
    }
    return highest_mountain;
}

void task5() {
    int n;

    printf("Enter the number of mountains: \n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of mountains must be a positive integer.\n");
        return;
    }

    Mountain mountains[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the name of mountain %d: \n", i + 1);
        scanf("%s", mountains[i].name);
        printf("Enter the height of mountain %d (in meters): \n", i + 1);
        scanf("%d", &mountains[i].height);
    }

    Mountain highest_mountain = highest(mountains, n);
    printf("The highest mountain is %s with a height of %d meters.\n", highest_mountain.name, highest_mountain.height);
}

int main() {
    Date d;
    if (!inputDate(&d)) {
        outputDate(d);
    }

    Chess_board cell;
    if (!input_cell(&cell)) {
        output_cell(cell);
    }

    Rectangle rect;
    if (!inputRectangle(&rect)) {
        outputRectangle(&rect);
    }

    Poly poly;
    if (!inputPoly(&poly)) {
        outputPoly(poly);
        deletePoly(&poly);
    }
    task2();
    task3();
    task5();
}

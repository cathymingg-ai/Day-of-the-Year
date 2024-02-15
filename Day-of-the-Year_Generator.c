// Calculating the Day of the Year (Struct)

#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int daysPassedInYear(struct Date date) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    for (int i = 1; i < date.month; i++) {
        days += daysInMonth[i];
        if (i == 2 && isLeapYear(date.year)) {
            days++;
        }
    }

    days += date.day;

    return days;
}

void getUserInput(struct Date *date) {
    printf("Enter date in the format (month/day/year): ");
    if (scanf("%d/%d/%d", &date->month, &date->day, &date->year) != 3) {
        printf("Invalid input format. Please try again.\n");
    } // if user enters invalid input, the program will return an error message
}

int main() {
    struct Date inputDate;
    getUserInput(&inputDate);

    if (inputDate.month < 1 || inputDate.month > 12) {
        printf("Invalid month. Please enter a valid month (1-12).\n");
        return 1;
    }

    int days = daysPassedInYear(inputDate);
    if (days > 0) {
        printf("Day of the year: %d\n", days);
    } else {
        printf("Invalid day. Please enter a valid day.\n");
    }

    return 0;
}
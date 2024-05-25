/**
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>

using namespace std;

template<typename T>
void printl(const T &item) {
    std::cout << item << std::endl;
}

template<typename T>
auto get_value(const std::string &message) -> T {
    std::cout << message;
    T value;
    std::cin >> value;
    cin.ignore();
    return value;
}

static bool is_leap_year(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int days_in_month(const int month, const int year) {
    switch (month) {
        case 2: {
            return is_leap_year(year) ? 29 : 28;
        }
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            return 31;
        }
        default:
            return 30;
    }
}

int main() {
year_input:
    const auto year = get_value<int>("Type the year: ");
    if (year < 10) {
        printl("You must type a number equal or greater than 10. Please try again.");
        goto year_input;
    }

month_input:
    const auto month_number = get_value<int>("Type the month (1-12): ");
    if (month_number < 1 || 12 < month_number) {
        printl("You must type a number between 1 & 12. Please try again.");
        goto month_input;
    }

    const int maximum_day_number = days_in_month(month_number, year);

day_input:
    const auto day_number = get_value<int>("Type the day (1-" + to_string(maximum_day_number) + "): ");
    if (day_number < 1 || maximum_day_number < day_number) {
        printl("You must type a number between 1 & " + to_string(maximum_day_number) + ". Please try again.");
        goto day_input;
    }

    const bool is_magic_date = day_number * month_number == year % 100;

    printl("The date is " + static_cast<string>(is_magic_date ? "" : "not ") + "magic.");

    return 0;
}

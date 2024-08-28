#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

struct ISODate {
    int year;
    int month;
    int day;
};

// Convert ISO date string to ISODate structure
ISODate parseISODate(const std::string& isoDate) {
    ISODate date;
    if (sscanf(isoDate.c_str(), "%d-%d-%d", &date.year, &date.month,
               &date.day) != 3) {
        // Handle invalid date format
        std::cerr << "Invalid ISO date format: " << isoDate << std::endl;
        exit(1);
    }
    return date;
}

// Convert ISODate structure to ISO date string
std::string formatISODate(const ISODate& date) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", date.year, date.month,
             date.day);
    return std::string(buffer);
}

// Check if a date is between two dates
// bool isDateBetween(const ISODate& date, const ISODate& start,
//                    const ISODate& end) {
//     return date >= start && date <= end;
// }

// Get the current date
ISODate getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&time_t);
    ISODate date;
    date.year = tm.tm_year + 1900;
    date.month = tm.tm_mon + 1;
    date.day = tm.tm_mday;
    return date;
}

int main() {
    // Parse ISO date strings
    std::string startDateStr = "2023-01-01";
    std::string endDateStr = "2023-12-31";
    ISODate startDate = parseISODate(startDateStr);
    ISODate endDate = parseISODate(endDateStr);

    // Check if a date is between two dates
    std::string checkDateStr = "2023-06-15";
    ISODate checkDate = parseISODate(checkDateStr);
    // if (isDateBetween(checkDate, startDate, endDate)) {
    //     std::cout << checkDateStr << " is between " << startDateStr << " and
    //     "
    //               << endDateStr << std::endl;
    // } else {
    //     std::cout << checkDateStr << " is not between " << startDateStr
    //               << " and " << endDateStr << std::endl;
    // }

    // Get the current date
    ISODate currentDate = getCurrentDate();
    std::cout << "Current date: " << formatISODate(currentDate) << std::endl;

    return 0;
}
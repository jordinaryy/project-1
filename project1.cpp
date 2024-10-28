#include <iostream>
using namespace std;

// A simple Clock class to manage and display time
class Clock {
private:
    int hours;   // Stores the hour part of the time
    int minutes; // Stores the minute part of the time
    int seconds; // Stores the second part of the time

public:
    // Constructor to initialize the time (hours, minutes, seconds)
    Clock(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Method to set the time (hours, minutes, seconds)
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Method to display time in 12-hour format (with AM/PM)
    void display12HourFormat() const {
        int displayHours = hours % 12; // Convert 24-hour to 12-hour format
        if (displayHours == 0) displayHours = 12; // Fix for 12 AM/PM cases
        string period = (hours >= 12) ? "PM" : "AM"; // Set AM or PM

        // Display the time in 12-hour format with AM/PM
        cout << "12-Hour Format: " << displayHours << ":" 
             << (minutes < 10 ? "0" : "") << minutes << ":"  // Add leading zero for minutes
             << (seconds < 10 ? "0" : "") << seconds << " " 
             << period << endl;
    }

    // Method to display time in 24-hour format (military time)
    void display24HourFormat() const {
        // Display the time in 24-hour format
        cout << "24-Hour Format: " << (hours < 10 ? "0" : "") << hours << ":"  // Add leading zero for hours
             << (minutes < 10 ? "0" : "") << minutes << ":"  // Add leading zero for minutes
             << (seconds < 10 ? "0" : "") << seconds << endl; // Add leading zero for seconds
    }
};

int main() {
    // Create a clock object with the initial time set to 14:30:45 (2:30:45 PM)
    Clock clock(14, 30, 45);

    // Display the initial time in both formats
    cout << "Initial Time:" << endl;
    clock.display12HourFormat(); // Show 12-hour format
    clock.display24HourFormat(); // Show 24-hour format

    // Ask the user to input new time (hours, minutes, and seconds)
    int h, m, s;
    cout << "Enter new time (hours, minutes, seconds): ";
    cin >> h >> m >> s;

    // Set the clock to the new time
    clock.setTime(h, m, s);

    // Display the updated time in both formats
    cout << "Updated Time:" << endl;
    clock.display12HourFormat(); // Show updated 12-hour format
    clock.display24HourFormat(); // Show updated 24-hour format

    return 0;
}
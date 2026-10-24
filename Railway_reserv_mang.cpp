#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Reservation {
private:
    int bookingID;
    string passengerName;
    int age;
    string source;
    string destination;
    int seats;

public:
    Reservation(int id, string name, int a,
                string src, string dest, int s) {
        bookingID = id;
        passengerName = name;
        age = a;
        source = src;
        destination = dest;
        seats = s;
    }

    int getBookingID() const {
        return bookingID;
    }

    int getSeats() const {
        return seats;
    }

    void display() const {
        cout << "\nBooking ID   : " << bookingID;
        cout << "\nPassenger    : " << passengerName;
        cout << "\nAge          : " << age;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nSeats Booked : " << seats;
        cout << "\n-------------------------------\n";
    }
};

class RailwaySystem {
private:
    vector<Reservation> reservations;
    int totalSeats;
    int nextBookingID;

public:
    RailwaySystem(int capacity) {
        totalSeats = capacity;
        nextBookingID = 1001;
    }

    void bookTicket() {
        string name, source, destination;
        int age, seats;

        cout << "Enter passenger name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;

        if (age < 1 || age > 120) {
            cout << "Invalid age!\n";
            return;
        }

        cout << "Enter source station: ";
        cin >> ws;
        getline(cin, source);

        cout << "Enter destination station: ";
        getline(cin, destination);

        if (source == destination) {
            cout << "Source and destination must differ!\n";
            return;
        }

        cout << "Enter number of seats: ";
        cin >> seats;

        if (seats <= 0) {
            cout << "Invalid seat count!\n";
            return;
        }

        if (seats > totalSeats) {
            cout << "Not enough seats available!\n";
            return;
        }

        reservations.emplace_back(
            nextBookingID, name, age,
            source, destination, seats
        );

        cout << "\nTicket booked successfully!\n";
        cout << "Your booking ID is: "
             << nextBookingID << endl;

        nextBookingID++;
        totalSeats -= seats;
    }

    void displayAll() const {
        if (reservations.empty()) {
            cout << "No reservations found!\n";
            return;
        }

        for (const Reservation& r : reservations) {
            r.display();
        }
    }

    void searchTicket() const {
        int id;
        cout << "Enter booking ID: ";
        cin >> id;

        for (const Reservation& r : reservations) {
            if (r.getBookingID() == id) {
                r.display();
                return;
            }
        }

        cout << "Reservation not found!\n";
    }

    void cancelTicket() {
        int id;
        cout << "Enter booking ID to cancel: ";
        cin >> id;

        for (int i = 0; i < (int)reservations.size(); i++) {
            if (reservations[i].getBookingID() == id) {
                totalSeats += reservations[i].getSeats();

                cout << "Reservation cancelled successfully!\n";
                reservations.erase(reservations.begin() + i);
                return;
            }
        }

        cout << "Reservation not found!\n";
    }

    void showAvailableSeats() const {
        cout << "Available seats: " << totalSeats << endl;
    }
};

int main() {
    RailwaySystem railway(50);
    int choice;

    do {
        cout << "\n===== RAILWAY RESERVATION SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Display All Reservations\n";
        cout << "3. Search Ticket\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Check Available Seats\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            railway.bookTicket();
            break;

        case 2:
            railway.displayAll();
            break;

        case 3:
            railway.searchTicket();
            break;

        case 4:
            railway.cancelTicket();
            break;

        case 5:
            railway.showAvailableSeats();
            break;

        case 6:
            cout << "Thank you for using the railway system!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

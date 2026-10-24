
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Customer {
private:
    int customerID;
    string name;
    int units;
    double bill;

public:
    Customer(int id, string n, int u) {
        customerID = id;
        name = n;
        units = u;
        bill = calculateBill();
    }

    double calculateBill() const {
        double amount = 0;

        // Illustrative domestic tariff
        if (units <= 100) {
            amount = units * 1.50;
        }
        else if (units <= 200) {
            amount = 100 * 1.50
                   + (units - 100) * 2.50;
        }
        else if (units <= 300) {
            amount = 100 * 1.50
                   + 100 * 2.50
                   + (units - 200) * 4.00;
        }
        else {
            amount = 100 * 1.50
                   + 100 * 2.50
                   + 100 * 4.00
                   + (units - 300) * 6.00;
        }

        return amount;
    }

    int getID() const {
        return customerID;
    }

    void displayBill() const {
        cout << fixed << setprecision(2);
        cout << "\n======= ELECTRICITY BILL =======\n";
        cout << "Customer ID : " << customerID << endl;
        cout << "Name        : " << name << endl;
        cout << "Units Used  : " << units << endl;
        cout << "Bill Amount : Rs. " << bill << endl;
        cout << "================================\n";
    }
};

int main() {
    vector<Customer> customers;
    int choice;

    do {
        cout << "\n===== ELECTRICITY BILL SYSTEM =====\n";
        cout << "1. Register Customer\n";
        cout << "2. Display All Bills\n";
        cout << "3. Search Customer Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, units;
            string name;
            bool exists = false;

            cout << "Enter customer ID: ";
            cin >> id;

            for (const Customer& c : customers) {
                if (c.getID() == id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Customer ID already exists!\n";
                break;
            }

            cout << "Enter customer name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter units consumed: ";
            cin >> units;

            if (units < 0) {
                cout << "Units cannot be negative!\n";
                break;
            }

            customers.emplace_back(id, name, units);
            cout << "Customer registered successfully!\n";
            break;
        }

        case 2:
            if (customers.empty()) {
                cout << "No customer records found!\n";
            } else {
                for (const Customer& c : customers) {
                    c.displayBill();
                }
            }
            break;

        case 3: {
            int id;
            bool found = false;

            cout << "Enter customer ID: ";
            cin >> id;

            for (const Customer& c : customers) {
                if (c.getID() == id) {
                    c.displayBill();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Customer not found!\n";
            }
            break;
        }

        case 4:
            cout << "Exiting electricity bill system...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

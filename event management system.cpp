//SYEDA AZKA ALI 230201116
//HAJRA AHMED 230201080

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Base Event class
class Event {
public:
    string name;
    string date;
    string time;
    int totalGuests;
    double price;

    Event() {}
    Event(string name, string date, string time, int totalGuests, double price)
        : name(name), date(date), time(time), totalGuests(totalGuests), price(price) {}

    virtual void display() const {
        cout << "Event: " << name << " | Date: " << date << " | Time: " << time 
             << " | Guests: " << totalGuests << " | Price: $" << price << endl;
    }

    virtual void displayPrice() const {
        cout << "Event: " << name << "   | Price: $" << price << endl;
    }

    virtual ~Event() {}
};

// Derived classes for specific event types
class Birthday : public Event {
public:
    Birthday(string date, string time, int totalGuests, double price)
        : Event("Birthday", date, time, totalGuests, price) {}

    void display() const override {
        cout << "Birthday Event | Date: " << date << " | Time: " << time 
             << " | Guests: " << totalGuests << " | Price: $" << price << endl;
    }

    void displayPrice() const override {
        cout << "Birthday Event | Price: $" << price << endl;
    }
};

class Wedding : public Event {
public:
    Wedding(string date, string time, int totalGuests, double price)
        : Event("Wedding", date, time, totalGuests, price) {}

    void display() const override {
        cout << "Wedding Event | Date: " << date << " | Time: " << time 
             << " | Guests: " << totalGuests << " | Price: $" << price << endl;
    }

    void displayPrice() const override {
        cout << "Wedding Event | Price: $" << price << endl;
    }
};

class Party : public Event {
public:
    Party(string date, string time, int totalGuests, double price)
        : Event("Party", date, time, totalGuests, price) {}

    void display() const override {
        cout << "Party Event | Date: " << date << " | Time: " << time 
             << " | Guests: " << totalGuests << " | Price: $" << price << endl;
    }

    void displayPrice() const override {
        cout << "Party Event | Price: $" << price << endl;
    }
};

// User class
class User {
public:
    string username;
    string password;

    void registerUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        ofstream file;
        file.open("users.txt", ios::app);
        file << username << " " << password << endl;
        file.close();
        cout << "Registered successfully!\n";
    }

    bool login() {
        string user, pass;
        cout << "Enter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;

        ifstream file("users.txt");
        while (file >> username >> password) {
            if (username == user && password == pass) {
                cout << "Login successful!\n";
                return true;
            }
        }
        file.close();
        cout << "Invalid username or password.\n";
        return false;
    }
};

// EventManager class
class EventManager {
public:
    Event* events[100]; // Assuming a fixed number of events, adjust size as needed
    int eventCount = 0;

    ~EventManager() {
        for (int i = 0; i < eventCount; ++i) {
            delete events[i];
        }
    }

    void loadEvents() {
        ifstream file("events.txt");
        string type, date, time;
        int totalGuests;
        double price;
        while (file >> type >> date >> time >> totalGuests >> price) {
            if (type == "Birthday") {
                events[eventCount++] = new Birthday(date, time, totalGuests, price);
            } else if (type == "Wedding") {
                events[eventCount++] = new Wedding(date, time, totalGuests, price);
            } else if (type == "Party") {
                events[eventCount++] = new Party(date, time, totalGuests, price);
            }
        }
        file.close();
    }

    void viewEventPrices() const {
        for (int i = 0; i < eventCount; ++i) {
            events[i]->displayPrice();
        }
    }

    void bookEvent() {
        string type, date, time, venue;
        int totalGuests;
        double price;
        cout << "Enter event type (Birthday/Wedding/Party): ";
        cin >> type;
        cout << "Enter venue name: ";
        cin >> venue;
        cout << "Enter date (DD-MM-YYYY): ";
        cin >> date;
        cout << "Enter time (HH:MM): ";
        cin >> time;
        cout << "Enter total guests: ";
        cin >> totalGuests;
        cout << "Enter price: ";
        cin >> price;

        ofstream file;
        file.open("bookings.txt", ios::app);
        file << type << " " << date << " " << time << " " << totalGuests << " " << price << endl;
        file.close();
        cout << "Event booked successfully!\n";
    }

    void viewBookedEvents() const {
        ifstream file("bookings.txt");
        string type, date, time;
        int totalGuests;
        double price;
        cout << "Your Booked Events Details are:\n";
        while (file >> type >> date >> time >> totalGuests >> price) {
            cout << "Event Type: " << type << " | Date: " << date << " | Time: " << time 
                 << " | Guests: " << totalGuests << " | Price: $" << price << endl;
        }
        file.close();
    }
};

// Display menu
void displayMenu() {
    cout << "\t\t\t\t    -------------------------------" << endl;
    cout << "\t\t\t\t    |   EVENT MANAGEMENT SYSTEM   |" << endl;
    cout << "\t\t\t\t    -------------------------------" << endl;

    cout << "\n\n\t\t-------------------------------- Event Details -------------------------------------" << endl;

    cout << "\n\t\t\t\t 1. Login\n";
    cout << "\n\t\t\t\t 2. Register\n";
    cout << "\n\t\t\t\t 3. Book Event\n";
    cout << "\n\t\t\t\t 4. View Booked Event Details\n";
    cout << "\n\t\t\t\t 5. View Event Prices\n";
    cout << "\n\t\t\t\t 6. About Us\n";
    cout << "\n\t\t\t\t 7. Exit\n";
}

// About Us information
void aboutUs() {
    cout << "\n\n" << endl;
    cout << "\t--------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\t\t\t\t***************************************************" << endl;
    cout << "\n\t\t\t\t\t|   Welcome to Event Management System| | \n\n";
    cout << "\t\t\t\t***************************************************" << endl;
    cout << "\n\n\t\t                       *---------- About Us ---------*\n" << endl;
    cout << "\t|-> Event Management System, your ultimate solution for seamless event planning and execution.\t\t|" << endl;
    cout << "\t|   Whether you're organizing a small gathering or a large-scale event, our system is designed  \t|" << endl;
    cout << "\t|   to make event management effortless and efficient. Celebrate your occasion with us to make  \t|" << endl;
    cout << "\t|   your event more special at a reasonable price.                                        \t\t|" << endl;
    cout << "\t|-> Contact us now: Email: eventmanagement24@gmail.com                                    \t\t|" << endl;
    cout << "\t|-> Phone: 01234567890                                                                    \t\t|" << endl;
    cout << "\t|-> Address: IST                                                                          \t\t|" << endl;
    cout << "\t|-> Timing: Monday-Friday --> Opening & Closing Hours: 9AM To 5PM                         \t\t|" << endl;
    cout << "\t|-> Thank You :) !                                                                        \t\t|" << endl;
    cout << "\t--------------------------------------------------------------------------------------------------------\n" << endl;
}

// Main function
int main() {
    User user;
    EventManager eventManager;
    eventManager.loadEvents();
    int choice;
    bool loggedIn = false;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            loggedIn = user.login();
            break;
        case 2:
            user.registerUser();
            break;
        case 3:
            if (loggedIn) {
                eventManager.bookEvent();
            } else {
                cout << "Please login first.\n";
            }
            break;
        case 4:
            if (loggedIn) {
                eventManager.viewBookedEvents();
            } else {
                cout << "Please login first.\n";
            }
            break;
        case 5:
            eventManager.viewEventPrices();
            break;
        case 6:
            aboutUs();
            break;
        case 7:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        
    } while (choice != 7);

    return 0;
}


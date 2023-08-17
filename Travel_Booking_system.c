#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BOOKINGS 100
#define MAX_SEATS 12

struct Flight {
    char flightNumber[MAX_NAME_LENGTH];
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
    int availableSeats;
    float price;
    double totalCost;
    int seats;
};
struct Taxis {
    char taxisName[MAX_NAME_LENGTH];
    char taxisSource[MAX_NAME_LENGTH];
    char taxisDestination[MAX_NAME_LENGTH];
    char taxisSeats[MAX_SEATS];
    float taxisPrice;
};

struct Booking {
    char username[MAX_USERNAME_LENGTH];
    char flightNumber[MAX_NAME_LENGTH];
    char taxisName[MAX_NAME_LENGTH];
};

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};
struct Taxis taxis[MAX_FLIGHTS];
int numTaxis=0;

struct Flight flights[MAX_FLIGHTS];
int numFlights = 0;

struct Booking bookings[MAX_BOOKINGS];
int numBookings = 0;

struct User users[MAX_BOOKINGS];
int numUsers = 0;
void displayTaxis()
{
    printf("Available Taxis ");
    printf("--------------------------------------------------------\n");
    printf("Taxi Name \t Source\t\t Destination\t Price\tSeats\n");
    printf("--------------------------------------------------------\n");
    for(int i=0;i<numTaxis;i++)
    {
        printf("%s\t\t%s\t\t%s\t\t%.2f\t%s\n",taxis[i].taxisName,taxis[i].taxisSource,taxis[i].taxisDestination,taxis[i].taxisPrice,taxis[i].taxisSeats);
    }
}
void displayFlights() {
    printf("Available Flights:\n");
    printf("--------------------------------------------------------\n");
    printf("Flight No.\tSource\t\tDestination\tPrice\tSeats\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < numFlights; i++) {
        printf("%s\t\t%s\t\t%s\t\t%.2f\t%d\n", flights[i].flightNumber, flights[i].source, flights[i].destination, flights[i].price, flights[i].availableSeats);
    }

    printf("--------------------------------------------------------\n");
}
void bookTaxis(char* username)
{
    char taxisName[MAX_NAME_LENGTH];
    char numPassenger;

    printf("Enter the Taxi Name : ");
    scanf("%s",taxisName);

    for(int i=0; i < numTaxis; i++)
    {
        if(strcmp(taxis[i].taxisName,taxisName)== 0)
        {
            strcpy(bookings[numBookings].username,username);
            strcpy(bookings[numBookings].taxisName, taxisName);
            numBookings++;

            printf("Booking successful. Enjoy your journey!\n");
        }
        else
            printf("Sorry this taxi not Available.");
    }
}

void bookFlight(char* username) {
    char flightNumber[MAX_NAME_LENGTH];
    int numPassengers;

    printf("Enter the flight number: ");
    scanf("%s", flightNumber);

    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            printf("Enter the number of passengers: ");
            scanf("%d", &numPassengers);

            if (flights[i].availableSeats >= numPassengers) {
                flights[i].availableSeats -= numPassengers;
                flights[i].totalCost=flights[i].price*numPassengers;
                flights[i].seats=numPassengers;

                strcpy(bookings[numBookings].username, username);
                strcpy(bookings[numBookings].flightNumber, flightNumber);
                numBookings++;

                printf("Booking successful. Enjoy your flight!\n");
            } else {
                printf("Sorry, there are not enough seats available.\n");
            }

            return;
        }
    }

    printf("Flight not found.\n");
}

void addFlight() {
    if (numFlights >= MAX_FLIGHTS) {
        printf("Maximum number of flights reached.\n");
        return;
    }

    struct Flight newFlight;

    printf("Enter the flight number: ");
    scanf("%s", newFlight.flightNumber);
    printf("Enter the source: ");
    scanf("%s", newFlight.source);
    printf("Enter the destination: ");
    scanf("%s", newFlight.destination);
    printf("Enter the price: ");
    scanf("%f", &newFlight.price);
    printf("Enter the number of available seats: ");
    scanf("%d", &newFlight.availableSeats);

    flights[numFlights] = newFlight;
    numFlights++;

    printf("Flight added successfully.\n");
}

int userExists(char* username) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }

    return 0;
}
void addTaxis() {

    struct Taxis newTaxis;

    printf("Enter the Taxis Name : ");
    scanf("%s", newTaxis.taxisName);
    printf("Enter the source: ");
    scanf("%s", newTaxis.taxisSource);
    printf("Enter the destination: ");
    scanf("%s", newTaxis.taxisDestination);
    printf("Enter the price: ");
    scanf("%f", &newTaxis.taxisPrice);
    printf("Enter the number of available seats: ");
    scanf("%s", newTaxis.taxisSeats);

    taxis[numTaxis] = newTaxis;
    numTaxis++;

    printf("Taxis added successfully.\n");
}

void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    if (userExists(username)) {
        printf("Username already exists. Please choose a different username.\n");
        return;
    }

    printf("Enter a password: ");
    scanf("%s", password);

    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    numUsers++;

    printf("Registration successful. Welcome, %s!\n", username);
}

void generateTicket(char* username, char* flightNumber) {
    printf("Generating ticket for %s...\n", username);

    int flightIndex = -1;
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        printf("Flight not found.\n");
        return;
    }

    int bookingIndex = -1;
    for (int i = 0; i < numBookings; i++) {
        if (strcmp(bookings[i].username, username) == 0 && strcmp(bookings[i].flightNumber, flightNumber) == 0) {
            bookingIndex = i;
            break;
        }
    }

    if (bookingIndex == -1) {
        printf("Booking not found.\n");
        return;
    }

    printf("\n----------------------------------------------------------------\n");
    printf("               TICKET FOR FLIGHT %s\n", flightNumber);
    printf("----------------------------------------------------------------\n");
    printf("Passenger: %s\n", username);
    printf("Flight: %s - %s to %s\n", flightNumber, flights[flightIndex].source, flights[flightIndex].destination);
    printf("Price: $%.2f\n", flights[flightIndex].price);
    printf("Total Cost: $%.2f\n", flights[flightIndex].totalCost);
    printf("Price: %d\n", flights[flightIndex].seats);
    printf("-----------------------------------------------------------------\n");
}
void displayUserTaxiBookings(char* username) {
    printf("----Your Bookings----\n");
    printf("----------------------------------------------------------------\n");
    printf("Taxi Name.\tSource\t\tDestination\tPrice\tSeats\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < numBookings; i++) {
        if (strcmp(bookings[i].username, username) == 0) {
            int taxisIndex = -1;
            for (int j = 0; j < numTaxis; j++) {
                if (strcmp(bookings[i].taxisName, taxis[j].taxisName) == 0) {
                    taxisIndex = j;
                    break;
                }
            }

            if (taxisIndex != -1) {
                printf("%s\t\t%s\t\t%s\t\t%.2f\t%.2f\t%d\n", taxis[taxisIndex].taxisName, taxis[taxisIndex].taxisSource, taxis[taxisIndex].taxisDestination, taxis[taxisIndex].taxisPrice,taxis[taxisIndex].taxisSeats);
            }
        }
    }

    printf("----------------------------------------------------------------\n");
}

void displayUserBookings(char* username) {
    printf("----Your Bookings----\n");
    printf("----------------------------------------------------------------\n");
    printf("Flight No.\tSource\t\tDestination\tPrice\tTotal Cost\tSeats\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < numBookings; i++) {
        if (strcmp(bookings[i].username, username) == 0) {
            int flightIndex = -1;
            for (int j = 0; j < numFlights; j++) {
                if (strcmp(bookings[i].flightNumber, flights[j].flightNumber) == 0) {
                    flightIndex = j;
                    break;
                }
            }

            if (flightIndex != -1) {
                printf("%s\t\t%s\t\t%s\t\t%.2f\t%.2f\t%d\n", flights[flightIndex].flightNumber, flights[flightIndex].source, flights[flightIndex].destination, flights[flightIndex].price,flights[flightIndex].totalCost,flights[flightIndex].seats);
            }
        }
    }

    printf("----------------------------------------------------------------\n");
}
void adminDashboard()
{
    char adminPassword[50];
    char adminName[50];
    printf("\n----Admin Login----\n");
    printf("Enter Admin Name: ");
    scanf("%s", adminName);
    printf("Enter Admin Password: ");
    scanf("%s", adminPassword);

    if ((strcmp(adminPassword, "1234" )==0)&&(strcmp(adminName,"siam")==0)) {
        int choice;
        while(1)
        {
            printf("\n\t\t\t|-------------------------------------------------|\n");
            printf("\t\t\t|------Welcome to the Flight Booking System-------|\n");
            printf("\t\t\t|------------Wellcome to Admin %s--------------|\n",adminName);
            printf("\t\t\t|-------------------------------------------------|\n");
            printf("1. Add Fight\n");
            printf("2. Add Airport Taxis\n");
            printf("3. Logout\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addFlight();
                    break;
                case 2:
                    addTaxis();
                    break;
                case 3:
                    printf("Logging out.\n");
                    return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
   }else
    printf("invalid");
}

void userDashboard(char* username) {
    int choice;

    while (1) {
        printf("\nWelcome, %s!\n", username);
        printf("1. View Available Flights\n");
        printf("2. View Available Airport Taxi\n");
        printf("3. Book a Flight\n");
        printf("4. Book a Taxi\n");
        printf("5. View Your Bookings\n");
        printf("6. View your Taxi Bookings\n");
        printf("7. Generate Ticket\n");
        printf("8. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights();
                break;
            case 2:
                displayTaxis();
                break;
            case 3:
                bookFlight(username);
                break;
            case 4:
                bookTaxis(username);
                break;
            case 5:
                displayUserBookings(username);
                break;
            case 6:
                displayUserTaxiBookings(username);
                break;
            case 7: {
                char flightNumber[MAX_NAME_LENGTH];
                printf("Enter the flight number: ");
                scanf("%s", flightNumber);
                generateTicket(username, flightNumber);
                break;
            }
            case 8:
                printf("Logging out.\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            userDashboard(username);
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nWelcome to the Flight Booking System\n");
        printf("1. Admin\n");
        printf("2. Register\n");
        printf("3. Login\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminDashboard();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                login();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

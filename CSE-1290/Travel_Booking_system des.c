//Travel_booking_system
//1.Register
/*2.Login
-userName
-password
3.View Available Flight
4.View Available Toxis
*/
/*dashbroad
1. View Available Flight.\n");
2. View Available Airport Taxis.
3.Book a Flight.
4.Book a Airport Taxis.
5.View your booking Flight.
6.View your booking Taxis.
7.Logout.\n");
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_FLIGHTS 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BOOKINGS 100

struct User{
    char username[MAX_USERNAME_LENGTH];
    char userpassword[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_BOOKINGS];
int numUsers = 0;

int userExists(char* username) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }

    return 0;
}
void bookFlight(char* username)
{

}
void bookTaxis(char* username){

}
void displayFlight(char* username)
{

}
void displayTaxis(char* name)
{

}
void userRegiter()
{
    char username[MAX_USERNAME_LENGTH];
    char userpassword[MAX_PASSWORD_LENGTH];

    printf("Enter your user name : ");
    scanf("%s",username);

    if(userExists(username))
    {
        printf("Username already exists. Please choose a different username.\n");
    }

    printf("Enter your user password : ");
    scanf("%s",userpassword);

    strcpy(users[numUsers].username,username);
    strcpy(users[numUsers].userpassword,userpassword);
    numUsers++;

    printf("\n\nRegistration successful.Wellcome %s !",username);
}
void userDashboard(char* username)
{
    int choice;
    while(1)
    {
        printf("\n\t\t\t|-------------------------------------------------|\n");
        printf("\t\t\t|------Welcome to the Flight Booking System-------|\n");
        printf("\t\t\t|---------------Wellcome %s----------------|\n",username);
        printf("\t\t\t|-------------------------------------------------|\n");
        printf("1. View Available Flight.\n");
        printf("2. View Available Airport Taxis.\n");
        printf("3.Book a Flight.\n");
        printf("4.Book a Airport Taxis.\n");
        printf("5.View your booking Flight.\n");
        printf("6.View your booking Taxis.\n");
        printf("7.Logout.\n");
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                viewAvailableflight();
                break;
            case 2:
                viewAvailableTaxis();
                break;
            case 3:
                bookFlight(username);
            case 4:
                bookTaxis(username);
            case 5:
                displayFlight(username);
            case 6:
                displayTaxis(username);
            case 7:
                printf("Logging out.\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
void login()
{
    char username[MAX_USERNAME_LENGTH];
    char userpassword[MAX_PASSWORD_LENGTH];

    printf("Enter your user name : ");
    scanf("%s",username);
    printf("Enter your user password : ");
    scanf("%s",userpassword);

    for(int i=0;i<numUsers;i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].userpassword, userpassword) == 0)
        {
            printf("Login successfully.");
            userDashboard(username);
            return;
        }
    }
    printf("Invalid username or password.\n");
}
void viewAvailableflight()
{
    printf("\n\nFight Add Sucessfully.");
}
void viewAvailableTaxis()
{

}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\t\t\t|-------------------------------------------------|\n");
        printf("\t\t\t|------Welcome to the Flight Booking System-------|\n");
        printf("\t\t\t|-------------------------------------------------|");
        printf("\n\n\n1. Register\n");
        printf("2. Login\n");
        printf("3. View Available Flight\n");
        printf("4. View Available Taxis\n");
        printf("5. Exit\n");
        printf("Enter Your Choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                userRegiter();
                break;
            case 2:
                login();
                break;
            case 3:
                viewAvailableflight();
                break;
            case 4:
                viewAvailableTaxis();
                break;
            case 5:
                printf("Exiting Program.");
                exit(0);
            default:
                printf("Invalid input.Try again ");


        }

    }
}

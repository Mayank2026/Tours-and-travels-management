#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class tour {
private:
    int pid;
    int days;
    int nights;
    int destination;
    int mode_of_travel;
    float charges;
    int no_of_passengers;
    char passenger_name[10][20];
    int ages[10];
    int passportno[10];
    int phno[10];
    char address[20];
    int food_type[10];
    int hotelrating;
    int no_of_rooms;
    char date_of_travel[10];

public:
    tour();
    void Booking();
    void Passenger_details();
    float Total_Charge();
    void Change_Program();
    void Show_Program();
    int getpid() {
        return pid;
    }
};

tour::tour() {
    pid = 0;
    days = 0;
    nights = 0;
    destination = 0;
    charges = 0.0;
    strcpy(address, "NULL");
    strcpy(date_of_travel, "NULL");
}

void tour::Passenger_details() {
    int n = no_of_passengers;
    if (n > 10) {
        cout << "\nSorry, the passenger limit is exceeded.";
        getch();
        exit(1);
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << "\nEnter Passenger Name: ";
            cin.ignore();
            cin.getline(passenger_name[i], 20);
            cout << "\nEnter age of passenger: ";
            cin >> ages[i];
            cout << "\nEnter food type(PRESS 1 for VEG, 2 for NON-VEG, 3 for SPECIAL): ";
            cin >> food_type[i];
            cout << "\nEnter Passport Number: ";
            cin >> passportno[i];
            cout << "\nEnter phone number: ";
            cin >> phno[i];
        }
    }
}

float tour::Total_Charge() {
    float roomcost, foodcost, tripcost, travelcost, profit = 10000, cost = 0, total = 0;

    switch (destination) {
        case 1:
        case 2:
        case 3:
            tripcost = 50000;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            tripcost = 20000;
            break;
        case 8:
        case 9:
        case 10:
            tripcost = 30000;
            break;
    }
    switch (mode_of_travel) {
        case 1:
            travelcost = days * 5000;
            break;
        case 2:
            travelcost = days * 3000;
            break;
        case 3:
            travelcost = days * 2000;
            break;
    }

    for (int i = 0; i < no_of_passengers; i++) {
        cost = tripcost + travelcost;
        switch (food_type[i]) {
            case 1:
                foodcost = days * 2000;
                break;
            case 2:
                foodcost = days * 3000;
                break;
            case 3:
                foodcost = days * 5000;
                break;
        }
        cost += foodcost;
        cost += profit;
        if (ages[i] < 12) {
            cost = cost / 2;
        }
        total += cost;
    }

    switch (hotelrating) {
        case 1:
            roomcost = 5000;
            break;
        case 2:
            roomcost = 7500;
            break;
        case 3:
            roomcost = 12000;
            break;
        case 4:
            roomcost = 15000;
            break;
        case 5:
            roomcost = 20000;
            break;
    }
    roomcost *= no_of_rooms;
    roomcost *= nights;
    total += roomcost;
    return total;
}

void tour::Booking() {
    cout << "\nEnter package ID: ";
    cin >> pid;
    cout << "\nEnter date of travel(YYYY-MM-DD): ";
    cin >> date_of_travel;
    cout << "\nEnter number of days and nights: ";
    cin >> days >> nights;
    do {
        cout << "\nPick your dream destination: ";
        cout << "\n1.Paris";
        cout << "\n2.London";
        cout << "\n3.New York";
        cout << "\n4.Singapore";
        cout << "\n5.Agra";
        cout << "\n6.Shimla";
        cout << "\n7.Ooty";
        cout << "\n8.Dubai";
        cout << "\n9.Sydney";
        cout << "\n10.Hong Kong\n";
        cout << "\nEnter destination of travel(1-10): ";
        cin >> destination;
    } while (destination > 10);
    do {
        cout << "\n1.Cab";
        cout << "\n2.Bus";
        cout << "\n3.Other";
        cout << "\nEnter preferred mode of inland travel: ";
        cin >> mode_of_travel;
    } while (mode_of_travel > 3);
    cout << "\nEnter number of passengers travelling: ";
    cin >> no_of_passengers;
    Passenger_details();
    cout << "\nEnter star rating of hotel(1-5): ";
    cin >> hotelrating;
    cout << "\nEnter number of rooms required: ";
    cin >> no_of_rooms;
    cout << "\nEnter address: ";
    cin.ignore();
    cin.getline(address, 20);
    charges = Total_Charge();
    cout << "\nThe total cost is: " << charges;
    cout << "\n   BOOKING SUCCESSFUL! Enjoy your trip!!!";
}

void tour::Change_Program() {
    int ch;
    cout << "\nWhat do you want to change? ";
    cout << "\n1.Date of travel ";
    cout << "\n2.Days and nights of travel \n";
    cin >> ch;
    if (ch == 1) {
        cout << "\nEnter new date of travel: ";
        cin >> date_of_travel;
    }
    else {
        cout << "\nEnter new days and nights: ";
        cin >> days >> nights;
        charges = Total_Charge();
    }
}

void tour::Show_Program() {
    cout << "\n\n_________________________________TOUR DETAILS________________________________________\n";
    cout << "\nPackage ID: " << pid;
    cout << "\nDate of Travel: " << date_of_travel;
    cout << "\nNumber of days: " << days << " and nights: " << nights;
    cout << "\nDestination: ";
    switch (destination) {
        case 1:
            cout << "Paris";
            break;
        case 2:
            cout << "London";
            break;
        case 3:
            cout << "New York";
            break;
        case 4:
            cout << "Singapore";
            break;
        case 5:
            cout << "Agra";
            break;
        case 6:
            cout << "Shimla";
            break;
        case 7:
            cout << "Ooty";
            break;
        case 8:
            cout << "Dubai";
            break;
        case 9:
            cout << "Sydney";
            break;
        case 10:
            cout << "Hong Kong";
            break;
    }
    cout << "\nNumber of passengers: " << no_of_passengers;
    cout << "\nNumber of rooms: " << no_of_rooms;
    cout << "\nHotel rating: " << hotelrating << " stars";
    cout << "\n\tPASSENGER DETAILS\n";
    cout << "NAME\t\tAGE\t\tPASSPORT NO\t\tPHONE NO\n";
    cout << "\n_______________________________________________________________________________________";
    for (int i = 0; i < no_of_passengers; i++) {
        cout << "\n" << passenger_name[i] << "\t\t" << ages[i] << "\t\t" << passportno[i] << "\t\t\t" << phno[i] << "\t\t";
    }
    cout << "\n\nAddress: " << address;
    cout << "\nTotal Cost: " << charges;
    cout << "\nThank You for choosing us, please visit again!";
}

int main() {
    tour t;
    fstream file;
    int ch, tid, flag = 0;
    do {
        cout << "\n\n___________________________WELCOME TO AURORA TOURS AND TRAVELS________________________________\n";
        cout << "\n_______________________________________________MENU________________________________________";
        cout << "\n1.Add record";
        cout << "\n2.Search record";
        cout << "\n3.Update record";
        cout << "\n4.Delete record";
        cout << "\n5.Exit";
        cout << "\n\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                file.open("tourism.dat", ios::binary | ios::out);
                t.Booking();
                file.write((char*)&t, sizeof(t));
                file.close();
                break;
            case 2:
                flag = 0;
                file.open("tourism.dat", ios::in);
                cout << "\nEnter package ID to be searched: ";
                cin >> tid;
                while (file.read((char*)&t, sizeof(t))) {
                    if (tid == t.getpid()) {
                        t.Show_Program();
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    cout << "\n No record Found";
                file.close();
                break;
            case 3:
                flag = 0;
                cout << "\nEnter Package ID to be modified ";
                cin >> tid;
                file.open("tourism.dat", ios::in | ios::out | ios::binary);
                file.seekg(0);
                while (file.read((char*)&t, sizeof(t))) {
                    if (tid == t.getpid()) {
                        t.Change_Program();
                        file.seekp(file.tellg() - sizeof(t));
                        file.write((char*)&t, sizeof(t));
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    cout << "\n No record Found";
                file.close();
                break;
            case 4:
                flag = 0;
                cout << "\nEnter Package No. to be Deleted ";
                cin >> tid;
                file.open("tourism.dat", ios::in | ios::binary);
                ofstream ofile("tmptk.dat", ios::out | ios::binary);
                while (file.read((char*)&t, sizeof(t))) {
                    if (tid != t.getpid())
                        ofile.write((char*)&t, sizeof(t));
                    else
                        flag = 1;
                }
                if (flag == 0)
                    cout << "\n No record Found";
                else
                    cout << "\nRecord Deleted";
                file.close();
                ofile.close();
                remove("tourism.dat");
                rename("tmptk.dat", "tourism.dat");
                break;
        }
    } while (ch != 5);
    return 0;
}

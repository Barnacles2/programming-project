#include <iostream>
#include <string>

using namespace std;

const int groups_count = 3; // number of groups
const int students_per_group = 50; // number of students per group
const int sports_count = 4; // number of sporting activities
const int clubs_count = 5; // number of club/societies activities
const int sports_max_capacity = 20; // maximum capacity for each sporting activity
const int clubs_max_capacity = 60; // maximum capacity for each club/societies activity

struct Student {
    string firstname;
    string surname;
    string gender;
    int age;
    int group;
    string sport;
    string club;
};

Student students[150]; // array to store all students
int student_count = 0; // count of students

void addStudent() {
    Student student;
    cout << "Enter firstname: ";
    cin >> student.firstname;
    cout << "Enter surname: ";
    cin >> student.surname;
    cout << "Enter gender (Male/Female): ";
    cin >> student.gender;
    cout << "Enter age: ";
    cin >> student.age;
    cout << "Enter group (1-" << groups_count << "): ";
    cin >> student.group;

    // add option to choose a sport
    cout << "Choose a sport (1-4): \n";
    cout << "1. Rugby\n";
    cout << "2. Athletics\n";
    cout << "3. Swimming\n";
    cout << "4. Soccer\n";
    int sport_choice;
    cin >> sport_choice;
    string sport_name;
    switch (sport_choice) {
        case 1:
            sport_name = "Rugby";
            break;
        case 2:
            sport_name = "Athletics";
            break;
        case 3:
            sport_name = "Swimming";
            break;
        case 4:
            sport_name = "Soccer";
            break;
        default:
            cout << "Invalid sport choice. Try again.\n";
            return;
    }
    student.sport = sport_name;

    // add option to choose a club
    cout << "Choose a club (1-5): \n";
    cout << "1. Journalism Club\n";
    cout << "2. Red Cross Society\n";
    cout << "3. AISEC\n";
    cout << "4. Business Club\n";
    cout << "5. Computer Science Club\n";
    int club_choice;
    cin >> club_choice;
    string club_name;
    switch (club_choice) {
        case 1:
            club_name = "Journalism Club";
            break;
        case 2:
            club_name = "Red Cross Society";
            break;
        case 3:
            club_name = "AISEC";
            break;
        case 4:
            club_name = "Business Club";
            break;
        case 5:
            club_name = "Computer Science Club";
            break;
        default:
            cout << "Invalid club choice. Try again.\n";
            return;
    }
    student.club = club_name;

    students[student_count] = student;
    student_count++;
}

void viewStudents() {
    cout << "Viewing all students:\n";
    for (int i = 0; i < student_count; i++) {
        cout << "Firstname: " << students[i].firstname << ", Surname: " << students[i].surname << ", Gender: " << students[i].gender << ", Age: " << students[i].age << ", Group: " << students[i].group << ", Sport: " << students[i].sport << ", Club: " << students[i].club << "\n";
    }
    cout << "Viewing students by group:\n";
    for (int i = 1; i <= groups_count; i++) {
        cout << "Group " << i << ":\n";
        for (int j = 0; j < student_count; j++) {
            if (students[j].group == i) {
                cout << "Firstname: " << students[j].firstname << ", Surname: " << students[j].surname << ", Gender: " << students[j].gender << ", Age: " << students[j].age << ", Sport: " << students[j].sport << ", Club: " << students[j].club << "\n";
            }
        }
    }
}

void viewClubsSocieties() {
    cout << "Available clubs and societies:\n";
    cout << "1. Journalism Club\n";
    cout << "2. Red Cross Society\n";
    cout << "3. AISEC\n";
    cout << "4. Business Club\n";
    cout << "5. Computer Science Club\n";
    cout << "Available capacity for each club/society: " << clubs_max_capacity << "\n";
}

void viewSports() {
    cout << "Available sports:\n";
    cout << "1. Rugby\n";
    cout << "2. Athletics\n";
    cout << "3. Swimming\n";
    cout << "4. Soccer\n";
    cout << "Available capacity for each sport: " << sports_max_capacity << "\n";
}

int main() {
    int choice;
    do {
        cout << "1. Add a student\n";
        cout << "2. View all students\n";
        cout << "3. View students by group\n";
        cout << "4. View clubs and societies\n";
        cout << "5. View sports\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                // code to view students by group
                break;
            case 4:
                viewClubsSocieties();
                break;
            case 5:
                viewSports();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}

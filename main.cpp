#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// setting the constant variables
const int groups_count = 3; // number of groups
const int students_per_group = 50; // number of students per group
const int sports_count = 4; // number of sporting activities
const int clubs_count = 5; // number of club/societies activities
const int sports_max_capacity = 20; // maximum capacity for each sporting activity
const int clubs_max_capacity = 60; // maximum capacity for each club/societies activity
const int sports_min_members = 1; // minimum number of members required for each sporting activity
const int clubs_min_members = 1; // minimum number of members required for each club/societies activity
const int sports_max_male_percentage = 75; // maximum percentage of male members allowed for each sporting activity
const int clubs_max_male_percentage = 50; // maximum percentage of male members allowed for each club/societies activity

// define a struct to represent a student
struct Student {
    string firstname;
    string surname;
    string gender;
    int age;
    int group;
    string sport;
    string club;
};

// vector to store all students
vector<Student> students;

// maps to store the count of members for each sporting activity and club/society
map<string, int> sports_members;
map<string, int> clubs_members;

// maps to store the count of male members for each sporting activity and club/society
map<string, int> sports_male_members;
map<string, int> clubs_male_members;

// function to add a new student
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
    // update the sports_members map
    sports_members[sport_name]++;
    if (student.gender == "male") {
        sports_male_members[sport_name]++;
    }

    // add option to choose a club
    cout << "Choose a club (1-5): \n";
    cout << "1. Debate\n";
    cout << "2. Music\n";
    cout << "3. Drama\n";
    cout << "4. Art\n";
    cout << "5. Robotics\n";
    int club_choice;
    cin >> club_choice;
    string club_name;
    switch (club_choice) {
        case 1:
            club_name = "Debate";
            break;
        case 2:
            club_name = "Music";
            break;
        case 3:
            club_name = "Drama";
            break;
        case 4:
            club_name = "Art";
            break;
        case 5:
            club_name = "Robotics";
            break;
        default:
            cout << "Invalid club choice. Try again.\n";
            return;
    }
    student.club = club_name;
    // update the clubs_members map
    clubs_members[club_name]++;
    if (student.gender == "male") {
        clubs_male_members[club_name]++;
    }

    students.push_back(student);
}

// function to view all students or students by group
void viewStudents() {
    cout << "Viewing all students:\n";
    for (const auto& student : students) {
        cout << "Firstname: " << student.firstname << ", Surname: " << student.surname << ", Gender: " << student.gender << ", Age: " << student.age << ", Group: " << student.group << ", Sport: " << student.sport << ", Club: " << student.club << "\n";
    }
    cout << "Viewing students by group:\n";
    for (int i = 1;i <= groups_count; i++) {
        cout << "Group " << i << ":\n";
        for (const auto& student : students) {
            if (student.group == i) {
                cout << "Firstname: " << student.firstname << ", Surname: " << student.surname << ", Gender: " << student.gender << ", Age: " << student.age << ", Sport: " << student.sport << ", Club: " << student.club << "\n";
            }
        }
    }
}

// function to view available clubs and societies
void viewClubsSocieties() {
    cout << "Available clubs and societies:\n";
    cout << "1. Debate\n";
    cout << "2. Music\n";
    cout << "3. Drama\n";
    cout << "4. Art\n";
    cout << "5. Robotics\n";
    cout << "Available capacity for each club/society: " << clubs_max_capacity << "\n";
}

// function to view available sporting activities
void viewSports() {
    cout << "Available sporting activities:\n";
    cout << "1. Rugby\n";
    cout << "2. Athletics\n";
    cout << "3. Swimming\n";
    cout << "4. Soccer\n";
    cout << "Available capacity for each sporting activity: " << sports_max_capacity << "\n";
}

// function to view students participating in a specific activity
void viewGroupedStudents() {
    cout << "Enter activity (1-4 for sporting activities, 5-9 for clubs/societies): ";
    int activity;
    cin >> activity;
    string activity_name;
    switch (activity) {
        case 1:
            activity_name = "Rugby";
            break;
        case 2:
            activity_name = "Athletics";
            break;
        case 3:
            activity_name = "Swimming";
            break;
        case 4:
            activity_name = "Soccer";
            break;
        case 5:
            activity_name = "Debate";
            break;
        case 6:
            activity_name = "Music";
            break;
        case 7:
            activity_name = "Drama";
            break;
        case 8:
            activity_name = "Art";
            break;
        case 9:
            activity_name = "Robotics";
            break;
default:
            cout << "Invalid activity. Try again.\n";
            return;
    }
    cout << "Students participating in " << activity_name << ":\n";
    for (const auto& student : students) {
        // check if the student is participating in the activity
        // (this logic is not implemented, you need to add it)
        cout << "Firstname: " << student.firstname << ", Surname: " << student.surname << "\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. View Clubs/Societies\n";
        cout << "4. View Sports\n";
        cout << "5. View Grouped Students\n";
        cout << "6. Save all Files\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                viewClubsSocieties();
                break;
            case 4:
                viewSports();
                break;
            case 5:
                viewGroupedStudents();
                break;
            case 6:
                // save all files (not implemented)
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

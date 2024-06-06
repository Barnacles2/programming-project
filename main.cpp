#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Setting the constant variables
const int groups_count = 3;
const int students_per_group = 50;
const int sports_count = 4;
const int clubs_count = 5;
const int sports_max_capacity = 20;
const int clubs_max_capacity = 60;
const int sports_min_members = 1;
const int clubs_min_members = 1;
const int sports_max_male_percentage = 75;
const int clubs_max_male_percentage = 50;

int main() {
    std::map<std::string, int> gender_count;
    gender_count["male"] = 0;
    gender_count["female"] = 0;

    // Displays group class and how many students per group
    int total_students = 0;
    for (int i = 0; i < groups_count; i++) {
        cout << "Group " << i + 1 << " has " << students_per_group << " students. \n";
        // Will output and request user to put in name of the student first then the gender
        for (int j = 0; j < students_per_group; j++) {
            string name;
            cout << "Enter name of student " << j + 1 << ": ";
            cin >> name;

            string gender;
            cout << "Enter gender (Male/Female) of student " << j + 1 << ": ";
            cin >> gender;

            if (gender == "male") {
                gender_count["male"]++;
            } else if (gender == "female") {
                gender_count["female"]++;
            } else {
                cout << "Invalid gender. Try again. \n";
                j--;
                continue;
            }
            total_students++;

            // Co-curricular activities
            vector<string> sports = {"Rugby", "Athletics", "Swimming", "Soccer"};
            vector<string> clubs = {"Journalism Club", "Red Cross Society", "AISEC", "Business Club", "Computer Science Club"};

            int sport_count = 0;
            int club_count = 0;

            cout << "Enter co-curricular activities for student " << j + 1 << ":\n";
            while (true) {
                int choice;
               cout << "1. Sporting activities";
               cin >> choice;
               cout << "\n2. Club/Societies activities";
               cin >> choice;

                if (choice == 1) {
                    if (sport_count < 1) {
                        cout << "Select a sporting activity:\n";
                        for (int k = 0; k < sports_count; k++) {
                            cout << k + 1 << ". " << sports[k] << "\n";
                        }
                        int sport_choice;
                        cin >> sport_choice;
                        sport_count++;
                    } else {
                        cout << "You have already selected a sporting activity.\n";
                    }
                } else if (choice == 2) {
                    if (club_count < 2 || sport_count == 0) {
                        cout << "Select a club/societies activity:\n";
                        for (int k = 0; k < clubs_count; k++) {
                            cout << k + 1 << ". " << clubs[k] << "\n";
                        }
                        int club_choice;
                        cin >> club_choice;
                        club_count++;
                    } else {
                        cout << "You have already selected the maximum number of club/societies activities.\n";
                    }
                } else {
                    cout << "Invalid choice. Try again.\n";
                }

                if (sport_count > 0 || club_count > 0) {
                    break;
                }
            }
        }
    }

    return 0;
}

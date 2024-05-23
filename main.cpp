#include <iostream>
#include <map>
using namespace std;
//setting the constant variables
const int groups_count =3;
const int students_per_group =50;
const int sports_count =4;
const int clubs_count =5;
const int sports_max_capacity =20;
const int clubs_max_capacity =60;
const int sports_min_members =1;
const int clubs_min_members =1;
const int sports_max_male_percentage=75;
const int clubs_max_male_percentage=50;


int main() {
std::map<std::string, int>gender_count;
    gender_count["male"] =0;
    gender_count["female"] =0;

    int total_students =0;
    for (int i = 0; i < groups_count; i++) {
        cout<<"Group " <<i+1 <<" has "<< students_per_group<<" students. \n";

    }



    return 0;
}

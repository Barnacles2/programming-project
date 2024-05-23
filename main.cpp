#include <iostream>
#include <map>
#include <string>
//#include <vector>--not yet being used
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
//displays group class and how many students per group
    int total_students =0;
    for (int i = 0; i < groups_count; i++) {
        cout<<"Group " <<i+1 <<" has "<< students_per_group<<" students. \n";
        //will output and request user to put in name of the student first then the gender
        for (int j = 0; j<students_per_group; j++) {
           string name;
           cout<<"Enter name of student" <<j+1<<":";
           cin>>name;

           string gender;
           cout<<"Enter gender (Male/Female) of student " << j + 1 << ": ";
           cin>>gender;

           if (gender=="male") {
               gender_count["male"]++;
           }else if (gender=="female") {
               gender_count["female"]++;
           }else {
               cout<<"Invalid gender. Try again. \n";
               j--;
               continue;
           }
           total_students++;
       }
    }

    



    return 0;
}

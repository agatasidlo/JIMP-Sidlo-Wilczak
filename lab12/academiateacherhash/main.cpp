
#include <iostream>
#include "TeacherHash.h"

using namespace std;
using namespace academia;

int main() {
    Teacher s1 = Teacher(TeacherId(1002), "Alozjzy", "Katedra Informatyki");
    Teacher s2 = Teacher(TeacherId(1002), "Alozjzy", "Katedra InFormatyki");
    Teacher s3 = Teacher(TeacherId(1003), "Alozjzy", "Katedra Informatyki");
    Teacher s4 = Teacher(TeacherId(1002), "alozjzy", "Katedra Informatyki");

    cout << s1.Id() << ", " << s1.Name() << ", " << s1.Department() << endl;
    cout << s2.Id() << ", " << s2.Name() << ", " << s2.Department() << endl;
    cout << s3.Id() << ", " << s3.Name() << ", " << s3.Department() << endl;
    cout << s4.Id() << ", " << s4.Name() << ", " << s4.Department() << endl;


    int Sum1 = 0, Sum2 = 0;
    int Sum3 = 0, Sum4 = 0;


    for (int i = 0; i < s1.Name().length(); i++) {
        Sum1 += s1.Name()[i];
    }
    for (int i = 0; i < s1.Department().length(); i++) {
        Sum2 += s1.Department()[i];
    }


    for (int i = 0; i < s2.Name().length(); i++) {
        Sum3 += s2.Name()[i];
    }
    for (int i = 0; i < s2.Department().length(); i++) {
        Sum4 += s2.Department()[i];
    }
    cout << "suma string name  " << Sum1 << " department   " << Sum2 << endl;
    cout << "suma string name  " << Sum3 << " department   " << Sum4 << endl;

    cout << (std::hash<std::string>()(s1.Name()) ^ std::hash<int>()(Sum2)) << endl
         << (std::hash<std::string>()(s2.Name()) ^ std::hash<int>()(Sum4)) << endl;
}
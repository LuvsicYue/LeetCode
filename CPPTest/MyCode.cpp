//
// Created by ChenshuoYue on 6/7/17.
//

#include "MyCode.hpp"
#include <sstream>
using namespace std;

inline void printTest() {
    cout << "Have inline function"<< endl;

}

int My_code::main() {
    cout << "Hello World" << endl;
    // -------------------Enumerations-----------------------
    enum RainbowColors {
        Viotlet = 20,
        Indigo,
        Blue,
        Green,
        Yellow,
        Orange,
        Rea
    };

    RainbowColors color = Blue;
    cout << "Blue is " << color << endl;
    // ------------------- -----------------------
    printTest();

    // Test stringstream
    string str = "12, 13, 14";
    stringstream ss(str);
    char ch;
    int tmp;
    while(ss >> tmp) {
        cout << tmp << ", ";
        ss >> ch;
    }
    return 0;
}

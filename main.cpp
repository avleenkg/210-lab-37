#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int sum_ascii(string s);

int main() {
    ifstream fin("lab-37-data.txt");

    if (fin.is_open()) {
        string codes;
        int grandtotal = 0;
        while (fin >> codes) {
            grandtotal += sum_ascii(codes);
        }

        cout << "The total ascii value of the whole file is: " << grandtotal << endl;

        fin.close();
    }
    else {
        cout << "Error. File not opened.\n";
    }

    return 0;
}
int sum_ascii(string s) {
    int sum = 0;
    for (char c : s) {
        sum += (int) c;
    }
    return sum;
}


/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

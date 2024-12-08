#include <iostream>
#include <string>
using namespace std;


int sum_ascii(string s);

int main() {

    //test 1
    cout << "Testing ascii value for 536B9DFC93AF\n";
    int testsum = sum_ascii("536B9DFC93AF");
    cout << "The ascii value is " << testsum << endl;  

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

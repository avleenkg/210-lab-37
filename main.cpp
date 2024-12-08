#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

const int TABLESIZE = 5000;

int gen_hash_index(string s, int t);

int main() {
    ifstream fin("lab-37-data.txt");

    if (fin.is_open()) {

        map<int, list<string>> hash_table;

        string codes;
        while (fin >> codes) {
            int index = gen_hash_index(codes, TABLESIZE);
            hash_table[index].push_back(codes);
        }

        cout << "First 100 elements displayed:\n";
        int count = 0;
        for (const auto& indices : hash_table) {
            if (count >= 100) {
                break;
            }
            cout << "Table Index: " << indices.first << " | Codes: ";
            for (const auto& codes : indices.second) {
                cout << codes << ", ";
            }
            cout << endl;
            count++;
        }
        

        fin.close();
    }
    else {
        cout << "Error. File not opened.\n";
    }

    return 0;
}
int gen_hash_index (string s, int TABLESIZE) {
    int sum = 0;
    for (char c : s) {
        sum += (int) c;
    }
    return sum % TABLESIZE;
}


/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

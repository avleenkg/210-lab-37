//Labs 37 and 38 - Avleen Gill

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

        int choice, tableindex = 0, count = 0;
        string search;

        do {
            cout << "------Data Records 3000------\n";
            cout << "\t1. Print first 100 entries\n";
            cout << "\t2. Search for a key\n";
            cout << "\t3. Add a key\n";
            cout << "\t4. Remove a key\n";
            cout << "\t5. Modify a key\n";
            cout << "\t6. Exit\n";

            cout << "Enter a number: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    //print 100 entries
                    cout << "First 100 elements displayed:\n";
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
                    break;
                case 2:
                    //search for a key
                    cout << "Enter the key to search: ";
                    cin >> search;
                    tableindex = gen_hash_index(search, TABLESIZE);
                    if (hash_table[tableindex].empty()) {
                        cout << "Key not found.\n";
                    }
                    else {
                        if (find(hash_table[tableindex].begin(), hash_table[tableindex].end(), search) != hash_table[tableindex].end()){
                            cout << "Key found at index " << tableindex << endl;
                        }
                        else {
                            cout << "Key not found.\n";
                        }
                    }
                    break;
                case 3:
                    //add a key
                    break;
                case 4:
                    //remove a key
                    break;
                case 5:
                    //modify a key
                    break;
                case 6:
                    //quit
                    cout << "Exiting...\n";
                    return 0; 
                default:
                    cout << "Error. Not a valid entry.\n";
                    break;
           }

        } while (choice != 6);
        

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

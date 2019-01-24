#include <string>
#include "ttree.h"

int main() {
    /// testing
    /*ttree *mytree = new ttree(3);
    mytree->insert("STORMWIND");
    mytree->insert("SILVERBOOK");
    mytree->insert("BLACKROCK");
    mytree->insert("BLACKWIND");
    mytree->insert("BLADESPIRE");
    mytree->insert("STONARD");
    cout << *mytree;
    try{
    mytree->search("B");
    }
    catch (ttreeException& ex){
    cout << ex.what();
    }*/

    // ttree object created
    ttree *mytree = new ttree();
    //ifstream input("simpleInput.txt");
    string inputString;

    // input oriented runs with I as insert, D as display, S as search as well as throwing exceptions in proper cases
    while (cin >> inputString) {
        if (inputString == "I") {
            cin >> inputString;
            mytree->insert(inputString);
        }
        else if (inputString == "D") {
            cout << *mytree;
        }
        else if (inputString == "S") {
            cin >> inputString;
            try {
                mytree->search(inputString);
                cout << endl;
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }
            cout << endl;
        }
    }
}
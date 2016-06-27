#include <iostream>
#include "Hashtable.h"

using namespace std;

int main() {

    LinkedList test;

    Hashtable * table = new Hashtable(13);


    Item * test1 = new Item;
    test1->next = nullptr;
    test1->Key = (char *)"Key1";
    Item * test2 = new Item;
    test1->next = nullptr;
    test1->Key = (char *)"Key2";

    table->insertItem(test1);

    cout << "Hello, World!" << endl;
    return 0;
}
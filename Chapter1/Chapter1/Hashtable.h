//
// Created by ommalik on 6/26/2016.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include "LinkedList.h"

class Hashtable
{
    private:
        LinkedList *HashEntry;
        int length;
        int hash(char * itemKey);
    public:
        Hashtable(int tableLength = 13);
        void insertItem(Item * newItem);
        bool removeItem(char * itemKey);
        Item * getItemByKey(char * itemKey);
        void printTable();
        void printHistogram();
        int getLength(char* itemKey);
        int getNumberofItems();
        int stringlength(char * Keystring);
        ~Hashtable();
};


#endif //HASHTABLE_HASHTABLE_H

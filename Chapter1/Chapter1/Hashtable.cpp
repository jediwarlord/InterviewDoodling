//
// Created by ommalik on 6/26/2016.
//
#include <stdafx.h>
#include "Hashtable.h"

int Hashtable::hash(char *itemKey)
{
    int value = 0;
    int _stringlength = stringlength(itemKey);
    for ( int i = 0; i < _stringlength; i++ )
        value += itemKey[i];

    return (value * stringlength(itemKey) ) % length;

}

Hashtable::Hashtable(int tableLength)
{
    if (tableLength <= 0) tableLength = 13;
    HashEntry = new LinkedList[tableLength];
    length = tableLength;
	void* ptr = &HashEntry[10];
}

void Hashtable::insertItem(Item *newItem)
{
    int index = hash( newItem->Key );
    HashEntry[ index ].insertItem( newItem );
}

bool Hashtable::removeItem(char *itemKey) {
    return false;
}

Item *Hashtable::getItemByKey(char *itemKey) 
{
	//we want to find the item defined by the key...
	//first we get the Hashkey and then from that we go the Hashentries and retrieve that particular key...
	auto index = hash(itemKey);
	
	//now retrieve the item...

    return HashEntry[index].getItem(itemKey);
}

void Hashtable::printTable() {

}

void Hashtable::printHistogram() {

}

int Hashtable::getLength() {
    return 0;
}

int Hashtable::getNumberofItems() {
    return 0;
}

Hashtable::~Hashtable() {

}

int Hashtable::stringlength(char *Keystring)
{
    int length = 0;
    if (Keystring)
    {

        char * currentchar = Keystring;
        while((*currentchar != '\0'))
        {
            Keystring++;
            length++;
            currentchar = Keystring;
        }
    }
    return length;
}






















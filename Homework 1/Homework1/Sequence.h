#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdio.h>
#include <iostream>

using ItemType = unsigned long;

const int DEFAULT_MAX_ITEMS = 160;

class Sequence
{
  public:
    
    Sequence();    // Create an empty sequence (i.e., one whose size() is 0).
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
    int insert(int pos, const ItemType& value);
      

    int insert(const ItemType& value);
      
    bool erase(int pos);
      
    int remove(const ItemType& value);

    bool get(int pos, ItemType& value) const;

    bool set(int pos, const ItemType& value);

    int find(const ItemType& value) const;

    void swap(Sequence& other);
    
private:
    int m_size;
    ItemType m_array[DEFAULT_MAX_ITEMS];
};

#endif

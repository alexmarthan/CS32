#include <iostream>
#include "Sequence.h"

using namespace std;

//constructor
Sequence::Sequence(): m_size(0){}

bool Sequence::empty() const{
    if (m_size == 0){
        return true;
    }
    else return false;
}  // Return true if the sequence is empty, otherwise false.

int Sequence::size() const{
    return m_size;
}    // Return the number of items in the sequence.


int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0 || pos > m_size)
        return -1;
    
    int tracker = m_size;
    
    while (tracker != pos)
    {
        m_array[tracker] = m_array[tracker - 1];
        tracker--;
    }
    
    m_array[pos] = value;
    m_size++;
    return true;
}

int Sequence::insert(const ItemType& value)
{
    int target = size();
    
    for (int i = 0; i < size(); i++)
        if (value <= m_array[i])
        {
            target = i;
            break;
        }
    
    int mySize = size();
    
    while (mySize != target)
    {
        m_array[mySize] = m_array[mySize - 1];
        mySize--;
    }
    
    m_array[target] = value;
    m_size++;
    return target;
}


bool Sequence::erase(int pos){ // i did not change the last value to empty string or smth, i just left it there unchanged
    if (pos >= 0 && pos < size()){
        for (int i = 0; i < size();i++){
            m_array[pos] = m_array[pos+1];
            pos++;
        }
        m_size--; // size is reduced by 1, we removed one value
        return true;
    }
    else return false;
}

int Sequence::remove(const ItemType& value){
    int counter(0);
    for (int i = 0; i < size(); i++){
        if (value == m_array[i]){
            counter++;
            erase(i);
        }
    }
    return counter;
}

bool Sequence::get(int pos, ItemType& value) const {
    if (pos >= 0 && pos < size()){
        value = m_array[pos];
        return true;
    }
    else return false;
}

bool Sequence::set(int pos, const ItemType& value){
    if (0 <= pos && pos < size()){
        m_array[pos] = value;
        return true;
    }
    else return false;
}

int Sequence::find(const ItemType& value) const{
    
    
    int p = -1;
    for (int i = 0; i < size(); i++){
        if (m_array[i] == value){
            p = i;
            break;
        }
    }
    return p;
}

void Sequence::swap(Sequence& other){ 
    Sequence temp = other;
    other = *this;
    *this = temp;
}

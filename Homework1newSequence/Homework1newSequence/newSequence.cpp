#include "newSequence.h"
#include <iostream>

using namespace std;

//constructors
Sequence::Sequence(const int& input): m_capacity(input), m_size(0){
    m_ptr = new ItemType[input];
}

Sequence::Sequence(): m_size(0), m_capacity(DEFAULT_MAX_ITEMS){ //
    m_ptr = new ItemType[DEFAULT_MAX_ITEMS];
}

//copy constructor
Sequence::Sequence(const Sequence& other){
    m_size = other.m_size;
    m_ptr = new ItemType[m_size];
    
    m_capacity = other.m_capacity;
    
    ItemType* ptrToOther = other.m_ptr;
    ItemType* ptrToMine = m_ptr;
    
    for (int i = 0; i < m_size; i++){
        *ptrToMine++ = *ptrToOther++;
    }
}

//operator=
Sequence& Sequence::operator=(const Sequence& seq){
    if (this != &seq){
        Sequence temp = seq;
        swap(temp);
    }
    return *this;
}

//destructor
Sequence::~Sequence(){
    delete [] m_ptr;
}

//member functions
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
    if (pos < 0 || pos > m_size || m_size == m_capacity)
        return -1;
    
    int tracker = m_size;
    
    while (tracker != pos)
    {
        m_ptr[tracker] = m_ptr[tracker - 1];
        tracker--;
    }
    
    m_ptr[pos] = value;
    m_size++;
    return true;
}

int Sequence::insert(const ItemType& value)
{
    if (size() == m_capacity)
        return -1;
    
    int target = size();
    
    for (int i = 0; i < size(); i++)
        if (value <= m_ptr[i])
        {
            target = i;
            break;
        }
    
    int tracker = size();
    
    while (tracker != target)
    {
        m_ptr[tracker] = m_ptr[tracker - 1];
        tracker--;
    }
    
    m_ptr[target] = value;
    m_size++;
    return target;
}

bool Sequence::erase(int pos){ // i did not change the last value to empty string or smth, i just left it there unchanged
    if (pos >= 0 && pos < size()){
        for (int i = 0; i < size();i++){
            m_ptr[pos] = m_ptr[pos+1];
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
        if (value == m_ptr[i]){
            counter++;
            erase(i);
        }
    }
    return counter;
}

bool Sequence::get(int pos, ItemType& value) const {
    if (pos >= 0 && pos < size()){
        value = m_ptr[pos];
        return true;
    }
    else return false;
}

bool Sequence::set(int pos, const ItemType& value){
    if (0 <= pos && pos < size()){
        m_ptr[pos] = value;
        return true;
    }
    else return false;
}
 
int Sequence::find(const ItemType& value) const{
    
    
    int p = -1;
    for (int i = 0; i < size(); i++){
        if (m_ptr[i] == value){
            p = i;
            break;
        }
    }
    return p;
}

void Sequence::swap(Sequence& other){
    
    // Swap the sizes
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
    
    //Swap the capacities
    int tempCapacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tempCapacity;
    
    // Swap the pointers instead of the values so that you can use normal assignment operator
    ItemType* tempPtr = m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = tempPtr;
}



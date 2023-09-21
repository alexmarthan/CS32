#include "RainfallList.h"

RainfallList::RainfallList(): m_sequence(){}


bool RainfallList::add(unsigned long rainfall){
    if (rainfall <= 400 && rainfall >= 0){
        m_sequence.insert(size(), rainfall); // size() is possibly wrong
        return true;
    }
    return false;
}


bool RainfallList::remove(unsigned long rainfall){

    int position = m_sequence.find(rainfall);
    if (m_sequence.erase(position)){ // hopefully this line also runs the erase function
        return true;
    }
    return false;
}

int RainfallList::size() const{
    return m_sequence.size();
}

unsigned long RainfallList::minimum() const{
    unsigned long value = NO_RAINFALLS;
    unsigned long other;
    m_sequence.get(0,value);
    for (int i = 0; i < m_sequence.size();i++){
        m_sequence.get(i,other);
        if ( value > other){
            value = other;
        }
    }
    return value;
}

unsigned long RainfallList::maximum() const{
    unsigned long value = NO_RAINFALLS;
    unsigned long other;
    m_sequence.get(0,value);
    for (int i = 0; i < m_sequence.size();i++){
        m_sequence.get(i,other);
        if ( value < other){
            value = other;
        }
    }
    return value;
}

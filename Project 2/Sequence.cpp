
#include <iostream>
#include "Sequence.h"

Sequence::Sequence(): m_size(0), head_ptr(nullptr), tail_ptr(nullptr) {} // Sequence constructor

Sequence::Sequence(const Sequence& other): head_ptr(nullptr), tail_ptr(nullptr){ // copy constructor
    m_size = 0;
    Node* node_ptr = other.head_ptr; // initialized as pointing to the head node of other sequence
    while (node_ptr != nullptr ){
        insert(m_size,node_ptr->data); // insert the node
        node_ptr = node_ptr->next; // node_ptr points to next node
    }
}


Sequence::~Sequence(){ //destructor
    Node* node_ptr = head_ptr;
    while (node_ptr != nullptr){
        Node* temp_ptr = node_ptr->next; // temporary ptr points to the next node in list
        delete node_ptr; // delete the node pointed to by node_ptr
        node_ptr = temp_ptr; // node_ptr points to the next node in list
    }
}

Sequence& Sequence::operator=(const Sequence& seq){
    if (this != &seq){
        Sequence temp(seq);
        swap(temp);
    }
    return *this;
}

int Sequence::size() const
{
    return m_size;
}

bool Sequence::empty() const
{
    return size() == 0;
}

int Sequence::insert(int pos, const ItemType& value) {
    if (pos < 0 || pos > m_size) {
        return -1; // check for out of bounds
    }
    Node* new_node = new Node(value);
    
    if (pos == 0) { // inserting at beginning
        if (m_size == 0) { // if empty list
            head_ptr = new_node;
            tail_ptr = new_node;
        }
        else{
            
            new_node->next = head_ptr;
            head_ptr = new_node;
            new_node->next->prev = new_node;
        }
    }
    
    else if (pos == m_size) { // inserting at end
        new_node->prev = tail_ptr;
        tail_ptr = new_node;
        new_node->prev->next = new_node;
    }
    else { // inserting in general case
        Node* current = head_ptr;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
    }
    m_size++;
    return pos; // success
}

int Sequence::insert(const ItemType& value)
{
    int pos = 0;
    Node* placeholder = head_ptr;  // this is a pointer to figure out which position im inserting at
    while (placeholder!= tail_ptr && placeholder->data < value){
        pos++; // increment the insertion position
    }
    return insert(pos, value); // call insert function and return the position
}

bool Sequence::erase(int pos) {
        if (pos < 0 || pos >= m_size) {
            return false; // check for out of bounds
        }
        if (m_size == 1) { // erasing the only node
            delete head_ptr; // delete the node pointed to by head_ptr
            head_ptr = nullptr;
            tail_ptr = nullptr;
        }
        else if (pos == 0) { // erasing first node
            Node* temp = head_ptr;
            head_ptr = head_ptr->next;
            head_ptr->prev = nullptr;
            delete temp;
        }
        else if (pos == m_size-1) { // erasing last node
            Node* temp = tail_ptr;
            tail_ptr = tail_ptr->prev;
            tail_ptr->next = nullptr;
            delete temp;
        }
        else { // erasing any other node
            Node* current = head_ptr;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        m_size--;
        return true;
    }

int Sequence::remove(const ItemType& value)
{
    int counter = 0; // initialize a counter variable at zero
    
    while (find(value) != -1){ // while there is still a node with the value "value" keep running
        if (erase(find(value)) == true){ // erase the node at that position
            counter++; // increment the counter only if
        }
    }
    return counter; // return the number of nodes erased
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= size()) // check for out of bounds
        return false;
    
    Node* placeholder = head_ptr;  // create a pointer that will iterate through the linked list
    int i = 0;
    while (i!=pos){
        placeholder = placeholder->next;
        i++;
    }
    value = placeholder->data; // the data of the node at pos is placed in the value object
    return true;
}
 
bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= size()) // check for out of bounds
        return false;
    
    Node* placeholder = head_ptr;  // create a pointer that will iterate through the linked list
    int i = 0;
    while (i!=pos){
        placeholder = placeholder->next;
        i++;
    }
    placeholder->data = value; // the data of the node at pos is set to the object value
    return true;
}
 
int Sequence::find(const ItemType& value) const
{
    Node* nodePtr = head_ptr; // create a ptr and make it point to the first node
    int i(0); 
    while ( i != size()){ // iterating through linked list
        if (nodePtr->data == value){ // if the data in the node has the same value as "value" then return the
            return i;                // position of the node in the linked list
        }
        nodePtr = nodePtr->next; // pointer points to the next node in the list every time it loops
        i++;
    }
    return -1;
}

void Sequence::swap(Sequence& other)
{
    //Swap head nodes
    Node* tempHead = head_ptr;
    head_ptr = other.head_ptr;
    other.head_ptr = tempHead;
    
    //Swap tail nodes
    Node* tempTail = tail_ptr;
    tail_ptr = other.tail_ptr;
    other.tail_ptr = tempTail;
    
    // Swap sizes
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

///
// Sequence Algorithms
///

int subsequence(const Sequence& seq1, const Sequence& seq2){
    ItemType value;
    seq2.get(0,value); // this places the value of the first member of list in value var
    
    int startPos = seq1.find(value); // find the first member of seq2's sequence in seq 1
    if (startPos == -1){ // if seq1 doesnt contain the first element of seq2
        return(-1);
    }
    
    Sequence tempseq = seq1; // create a temp sequence
    int nbOfErases(0);
    while (startPos != -1){
        startPos = tempseq.find(value); // find first value corresponding to that value
        
        int counter(0);
        
        for (int index = 0; index < seq2.size(); index++){ // repeatedly check if the following values in seq1
            ItemType value1, value2;                       // match all values in seq2
            tempseq.get(startPos + index,value1);
            seq2.get(index,value2);
            if (value1==value2){
                counter++;
            }
            else break;
        }
        if (counter == seq2.size()){
            return startPos + nbOfErases;
        }
        
        tempseq.erase(startPos); // erase that value
        nbOfErases++;
    }
           
    
    return (-1);
}

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result){
    
    result = Sequence(); // clear the result sequence
    
    result = seq2;
    ItemType value;
    
    // concatenation
    for (int i = 0; i < seq1.size(); i++){ // this loop appends seq1 to seq2 in result
        seq1.get(i,value);
        result.insert(seq2.size() + i,value);
    } // result sequence holds the concatenation: seq2+seq1
    
    // reverse
    Sequence temp; // creation of temp sequence
    for (int i = 0; i < result.size();i++){ // iterating forwards through temp, and backwards through result
        result.get(result.size()-i-1,value);
        temp.insert(i,value);
    }
    temp.swap(result); // swap temp with result
}

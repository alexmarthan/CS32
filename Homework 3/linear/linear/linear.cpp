
#include <iostream>
#include <string>
using namespace std;

bool somePredicate(string s)
{
    int nDigits = 0;
    for (int k = 0; k != s.size(); k++)
    {
        if (isdigit(s[k]))
            nDigits++;
    }
    return nDigits == 10;
}

bool allTrue(const string a[], int n)
{
    if (n <= 0){return true;}

    bool b(true);
    if (somePredicate(*a) == false){
        return false;
    }
    if (n > 1){
        b = allTrue(a+1,n-1);
    }
    return b;
}

int countTrue(const string a[], int n)
{
    if (n <= 0){return 0;}
    int counter(0);
    if (n > 0){
        if (somePredicate(*a)){ // if true
            counter = 1; // increment counter (could be counter++ too)
        }
    }
    if (n > 1){
        counter+= countTrue(a+1,n-1);
    }
    return counter;
}

int firstTrue(const string a[], int n)
{
    int position(0);
    if (n > 0){
        if (somePredicate(*a)){
            return position;
        }
        else {
            position = firstTrue(a+1,n-1);
            if (position >= 0){
                position++;
            }
        }
    }
    else position = -1; // if never
    
    return position;
}


// Return the subscript of the first string in the array that is >= all
// strings in the array (i.e., return the smallest subscript m such
// that a[m] >= a[k] for all k from 0 to n-1).  If the function is told
// that no strings are to be considered to be in the array, return -1.

int positionOfMax(const string a[], int n)
{
    if (n <=0 ) {return -1;}
    else if (n == 1) return 0;
    else{
        int max_index = positionOfMax(a,n-1);
        if (a[n-1] > a[max_index]){
            max_index = n-1;
        }
        return max_index;
    }
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "john" "sonia" "elena" "ketanji" "sonia" "elena" "samuel"
// then the function should return true if a2 is
//    "sonia" "ketanji" "samuel"
// or
//    "sonia" "elena" "elena"
// and it should return false if a2 is
//    "sonia" "samuel" "ketanji"
// or
//    "john" "ketanji" "ketanji"
bool contains(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 == 0) { return true;}
    if (n1 == 0) { return false;}
    if (n1 < n2) { return false;}
    
    if (*a2 == *a1){
        if (contains(a1+1,n1-1,a2+1,n2-1)){
            return true;
        }
    }
    return contains(a1+1,n1-1,a2,n2); // go to next string in a1 to see if a2 equals that
    
}




int main(){
    string arr[] = {"0123456789"};
    string arr2[] = {"0123456789","1111111111", "2", "3", "4", "5", "6", "7", "8", "9"};
    string arr3[] = {"2", "3", "4", "5", "6", "7", "8"};
    string arr4[] = {"1","1234567894"};
    string arr5[] = {"1234567894","1"};

    assert(allTrue(arr,1) == true);
    assert(allTrue(arr2,10) == false);
    assert(allTrue(arr2,1) == true);
    assert(allTrue(arr2,2) == true);
    assert(allTrue(arr2,-2) == true);


    assert(countTrue(arr,1) == 1);
    assert(countTrue(arr2,2) == 2);
    assert(countTrue(arr2,8) == 2);
    assert(countTrue(arr2,-2) == 0);

    assert(firstTrue(arr,1) == 0);
    assert(firstTrue(arr2,8) == 0);
    assert(firstTrue(arr3,7) == -1);
    assert(firstTrue(arr3,-2) == -1);
    assert(firstTrue(arr4,2) == 1);

    assert(positionOfMax(arr,1) == 0);
    assert(positionOfMax(arr2,4) == 3);
    assert(positionOfMax(arr3,3) == 2);
    assert(positionOfMax(arr3,7) == 6);
    assert(positionOfMax(arr5,2) == 0);

    assert(contains(arr2, 7, arr, 1) == true);
    assert(contains(arr2, 10, arr3, 7) == true);
    std::cout << "tests passed" << endl;


}



#include <iostream>

using namespace std;

// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "john" "sonia" "elena" "ketanji" "sonia" "elena" "samuel"
// then for this value of a2            the function must return
//    "john" "ketanji" "elena"                     1
//    "john" "elena" "samuel"                      2
//    "ketanji" "john" "elena"                     0
//    "sonia" "elena" "samuel"                     3


int countIncludes(const std::string a1[], int n1, const std::string a2[], int n2)
{
    if (n2 == 0){
        return 1;
    }
    if (n1 == 0){ //
        return 0;
    }
    if (n2 > n1){
        return 0;
    }
    if (*a1 == *a2){
        return countIncludes(a1+1,n1-1,a2,n2) + countIncludes(a1+1,n1-1,a2+1,n2-1); //this is good
    }
    else{
        return countIncludes(a1+1,n1-1,a2,n2); // this is good
    }
}

// Exchange two strings
void exchange(std::string& x, std::string& y)
{
    std::string t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < separator come before all the other elements,
// and all the elements whose value is > separator come after all
// the other elements.  Upon return, firstNotLess is set to the
// index of the first element in the rearranged array that is
// >= separator, or n if there is no such element, and firstGreater is
// set to the index of the first element that is > separator, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < separator
//   * for firstNotLess <= i < firstGreater, a[i] == separator
//   * for firstGreater <= i < n, a[i] > separator
// All the elements < separator end up in no particular order.
// All the elements > separator end up in no particular order.
void separate(std::string a[], int n, std::string separator,
              int& firstNotLess, int& firstGreater)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < separator
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == separator
    //  Every element from firstUnknown to firstGreater-1 is not known yet
    //  Every element at position firstGreater or later is > separator
    
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > separator)
        {
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < separator)
            {
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(std::string a[], int n) // this is kind of like the sort function, go to the smallest case and call separate
{
    int firstNotLess(0), firstGreater(0);
    if (n > 1){
        separate(a,n, a[0], firstNotLess, firstGreater); // keep separating in two, til I get
        order(a,n-1); // call order on the first half of function
        order(a+1,n-1); // call order on second half of function
    }
    
    return;  // This is not always correct.
}


//int main () {
//
//
//    std::string myArr[3] = {"a", "b", "c"};
//    std::string myArr2[5] = {"a","b", "c", "b","c"};
//    std::string myArr4[6] = {"a","b", "c", "b","c","c"};
//
//    std::string Array[] = {"john", "sonia", "elena", "ketanji", "sonia", "elena", "samuel"};
//    std::string Array2[] = {"john", "ketanji", "elena"};
//    std::string Array5[] = {"john", "elena", "samuel"};
//    std::string Array3[] = {"ketanji", "john", "elena"};
//    std::string Array4[] = {"sonia", "elena", "samuel"};
//
//    std::cout << countIncludes(Array, 7, Array2, 3) << '\n'; // 1
//    std::cout << countIncludes(Array, 7, Array5, 3) << '\n'; // 2
//    std::cout << countIncludes(Array, 7, Array3, 3) << '\n'; // 0
//    std::cout << countIncludes(Array, 7, Array4, 3) << '\n'; // 3
//
//    std::string f[16] = {"4","7","0","f","2","4","5","e","a","1","0","6","c","e","4","8"};
//    std::string g[16] = { "0", "0", "1", "2", "4", "4", "4", "5", "6", "7", "8", "a", "c", "e", "e", "f" };
//
//    order(f,16);
//    assert(equal(f,f+16,g));
//
//
////
////    std::cout << countIncludes(myArr2, 5, myArr, 3); // should be 3
////    std::cout << countIncludes(myArr4, 6, myArr, 3); // should be 5
////
//
//    order(myArr4,6);
//    for (int i =0; i < 6; i++){
//        std::cout << myArr4[i] << '\n';
//    }
//
//}

void testone(int n)
{

    string a[10] = { "", "", "#", "", "#", "", "#", "#", "", "" };
    string aa[10] = { "#", "#", "", "#", "", "#", "", "", "#", "#" };
    string x[10] = { "2", "7", "4", "8", "9", "0", "9", "9", "8", "6" };
    string y[10] = { "8", "10", "0", "9", "4", "5", "#", "2", "12", "6" };
    string b[4] = { "10", "0", "4", "2" };
    string c[8] = { "1", "9", "7", "3", "9", "7", "5" };
    string d[12] = { "1", "3", "7", "1", "7", "5", "3", "1", "7", "9", "7", "5" };
    string f[16] = { "4", "7", "0", "f", "2", "4", "5", "e", "a", "1", "0", "6", "c", "e", "4", "8" };
    string g[16] = { "0", "0", "1", "2", "4", "4", "4", "5", "6", "7", "8", "a", "c", "e", "e", "f" };

    switch (n)
    {
                     case 49: {
        assert(countIncludes(c, 0, d, 0) == 1);
            } break; case 50: {
        assert(countIncludes(c, 7, d, 0) == 1);
            } break; case 51: {
        assert(countIncludes(c, 2, d+2, 1) == 0);
            } break; case 52: {
        assert(countIncludes(c, 7, d, 3) == 1);
            } break; case 53: {
        assert(countIncludes(c, 7, d+3, 3) == 2);
            } break; case 54: {
        assert(countIncludes(c, 7, d+6, 3) == 0);
            } break; case 55: {
        assert(countIncludes(c, 7, d+9, 3) == 3);
            } break; case 56: {
        assert(countIncludes(c, 7, d+2, 1) == 2);
            } break; case 57: {
        auto i = f[0];
        order(f, 1);
        assert(f[0] == i);
            } break; case 58: {
        auto i = f[0];
        order(f, 0);
        assert(f[0] == i);
            } break; case 59: {
        order(f, 16);
        assert(equal(f, f+16, g));
            } break;
    }
}

int main()
{
//    cout << "Enter test number: ";
//    int n;
//    cin >> n;
//    if (n < 1  ||  n > 63)
//    {
//        cout << "Test number must be 1-63" << endl;
//        return 1;
//    }
    for (int n = 49; n < 60; n++){
        testone(n);
    }
    cout << "Passed" << endl;
}


#include <iostream>
#include "Sequence.h"

using namespace std;
int main(){

//    Sequence s;
//    s.insert(0, "caine");
//    s.insert(1, "abel");
//    s.insert(2, "");
//    s.insert(3, "jesus");
//    assert(s.find("") == 2);
//    s.remove("caine");
//    assert(s.size() == 3  &&  s.find("abel") == 0  &&  s.find("") == 1  &&
//                s.find("jesus") == 2);
    
    Sequence s1;
        s1.insert(0, "cool");
        s1.insert(0, "hot");
        Sequence s2;
        s2.insert(0, "warm");
        s1.swap(s2);
        assert(s1.size() == 1  &&  s1.find("warm") == 0  &&  s2.size() == 2  &&
                    s2.find("hot") == 0  &&  s2.find("cool") == 1);
    
    Sequence s;
        s.insert(0, "a");
        s.insert(1, "b");
        s.insert(2, "d");
        s.insert(3, "b");
        s.insert(4, "c");
        assert(s.remove("b") == 2);
        assert(s.size() == 3);
        string y;
        assert(s.get(0, y)  &&  y == "a");
        assert(s.get(1, y)  &&  y == "d");
        assert(s.get(2, y)  &&  y == "c");
    
    Sequence par, rot;
    par.insert(0,"p");
    par.insert(1,"a");
    par.insert(2,"r");

    rot.insert(0,"r");
    rot.insert(1,"o");
    rot.insert(2,"t");

    Sequence bay = rot;

    concatReverse(par, rot, bay);
    
    assert(bay.find("r") == 0 );
    assert(bay.find("a") == 1 );
    assert(bay.find("p") == 2 );
    assert(bay.find("t") == 3 );
    assert(bay.find("o") == 4 );
    bay.erase(0);
    assert(bay.find("r") == 4 );


    return(0);
}

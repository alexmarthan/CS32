// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).

#include "Dictionary.h"
#include <string>
#include <list>
#include <cctype>
#include <utility>  // for swap
#include <vector>

#include <functional> // for stl hash function

using namespace std;

void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);



// END OF MY HASH TABLE CLASS ************

  // This class does the real work of the implementation.

class DictionaryImpl
{
  public:
    DictionaryImpl(int maxBuckets) : m_words(maxBuckets){}
    ~DictionaryImpl() {}
    void insert(string word);
    void lookup(string letters, void callback(string)) const;
  private:
    size_t myHashFunc(const string& word) const;
    vector<list<string>> m_words;
};

size_t DictionaryImpl::myHashFunc(const string& word) const{
    std::string sorted = word;
    sort(sorted.begin(),sorted.end());
    std::hash<std::string> hasher;
    return hasher(sorted) % m_words.size();
}


void DictionaryImpl::insert(string word)
{
    removeNonLetters(word);
    if ( ! word.empty())
        m_words[myHashFunc(word)].push_back(word);
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
        
    if (callback == nullptr)
        return;

    removeNonLetters(letters);
    if (letters.empty())
        return;
    
    
    string unsorted = letters;
    sort(letters.begin(),letters.end());
    size_t key = myHashFunc(letters);
    
    for (string iter : m_words[key]){
        string unsorted = iter;
        sort(iter.begin(),iter.end());
        if (iter == letters){
            callback(unsorted);
        }
    }
}

void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
}

  

//******************** Dictionary functions ******************************

// These functions simply delegate to DictionaryImpl's functions
// You probably don't want to change any of this code

Dictionary::Dictionary(int maxBuckets)
{
    m_impl = new DictionaryImpl(maxBuckets);
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters,callback);
}

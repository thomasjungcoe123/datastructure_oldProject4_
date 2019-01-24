#ifndef TOM_TTREE_H
#define TOM_TTREE_H

#include <iostream>
#include <list>
using namespace std;
class ttree;
class tnode;

class ttreeException: public exception{

public:
    virtual const char* what() const throw(){
        return "Ttree exception";
    }
};

class ttreeNotFound: public ttreeException{

    virtual const char* what() const throw(){
        return "not found";
    }
};

class ttree
{
private:
    tnode* _tnodes;  // pointer to _tnodes, a tnode
    // array of size 26 will be created
    // in the constructor
    int _maxDepth;  // max depth allowance
    int _currentDepth; // the depth of current node ( root is depth 1)
public:
    ttree();  // set the maxDepth to 5 in the empty constuctor
    ttree( int maxDepth);  // constructor with given maxDepth value
    ~ttree();
    void insert(string key);  // insert 'key' into the tree
    void search(string key);  // search for 'key' in the tree and
    // print out all the matches
    int getCurrentDepth();
    void insertIntoWords(list<string> *words, const string &key);
    int getMaxDepth();
    void setCurrentDepth(int currentDepth);
    void search_helper(string key, int depth, int &count);
    void setMaxDepth(int maxDepth);
    // ostream operator and other methods
    friend ostream &operator<<(ostream& output, const ttree &T);
};

class tnode
{
private:
    ttree* _nextLevel;  // pointer to the ttree at the next level
    list<string>*   _words;  // store keywords
public:
    tnode();
    ~tnode();
    ttree* getNextLevel();
    list<string>* getWords();
    void setNextLevel(ttree* nextLevel);
    void setWords(list<string>* words);

    // ostream operator and other methods
};


#endif //TOM_TTREE_H

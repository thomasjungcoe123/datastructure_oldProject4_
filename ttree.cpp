#include "ttree.h"

// helper function
// that help find the number of common prefix between two strings
// return type int and taking two const string params
int lengthOfCommonPrefix(const string &s1, const string &s2){
    // whichever has less length gets the min
    int minLength = (s1.length() > s2.length()) ? s2.length() : s1.length();
    int commonLength = 0;
    for(unsigned int i=0; i<minLength; i++){
        if(s1.at(i) == s2.at(i)){
            // increment common length per each match iteration
            commonLength++;
        }
        else{
            break;
        }
    }
    return commonLength;
}

// insert method for ttree
// takes list of type string as well as a key of type string
// to insert the the word into the list
void ttree::insertIntoWords(list<string> *words, const string &key){
    // iterator starting from pos 1
    auto it = words->begin();
    // looping through words
    while(it != words->end()){
        // compare and increment
        if(it->compare(key) < 0)
            it++;
        else
            break;
    }
    // if end of the iterator is reached. put the it in the back
    if(it == words->end())
        words->push_back(key);
    else
        // or inert it
        words->insert(it, key);

    //Re-organize
    /*it = words->begin();
    while(it != words->end()){

        string prevWord = *it;
        it++;
        if(it != words->end() && lengthOfCommonPrefix(prevWord, *it) > _currentDepth){

        }
        words->remove(*it);
        insert(*it);
    }*/

}

// default constructor of ttree class
ttree::ttree() {
    //It is given that the default
    //constructor should set the maxDepth to 5
    _maxDepth = 5;
    _currentDepth = 1;
    //_tnodes is an array of 26 tnode objects
    _tnodes = new tnode[26];

}

// copy constructor of ttree class
ttree::ttree(int maxDepth) {
    // initializing maxDepth with the param
    _maxDepth = maxDepth;
    _currentDepth = 1;
    _tnodes = new tnode[26];
}

// destructor
ttree::~ttree()
{
    delete(_tnodes);
    _tnodes = nullptr;
}

// helper method #2
//s1 begins with s2
bool begins_with(const string& s1, const string& s2){
    //If s2's length is greater, return false
    if(s2.length() > s1.length())
        return false;

    const char *array1 = s1.c_str();
    const char *array2 = s2.c_str();
    //Check if all the chars in s2 are present in s1
    for(int i=0; i < s2.length(); i++){
        if(array1[i] != array2[i]){
            return false;
        }
    }
    return true;
}

// search helper method of ttree class
void ttree::search_helper(string key, int depth, int& count){

    if(depth <= key.length()-1){
        tnode& node = _tnodes[key[depth]-'A'];
        ttree* nextlevel = node.getNextLevel();
        if(nextlevel != nullptr){
            nextlevel->search_helper(key, depth+1, count);
        }
        if(node.getWords() != nullptr){
            auto it = node.getWords()->begin();
            while(it != node.getWords()->end()){
                if(begins_with(*it, key)){
                    cout << *it << " ";
                    count++;
                }
                it++;
            }
        }
    }
    else{
        //Search all the nodes at this level
        for(int i=0; i<26; i++){
            tnode& node = _tnodes[i];
            ttree* nextlevel = node.getNextLevel();
            if(nextlevel != nullptr){
                nextlevel->search_helper(key, depth+1, count);
            }
            if(node.getWords() != nullptr){
                auto it = node.getWords()->begin();
                while(it != node.getWords()->end()){
                    if(begins_with(*it, key)){
                        cout << *it << " ";
                        count++;
                    }

                    it++;
                }
            }
        }
    }
}

// search method of ttree class
void ttree::search(string key) {
    int count = 0;
    search_helper(key, 0, count);
    if(count == 0)
    {
        throw ttreeNotFound();
    }
}

// insert method of ttree class taking a key as a param of type string
void ttree::insert(string key) {

    if(key.length() == 0)
        return;

    tnode& nodeToInsertIn = _tnodes[key[_currentDepth-1]-'A'];
    list<string> *words = nodeToInsertIn.getWords();
    //Case 1: Both the _words and _nextLevel are NULL
    if(words == NULL && nodeToInsertIn.getNextLevel() == NULL){
        nodeToInsertIn.setWords(new list<string>);
        nodeToInsertIn.getWords()->push_back(key);
    }
        //Case 2: If the currentDepth == maxDepth, we cannot create next level.
        //So, we should insert this in the words list in sorted order
    else if(_currentDepth == _maxDepth){
        insertIntoWords(words, key);
    }
        //Case 3: If there are elements in the words list of the tnode
        // Then, check for the length of common prefix
        //If the next level isn't empty, then we should insert it in the
    else if(words == nullptr){
        nodeToInsertIn.getNextLevel()->insert(key);
    }
        //Both aren't null
    else{
        auto it = words->begin();
        while(it != words->end()) {
            if (it->compare(key) < 0)
                it++;
            else
                break;
        }

        //
        if(it != words->end() ){
            string nextWord = *it;
            string prevWord = "";
            if(it != words->begin()){
                it--;
                prevWord = *it;
                it++;
            }
            if(prevWord == "")
            {
                if(lengthOfCommonPrefix(key, nextWord) <= _currentDepth){
                    insertIntoWords(words, key);
                    return;
                }
            }
            else{
                if(lengthOfCommonPrefix(key, nextWord) <= _currentDepth && lengthOfCommonPrefix(key,prevWord) <= _currentDepth){
                    insertIntoWords(words, key);
                    return;
                }
            }

        }
        else{
            it--;
            string prevWord = *it;
            if(lengthOfCommonPrefix(prevWord, key) <= _currentDepth){
                insertIntoWords(words, key);
                return;
            }
        }

        //TODO: Tomorrow. Need to handle the case of insertion
        //TODO: when there are multiple words in the words list
        //Have to find the appropriate postion and then compare with it


        if(nodeToInsertIn.getNextLevel() == NULL){
            ttree* nextLevel = new ttree(_maxDepth);
            nextLevel->setCurrentDepth(_currentDepth+1);
            nodeToInsertIn.setNextLevel(nextLevel);
            nextLevel->insert(key);
            auto it = words->begin();
            while(it != words->end()){
                nextLevel->insert(*it);
                it++;
            }
            words->clear();
            delete(words);
            words = nullptr;
            nodeToInsertIn.setWords(words);
        }
        else {
            ttree* nextLevel = nodeToInsertIn.getNextLevel();
            nextLevel->insert(key);
            auto it = words->begin();
            while (it != words->end()){
                nodeToInsertIn.getNextLevel()->insert(*it);
                it++;
            }
            words->clear();
            delete(words);
            words = nullptr;
            nodeToInsertIn.setWords(words);
        }
    }
}

// getter for fields
int ttree::getCurrentDepth() { return _currentDepth; }
int ttree::getMaxDepth() { return _maxDepth; }

// setter for fields
void ttree::setCurrentDepth(int currentDepth) { _currentDepth = currentDepth; }
void ttree::setMaxDepth(int maxDepth) { _maxDepth = maxDepth; }

// default constructor of tnode
tnode::tnode() {
    this->_nextLevel = nullptr;
    this->_words = nullptr;
}

// destructor of tnode
tnode::~tnode() {
    delete(this->_words);
    delete(this->_nextLevel);
}

// getter for tnode fields
ttree* tnode::getNextLevel() { return _nextLevel; }
list<string>* tnode::getWords() { return _words; }

// setter for tnode fields
void tnode::setNextLevel(ttree *nextLevel) { _nextLevel = nextLevel; }
void tnode::setWords(list<string> *words) { _words = words; }

// operator << of tnode
ostream& operator<<(ostream &output, const ttree &T) {
    //Print leading "_"
    if(T._tnodes == nullptr){
        output << "";
        return output;
    }

    for(int i=0; i<26; i++){
        tnode& currentTNode = T._tnodes[i];
        //If the current t-node doesn't have a next level and a words list
        if(currentTNode.getWords() == nullptr && currentTNode.getNextLevel() == nullptr){
            continue;
        }

        char c = (char)(i+'A');
        for(int j=1; j<T._currentDepth; j++){
            //output << "__";
            output << "   ";
        }
        output << c << " ";

        if(currentTNode.getWords() != nullptr){

            auto it = currentTNode.getWords()->begin();
            while(it != currentTNode.getWords()->end()){
                output << *it << " ";
                it++;
            }
        }
        output << endl;
        if(currentTNode.getNextLevel() != nullptr)
            output << *currentTNode.getNextLevel();
    }
}
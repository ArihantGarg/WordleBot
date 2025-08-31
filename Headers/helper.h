#include <vector>
#include "constants.h"
using namespace std;

int WORD_SIZE;
string answerWord = ANSWER_WORD; 
vector<string> possibleAnswerWordList;
vector<string> possibleNonAnswerWordList;

// Converts any lowercase characters in the guess to uppercase
string toUpper(string s){
    for(auto &c:s){
        if(c >= 'a' && c <= 'z')
            c = (c - 'a') + 'A'; 
    }

    return s;
}
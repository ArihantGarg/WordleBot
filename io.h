#include <fstream>
#include <cassert>
#include <random>
#include <chrono>
#include "helper.h"
using namespace std;

void fillVectorFromFileStream(vector<string>& vectorToFill,ifstream& FileInput){
    string curWord;
    while(FileInput >> curWord){
        vectorToFill.push_back(curWord);
    }
}

void fillAnswerWordList(){
    ifstream answerWordListFileInput(ANSWER_WORD_FILE_PATH);
    fillVectorFromFileStream(possibleAnswerWordList,answerWordListFileInput);
}

void fillNonAnswerWordList(){
    ifstream nonAnswerWordListFileInput(NON_ANSWER_WORD_FILE_PATH);
    fillVectorFromFileStream(possibleNonAnswerWordList,nonAnswerWordListFileInput);
}

void validateInput(){
    assert(possibleAnswerWordList.size() != 0); // List of answers must be greater than 0
    assert(MAX_GUESS_LIMIT > 0); // Max guess limit must be greater than 0
    
    // All words must have the same size
    for(auto curWord : possibleAnswerWordList){
        assert(curWord.size() == possibleAnswerWordList[0].size());
    }
    // All words must have the same size
    for(auto curWord : possibleNonAnswerWordList){
        assert(curWord.size() == possibleNonAnswerWordList[0].size());
    }

    // ANSWER_WORD must be either "" or exist in possibleAnswerList
    if(ANSWER_WORD != ""){
        bool exists = false;
        for(auto curWord : possibleAnswerWordList){
            if(curWord == ANSWER_WORD){
                exists = true;
                break;
            }
        }

        assert(exists == true);
    }
}

string chooseRandomWord(){ // Chooses a random word as the answer
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    return possibleAnswerWordList[rng() % ((int)(possibleAnswerWordList.size()))];
}

void inputFiles(){
    fillAnswerWordList();
    fillNonAnswerWordList();
    validateInput();

    WORD_SIZE = (int)(possibleAnswerWordList[0].size());
    answerWord = ANSWER_WORD;
    if(ANSWER_WORD == ""){
        answerWord = chooseRandomWord();
    }
}



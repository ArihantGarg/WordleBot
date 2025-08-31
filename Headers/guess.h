#include <set>
#include <vector>
#include "io.h"
#include "colour.h"
using namespace std;

enum guessColor{
    Green, // Perfect letter match at that position, priority 1 for match.
    Yellow, // After greens, among remaining letters, going left to right, this letter exists somewhere in the word that hasn't been marked yet and now the letter is marked, priority 2 (left to right)
    Grey, // Does not exist in that position, and also does not occur any more times in word than already yellow and green occurrences, priority 2 (left to right).
    Undefined, // Not Initialised Yet
};

class Guess {

private:
    string _wordGuess;
    vector<guessColor> _wordGuessColor; 

public:
    Guess(string wordGuess) : _wordGuess(wordGuess),_wordGuessColor(WORD_SIZE,Undefined)  {
        initialiseColor();
    }
    
    void initialiseColor(){
        // Priority 1 : Green
        multiset<char> unmatchedLetterMultiset;
        for(int index = 0; index < WORD_SIZE; index++){
            if(answerWord[index] == _wordGuess[index]){
                _wordGuessColor[index] = Green;
            }
            else{
                unmatchedLetterMultiset.insert(answerWord[index]);
            }
        }

        // Priority 2 : Left to Right (Yellow and Grey)
        for(int index = 0; index < WORD_SIZE; index++){
            if(_wordGuessColor[index] != Green){
                if(unmatchedLetterMultiset.find(_wordGuess[index]) != unmatchedLetterMultiset.end()){
                    unmatchedLetterMultiset.erase(unmatchedLetterMultiset.find(_wordGuess[index]));
                    _wordGuessColor[index] = Yellow;
                }
                else{
                    _wordGuessColor[index] = Grey;
                }
            }
        }
    }

    void printGuess(){
        for(int i = 0; i < _wordGuess.size(); i++){
            switch(_wordGuessColor[i]){
                case Green:
                    Colour::printChar(Colour::colourType::Green,_wordGuess[i]);
                    break;
                case Yellow:
                    Colour::printChar(Colour::colourType::Yellow,_wordGuess[i]);
                    break;
                case Grey:
                    Colour::printChar(Colour::colourType::Grey,_wordGuess[i]);
                    break;
                default:
                    cout<<"Error, undefined colour\n";
            }
        }

        cout<<"\n";
    }
};
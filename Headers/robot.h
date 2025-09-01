#include <map>
#include <algorithm>
using namespace std;

int calcHash(vector<guessColor> v){
    int curThreePowerValue = 1;
    int hashValue = 0;
    for(int guessColor : v){
        hashValue += curThreePowerValue * guessColor;
        curThreePowerValue *= 3;
    }

    return hashValue;
}

void robot(){
    ofstream printToOutFile("out_raise.txt"); // Set to out_FIRSTWORD.txt
    printToOutFile << "Robot starting...\n";
    printToOutFile.flush();

    int currentWordCount = 0;
    int currentGuessCount = 0;

    for(auto wordToGuess:possibleAnswerWordList){
        answerWord = wordToGuess;
        vector<string> curAnswerWordList = possibleAnswerWordList;
        vector<string> curGuessWordList = possibleAnswerWordList;
        for(auto guessWord:possibleNonAnswerWordList){
            curGuessWordList.push_back(guessWord);
        }

        //

        string previousGuess = "";
        int previousHashValue;
        int numGuesses = 0;

        cout << "\nTo Guess : "<<answerWord<<"\n";

        do{
            // Updating word list

            if(numGuesses != 0){
                vector<string> updatedAnswerWordList;

                for(auto possibleAnswer : curAnswerWordList){
                    Guess currentGuess(previousGuess,possibleAnswer);   
                    int currentHashValue = calcHash(currentGuess.getVectorGuessColor());

                    if(currentHashValue == previousHashValue){
                        updatedAnswerWordList.push_back(possibleAnswer);
                    }
                }

                curAnswerWordList = updatedAnswerWordList;
            }

            // Optimization
            if(numGuesses == 0){
                numGuesses++;
                previousGuess = "RAISE";
                cout << "Guess " << numGuesses << " : ";
                
                // Resulting Hash Value

                Guess guessResult(previousGuess,answerWord);
                guessResult.printGuess();
                previousHashValue = calcHash(guessResult.getVectorGuessColor());
                continue;
            }
            else if(numGuesses == 1 && previousHashValue == 242){
                numGuesses++;
                previousGuess = "BLUDY";
                cout << "Guess " << numGuesses << " : ";
                
                // Resulting Hash Value

                Guess guessResult(previousGuess,answerWord);
                guessResult.printGuess();
                previousHashValue = calcHash(guessResult.getVectorGuessColor());
                continue;
            }

            // Finding next best guess

            string bestGuess = "Invalid";
            int bestGuessMinSize = INT_MAX;
            bool flagIsBestGuessPresentInAnswerList = false;

            if(curAnswerWordList.size() == 1){
                // Only 1 answer possible
                bestGuess = curAnswerWordList[0];
                bestGuessMinSize = 1;
                flagIsBestGuessPresentInAnswerList = true;

                numGuesses++;
                previousGuess = bestGuess;
                cout << "Guess " << numGuesses << " : ";
                
                // Resulting Hash Value

                Guess guessResult(previousGuess,answerWord);
                guessResult.printGuess();
                previousHashValue = calcHash(guessResult.getVectorGuessColor());
                cout.flush();

                continue;
            }

            for(auto possibleGuess : curGuessWordList){
                int curGuessMaxSize = 0;
                map<int,int> wordsLeft;

                for(auto possibleAnswer : curAnswerWordList){
                    Guess currentGuess(possibleGuess,possibleAnswer);
                    int hashValue=calcHash(currentGuess.getVectorGuessColor());

                    wordsLeft[hashValue]++;
                    if(wordsLeft[hashValue] > curGuessMaxSize){
                        curGuessMaxSize = wordsLeft[hashValue];
                    }
                }

                if(curGuessMaxSize < bestGuessMinSize){
                    bestGuess = possibleGuess;
                    bestGuessMinSize = curGuessMaxSize;
                }
                else if(!flagIsBestGuessPresentInAnswerList && curGuessMaxSize == bestGuessMinSize && find(curAnswerWordList.begin(),curAnswerWordList.end(),possibleGuess)!=curAnswerWordList.end()){
                    bestGuess = possibleGuess;
                    bestGuessMinSize = curGuessMaxSize;
                    flagIsBestGuessPresentInAnswerList = true;
                }
            }

            // Printing current guess number

            numGuesses++;
            previousGuess = bestGuess;
            cout << "Guess " << numGuesses << " : ";
            
            // Resulting Hash Value

            Guess guessResult(previousGuess,answerWord);
            guessResult.printGuess();
            previousHashValue = calcHash(guessResult.getVectorGuessColor());
            cout.flush();
        }
        while(previousGuess != answerWord);

        cout << "Success in " << numGuesses << " for " << answerWord << "\n";

        printToOutFile << answerWord << " " << numGuesses << "\n";
        printToOutFile.flush();

        currentGuessCount += numGuesses;
        currentWordCount += 1;
        printToOutFile << ((double)(currentGuessCount))/(currentWordCount) << "\n";
    }
}
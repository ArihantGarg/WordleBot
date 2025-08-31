using namespace std;

// Returns false if guess is invalid, else returns true
bool validateGuess(string guessedWord){
    for(auto c:guessedWord){
        if(c < 'A' || c > 'Z')
            return false;
    }

    if((int)(guessedWord.size()) != ((int)answerWord.size()))
        return false;

    for(auto word : possibleAnswerWordList){
        if(guessedWord == word)
            return true;
    }

    for(auto word : possibleNonAnswerWordList){
        if(guessedWord == word)
            return true;
    }

    return false;
}

string next_guess(){
    cout << "\nEnter next guess : ";
    string guessedWord;
    cin >> guessedWord;
    guessedWord = toUpper(guessedWord);

    if(validateGuess(guessedWord) == true){
        return guessedWord;   
    }

    cout << "Invalid guess, try again\n";
    return next_guess();
}

void human(){
    cout << "\n\nWORDLE HUMAN VERSION\n";
    bool correctGuess = false;
    int numGuesses = 0;
    
    while(correctGuess == false && numGuesses < MAX_GUESS_LIMIT){
        numGuesses++;
        string guessedWord = next_guess();

        Guess currentGuess(guessedWord);
        currentGuess.printGuess();

        if(guessedWord == answerWord){
            correctGuess = true;
        }
    }

    if(correctGuess){
        cout << "\nCongratulations, you successfully guessed the word " << answerWord << " in " << numGuesses << " guesses\n\n";
    }
    else{
        cout << "\nYou failed to guess the word " << answerWord << " in " << numGuesses << " guesses\n\n";
    }
}
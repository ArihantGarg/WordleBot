using namespace std;

int MAX_GUESS_LIMIT = 6; // Must be set to expected guess max amount
string ANSWER_WORD = ""; // Leave as "" if you want it to be chosen randomly, else if you want to check a particular word then set it to that word (will throw exception if the word does not exist in the list)
string ANSWER_WORD_FILE_PATH = "Text/possibleAnswerWordList.txt"; // Set to answer word file path relative to repository root
string NON_ANSWER_WORD_FILE_PATH = "Text/possibleNonAnswerWordList.txt"; // Set to non answer word file path relative to repository root
bool IS_HUMAN_PLAYING = 0; // Set to 1 if human is playing, else set to 0 for robot playing

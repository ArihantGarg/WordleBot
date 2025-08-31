using namespace std;

namespace Colour{
    enum colourType{
        Green = 32,
        Yellow = 33,
        Grey = 90,
    };

    void printChar(colourType colour,char outputChar){
        cout << "\033[1;" << colour << "m" << outputChar << "\033[0m";
    }
};

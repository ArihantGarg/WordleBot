#include <iostream>
#include "Headers/guess.h"
#include "Headers/human.h"
#include "Headers/robot.h"
using namespace std;

int main(){
    inputFiles();

    if(IS_HUMAN_PLAYING == 1){
        human();
    }
    else if(IS_HUMAN_PLAYING == 0){
        robot();
    }
    else {
        cout << "Error : IS_HUMAN_PLAYING should be set to either 1 or 0\n";
        return 0;
    }
}
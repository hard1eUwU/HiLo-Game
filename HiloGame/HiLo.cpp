#include <iostream>
#include <string>
#include <ctime>
#include "Add.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int randNum =  getRandomNumber(1, 100);
    bool result = attemps(randNum);
    printResult(result, randNum);
    playAgain(result, getRandomNumber(1, 100));
}

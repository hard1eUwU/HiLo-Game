#include <iostream>
#include "Add.h"

// Функция генерации случайного числа.
int getRandomNumber(int min, int max)
{
    rand();
    rand();
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// Функция с основной логикой программы.
bool attemps(int randNum)
{
    std::cout << "Let's play a game. I'm thinking of a number from 1 to 100. You have 7 tries to guess what it is." << "\n";

    for (int i = 0; i < 7; i++)
    {
        std::cout << i + 1 << "# Guess: ";
        int userNum;
        std::cin >> userNum;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Wrong input. " << std::endl;
            i--;
        }
        else if (userNum > randNum) {
            std::cout << "Too big" << std::endl;
        }
        else if (userNum < randNum) {
            std::cout << "Too small" << std::endl;
        }
        else if (userNum == randNum) {
            return true;
        }
    }
    return false;
    std::cout << std::endl;
}

// Функция вывода победы или поражения.
void printResult(bool result, int randNum) {
    if (result) {
        std::cout << "You won, well done. ";
        std::cout << "The answer is: " << randNum << std::endl;
    }
    else
        std::cout << "You failed. The right answer is: " << randNum << std::endl;
}

// Функция предложения играть снова.
void playAgain(bool result, int randNum)
{
    std::cout << "Do you want to play again [Yes: y][No: n]: ";
    char opt;
    std::cin >> opt;

    switch (opt) {
    case 'y':
        randNum = getRandomNumber(1, 100);
        result = attemps(randNum);
        printResult(result, randNum);
        playAgain(result, randNum);
        break;

    case 'n':
        std::cout << "See you later." << std::endl;
        exit(0);
        break;

    default:
        std::cout << "Wrong input. " << std::endl;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
    }

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong input. " << std::endl;
        playAgain(result, randNum);
    }
}

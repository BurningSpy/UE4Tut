#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    // Print welcome messages
    std::cout << "Bro, you da maan, broo! (Difficulty: " << Difficulty << ")\n\n";
    std::cout << "Put in the code, brooo!\n\n";
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    // declare 3 number code
    const int Number1 = rand() % 5 * Difficulty + 1;
    const int Number2 = rand() % 5 * Difficulty + 1;
    const int Number3 = rand() % 5 * Difficulty + 1;

    const int CodeSum = Number1 + Number2 + Number3;
    const int CodeProduct = Number1 * Number2 * Number3;

    //Print CodeSum and CodeProduct
    std::cout << "Dude... There are 3 numbers in the coode\n";
    std::cout << "The numbers add-up to " << CodeSum << ", maaan\n";
    std::cout << "They also multiply to " << CodeProduct << ". Thats huuge, dude!\n"; // << in between strings or variables instead of +

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct =  GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Yeah dude! You rock! \n\n";
        return true;
    } else {
        std::cout << "Nah, man. You failed, dude\n\n";
        return false;
    }
}


int main() {
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 4;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete){
            LevelDifficulty++;
        }
    }
    std::cout << "\n Yeah Man! That's the Stuff!";
    return 0; 
}
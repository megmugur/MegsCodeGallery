# include <iostream>
# include <ctime>

void Introduction(int DifficultyValue)
{
    std::cout << "\n\nWelcome to Meg's game.\nYou will be given the sum and product of three numbers. Guess the numbers.\n";
}

bool PlayGame(int Difficulty)
{
    std::cout << "\nLevel: " << Difficulty;
    int Code1 = rand () % Difficulty + Difficulty;
    int Code2 = rand () % Difficulty + Difficulty;
    int Code3 = rand () % Difficulty + Difficulty;

    int CodeSum = Code1 + Code2 + Code3;
    int CodeProduct = Code1 * Code2 * Code3;
    std :: cout << "\n\nProduct = " << CodeProduct;
    std :: cout <<"\nSum = " << CodeSum;

    int Guess1, Guess2, Guess3;

    std :: cout << "\nGuess the three numbers:\n";
    std ::cin >> Guess1;
    std ::cin >> Guess2;
    std ::cin >> Guess3;

    int GuessProduct = Guess1 * Guess2 * Guess3;
    int GuessSum = Guess1 + Guess2 + Guess3;

    if (GuessSum == CodeSum && GuessProduct==CodeProduct)
    {
        return true;
    }
    else
    {
        {
            return false;
        }
    }
    
}

// Main function returns 0 to the operating system
int main()
{
    srand(time(NULL)); // This helps to produce more random results based on computer time.
    int DifficultyLevel = 1;
    int MaxDifficulty = 3;
    Introduction (DifficultyLevel);
    while (DifficultyLevel <= MaxDifficulty)
    {
        bool SuccessFlag = PlayGame(DifficultyLevel);
        if (SuccessFlag = true)
        {
            ++DifficultyLevel;
        }
    }
    std::cout << "Yay! You won!\n";
    
    return 0;
}
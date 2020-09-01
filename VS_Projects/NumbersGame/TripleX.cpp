# include <iostream>
# include <ctime>

/* This game gives the the sum and product of three numbers, and asks to player to guess the numbers. */



/* This function displays a welcome message with instructions for the player. */
void Introduction()
{
    std::cout << "\n\nWelcome to Meg's game.\nYou will be given the sum and product of three numbers. Guess the numbers.\n";
}

/* This function displays a welcome message with instructions for the player.
* Key concept used to achieve level difficulty is as follows:
* The higher the value of the Difficulty variable, higher the range of possible remainders when you perform rand() % Difficulty.
* @param Difficulty : inputs the difficulty level.
* @return bool : true when player guesses the numbers correctly. False otherwise.
*/
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
/* Main function returns 0 to the operating system
* Sets the starting and limit of difficulty levels.
* Calls the Introduction function to display opening message, sends difficulty level to PlayGame function.
* If it receives true from the PlayGame function, increments the level and calls the funcion again, until max difficulty is reached.
* @return 0 : sends 0 to the OS.
*/
// 
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
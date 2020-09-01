/* Copyright Meg Mugur 2020
This program works out the logic for the game. Player has to guess a word, an isogram (no repeating letters).
The number of attempts available is dependent on the length of the word.
Bull count is the number of guessed characters that are correct and in the correct position.
Cow count is the number of guessed characters that are correct but in the wrong position.
*/
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HiddenWordList.h"
// #include "Math/UnrealMathUtility.h"   :library for random function, if required in the future.

/*
This function is executed at the start of the game.
Isogram words are loaded and basic game is setup.
More details in the respective, called functions.
*/
void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    Isograms = GetValidWords(Words);
    SetupGame();
}

/*
When the player hits enter, if it is the end of the game, clear the screen and restart the game.
If not, process the guess that the player has made.
*/
void UBullCowCartridge::OnInput(const FString& PlayerInput)
//'const' ensures that PlayerInput does not change within this function.
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(PlayerInput);
    } 
}

/*
Loads a random isogram from the list, displays a message containing the length of the word 
and the number of attempts granted to the player for guessing that word.
*/
void UBullCowCartridge::SetupGame()
{
    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num()-1 )];
    bGameOver = false;

    PrintLine(TEXT("Guess the %i-letter isogram."), HiddenWord.Len());

    Lives = HiddenWord.Len() * 2;
    PrintLine(TEXT("Attempts left = %i"), Lives);
}

/*
If the player's guess is correct, procceeds towards the end.
If not, reduces Lives count, and displays an appropriate message, based on the answer.
If the answer is in the correct format, displays the bull and cow counts. If not, displays error.
*/
void UBullCowCartridge::ProcessGuess(FString Guess)
{

    if (Guess == HiddenWord)
    {
        EndGame();
        return;
    }

    if (HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("Yo! Didn't I say the word length is %i?"), HiddenWord.Len());
        PrintLine(TEXT("Lives left = %i"), Lives);
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("Sigh. No repeating letters!"));
        PrintLine(TEXT("Lives left: %i"), Lives);
        return;
    }

    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        EndGame();
        return;
    }

    FBullCowCount Score = GetBullCows(Guess);        // FBullCowCount is a struct containing two integers : Bulls and Cows.
    PrintLine(TEXT("Lives left: %i"), Lives);
    PrintLine(TEXT("Bulls = %i, Cows = %i"), Score.Bulls, Score.Cows);
}

/*
At the end of the game, clears the screen and displays a success or failure message.
*/
void UBullCowCartridge::EndGame()
{

    bGameOver = true;
    ClearScreen();
    if (Lives > 0) PrintLine (TEXT("Played like a champ. \\o/ \n Now hit enter."));
    else PrintLine(TEXT("SMH. The word was '%s'"), *HiddenWord);
    PrintLine(TEXT("Press enter to play again"), *HiddenWord);
}

/*
This functions checks if the input word is an isogram or not.
This helps us later in the game, to create a list of isograms to make a random selection from.
*/
bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    bool bIsogramFlag = true;
    for (int32 Index = 0; Index < (Word.Len() - 1); Index++)
    {
        for (int32 Comparison = Index +1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word [Comparison])
            {
                bIsogramFlag = false;
            } 
        }
    }

    return bIsogramFlag;
}

/*
This function goes through the list, and makes a sub-list of words that are only 4-8 letters long. 
*/
TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;
    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }
    return ValidWords;
}

/*
This function finds the number of bulls and cows in the player's guess.
*/
FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls ++;
            continue;
        }
        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                Count.Cows ++;
            }
        }
    }
    return Count;
}
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HiddenWordList.h"
// #include "Math/UnrealMathUtility.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    // const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    // FFileHelper::LoadFileToStringArray(WordList, *WordListPath);

    Isograms = GetValidWords(Words);
    SetupGame();

}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
//'const' makes sure that PlayerInput does not change within this function.
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

void UBullCowCartridge::SetupGame()
{
    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num()-1 )];
    bGameOver = false;

    PrintLine(TEXT("Welcome to Word Guess!"));
    PrintLine(TEXT("Level : Easy"), HiddenWord.Len());


    //const TCHAR HW[]= TEXT("cakes");
    //PrintLine(TEXT("Hidden word is: %s"), *HiddenWord);
    Lives = HiddenWord.Len() * 2;
    PrintLine(TEXT("Lives left = %i"), Lives);
}

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

    FBullCowCount Score = GetBullCows(Guess);
    PrintLine(TEXT("Lives left: %i"), Lives);
    PrintLine(TEXT("Bulls = %i, Cows = %i"), Score.Bulls, Score.Cows);
}

void UBullCowCartridge::EndGame()
{

    bGameOver = true;
    ClearScreen();
    if (Lives > 0) PrintLine (TEXT("Played like a champ. \\o/ \n Now hit enter."));
    else PrintLine(TEXT("SMH. The word was '%s'"), *HiddenWord);
    PrintLine(TEXT("Press enter to play again"), *HiddenWord);
}

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
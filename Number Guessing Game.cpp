#include <iostream>
using namespace std;
enum  GuessResult { TooLow, Equal, TooHigh };
bool IsNumberOutOfRange(int From, int To, int Num)
{
    return (Num < From || Num > To);
}
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int GetPlayerGuess()
{
    int Guess;
    while (true)
    {
        cout << endl << "Enter Your Guess 1~100: " << endl;
        if (cin >> Guess && !IsNumberOutOfRange(1, 100, Guess))
            return Guess;

        cout << "Invalid input! " << endl;;
        cin.clear();                    
        cin.ignore(10000, '\n');        
    }
}
GuessResult DidPlayerGuessCourectlly(int Guess, int NumToGuess)
{
   
    if (Guess > NumToGuess)
        return TooHigh;
    if (Guess < NumToGuess)
        return TooLow;
    if (Guess == NumToGuess)
        return Equal;
    
}
string resultToString(GuessResult r)
{
    switch (r)  
    {
    case GuessResult::TooLow:  return "Too low!";
    case GuessResult::Equal:   return "You won!";
    case GuessResult::TooHigh: return "Too high!";
    }
    return "";
}

void StartGame()
{
    int NumToGuess = RandomNumber(1, 100);
    GuessResult result;

    do
    {
        int Guess = GetPlayerGuess();
        result = DidPlayerGuessCourectlly(Guess, NumToGuess);

        cout << resultToString(result);

    } while (result != Equal);
    
    
}

int main()
{
   
    StartGame();
    srand((unsigned)time(NULL));
}


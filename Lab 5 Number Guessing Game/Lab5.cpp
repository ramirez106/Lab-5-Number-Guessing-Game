/*
Carlos Ramirez
C++ Fall 2022
Lab 5 Number Guessing Game
Write a number-guessing game in which the computer selects a random
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game. Create 10 different messages for each of these cases, and use
random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and
documenting comments. You should use functions in your code as well. Your source
code file should be called Lab5.cpp.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void winOrLose(int numGuesses, int& randomNum_);

bool again();

void replayQuestion();
void winCounter(int& gamesWon_, int& gamesLost_, int& numGuesses_);
void gameLoop(int& numGuesses_, int& randomNum_);

int main()
{
	int gamesWon = 0;
	int gamesLost = 0;
	int numGuesses;
	bool playAgain = true;

	cout << "Welcome human, \nyou will have twenty attempts to guess the random number correctly. \n Good luck!" << endl;

	do
	{
		srand(unsigned int(time(NULL)));
		int randomNum = rand() % 101;
		gameLoop(numGuesses, randomNum);

		if (!cin)
		{
			break;
		}

		winCounter(gamesWon, gamesLost, numGuesses);
		winOrLose(numGuesses, randomNum);

		if (again())
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}

		cout << "\n";

	} while (playAgain);

	if (!cin)
	{
		cout << " \n It's not me, its you. We're done!";
		return 1;
	}

	else
	{
		cout << "thanks for playing \n" << "you won: " << gamesWon << " times \n" << "you lost: " << gamesLost << " times";

	}

	return 0;
}

void winOrLose(int numGuesses, int& randomNum_)
{

	srand(unsigned int(time(NULL)));
	int randomNum2 = rand() % 10 + 1;
	int winStatement = randomNum2;
	int loseStatement = randomNum2;

	if (numGuesses == 103)
	{
		cout << "you win, \n";

		switch (winStatement)
		{
		case 1: cout << "but I still wouldn't try my luck at a casino if I were you";
			break;
		case 2: cout << "do a backflip! RIGHT NOW! YOU CAN DO ANYTHING!";
			break;
		case 3: cout << "Good job bro. ";
			break;
		case 4: cout << "This was supposed to be the entire shrek movie script but it was to long. :(";
			break;
		case 5: cout << "you just like Mike!";
			break;
		case 6: cout << "those words are powerful, arn't they?";
			break;
		case 7: cout << "you should ask her out.\n \n \n \n \n \n No. You really shouldn't";
			break;
		case 8: cout << "eres el campeón!";
			break;
		case 9: cout << "the ladies must love you!";
			break;
		case 10: cout << "you must be the favorite child.";
			break;
		}
		cout << "\n \n";
	}

	else
	{
		cout << "you lose, the number is " << randomNum_ << "\n";

		switch (loseStatement)
		{
		case 1: cout << "You are not the favorite child.";
			break;
		case 2: cout << "As my mom tells me, 'Eres un Idiota'";
			break;
		case 3: cout << "This game was actually a quiz to test your intelligence. If you happened to get this message, I have bad news for you....";
			break;
		case 4: cout << "Knowing is better than wondering. Waking is better than sleeping, and even the biggest failure, even the worst, beats the hell out of never trying. Go on, Try again.";
			break;
		case 5: cout << "There is only one good, knowledge, and one evil, ignorance - Socrates. \n What an honor to have the infamous Adolf Hitler playing my guessing game!";
			break;
		case 6: cout << "Have you seen the movie Finding Nemo? If you were Nemo, Marlon wouldn't look for you.";
			break;
		case 7: cout << "People are supposed to say no to drugs. I'm assuming you're the type to say yes.";
			break;
		case 8: cout << "After having you I'm betting your parents became Pro-Abortion.";
			break;
		case 9: cout << "Has your dad come back with the milk yet?";
			break;
		case 10: cout << "Rene Descartes once said 'I Think Therefore, I am.' You don't and are not.";
			break;
		}
		cout << "\n \n";
	}
}

bool again()
{
	int YoN = 0;

	replayQuestion();
	cout << "press 1 for yes and 2 for no: ";
	cin >> YoN;

	switch (YoN)
	{

	case 1: return true;
		break;

	case 2: return false;
		break;

	default: cout << "ok then, no";
		return false;
		break;
	}

	cout << "\n";
}

void replayQuestion()
{
	srand(unsigned int(time(NULL)));
	int randomNum3 = rand() % 10 + 1;

	int replayStatement = randomNum3;

	switch (replayStatement)
	{
	case 1: cout << "again? ";
		break;
	case 2: cout << "you are welcome to try again, if you would like. ";
		break;
	case 3: cout << "another round? ";
		break;
	case 4: cout << "Uno mas? ";
		break;
	case 5: cout << "Come on champ! Lets play another! ";
		break;
	case 6: cout << "As DJ Khalid always says 'Another one!' ";
		break;
	case 7: cout << "I'm only one button away. Press it to join me one more time. ";
		break;
	case 8: cout << "You know you enjoyed this game, play it again. ";
		break;
	case 9: cout << "Minecarft don't got nothing on this game! Run it back! ";
		break;
	case 10: cout << "If you go to church you will hit play again. Remember God's always watching. ";
		break;
	}
}

void winCounter(int& gamesWon_, int& gamesLost_, int& numGuesses_)
{
	if (numGuesses_ == 103)
	{
		gamesWon_++;
	}
	else
	{
		gamesLost_++;
	}
}

void gameLoop(int& numGuesses_, int& randomNum_)
{
	int guess;

	for (numGuesses_ = 1; numGuesses_ <= 20; numGuesses_++)
	{
		cout << "you have " << (21 - numGuesses_) << " guesses remaining \n";
		cout << "enter a value in betwen 0 and 100: ";
		cin >> guess;

		if (!cin)
		{
			break;
		}

		if ((guess < 0) || (guess > 100))
		{
			--numGuesses_;
			cout << "\n that number is out of the range please try again \n" << endl;
			continue;
		}

		if (guess == randomNum_)
		{
			cout << "\n your guess is correct \n" << endl;
			numGuesses_ = 102;
		}
		else
		{
			cout << "\n your guess is incorrect \n" << endl;
		}
	}
}
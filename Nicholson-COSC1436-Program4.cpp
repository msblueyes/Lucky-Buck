// Nicholson-COSC1436-Program4
// This program is to simulate playing the lottery
// the user will choose numbers to see if they can match the winning numbers 
// referenced Ch 3 for random usage 

#include <iostream>
#include <iomanip>
#include <random> // needed in order to generate the numbers for the lotto array
#include <ctime> // needed to be able to generate the numbers for each time the  drawing happens
using namespace std;

//Global Constants
const int ARRAY_SIZE = 6;   
const int MIN_AMOUNT = 5;   

//Function Prototypes
void displaygetUser(int[], int); // user numbers 
void generateNums(int[], int); //generates the numbers for the draw
void displayNums(int[], int[], int); //lotto numbers
int findDigits(int[], int[], int); // finds the matching numbers 
int matchDigits; // used to display the matching digits in the lotto and user array


int main()
{
	int lotto[ARRAY_SIZE]; //Lotto numbers
	int user[ARRAY_SIZE]; // Users Input
	int matchDigits; // Number of matching digits between the arrays
	

	//generates  lotto numbers
	generateNums(lotto,ARRAY_SIZE);

	// displays users numbers
	displaygetUser(user, ARRAY_SIZE);

	//displays lottery numbers
	displayNums(lotto,user,ARRAY_SIZE);

	 // gets matching numbers
	 matchDigits = findDigits(lotto, user, ARRAY_SIZE);

	// returns matching numbers
	 cout << "You matched " << matchDigits << " numbers. \n";
	 cout << endl;
	 cout << "Better luck next time." << endl; //you did not win
	 
	 //GRAND PRIZE WINNER
	 if(matchDigits == 5)
	 cout << "AMAZING!!! YOU ARE A GRAND PRIZE WINNER " << endl;


	return 0;
}
//*****************************************************
// This function will generate the random numbers and *
// store them in the lotto array                      *
//*****************************************************
void generateNums(int lotto[], int size)
{
	unsigned seed = time(0);

	// Seed the random number generater for the drawing into the lotto array
	srand(time(0)); // we want this to generate as many times as we need it to
					
	for (int i = 0; i < size; i++) 
	{
		lotto[i] = 1 + rand() % MIN_AMOUNT; // displays the randomly generated numbers

	}

}
//***************************************************************
// displaygetUser Function will	allow you to enter your numbers *
//***************************************************************
void displaygetUser(int user[], int size)
{  
	// will let you enter your lucky numbers :)
	cout << "Enter your 6 lottery number picks (you must choose between the numbers 1-5 ). \n";

	for (int i = 0; i < size; i++) //displays the users numbers
	{
		cout << "Number " << (i + 1) << ": ";
		cin >> user[i];

	}
	
	cout << endl;
}
//***********************************************************
// findDigits function returns the matching numbers between *
// the two arrays                                           *
//***********************************************************
int findDigits(int lotto[], int user[], int size)
{
	int digits = 0;
	//finds the matches between the two arrays

	for (int num = 0; num < size; num++)
	{
		if (lotto[num] == user[num]) // displays the matching numbers if any
			digits++;
	}

	return digits; //returns the matching numbers 

}
//**********************************************************
// the displayNums Function will display the lotto numbers *
// that were generated and what the user picked            *
//**********************************************************
void displayNums(int lotto[], int user[], int size)
{
	// displays the lottery numbers in that array
	cout << "Lottery Numbers:\n";

	for (int lottoNum = 0; lottoNum < size; lottoNum++) // lotto picks
	{
		cout << setw(3) << lotto[lottoNum];
	}
	cout << endl;

	//Displays user numbers in that array

	cout << "Your Numbers:\n";

	for (int userNum = 0; userNum < size; userNum++) // user numbers
	{
		cout <<setw(3) << user[userNum];
	}
	cout << endl;
}

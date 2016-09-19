#include <iostream>
#include <time.h>
using namespace std;

//Program: Lottery
//Author: Tyler Timmins
//Class: ITSE 2331
//Description: Program that generates lottery and allows user to pick 5 numbers
//	and displays the winning numbers to picked ones, and tells if you win or lose;

//function prototypes
void generateWinningNumbers(int win[], int numElms);
void getPickedNumbers(int pick[], int NumElms);
int comparePicks(int winNums[], int pickNums[], int NumElms);
void BubbleSort(int list[], int numElms);

int main()
{
	//declare variables
	int iMatched;

	//declare arrays
	int winNums[5];
	int pickNums[5];

	//see if it works
	getPickedNumbers(pickNums, 5);
	cout << "Picked Numbers: ";
	for (int x = 0; x < 5; x++)
	{
		cout << pickNums[x] << " ";
	}

	cout << endl;

	//see if it works
	generateWinningNumbers(winNums, 5);
	cout << "Winning Numbers: ";
	for (int x = 0; x < 5; x++)
	{
		cout << winNums[x] << " ";
	}

	cout << endl;

	iMatched = comparePicks(winNums, pickNums, 5);
	if (iMatched >= 3)
	{
		cout << "You won 10000000 DOLLARS!" << endl;
	}
	else
		cout << "Better luck next time." << endl;

		cout << "You matched " << iMatched << " number(s)." << endl;

	return 0;
}

//function used to generate 5 random winning numbers
void generateWinningNumbers(int win[], int numElms)
{
	//delcare variables
	bool bCheck; //check variable
	int iHolder; // hold the number stored in

	//seed random number generator
	srand(time(NULL));

	//loop through array
	for (int x = 0; x < numElms; x++)
	{
		do
		{
			iHolder = (rand() % 40 + 1); //store random number in array
			bCheck = true; //make ture

			for (int y = 0; y < win[x]; y++)
			{
				if (iHolder == win[y])
				{
					bCheck = false; //set check variable to false
					break;
				}
			}

		} while (!bCheck); //loop until new number is found
		
		win[x] = iHolder; //store generated number in array
	}

	BubbleSort(win, numElms);
}


//function used to pick numbers for lottery
void getPickedNumbers(int picks[], int NumElms)
{
	//declare variables
	

	//loop for input - store input into array
	for (int x = 0; x < NumElms; x++)
	{
		cout << "Pick a number between 1 through 40: ";
		cin >> picks[x];
	}

}


//function used to compare the picks
int comparePicks(int winNums[], int pickNums[], int NumElms)
{
	//declare variable
	int iCounter = 0;

	//loop throught the winNums array
	for (int x = 0; x < NumElms; x++)
	{
		//loop through the pickNums array
		for (int y = 0; y < NumElms; y++)
		{
			//if the winNums element == to pickNums element
			if (winNums[x] == pickNums[y])
			{
				//increment a counter
				iCounter++;
			}
		}//end loop
	}//end loop

	//return the counter
	return iCounter;
}

//function used to sort from least to greatest
void BubbleSort(int list[], int numElms)
{
	bool blSwap; //flag to store whether or not a swap occured

	//loop for number of elements
	for (int x = 0; x < numElms; x++)
	{
		blSwap = false; //reset the flag to false

		//loop through the array
		for (int y = 0; y < numElms - 1; y++) //loop to last index - 1
		{

			//compare current element ot next element
			// > for ascending (Least to Greatest)
			// < for descending (Greatest to Least)
			if (list[y] > list[y + 1])
			{
				int iSwap; //need a swap varaiable, must match array dataType

				iSwap = list[y]; //do the swap variable first

				list[y] = list[y + 1]; //1st index is safe, therefore safe to swap

				list[y + 1] = iSwap; //finally take swap variable and store in 2nd spot

				blSwap = true; //a swap happened, set the flag
			}

		}//end of the inner loop

		if (blSwap == false) //if swap never happened, array sorted
			break; //jump out of the outer loop

	} // end of the bubble sort

}
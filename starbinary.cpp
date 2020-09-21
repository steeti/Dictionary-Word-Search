//Saad Teeti
#include "header.h" // including the header file
using namespace std;

void starbinary(string wordsearch, vector<string> myvector, int foundstar, int high, int low, int comp1, vector<string>& words)
{
	if (high>low)
	{
		int middlepoint=(high+low)/2; // declaring middle point as half of the vector
		if (wordsearch.compare(myvector[middlepoint].substr(0,foundstar))==0)		// check if our word until the star is matching to any words in the middle of the vector
			{
				comp1++; //incrementing for comparison
				words.push_back(myvector[middlepoint]); // if the word is found then store it in the vector

				cout<< "Words found!" << endl;	//	output if words are found)
				cout<<"Words compared "<< comp1 << " times up to the first match" << endl; //  outputting the comparsion up to the first match
				//declaring up and down as we will use them in while loop to compare the word found with its neighbours
				int up = middlepoint+1;
				int down = middlepoint-1;
				while (wordsearch.compare(myvector[up].substr(0,foundstar))==0) // checking if the neighbouring word above word found matches the prefix condition
				{
					words.push_back(myvector[up]); 	// storing into the vector
					up++; // moving to the next word up
				}
				while (wordsearch.compare(myvector[down].substr(0,foundstar))==0) // checking if the neighbouring word below word found matches the prefix condition
				{
					words.push_back(myvector[down]);  // storing into the vector
					down--; // moving to the next word down
				}


			}
		else if (wordsearch.compare(myvector[middlepoint].substr(0,foundstar))>0)      // Check for the second half of the vector
			{
				low = middlepoint+1;									// change the position of low according to the new vector half
				comp1++;												//incrementing each time it compares
				starbinary(wordsearch, myvector, foundstar, high , low, comp1, words); //Calling Recursive Function
			}

		else if (wordsearch.compare(myvector[middlepoint].substr(0,foundstar))<0) 		// Check for the first half of the vector
			{
				high = middlepoint-1;								// change the position of low according to the new vector half
				comp1++;											//incrementing each time it compares
				starbinary(wordsearch, myvector, foundstar, high , low, comp1, words); //Calling Recursive Function
			}
	}
	else
	{
		if (wordsearch.compare(myvector[low].substr(0,foundstar))==0) //check if the word(substring) is equal to low(low and high are the same at this point)
			{
				comp1++;

				cout<< "Word found!" << endl;	//	recursion)
				cout<<"Word compared "<< comp1 << " times." << endl;
		}
		else
		{
			cout<<"Word Not found"<<endl; // print if the word is not found
		}
	}
}

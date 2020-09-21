//Saad Teeti
#include "header.h"
using namespace std;

void quesbinarysearch(string wordsearch, vector<string>& myvector, int high, int low, int& comp2, vector<string>& wordsfound)
{

	int middlepoint=(high+low)/2;

	if (high>low){

		if (wordsearch.compare(myvector[middlepoint])==0)		// check if our word until the star is matching to any words in the middle of the vector
			{comp2++; //incrementing for comparison
			wordsfound.push_back(myvector[middlepoint]); // if same , then store it in vector wordsfound


		}
		else if (wordsearch.compare(myvector[middlepoint])>0)      // Check the seconf half of the vector
			{low = middlepoint+1;
			comp2++; // incrementing for comparison
			quesbinarysearch (wordsearch, myvector, high , low, comp2, wordsfound);} //Calling Recursive Function

		else if (wordsearch.compare(myvector[middlepoint])<0) 		// Check for the first half of the vector
			{high = middlepoint-1;
			comp2++; //incrementing for comparison
			quesbinarysearch (wordsearch  , myvector, high , low, comp2, wordsfound);} //Calling Recursive Function
	}
	else{
		if (wordsearch.compare(myvector[low])==0)	// check if our word is equal to low(low and high are the same at this point)
			{comp2++; // incrementing for comparison
			wordsfound.push_back(myvector[middlepoint]); //store the word into vector



		}

	}
}

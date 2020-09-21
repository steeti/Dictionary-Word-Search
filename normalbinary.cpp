//Saad Teeti
#include "header.h"
using namespace std;


//Binary Search implementation method for normal words
void normalbinarysearch(string wordsearch, vector<string> myvector, int high, int low, int comp3)
{

//Check for the condition as high is greater than low
	if (high>low){
		int middlepoint=(high+low)/2; //declare the middle point as the half of the vector
		if (wordsearch.compare(myvector[middlepoint])==0)		// check if our word is the same as the word in the middle of the vector
			{comp3++;                            // Increament comp3 which is the comparsion variable

			cout<< "Word found!" << endl;	// output the "word found" if the search word is equal to the word in the middle of the vector
			cout<<"Word compared "<< comp3 << " times." << endl; //output the number of times word was compared

		}
		else if (wordsearch.compare(myvector[middlepoint])>0)      // checking the second half of the vector
			{low = middlepoint+1;
			comp3++;                                          // increment comp3 each time it compares
			normalbinarysearch (wordsearch, myvector, high , low, comp3);} //Recursive Function

		else if (wordsearch.compare(myvector[middlepoint])<0) 		// Checking first half of the vector
			{high = middlepoint-1;
			comp3++;												// increament comp3 each time it compares
			normalbinarysearch (wordsearch, myvector, high , low, comp3);} //Recursive function
	}
	else{
		if (wordsearch.compare(myvector[low])==0)	// check if our word is equal to low(low and high are the same at this point)
			{comp3++; //increament comp3 for checking again

			cout<< "Word found!" << endl;	//outputting if the word is found
			cout<<"Word compared "<< comp3 << " times." << endl; //outputting the number of times words are compared
		} else{
			cout<<"Word Not found"<<endl;  // if words aren't found then output "Words Not Found"
		}
	}
}

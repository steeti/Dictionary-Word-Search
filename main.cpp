/*Saad Teeti*/
#include "header.h"
using namespace std;

int main(int argc, char* args[])
{


	//declaring Vectors
	vector<string> myvector; // vector to store words from the dictionary
	vector<string> words; //vector for storing the words from star binary
	vector<string> wordsfound; // vector for storing the words from ques binary
	// declaring filename and maxnumber
	string filename;
	int maxnumber=0;
	// command line argument
	for (int i = 1; i < argc; i++) {
		if (strcmp(args[i],"-d")==0)
			filename=args[i+1];

		else if (strcmp (args[i],"-l")==0){
			maxnumber=stoi(args[i+1]);
		}
	}
	// the filename and max number that the user inputs in the command line
	cout<<"filename is:"<<filename<<endl;
	cout<<"The maximum number is "<<maxnumber<<endl;
	//opening file
	ifstream fin(filename);
	if(not fin.is_open())
	{
		//checking if the file can't open
		cout<<"Can't open the file"<<endl;
		return EXIT_FAILURE;

	}

	// do while loop to store the data from file into myvector
	do
	{

		string str;
		fin>>str;
		myvector.push_back(str);
	}


	while(fin);



	{

		string wordsearch;

		while (true)
		{cout<<"Enter the word you want to search for"<<endl;
		cin>> wordsearch; // userinput}

		if (wordsearch=="exit") // if the word is quit or exit then exit the program
			{return EXIT_SUCCESS;}


		string star="*";
		string ques="?";





// checking the possible invalid input; (if there is star then check if there is anything after it, check if there is a star and quesition in the same one, check if there is quesition mark in the first place, if there is more than one quesition mark)
		while ( ((wordsearch.size() > wordsearch.find(star)+1) and (wordsearch.find(star) != string::npos)) or ((wordsearch.find(star) != string::npos) and (wordsearch.find(ques) != string::npos)) or (wordsearch.find(ques)==0) or (count(begin(wordsearch), end(wordsearch), '?') > 1))
			{

			cout<<"Invalid input. Please enter the word again."<<endl;
			cin>> wordsearch;
			// if input is invalid then enter the wordsearch again
			}




		size_t foundstar=wordsearch.find(star); // returns the index of a * in the word if found
		size_t foundques=wordsearch.find(ques); // returns the index of a ? in the word if found

		int low=0;// beginning of the vector
		int high=myvector.size()-1;// end of the vector
		int comp1=0;// star binary search
		int comp2=0;// ques binary search
		int comp3=0;// normal binary seach

		// if statement to check for the cases of the program
		if (foundstar != string::npos)
			// if there is a star in the word
		{
			starbinary(wordsearch.substr(0,foundstar), myvector,foundstar, high, low, comp1, words); // calling the function
			cout << words.size() << " matches found" << endl; // outputing the numbers of matches found based on the vector size that the words were stored in
			for(int i=0; i< min(maxnumber, (int)words.size()); ++i) // for the output screen take the minimum between the vector size and the max number, and output the words in the vector

  				cout << words[i] << endl;



		}

		else if(foundques != string::npos)
			// if there is a question mark in the word
		{
			for (int i=33;i<127;i++){
				wordsearch[foundques]= char(i); // change the index of where the "?" is to the ASCII characthers from 33-127
				quesbinarysearch(wordsearch, myvector, high , low, comp2, wordsfound);// check for evey word from i=33 to i=127
			}
			if (wordsfound.size()>0){
				// if the wordsfound vector contain elements
				cout<<"Word/s Found: "<<wordsfound.size()<<endl;
				// output the number of matches which is the size of the vector
				for(int i=0; i< min(maxnumber, (int)wordsfound.size()); ++i) // for the output screen take the minimum between the vector size and the max number, and output the words in the vector
  				cout << wordsfound[i] << endl;
  				// output the words found that were stored into the vector
			}
			else
				{cout<<"Words Not Found"<<endl;} // if the vector is empty then words are not found
			cout<<"Word compared "<< comp2 << " times." << endl; // output the words compared

		}

		else{ // if the wordsearch doesn't include "?" or "*" then do normal binary search

			normalbinarysearch(wordsearch, myvector, high , low, comp3);

		}

	}

}
}

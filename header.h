#ifndef HEADER_H
#define HEADER_H
#include<vector>
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include <typeinfo>
#include <algorithm>
using namespace std;
void normalbinarysearch(string wordsearch, vector<string> myvector, int high, int low, int comp3);
void starbinary(string wordsearch, vector<string> myvector, int foundstar, int high, int low, int comp1, vector<string>& words);
void quesbinarysearch(string wordsearch, vector<string>& myvector, int high, int low, int& comp2, vector<string>& wordsfound);
#endif
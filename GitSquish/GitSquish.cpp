// Squish.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <set> 
#include <iterator> 
#include <string>
#include <vector>

void squishWord(std::string word, std::set<std::string> &output, std::set<std::string> &checkwords, std::set<std::string> dictionary) {

	if (word.length() == 0)
	{
		return;

	}
	else
	{
		//Check whether the word has already been checked	
		if (checkwords.find(word) == checkwords.end())
		{
			//This is the first time we are seeing this wrod

			//Regress the string to null by eliminating one letter in one go
			int i = 0;
			for (i = 0; i < word.length(); i++)
			{
				std::string currword;
				currword = word;
				currword.erase(i, 1);
				squishWord(currword, output, checkwords, dictionary);
			}
			//Since the word has been checked add it to the checkwords set
			checkwords.insert(word);
			//Check whether it is in dictionary
			if (dictionary.find(word) != dictionary.end()) {
				//add it to output if it matched
				output.insert(word);
			}
		}
		else
		{
			//Word has been checked so do nothing
			return;
		}

	}
}

void squishWord2(std::set<std::string> dictionary, std::string input, std::set<std::string> &output, std::string left, std::string right) {

	if (dictionary.find(left) != dictionary.end()) {
		//add it to output if it matched
		if (output.find(left) == output.end())
		{
			output.insert(left);
		}

	}
	if (dictionary.find(right) != dictionary.end()) {
		//add it to output if it matched
		if (output.find(right) == output.end())
		{
			output.insert(right);
		}
	}
	if (input.length() == 0)
	{
		return;

	}
	else
	{

		char ch = input[0];
		std::string rest = input.substr(1);
		squishWord2(dictionary, rest, output, left + ch, right);
		squishWord2(dictionary, rest, output, left, right + ch);

	}
}

void printOutput(std::set<std::string> output)
{
	// using begin() to print set 
	for (auto it = output.begin(); it != output.end(); ++it)
		std::cout << *it << " ";
	return;
}

void largestSumHelper(std::set<int> v, int N, int left, int right, int& largestSum) {

	std::cout << std::endl << left << " " << right;
	if (largestSum < left && left < N) {
		largestSum = left;
	}
	if (largestSum < right && right < N) {
		largestSum = right;
	}

	if (v.size() == 0) {

	}
	else {


		auto ini = v.begin();
		int initial = *ini;

		std::set<int>::iterator it1, it2;
		it1 = v.begin();
		it2 = v.begin();

		// decrementing the it2 two times 
		it2++;
		v.erase(it1, it2);
		largestSumHelper(v, N, left + initial, right, largestSum);
		largestSumHelper(v, N, left, right + initial, largestSum);
	}

}




int largestSum(std::set<int> V, int N) {
	std::set<int> copy;
	for (int i : V) {
		copy.insert(i);
	}
	int left = 0;
	int right = 0;
	int largestSum = 0;
	largestSumHelper(copy, N, left, right, largestSum);
	std::cout << std::endl << largestSum;
	return largestSum;
}

int main()
{
	//squishWord("i", { "Startling","Starling","Staring","String","Sting", "ting", "tin", "in","i", "is"});
	//squishWord("is", { "Startling","Starling","Staring","String","Sting", "ting", "tin", "in","i","is" });
	std::set<std::string> output, output2;
	std::set<std::string> checkwords;
	squishWord("Startling", output, checkwords, { "Star", "Start","Startling", "Starling","Staring","String","Sting", "ting", "tin", "in","i" });
	printOutput(output);
	std::cout << std::endl;
	squishWord2({ "Star", "Start","Startling", "Starling","Staring","String","Sting", "ting", "tin", "in","i" }, "Startling", output2, "", "");
	printOutput(output2);
	largestSum({ 7,30,8,22,6,1 }, 19);
	largestSum({ 5,30,15,22,6,1 }, 19);
	std::cout << "This is the first branch I created";
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

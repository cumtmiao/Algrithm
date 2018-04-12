/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
*/
#include<iostream>
#include<string>
using namespace std;

bool isCapital(char c)
{
	return (c >= 'A'&&c <= 'Z');
}
bool detectCapitalUse(string word) {
	int n = word.size();
	if (n == 1)return true;
	if (isCapital(word[0]))
	{
		bool secondcapital = isCapital(word[1]);
		if (secondcapital == true)
		{
			for (int i = 2; i < n; i++)
			{
				if (!isCapital(word[i]))return false;

			}
			return true;
		}
		if (secondcapital == false)
		{
			for (int i = 2; i < n; i++)
			{
				if (isCapital(word[i]))return false;

			}
			return true;
		}
		
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (isCapital(word[i]))return false;
		}
		return true;
	}
}
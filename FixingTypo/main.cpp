// C_FixingTypos.cpp : Defines the entry point for the console application.
//


#include "iostream"
#include "cstring"
#include "string"

using namespace std;

string CorrectTypo(string in);

int main()
{
	string input;
	cin >> input;
	input = CorrectTypo(input);
	cout << input;
	return 0;
}

string CorrectTypo(string in)
{
	string output = "";
	int prevCount = 0, currCount = 0;
	char prevChar = 0, currChar = 0;

	for(int i = 0 ; i < in.size() ; i++)
	{
		//1- update the prevChar
		if(i>0 && in[i-1]!=in[i])
		{
			prevChar = in[i-1];
			prevCount = currCount;
			currCount = 0;
		}

		currChar = in[i];
		currCount++;

		if((currCount >= 3) ||
			(prevCount >= 2 && currCount >= 2)
			)
		{
			//dont add the char to the output
			// decrease curr count by 1
			currCount--;
		}
		else
		{
			output+=currChar;
		}

	}

	return output;
}

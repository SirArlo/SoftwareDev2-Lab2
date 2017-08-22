#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "FileReader.h"
#include "Paragraph.h"
#include "Word.h"


using namespace std;

//function prototype to ask for a file name until a valid one is entered
bool OpenFile(string FileName);

int main(int argc, char **argv)
{
	//initialization of variables
	string UserSearch = "";
	vector<int> lineNumbers;
	string FileName = "";

	//using FileReader and OpenFile user input is required until a valid file name is entered
	bool FileFound = false;
	while (FileFound == false)
	{
		cout << "Please enter file name: ";
		cin >> FileName;
		FileFound = OpenFile(FileName);
	}

	//user input is repeatedly required until the input is "."
	while (UserSearch != ".")
	{
		//reset variables for next query
		FileReader FileText(FileName);
		lineNumbers.clear();
		//user input is required
		cout << "Please enter a word to search for or \".\" to quit: ";
		cin >> UserSearch;
		//if the input is "." then the program exits
		if (UserSearch != ".")
		{
			//a Word object is created and used to search within the Paragraph object
			Word NewWord(UserSearch);
			Paragraph NewParagraph;
			FileText.readFileInto(NewParagraph);
			//if the word is found, all line numbers the word appears in is displayed
			if (NewParagraph.contains(NewWord, lineNumbers))
			{
				cout << "Word found: ";
				for (unsigned int i = 0; i < lineNumbers.size(); i++)
				{
					cout << "line " << lineNumbers[i] << endl;
				}
			}
			else
			{
				cout << "Word not found" << endl;
			}
		}
	}
	return 0;
}

bool OpenFile(string FileName)
{
	//if the file doesnt exist an exception is thrown
	try 
	{
		FileReader FileText(FileName);
	}
	catch(FileCannotBeOpened())
	{
		cout << "File cannot be opened" << endl;
		return false;
	}
	return true;
}

/* 5.4 
 
The code will ignore the second occurance of the word, however since it shows which lines
the words appear on, you only need to show which line contains the word once seeing 
as the word can occur on the line multiple times and the line numbers will still be correct.
 
To support this functionality the design would have to show the number of occurances of 
the word in the line  for example  " word found on line 1, 3 times "   and the functionality 
of the system would need to change in order to provide  for this request.

*/
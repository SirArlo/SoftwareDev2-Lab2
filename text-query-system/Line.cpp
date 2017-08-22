// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include "iostream"

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	//initialization of variables
	unsigned int WordStart = 0;
	unsigned int WordLength = 0;
	unsigned int i = 0;

	//while there are stil remaining characters in the string line split the string into multiple Word objects
	while (i != line.length())
	{
		while (line[i] != '\0')
		{
			//determine the length of the new word
			WordLength++;
			if (line[i+1] == '\0')
			{
				_line.push_back(Word(line.substr(WordStart,WordLength)));
				WordStart = i+1;
				WordLength = 0;
			}
			else 
			{
				if ( (line[i] == ' ') )
				{
					//the Word object will remove punctuation
					_line.push_back(Word(line.substr(WordStart,WordLength-1)));
					WordStart = i+1;
					WordLength = 0;
				}
			}
			i++;
		}
	}
}

bool Line::contains(const Word& search_word) const
{
	//if the length of the Word object search_word is less than 3 it is not queryable
	if (!search_word.isQueryable())
	{
		return false;
	}
	//if there are any errors with the Word object search_word an exception will be thrown
	try 
	{
		Word NewWord(search_word);
	
	}
	catch (WordContainsNoLetters())
	{
		std::cout << "Error: Word contains no letters" << std::endl;
		return false;
	}
	catch (WordContainsNoLetters())
	{
		std::cout << "Error: Word contains no letters" << std::endl;
		return false;
	}
	catch (WordContainsSpace())
	{
		std::cout << "Error: Word contains a space" << std::endl;
		return false;
	}

	//the vector of Word objects _line will be compared to the search_word
	for (unsigned int i = 0; i < _line.size(); i++)
	{
		if (search_word == _line[i])
		{
			return true;
		}
	}
	return false;
}
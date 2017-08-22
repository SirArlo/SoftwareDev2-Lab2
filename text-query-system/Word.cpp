// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <stdio.h>
#include <string>
#include "iostream"

Word::Word(const string& word): _word{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (_word.empty()) throw WordContainsNoLetters();
	//call all functions in order here
	//change word into all uppercase and remove all punctuation 
	CheckNoSpace();
	WordUpperLowerCase();
	RemovePunctuation();
	OnlyPunctuation();
	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (_word == rhs._word)
		return true;
	else
		return false;
}

//check if the word length is 3 or more
bool Word::isQueryable() const
{
	if (_word.length() < 3)
	{
		return false;
	}
	return true;
}

//convert the word into uppercase
void Word::WordUpperLowerCase()
{
	//if the letter is lowercase change it to uppercase using the ASCII table
	for (unsigned int i = 0; i < _word.length(); i++)
	{
		if (_word[i] >= 'a' && _word[i] <= 'z')
		{
			_word[i] = char( ((int)_word[i]) - 32 );
		}
	}
	return;
}

//remove punctuation from the word
void Word::RemovePunctuation()
{
	
	for (unsigned int i = 0; i < _word.length(); i++) 
	{
		//if the final letter was punctuation a ' ' will be remaining
		//if the final letter is a ' ' then it is removed
		if ( (_word[i] == ' ') && (_word[i+1] == '\0') )
		{
			_word = _word.substr(0, i);
		}
		if (ispunct(_word[i]))
		{
			_word.erase(i,1);
			i--;
		}
	}
	return;
}

//check to see if the word only contains punctuation
void Word::OnlyPunctuation()
{
	unsigned int counter = 0;
	for (unsigned int i = 0; i < _word.length(); i++)
	{
		if ((_word[i] >= 'A' && _word[i] <= 'Z') == false)
		{
			counter++;
		}
	}
	if (_word.length() == counter)
	{
		throw WordContainsNoLetters();
	}
}

//ensure that the word does not contain a space
void Word::CheckNoSpace()
{
		for (unsigned int i = 0; i < _word.length(); i++)
	{
		if (_word[i] == ' ')
		{
			throw WordContainsSpace();
		}
	}
}
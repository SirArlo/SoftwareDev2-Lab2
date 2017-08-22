// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"
#include "iostream"

void Paragraph::addLine(const Line& line)
{
	_paragraph.push_back(line);
	return;
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
	bool WordFound = false;
	//if the word is within the line then it is documented
	for (unsigned int i = 0; i < _paragraph.size(); i++)
	{
		if (_paragraph[i].contains(search_word))
		{
			line_numbers.push_back(i+1);
			WordFound = true;
		}
	}
	//after all lines are checked
	if (WordFound == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
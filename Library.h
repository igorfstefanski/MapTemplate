#pragma once

#include <iostream>

using namespace std;

enum status { borrowed = 0, on_the_bookshelf };
const string statusTxt[] = {"borrowed", "on the bookshelf"};

class Library
{
  private:
	string author;

  public:
	string category;
	unsigned int pages;
	status currentStatus;

	Library() : author("None"), category("None"), pages(0),
		  currentStatus(on_the_bookshelf){};
	Library(string _author, string _category, unsigned int _pages,
			status _currentStatus) : author(_author), category(_category), pages(_pages),
		  currentStatus(_currentStatus){};

	friend ostream& operator<<(ostream& out, const Library& e)
    {
		out << e.author << " ";
		out << e.category << " ";
		out << e.pages << " ";
		out << statusTxt[e.currentStatus];

		return out;
	};
};

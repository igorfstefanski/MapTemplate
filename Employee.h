#pragma once

#include <iostream>

using namespace std;

class Employee
{
  private:
	string name;

  public:
	string position;
	unsigned int age;

	Employee() : name("N/A"), position("N/A"), age(0){};
	Employee(string givenName, string givenPosition, unsigned int givenAge)
		: name(givenName), position(givenPosition), age(givenAge){};

	friend ostream& operator<<(ostream& out, const Employee& e)
    {
		out << e.name << " ";
		out << e.position << " ";
		out << e.age;

		return out;
	};
};

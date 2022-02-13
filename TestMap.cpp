#include "Employee.h"                                                   // Defines class Employee
#include "Library.h"
#include "Map.h"                                                        // Defines template Map<Key, Value>
#include <iostream>

using namespace std;

typedef unsigned int ID;			                                    // Identification number of employee
typedef Map<ID, Employee> Database;                                     // Database of employees
typedef string Title;
typedef Map<Title, Library> BookDatabase;

void testEmployee();
void addEmployees(Database& database);
void modifyEmployees(Database& database);

void testBookInfo();
void addBooks(BookDatabase& database);
void modifyBooks(BookDatabase& database);

int main()
{
	testEmployee();
	testBookInfo();
}

void testEmployee()
{
	Database database;
	addEmployees(database);

	Database newDatabase = database;                                    // Make a copy of database (copy constructor called)
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43)); // Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;                                             // Update original database (assignment operator called)

	cout << "Database after the assignment:" << endl << database << endl;
}

void addEmployees(Database& database)
{
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28));  // Add first employee: name: Jan Kowalski,
                                                                        // position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54)); // Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32)); // Add third employee
}

void modifyEmployees(Database& database)
{
	Employee* pE;

	pE = database.find(510212881);                                      // Find employee using its ID
	pE->position = "salesman";	                                        // Modify the position of employee

	pE = database.find(761028073);                                      // Find employee using its ID
	pE->age = 29;				                                        // Modify the age of employee
}

void testBookInfo()
{
	BookDatabase database;
	addBooks(database);

	BookDatabase newDatabase = database;
	newDatabase.add("The Da Vinci Code",
					Library("Dan Brown", "Crime", 524, borrowed));
	modifyBooks(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;

	cout << "Database after the assignment:" << endl << database << endl;
}

void addBooks(BookDatabase& database)
{
	database.add("One Day",
				 Library("David Nicholls", "Fiction", 358, on_the_bookshelf));
	database.add("Atonement",
				 Library("Ian McEwan", "Historical", 785, on_the_bookshelf));
	database.add("Harry Potter and the Prisoner of Azkaban",
				 Library("J. K. Rowling", "Fantasy", 325, borrowed));
}

void modifyBooks(BookDatabase& database)
{
	Library* pBooks;

	pBooks = database.find("One Day");
	pBooks->currentStatus = borrowed;

	pBooks = database.find("Atonement");
	pBooks->category = "Historical Fiction";
}

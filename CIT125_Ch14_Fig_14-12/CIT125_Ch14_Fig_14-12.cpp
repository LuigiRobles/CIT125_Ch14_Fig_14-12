// CIT125 Intro To C++ Luigi Robles
// 08-04-2020 Summer Term
// Ch.14 pg.525 Fig.14-12 eBook Collector Program
// Gets and displays the items in an eBook Collection

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//function prototype
void saveInfo();
void displayInfo();

int main()
{
	saveInfo(); //function call
	displayInfo(); //function call
	return 0;
} //end of main function

//******Function Definitions******
void saveInfo()
{
	//writes records to a sequntial access file
	string title = "";
	string author = "";

	//create file object and open the file
	ofstream outFile;
	outFile.open("eBooks.txt", ios::app);

	//determine wheter the file was opened
	if (outFile.is_open())
	{
		cout << "Title (-1 to stop): ";
		getline(cin, title); //input for Title of Book
		while (title != "-1") //while loop to continue taking Book Titles
		{
			cout << "Author: ";
			getline(cin, author); //input for Author
			//write the record
			outFile << title << '#' << author << endl;

			cout << "Title (-1 to stop): ";
			getline(cin, title);
		} //end while
		outFile.close();
	}
	else cout << "eBooks.txt file could not be opened"
			<< endl;
	//end if
} //end of saveInfo function

void displayInfo()
{
	//display the records stored in the file
	string title = "";
	string author = "";

	//create file object and open the file
	ifstream inFile;
	inFile.open("eBooks.txt", ios::in);

	//determine whether the file was opened
	if (inFile.is_open())
	{
		cout << endl << endl << "eBook Collection" << endl;
		cout << "----------------" << endl;
		//read a record
		getline(inFile, title, '#');
		getline(inFile, author);

		while (!inFile.eof()) 
		{
			//display the record
			cout << title << " by " << author << endl; //output part of IPO
			//read another record
			getline(inFile, title, '#');
			getline(inFile, author);
		} //end while
		inFile.close();
	}
	else
		cout << "eBook.txt file could not be opened"
			<< endl;
	//end if
} //end of displayInfo function
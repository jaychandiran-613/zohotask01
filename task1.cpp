#include <iostream>
#include <string.h>
#include <iterator>
#include <map>
using namespace std;
#include "class01.h"
#include "class02.h"

int main()
{
	bool game = 1;
	int input1;
	char input2; 

	HRM hrm1;

	while (game)
	{
		system("clear");
		cout << "1.Add new employee" << endl << "2.delete employee information" << endl << "3.Update employee information" << endl << "4.Make reports based on specific field" << endl << "5.search employee" << endl << "6.display details." << endl << "7.Quit" << endl;
		cout << "Please enter the related number of your requested command?";
		cin >> input1;

		switch (input1)
		{
			case 1:
				hrm1.Addperson();
				break;

			case 2:
				hrm1.deleteperson();
				break;

			case 3:
				hrm1.Updateperson();
				break;
				//case 4:
				// hrm1.reportlist();
				//  break;

			case 5:
				hrm1.searchperson();
				break;

			case 7:
				game = 0;
				break;
                
			case 6:
				hrm1.displaydetails();
				break;

			default:
				cout << "Enter correct options.";
				cin.ignore();
				input2 = getchar();
				break;

		}
	}
}
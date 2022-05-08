class HRM
{
	private:

		map<int, person> employee;
	int number_staff = 0;

	public:
		static int employeeid;
	char check;
	string fname, lname;
	int hrs, cost, personalIDcheck, index, i, j, k, option, S_min, S_max, option1;
	map<int, person>::iterator itr;
	HRM()
	{
		person p1("jayachandiran", "jai", 12, 45);//540
		employee.insert(pair<int, person> (++employeeid, p1));
		person p2("Kalai mani", "mama", 89, 45);//4005
		employee.insert(pair<int, person> (++employeeid, p2));
		person p3("Hemanthponneri", "hema", 56, 12);//672
		employee.insert(pair<int, person> (++employeeid, p3));
		person p4("Ranganathan", "ranga", 03, 56);//168
		employee.insert(pair<int, person> (++employeeid, p4));
		person p5("Aathithiyan", "ash", 89, 99);//8811
		employee.insert(pair<int, person> (++employeeid, p5));
		person p6("RajarajanJ", "raja", 42, 26);//1092
		employee.insert(pair<int, person> (++employeeid, p6));
		person p7("Arjunsrinath", "arjun", 102, 120);//12240
		employee.insert(pair<int, person> (++employeeid, p7));
	}

	void Addperson()
	{
		option = 1;
		while (option != 0)
		{
			cout << "Please enter the first name of an employee? ";
			cin >> fname;
			cin.ignore();
			cout << "Please enter the last name of an employee? ";
			getline(cin, lname);
			while (1)
			{
				try
				{
					cout << "How many hours a week is his/her work? ";
					cin >> hrs;
					if (hrs > 0)
					{
						break;
					}
					else
					{
						throw 505;
					}
				}

				catch (...)
				{
					cout << "Please enter only integer for hours\n";
					cin.clear();
					cin.ignore();
				}
			}

			while (1)
			{
				try
				{
					cout << "How many per hours is his/her salary? ";
					cin >> cost;
					if (cost > 0)
					{
						break;
					}
					else
					{
						throw 505;
					}
				}

				catch (...)
				{
					cout << "Please enter only integer for cost\n";
					cin.clear();
					cin.ignore();
				}
			}

			number_staff++;
			person newperson(fname, lname, hrs, cost);
			employee.insert(pair<int, person> (++employeeid, newperson));
			cout << "The employee with the following information has been added to the system:" << endl;
			cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
			cout << "---------  ----------  --------------  ------------\n";
			cout << newperson.get_FirstName() << "\t" << newperson.get_LastName() << "\t" << newperson.get_PersonalID() << "\t" << newperson.get_Salary() << endl;
			cout << "Do you want to add another employee(y/n) ";
			cin.ignore();
			check = getchar();
			if (check == 'n' || check == 'N')
			{
				option = 0;
			}
		}
	}

	void deleteperson()
	{
		option = 1;
		while (option != 0)
		{
			cout << "please enter the personal number of an employee? ";
			cin >> personalIDcheck;
			cin.ignore();
			itr = employee.find(personalIDcheck);
			if (itr == employee.end())
			{
				cout << "Sorry,there is not any employee with requested personal number.\n";
			}
			else
			{
				cout << "Do you want to delete employee " << itr->second.get_FirstName() << "  " << itr->second.get_LastName() << "(y/n)?";
				check = getchar();
				cin.ignore();
				if (check == 'Y' || check == 'y')
				{
					cout << "The employee " << itr->second.get_FirstName() << "  " << itr->second.get_LastName() << " has been deleted.";
					employee.erase(personalIDcheck);
					number_staff--;
				}
			}

			while (1)
			{
				cout << "Do you want to repeat delete by entering the new personal number(y/n)? ";
				check = getchar();
				if (check == 'n' || check == 'N')
				{
					option = 0;
					break;
				}
				else if (check == 'y' || check == 'Y')
				{
					break;
				}
			}
		}
	}

	void Updateperson()
	{
		option1 = 1;
		while (option1 != 0)
		{
			cout << "please enter the personal number of an employee? ";
			cin >> personalIDcheck;
			cin.ignore();
			itr = employee.find(personalIDcheck);
			if (itr == employee.end())
			{
				cout << "Sorry,there is not any employee with requested personal number.\n";
			}
			else
			{
				while (1)
				{
					cout << "(1.First name, 2.Family name, 3.WorkingHours, 4.payment for one hour)?";
					cin >> option;
					switch (option)
					{
						case 1:
							cout << "Please enter new First name for " << itr->second.get_FirstName();
							cin >> fname;
							itr->second.set_FirstName(fname);
							break;
						case 2:
							cout << "Please enter new Family name for " << itr->second.get_FirstName();
							cin >> lname;
							itr->second.set_LastName(lname);
							break;
						case 3:
							cout << "Please enter new WorkingHours for " << itr->second.get_FirstName();
							cin >> hrs;
							itr->second.set_WorkingHours(hrs);
							break;
						case 4:
							cout << "Please enter new payment for one hour for " << itr->second.get_FirstName();
							cin >> hrs;
							itr->second.set_CostperHour(hrs);
							break;
						default:
							cout << "enter correct option next time\n";
					}

					cout << "Do you want to update ant other field(y/n)? ";
					cin.ignore();
					check = getchar();
					//here;
					cin.ignore();
					if (check == 'n' || check == 'N')
					{
						break;
					}
				}
			}

			while (1)
			{
				cout << "Do you want to repeat update by entering the new personal number(y/n)? ";
				//cin.ignore();
				check = getchar();
				if (check == 'n' || check == 'N')
				{
					option1 = 0;
					break;
				}
				else if (check == 'y' || check == 'Y')
				{
					break;
				}
			}
		}
	}

	// bool compareemployee(person &q1,person &q2)
	// {   
	//     return (q2.get_Salary() > q1.get_Salary());
	// }

	void swap(vector<int> &v, int x, int y);

	void quicksort(vector<person> &vec, int L, int R, int U, int X)
	{
		if (X != 1 && X != 2)
		{
			return;
		}

		int i, j, mid, piv, u, x = X;
		string faname;
		i = L;
		j = R;
		u = U;
		mid = L + (R - L) / 2;
		piv = getsalaryorlname(vec, mid, U);
		while (i < R || j > L)
		{
			if (x == 1)
			{
				while (getsalaryorlname(vec, i, U) < piv)
					i++;
			}
			else if (x == 2)
			{
				while (getsalaryorlname(vec, i, U) > piv)
					i++;
			}

			if (x == 1)
			{
				while (getsalaryorlname(vec, j, U) > piv)
					j--;
			}
			else if (x == 2)
			{
				while (getsalaryorlname(vec, j, U) < piv)
					j--;
			}

			if (i <= j)
			{
				swap(vec, i, j);
				i++;
				j--;
			}
			else
			{
				if (i < R)
					quicksort(vec, i, R, u, x);
				if (j > L)
					quicksort(vec, L, j, u, x);
				return;
			}
		}
	}

	int getsalaryorlname(vector<person> &vec, int i, int j)
	{
		string faname;
		int piv;
		if (j == 1)
		{
			faname = vec[i].get_LastName();
			piv = (int) faname[0];
			return piv;
		}
		else
		{
			piv = vec[i].get_Salary();
			return piv;
		}
	}

	void swap(vector<person> &v, int x, int y)
	{
		person temp = v[x];
		v[x] = v[y];
		v[y] = temp;

	}

	void reportlist()
	{
		cout << "please enter the related number of the field which you would like to sort the list based on it.";
		cout << "\n(1.Family name, 2.salary? ";
		cin >> option;

		if (option == 2)
		{
			vector<person> vectoremployee;
			for (itr = employee.begin(); itr != employee.end(); ++itr)
			{
				vectoremployee.push_back(itr->second);
			}

			//sort(vectoremployee.begin(),vectoremployee.end(),compareemployee);
			cout << "1.Accending order 2.Desending order \n";
			cin >> option1;
			cout << "Following is the result:\n";
			cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
			cout << "---------  ----------  --------------  ------------\n";

			if (option1 == 1)
			{
				quicksort(vectoremployee, 0, vectoremployee.size() - 1, 2, 1);

			}
			else if (option1 == 2)
			{
				quicksort(vectoremployee, 0, vectoremployee.size() - 1, 2, 2);
			}
			else
			{
				cout << "enter correct option.\n";
			}

			for (i = 0; i < vectoremployee.size(); i++)
			{
				cout << vectoremployee[i].get_FirstName() << "\t\t" << vectoremployee[i].get_LastName() << "\t\t" << vectoremployee[i].get_PersonalID() << "\t\t" << vectoremployee[i].get_Salary() << endl;
			}
		}
		else if (option == 1)
		{
			vector<person> vectoremployee;
			for (itr = employee.begin(); itr != employee.end(); ++itr)
			{
				vectoremployee.push_back(itr->second);
			}

			cout << "1.Accending order 2.Desending order \n";
			cin >> option1;
			if (option1 == 1)
			{
				quicksort(vectoremployee, 0, vectoremployee.size() - 1, 1, 1);

			}
			else if (option1 == 2)
			{
				quicksort(vectoremployee, 0, vectoremployee.size() - 1, 1, 2);
			}
			else
			{
				cout << "enter correct option.\n";
			}

			for (i = 0; i < vectoremployee.size(); i++)
			{
				cout << vectoremployee[i].get_FirstName() << "\t\t" << vectoremployee[i].get_LastName() << "\t\t" << vectoremployee[i].get_PersonalID() << "\t\t" << vectoremployee[i].get_Salary() << endl;
			}
		}
		else
		{
			cout << "enter correct option";
		}

		cout << "Please enter any key to come back to main menu. ";
		cin.ignore();
		check = getchar();
	}

	void searchperson()
	{
		int option2,option3,option1;
		while (option1 != 0)
		{
            map<int,person> employeefilter1,employeefilter2,employeefilter3;
			employeefilter1=createquery();
			displaynamedetails(employeefilter1);
			while(option2)
			{
				cout<<"1.AND 2.OR 3.NOT Operation to perform, Please enter your option: \n Enter 4 for exit ";
				cin>>option3;
				employeefilter2.clear();
				employeefilter3.clear();
				if(option3==1)
				{
					employeefilter2=createquery();
					displaynamedetails(employeefilter2);
					cout<<"enter any key to show the result";
					cin>>option1;
					for(itr = employeefilter1.begin(); itr != employeefilter1.end(); ++itr)
					{
						if(employeefilter2.find(itr->first) != employeefilter2.end())
						{
							employeefilter3.insert(pair<int,person>(itr->first,itr->second));
						}
					}
					cout<<"After operation: The new query : \n";
					displaynamedetails(employeefilter3);
				}
				else if(option3==2)
				{
					employeefilter2=createquery();
					displaynamedetails(employeefilter2);
					cout<<"enter any key to show the result";
					cin>>option1;
					for(itr = employeefilter1.begin(); itr != employeefilter1.end(); ++itr)
					{
						employeefilter3.insert(pair<int,person>(itr->first,itr->second));
					}
					for(itr = employeefilter2.begin(); itr != employeefilter2.end(); ++itr)
					{
						employeefilter3.insert(pair<int,person>(itr->first,itr->second));
					}
					cout<<"After operation: The new query : \n";
					displaynamedetails(employeefilter3);
				}
				else if(option3==3)
				{
					for(itr = employee.begin(); itr != employee.end(); ++itr)
					{
						if(employeefilter1.find(itr->first) == employeefilter1.end())
						{
							employeefilter3.insert(pair<int,person>(itr->first,itr->second));
						}
					}
					cout<<"After operation: The new query  :  \n";
					displaynamedetails(employeefilter3);

				}
				else
				{
                    break;
				}
				employeefilter1.clear();
				employeefilter1 = employeefilter3;				
			}

			while (1)
			{
				cout << "Do you want to do new search(y/n)? ";
				cin.ignore();
				check = getchar();
				if (check == 'n' || check == 'N')
				{
					option1 = 0;
					break;
				}
				else if (check == 'y' || check == 'Y')
				{
					break;
				}
			}
		}
	}
    map<int,person> createquery()
	{       int option2;
		    option1 = 1;
		    int personIDforsearch;
		    string letterstart, letterend;
		    string containing;
		    SEARCHmethod searchmethod;
			map<int, person> employeefilter1;
			cout << "Search is based on four different fields(1.first name 2.family name, 3.Salary, 4.employeeID), Please enter your choice? ";
			cin >> option;
	
			if (option == 1 || option == 2)
			{
				cout << "Search by 1.starting letter   2.ending letter   3.containing ";
				cin >> option2;
				if (option2 == 1)
				{
					cout << "enter the starting letter ";
					cin >> letterstart;
					employeefilter1 = searchmethod.searchforstring(employee, letterstart, 1, option);

				}
				else if (option2 == 2)
				{
					cout << "enter the ending letter ";
					cin >> letterend;
					employeefilter1 = searchmethod.searchforstring(employee, letterend, 2, option);

				}
				else if (option2 == 3)
				{
					cout << "enter the string containing ";
					cin >> containing;
					employeefilter1 = searchmethod.searchforstring(employee, containing, 3, option);

				}
				else
				{
					cout << "enter the correct option.\n";
				}
			}
			else if (option == 3)
			{
				cout << "Please define your search range for Salary of employees .\n";
				cout << "what is Salary limit1 for search? ";
				cin >> S_min;
				cout << "Please enter 1.== 2.> 3.< 4.<= 5.>= 6.!= 7.between\n";
				cin >> option2;
				switch (option2)
				{
					case 1:
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, 0, 1);
						break;

					case 2:
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, 0, 2);
						break;

					case 3:
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, 0, 3);
						break;

					case 4:
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, 0, 4);
						break;

					case 5:
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, 0, 5);
						break;

					case 6:
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, 0, 6);
						break;

					case 7:
						cout << "enter the second upper limit ";
						cin >> S_max;
						employeefilter1 = searchmethod.searchfordouble(employee, S_min, S_max, 7);
						break;

					default:
						cout << "enter the correct option.\n";
						break;

				}
			}
			else if (option == 4)
			{
				cout << "Please define your search range for personID of employees .\n";
				cout << "enter the personID limit1 for search? ";
				cin >> S_min;
				cout << "Please enter 1.== 2.> 3.< 4.<= 5.>= 6.!= 7.between\n";
				cin >> option2;
				switch (option2)
				{
					case 1:
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, 0, 1);
						break;

					case 2:
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, 0, 2);
						break;

					case 3:
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, 0, 3);
						break;

					case 4:
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, 0, 4);
						break;

					case 5:
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, 0, 5);
						break;

					case 6:
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, 0, 6);
						break;

					case 7:
						cout << "enter the second upper limit ";
						cin >> S_max;
						employeefilter1 = searchmethod.searchforinteger(employee, S_min, S_max, 7);
						break;

					default:
						cout << "enter the correct option.\n";
						break;

				}

			}
			else
			{
				cout<<"enter correct option\n";
			}
			return employeefilter1;
	}
	void displaynamedetails(map<int,person> employeefilter1)
	{
		cout << "Following is the list of employees for your defined search fields:\n";
		cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
		cout << "---------  ----------  --------------  ------------\n";
		for (itr=employeefilter1.begin(); itr != employeefilter1.end(); ++itr)
			{
				cout << itr->second.get_FirstName() << "\t\t" << itr->second.get_LastName() << "\t\t" << itr->second.get_PersonalID() << "\t\t" << itr->second.get_Salary() << endl;
			}

	}

	void displaydetails()
	{
		cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
		cout << "---------  ----------  --------------  ------------\n";
		for (itr = employee.begin(); itr != employee.end(); ++itr)
		{
			cout << itr->second.get_FirstName() << "\t\t" << itr->second.get_LastName() << "\t\t" << itr->second.get_PersonalID() << "\t\t" << itr->second.get_Salary() << endl;

		}

		cout << "Please enter any key to come back to main menu. ";
		cin.ignore();
		check = getchar();
	}
};
int HRM::employeeid = 8921000;
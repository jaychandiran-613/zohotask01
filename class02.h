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
					cout << "Please enter only integer for hours\n";
					cin.clear();
					cin.ignore();
				}
			}

			number_staff++;
			person newperson;
			newperson.set_FieldName(fname, lname, hrs, cost);
			employee.insert(pair<int, person> (++employeeid, newperson));
			cout << "Do you want to add another employee(y/n) ";
			cin.ignore();
			check = getchar();
			cout << "a\n";
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
				if (check == 'Y' || 'y')
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
					if (check == 'n' || check == 'N')
					{
						break;
					}
				}
			}

			while (1)
			{
				cout << "Do you want to repeat update by entering the new personal number(y/n)? ";
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

	// void reportlist()
	// {
	//     cout<<"please enter the related number of the field which you would like to sort the list based on it.";
	//     cout<<"\n(1.Family name, 2.salary? ";
	//     cin>>option;
	//     cout<<"Following is the result:\n";
	//     cout<<"FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
	//     cout<<"---------  ----------  --------------  ------------\n";
	//     if(option==1)
	//     {
	//         for(i=1;i<=number_staff;i++)
	//         {
	//             p1[i]=p[i];
	//         }

	//         for(i=1;i<=number_staff;i++)
	//         {
	//             for(j=1;j<=number_staff-i;j++)
	//             {
	//                 string lname1=p1[j].get_LastName();
	//                 string lname2=p1[j+1].get_LastName();
	//                 int k=lname1[0],l=lname2[0];
	//               if((k-l)>0)
	//               {
	//                 p2=p1[j];
	//                 p1[j]=p1[j+1];
	//                 p1[j+1]=p2;
	//               }  
	//             }

	//         }

	//         for(i=1;i<=number_staff;i++)
	//         {
	//             cout<<p1[i].get_FirstName()<<"\t\t"<<p1[i].get_LastName()<<"\t\t"<<p1[i].get_PersonalID()<<"\t\t"<<p1[i].get_Salary()<<endl;
	//         }

	//     }

	//     else if(option==2){
	//         for(i=1;i<=number_staff;i++){
	//             p1[i]=p[i];
	//         }

	//         for(i=1;i<=number_staff;i++){
	//             for(j=1;j<=number_staff-i;j++){
	//                 if(p1[j].get_Salary()>p1[j+1].get_Salary()){
	//                  p2=p1[j];
	//                 p1[j]=p1[j+1];
	//                 p1[j+1]=p2;
	//                 }

	//             }

	//         }

	//         for(i=1;i<=number_staff;i++){
	//             cout<<p1[i].get_FirstName()<<"\t\t"<<p1[i].get_LastName()<<"\t\t"<<p1[i].get_PersonalID()<<"\t\t"<<p1[i].get_Salary()<<endl;
	//         }

	//     }

	//     else{
	//         cout<<"enter correct option";
	//     }

	//     cout<<"Please enter any key to come back to main menu. ";
	//     cin.ignore();
	//     check=getchar();
	// }

	void searchperson()
	{
		option1 = 1;
		while (option1 != 0)
		{
			cout << "Search is based on two different fields(1.family name, 2.Salary), Please enter your choice? ";
			cin >> option;
			if (option == 1)
			{
				cout << "please enter the family name of employee? ";
				cin >> lname;
				cout << "Following is the list of employees for your defined search fields:\n";
				cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
				cout << "---------  ----------  --------------  ------------\n";
				for (itr = employee.begin(); itr != employee.end(); ++itr)
				{
					if (itr->second.get_LastName() == lname)
					{
						cout << itr->second.get_FirstName() << "\t\t" << itr->second.get_LastName() << "\t\t" << itr->second.get_PersonalID() << "\t\t" << itr->second.get_Salary() << endl;

					}
				}
			}
			else if (option == 2)
			{
				cout << "Please define your search range for Salary of employees (S_min, S_max).\n";
				cout << "what is minimum Salary for search(S_min)? ";
				cin >> S_min;
				cout << "What is maximum Salary for search(S_max)? ";
				cin >> S_max;
				cout << "Following is the list of employees for your defined search fields:\n";
				cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
				cout << "---------  ----------  --------------  ------------\n";
				for (itr = employee.begin(); itr != employee.end(); ++itr)
				{
					if (itr->second.get_Salary() >= S_min && itr->second.get_Salary() <= S_max)
					{
						cout << itr->second.get_FirstName() << "\t\t" << itr->second.get_LastName() << "\t\t" << itr->second.get_PersonalID() << "\t\t" << itr->second.get_Salary() << endl;

					}
				}
			}
			else
			{
				continue;
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
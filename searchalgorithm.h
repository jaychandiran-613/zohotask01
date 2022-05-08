class SEARCHmethod
{
	public:

	string check;
	map<int,person> filteredemployee;
	map<int,person>:: iterator itr1;
	int j;
	map<int,person> searchforstring(map<int,person> mapperson, string letter, int letterselect, int nameselect)
	{   
		if (letterselect == 1)
		{
			for (itr1=mapperson.begin(); itr1 != mapperson.end(); ++itr1)
			{
				if (nameselect == 1)
				{
					check = itr1->second.get_FirstName();

				}
				else
				{
					check = itr1->second.get_LastName();

				}
                auto res = mismatch(letter.begin(), letter.end(), check.begin());

				if (res.first == letter.end())
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
		}
		else if (letterselect == 2)
		{
			for (itr1=mapperson.begin(); itr1!=mapperson.end(); ++itr1)
			{
				if (nameselect == 1)
				{
					check = itr1->second.get_FirstName();

				}
				else if (nameselect == 2)
				{
					check = itr1->second.get_LastName();

				}
				auto res = mismatch(letter.rbegin(), letter.rend(), check.rbegin());   
				if (res.first == letter.rend())
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
		}
		else
		{
			for (itr1=mapperson.begin(); itr1 != mapperson.end(); ++itr1)
			{
				if (nameselect == 1)
				{
					check = itr1->second.get_FirstName();

				}
				else
				{
					check = itr1->second.get_LastName();

				}

				// bool found = haystack.find(needle) != std::string::npos;
				if (check.find(letter) != string::npos)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
		}

		return filteredemployee;
	}

	map<int,person> searchfordouble(map<int,person> mapperson, double limit1, double limit2, int option)
	{   
		for (itr1=mapperson.begin(); itr1 != mapperson.end(); ++itr1)
		{
			if (option == 1)
			{
				if (itr1->second.get_Salary() == limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 2)
			{
				if (itr1->second.get_Salary() > limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 3)
			{
				if (itr1->second.get_Salary() < limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 4)
			{
				if (itr1->second.get_Salary() <= limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 5)
			{
				if (itr1->second.get_Salary() >= limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 6)
			{
				if (itr1->second.get_Salary() != limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 7)
			{
				if (itr1->second.get_Salary() >= limit1 && itr1->second.get_Salary() <= limit2)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
		}

		return filteredemployee;

	}

	map<int,person> searchforinteger(map<int,person> mapperson, int limit1, int limit2, int option)
	{
		// vector<person>::iterator it;
		// it=find(vectorperson.begin(),vectorperson.end(),personID);
		// fvectorperson.push_back(*it);  
		// return fvectorperson;
		for (itr1=mapperson.begin(); itr1 != mapperson.end(); ++itr1)
		{
			if (option == 1)
			{
				if (itr1->second.get_PersonalID() == limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 2)
			{
				if (itr1->second.get_PersonalID()  > limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 3)
			{
				if (itr1->second.get_PersonalID()  < limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 4)
			{
				if (itr1->second.get_PersonalID()  <= limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 5)
			{
				if (itr1->second.get_PersonalID()  >= limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 6)
			{
				if (itr1->second.get_PersonalID()  != limit1)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
			else if (option == 7)
			{
				if (itr1->second.get_PersonalID()  >= limit1 && itr1->second.get_PersonalID()  <= limit2)
				{
					filteredemployee.insert(pair<int,person>(itr1->second.get_PersonalID(),itr1->second));
				}
			}
		}

		return filteredemployee;
	}
};
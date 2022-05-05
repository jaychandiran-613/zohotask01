class person
{
	private:
		string FirstName;
	string LastName;
	static int PersonalID;
	int personalid;
	double salary;
	double WorkingHours;
	double CostPerHour;

	public:
		person()
		{
			personalid = ++PersonalID;
		}

	void set_FieldName(string fname, string lname, int hrs, int cost)
	{
		FirstName = fname;
		LastName = lname;
		WorkingHours = hrs;
		CostPerHour = cost;
		salary = (WorkingHours *CostPerHour);

		cout << "The employee with the following information has been added to the system:" << endl;
		cout << "FirstName  FamilyName  PersonalNumber  Salary(Euro)\n";
		cout << "---------  ----------  --------------  ------------\n";
		cout << FirstName << "\t" << LastName << "\t" << personalid << "\t" << salary << endl;
	}

	void set_FirstName(string fname)
	{
		FirstName = fname;
	}

	string get_FirstName()
	{
		return FirstName;
	}

	void set_LastName(string lname)
	{
		LastName = lname;
	}

	void set_WorkingHours(int hrs)
	{
		WorkingHours = hrs;
		salary = (WorkingHours *CostPerHour);
	}

	void set_CostperHour(int cost)
	{
		CostPerHour = cost;
		salary = (WorkingHours *CostPerHour);
	}

	void set_salary(int cost)
	{
		salary = cost;
	}

	string get_LastName()
	{
		return LastName;
	}

	double get_Salary()
	{
		return salary;
	}

	int get_PersonalID()
	{
		return personalid;
	}
};

int person::PersonalID = 8921000;
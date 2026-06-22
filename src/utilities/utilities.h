#ifndef REPORT_H
#define REPORT_H

#include<iostream>
#include<string>
using namespace std;
const int MAXSTUDENTS = 5;
class reports
{
public:
	void campusreport()
	{
		cout << "university campus report" << endl;
		cout << "Students Module = Active" << endl;
		cout << "Courses Module  = Active" << endl;
		cout << "Library Module  = Active" << endl;
		cout << "Finance Module  = Active" << endl;
		cout << "Hostel Module   = Active" << endl;
	}
	void pdfreport()
	{
		cout << "uni campus report" << endl;
		cout << "Student Records Available" << endl;
		cout << "Course Records Available" << endl;
		cout << "Library Records Available" << endl;
		cout << "Finance Records Available" << endl;
		cout << "Hostel Records Available" << endl;
	}
};
class utlis
{
public:
	void displaydate()
	{
		cout << "date= 21/06/2026" << endl;
	}
	void formattitle(string title)
	{
		cout << "------'.'---" << title << "-------'.'------" << endl;
	}
	bool validateinput(int value)
	{
		if (value < 0)
		{
			return false;
		}
		return true;
	}
		void sortGPA(double gpa[], int size)
	{
		for (int i = 0;i < size - 1;i++)
		{
			for (int j = 0;j < size - i - 1;j++)
			{
				if (gpa[j] < gpa[j + 1])
				{
					double temp = gpa[j];
					gpa[j] = gpa[j + 1];
					gpa[j + 1] = temp;
				}
			}
		}

		cout << "Sorted GPA" << endl;

		for (int i = 0;i < size;i++)
		{
			cout << gpa[i] << endl;
		}
	}

	void searchBook(string books[], int size, string name)
	{
		bool found = false;

		for (int i = 0;i < size;i++)
		{
			if (books[i] == name)
			{
				cout << "Book Found : " << books[i] << endl;
				found = true;
			}
		}

		if (found == false)
		{
			cout << "Book Not Found" << endl;
		}
	}
};

int main()
{
	Reports report;
	Utils utility;

	report.campusReport();

	cout << endl;

	report.pdfReport();

	cout << endl;

	utility.formatTitle("Student Report");

	utility.displayDate();

	if (utility.validateInput(10))
	{
		cout << "Valid Input" << endl;
	}
	else
	{
		cout << "Invalid Input" << endl;
	}

	cout << endl;

	double gpa[5] = { 3.2,3.9,2.8,3.5,3.0 };

	utility.sortGPA(gpa, 5);

	cout << endl;

	string books[5] =
	{
		"OOP","DSA","DBMS","AI","Networking"
	};
	utility.searchBook(books, 5, "DBMS");

	return 0;
}

#endif

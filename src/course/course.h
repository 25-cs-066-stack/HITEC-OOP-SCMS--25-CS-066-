#include<iostream>
#include<string>
#include"person.h"
using namespace std;

class capacityexceededexception
{
public:
	void message()
	{
		cout << "course capacity exceeded" << endl;
	}
};
class course
{
private:
	string coursecode;
	string coursename;
	int credithours;
	faculty* instructor;
	int maxcapacity;
	int enrolledcount;

	student* enrolledstudents[50];
public:
	course(string code, string name, int credits, faculty* inst, int capacity)
	{
		coursecode = code;
		coursename = name;
		credithours = credits;
		instructor = inst;
		maxcapacity = capacity;
		enrolledcount = 0;

	}
	string getcoursecode()
	{
		return coursecode;
	}
	string getcoursename()
	{
		return coursename;
	}
	int getcredithours()
	{
		return credithours;
	}
	int getmaxcapacity()
	{
		return maxcapacity;
	}
	int getenrolledcount()
	{
		return enrolledcount;
	}
	void setcoursename(string name)
	{
		coursename = name;
	}
	void setcredithours(int hours)
	{
		credithours = hours;
	}
	void setmaxcapacity(int cap)
	{
		maxcapacity = cap;
	}
	void enrollstudent(student* s)
	{
		if (enrolledcount >= maxcapacity)
		{
			throw capacityexceededexception();
		}
		enrolledstudents[enrolledcount] = s;
		enrolledcount++;
	}
	bool operator==(course& c)
	{
		return coursecode == c.coursecode;
	}
	student** operator+(course& c)
	{
		staic student* merged[100];
		int k = 0;

		for (int i = 0;i < waitingcount;i++)
		{
			merged[k] = waitinglist[i];
			k++;
		}
		for (int i = 0;i < c.waitingcount;i++)
		{
			merged[k] = c.waitinglist[i];
			k++;
		}
		return merged;
	}
	friend ostream& operator<<(ostream& out, course& c)
	{
		out << "course code " << c.coursecode << endl;
		out << "course name " << c.coursename << endl;
		out << "credit hours " << c.credithours << endl;
		out << "max capacity " << c.maxcapacity << endl;
		out << " enrolled student " << c.enrolledcount << endl;
		return out;

	}
};
class enrollment
{
private:
	student* student;
	course* course;
	string enrllmentdate;
	char grade;

public:
	enrollment(atudent* s, course* c, string date, char g)
	{
		student = s;
		course = c;
		enrollmentdate = date;
		grade = g;
	}
	void dispaly()
	{

		cou << "enrollement date " << enrollmentdate << endl;
		cout << "grade" << endl;
	}
};
int main()
{
	string facultycourses[3] = {"oop","pf","dld"};
	faculty f1("naveed", "1232-34534", 50,"348635345","f1014","computer science","prof", facultycourses);

	string studentcourses[3] = { "oop","dsa","dbms" }
	student s1("haseeb","111111-1111",20 ,"345875","25-cs-066",4 ,3.8 , studentcourses);

	student s2("irfan", "234324324-45", 20, "3584635", "25-cs-131", 4, 3.0, studentcourses);

	course c1("cs201", "oop", 3, &f1, 2);
	course c2("cs201", "oop", 3, &f1, 5);


	if (c1 == c2)
	{
		cout << "courses are same" << endl;
	}

	try
	{
		c1.enrollstudent(&s1);
		c1.enrollstudent(&s2);

		student s3("Hassan","33333-3333333-3",20,"03003334444","23-CS-003",4,3.2,studentCourses);

		c1.enrollStudent(&s3);

	}
	catch (capacityexceededexpection e)
	{
		e.message();
	}
	cout << c1;

	student** waitinglist;
	waitinglist = c1 + c2;

	enrollment e1(&s1, &c1, "20-06-2020", 'A');
	e1.display();
	return 0;
}

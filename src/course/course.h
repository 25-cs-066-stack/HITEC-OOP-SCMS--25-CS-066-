#ifndef COURSE_H
#define COURSE_H

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

	student* waitinglist[50];
	int waitingcount;
public:
	course(string code, string name, int credits, faculty* inst, int capacity)
	{
		coursecode = code;
		coursename = name;
		credithours = credits;
		instructor = inst;
		maxcapacity = capacity;
		enrolledcount = 0;
		waitingcount = 0;
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
		if (enrolledcount < maxcapacity)
		{
			enrolledstudents[enrolledcount] = s;
			enrolledcount++;
		}
		else
		{
			throw capacityexceededexception();
		}
		
	}
	bool operator==(course& c)
	{
		return coursecode == c.coursecode;
	}
	student** operator+(course& c)
	{
		static student* merged[100];
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
	student* enrolledstudent;
	course* enrolledcourse;
	string enrollmentdate;
	char grade;

public:
	enrollment(student* s, course* c, string date, char g)
	{
		enrolledstudent = s;
		enrolledcourse = c;
		enrollmentdate = date;
		grade = g;
	}
	void display()
	{

		cout << "enrollement date " << enrollmentdate << endl;
		cout << "grade" <<grade << endl;
	}
};
#endif
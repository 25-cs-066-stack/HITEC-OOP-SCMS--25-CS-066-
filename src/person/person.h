#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include <string>   // Name, CNIC, Contact aur dusri text values store karne ke liye
using namespace std;
class person
{
protected:
	string name;
	string cnic;
	int age;
	string contact;
public:
	person(string n, string c, int a, string con)
	{
		name = n;
		cnic = c;
		age = a;
		contact = con;
	}
	virtual void displayinfo() = 0;
	 virtual ~person(){}

};
class student :public person
{
private:
	string rollno;
	int semester;
	double gpa;
	string enrolledcourses[3];
public:
	student(string n, string c, int a, string con, string r, int s, double g,string courses[]) :person(n, c, a, con)
	{
		rollno = r;
		semester = s;
		gpa = g;
	
			enrolledcourses[0] = courses[0];
			enrolledcourses[1] = courses[1];
			enrolledcourses[2] = courses[2];
		
	}
	char calculategrade()
	{
		if(gpa>=3.7)
		{
			return 'A';
		}
		else if (gpa >= 3.0)
		{
			return 'b';
		}
		else if (gpa >= 2.0)
		{
			return'c';
		}
		else if (gpa >= 1.0)
		{
			return 'd';
		}
		else
		{
			return 'f';
		}
	}
	void displayinfo()
	{
		cout << "--------student info----- " << endl;

		cout << "name : " << name << endl;
		cout << "cnic : " << cnic << endl;
		cout << "age : " << age<<endl;
		cout << "contact : " << contact << endl;
		cout << "rollno : " << rollno << endl;
		cout << "semester : " << semester << endl;
		cout << "gpa : " << gpa << endl;
		cout << "grade : " << calculategrade() << endl;
		cout << "courses : "
			<< enrolledcourses[0] << ", "
			<< enrolledcourses[0] << ", "
			<< enrolledcourses[0] << ", " << endl;

	}
};
class faculty :public person
{
private:
	string employeeID;
	string department;
	string designation;
	string assignedcourses[3];
public:
	faculty(string n, string c, int a, string con, string id, string dept, string desig, string courses[])
		:person(n, c, a, con)
	{
		employeeID = id;
		department = dept;
		designation = desig;
		

			assignedcourses[0] = courses[0];
			assignedcourses[1] = courses[1];
			assignedcourses[2] = courses[2];
	
		}
	void displayinfo()
	{
		cout << "---------faculty--------" << endl;
		cout << "name : " << name << endl;
		cout << "cnic :" << cnic << endl;
		cout << "age : " << age << endl;
		cout << "contact : " << contact << endl;
		cout << "employee id : " << employeeID << endl;
		cout << "department : " << department << endl;
		cout << "designation :" << designation << endl;
		cout << "assigned courses :"

			<< assignedcourses[0] << " , "
			<< assignedcourses[1] << " , "
			<< assignedcourses[2] << endl;
	}
};
class staff :public person
{
private:
	string staffid;
	string role;
	double salary;
public:
	staff(string n,string id, string c, int a, string con, string r, double sal) :person(n, c, a, con)
	{
		staffid = id;
		role = r;
		salary = sal;
	}
	void displayinfo()
	{
		cout << "-----staff-----" << endl;
		cout << "name : " << name << endl;
		cout << "cnic :" << cnic << endl;
		cout << "age" << age << endl;
		cout << "contact" << contact << endl;
		cout << "staff id" << staffid << endl;
		cout << "role" << role << endl;
		cout << "salary" << salary << endl;
	}
};
#endif
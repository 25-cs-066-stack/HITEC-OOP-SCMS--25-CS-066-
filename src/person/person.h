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
	student(string n, string c, int a, string con, string r, int s, double g) :person(n, c, a)
	{
		rollno = r;
		semester = s;
		gpa = g;
		for (int i = 0;i < 3;i++)
		{
			enrolledcourses[i] = courses[i];//Yeh loop 3 courses ko ek array se doosre array me copy karne ke liye use kiya gaya hai.
		}
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
		cout << "student info " << endl;
		cout << "name : " << name << endl;
		cout << "cnic : " << cnic << endl;
		cout << "age : " << age<<endl;
		cout << "contact : " << contact << endl;
		cout << "rollno : " << rollno << endl;
		cout << "semester : " << semester << endl;
		cout << "gpa : " << gpa << endl;
		cout << "grade : " << calculategrade() << endl;
		cout << "courses : ";
		for (int i = 0;i < 3;i++)
		{
			cout << enrollmentcourses[i] << " ";// Student ke tamam enrolled courses display karne ke liye
			cout << endl;
		}
	}
};
class faculty :public person
{
private:
	string employee id;
	string department;
	string designation;
	string assignedcourses[3];
public:
	faculty(string n, string c, int a, string con, string id, string dept, string desig, string courses[])
		:person(n, c, a, con)
	{
		empolyeeid = id;
		department = dept;
		designation = desig;
		for (int i = 0;i < 3;i++)

		{
			assignedcourses[i] = courses[i];// Student ke courses ko object ke enrolledCourses array me copy karne ke liye
		}
	}
	void displayinfo()
	{
		cout << "faculty" << endl;
		cout << "name : " << name << endl;
		cout << "cnic :" << cnic << endl;
		cout << "age : " << age << endl;
		cout << "contact : " << contact << endl;
		cout << "employee id : " << employeeid << endl;
		cout << "department : " << department << endl;
		cout << "designation :" << designation << endl;
		cout << "assigned courses" << endl;
		for (int i = 0;i < 3;i++)
		{
			cout << "assigned courses :";
			for (int i = 0;i < 3;i++)
			{
				cout << assignedcourses[i]=coursesp[i] << "";// Faculty ke assigned courses ko object ke assignedCourses array me copy karne ke liye
				cout << endl;
			}
		}

	}
};
class staff :public person
{
private:
	string staffid;
	string role;
	double salary;
public:
	staff(string, string c, int a, string con, string r, double sal) :person(n, c, a, con)
	{
		staffid = id;
		role = r;
		salary = sal;
	}
	void display info()
	{
		cout << "staff" << endl;
		cout << "name : " << name << endl;
		cout << "cnic :" << cnic << endl;
		cout << "age" << age << endl;
		cout << "contact" << contact << endl;
		cout << "staff id" << staffid << endl;
		cout << "role" << role << endl;
		cout << "salary" << salary << endl;
	}
};
int main()
{
	string studentcourses[3] =
	{
	 "opp",
	 "dSA",
	 "dbms",
	};// Student ke enrolled courses store karne ke liye array
	string facultycourse[3] =
	{
		"oop",
		"pf",
		"dld",
	};// Faculty ko assign kiye gaye courses store karne ke liye array
	person* p1 = new student("haseeb", "112323343-45", 20, "0333443545435", "25-cs-066", 4, 3.8, studentcourses);
	person* p2=new faculty("ahmed","34345-6546",30,"f101","computer science","professor",facultycourse);
	person* p3 = new staff("usman","1111111-22222",35,"234343243434","sl202","lab assitant",5000);
	p1->displayinfo();
	p2->displayinfo();
	p3->displayinfo();
	return 0;
} 
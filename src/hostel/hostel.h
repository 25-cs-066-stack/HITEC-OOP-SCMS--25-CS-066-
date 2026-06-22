#ifndef HOSTEL_H
#define HOSTEL_H

#include<iostream>
#include<string>
#include"person.h"
using namespace std;

const int MAXROOMS = 5;
const int MAXSTUDENT = 3;

class Accommodation
{
public:
	virtual void allocateroom(student* s, int roomno) = 0;
	virtual void vacateroom(student* s, int roomno) = 0;
	virtual ~Accommodation(){}
};
class Reportable
{
public:
	virtual void generatereport() = 0;
	virtual~Reportable(){}
};
class room
{
private:
	int roomnumber;
	string type;
	int floor;
	student* occupants[MAXSTUDENT];
	int occupantCount;

public:
	room()
	{
		roomnumber = 0;
		type = "";
		floor = 0;
		occupantCount = 0;
	}
	room(int number, string t, int f)
	{
		roomnumber = number;
		type = t;
		floor = f;
		occupantCount = 0;
	}
	void addstudent(student* s)
	{
		if (occupantCount < MAXSTUDENT)
		{
			occupants[occupantCount] = s;
			occupantCount++;
		}
		else
		{
			cout << "room is full" << endl;
		}
	}
	void removestudent()
	{
		if (occupantCount > 0)
		{
			occupantCount--;
			occupants[occupantCount] = nullptr;
		}
		else
		{
			cout << "room is empty" << endl;
		}
	}
	int getroomnumber()
	{
		return roomnumber;
	}
	int getoccupantcount()
	{
		return occupantCount;
	}
	void display()
	{
		cout << "Room Number : " << roomnumber << endl;
		cout << "Type : " << type << endl;
		cout << "Floor : " << floor << endl;
		cout << "Occupants : " << occupantCount << endl;
	}
};
class hostelblock
{
private:
	string blockname;
	room rooms[MAXROOMS];
public:
	hostelblock()
	{
		blockname = "";
	}
	hostelblock(string name)
	{
		blockname = name;
		rooms[0] = room(101, "Single", 1);
		rooms[1] = room(102, "Double", 1);
		rooms[2] = room(201, "Single", 2);
		rooms[3] = room(202, "Double", 2);
		rooms[4] = room(301, "Triple", 3);
	}
	room* getroom(int roomno)
	{
		for (int i = 0;i < MAXROOMS;i++)
		{
			if (rooms[i].getroomnumber() == roomno)
			{
				return &rooms[i];
			}
		}
		return nullptr;
}
	void displayrooms()
	{
		for (int i = 0;i < MAXROOMS;i++)
		{
			rooms[i].display();
			cout << endl;
		}
	}
};
class hostelmanager :public Accommodation, public Reportable
{
private:
	hostelblock hostel;
public:
	hostelmanager(string block):hostel(block)
	{ }
	void allocateroom(student* s, int roomno)
	{
		room* room = hostel.getroom(roomno);
		if (room != nullptr)
		{
			room->addstudent(s);
			cout << "allocated sucessfully" << endl;
		}
		else
		{
			cout << "not found" << endl;
		}
	}
	void vacateroom(student* s, int roomno)
	{
		room* room = hostel.getroom(roomno);
		if (room != nullptr)
		{
			room->removestudent();
			cout << "vacuated sucessfully" << endl;
		}
		else
		{
			cout << "room not found" << endl;
		}
	} 
	void generatereport()
	{
		hostel.displayrooms();
	}
};
#endif 
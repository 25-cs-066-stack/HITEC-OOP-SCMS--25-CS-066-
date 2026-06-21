#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class overdueexception
{
private:
	double fine;
public:
	overdueexception(double f)
	{
		fine = f;
	}
	void message()
	{
		cout << " over due ....fine= rs." << fine << endl;
	}
};
struct issuerecord
{
	string rollno;
	string itemid;
};
class libraryitem
{
protected:
	string itemid;
	string title;
	string author;
	int publictaionyear;
public:
	libraryitem(string id, string t, string a, int y)
	{
		item = id;
		title = t;
		author = a;
		publicationyear = y;
	}
	virtual void checkout() = 0;
	string gettitle()
	{
		return title;
	}
	string getitemid()
	{
		return itemid;
	}
	virtual void display()
	{
		cout << "item id : " << itemid << endl;
		cout << "title : " << title << endl;
		cout << "author : " << author << endl;
		cout << "publication year : " << publicationyear << endl;
	}
	virtual ~libraryitem()
};
class book :public libraryitem
{
private:
	string ISBN;
	string genre;
	int copiesavailiable;
public:
	book(string id, string t, string a, int y, string isbn, string g, int copies) :libraryitem(id, t, a, y)
	{
		ISBN = isbn;
		genre = g;
		copiesavailable = copies;
	}
	void checkout()
	{
		if (copiesavailable > 0)
		{
			copiesavailiable--;
			cout << "book issued sucessfully" << endl;
		}
		else
		{
			cout << "no copies available" << endl;
		}
	}
	void display()
	{
		library::display();
		cout << "isbn is " << ISBN << endl;
		cout << "genre " << genre << endl;
		cout << "availble copies " << copiesavailable << endl;
	}
};
class journal :public libraryitem
{
private:
	string ISSN;
	int volume;
	int issuenumber;
public:
	journal(string id, string t, string a, int y, string issn, int v, int issue) :libraryitem(id, t, a, y)
	{
		ISSN = issn;
		volume = v;
		issuenumber = issue;
	}
	void checkout()
	{
		cout << "issued sucessfully" << endl;
	}
	void display()
	{
		libraryitem::display();
		cout << "issn  " << issn << endl;
		cout << "volume  " << volume << endl;
		cout << "issue number" << issuenumber << endl;
};
	class library
	{
	private:
		libraryitem* catalog[10];
		int count;
		issuedrecord issued[10];
		int issuedcount;

	pulic:
		library()
		{
			cout = 0;
			issuedcount = 0;
		}
		void additem(libraryitem* item)
		{
			catalog[count] = item;
			count++;
		}
		void searchbytitle(string t)
		{
			bool found = false;
			for (int i = 0;i < count;i++)
			{
				if (catalog[i]->gettitle() == t)
				{
					cout << "item " << endl;
					catalog[i]->display();
					found = true;
				}
			}
			if (found == false)
			{
				cout << "item not found" << endl;
			}
		}
		void savetofile()
		{
			ofstream file("library.txt");
			for (int i = 0;i < count;i++)
			{
				file << catalog[i]->getitemid() << endl;
				file << catalog[i]->getitle() << endl;
			}
			file.close();
			cout << "data saved " << endl;
		}
		void loadfromfile()
		{
			ifstream file("library.txt");
			string id;
			string title;
			while (file >> id)
			{
				file.ignore();
				getline(file, title);
				cout << "item id" << id << endl;
				cout << "title" << title << endl;
			}
			file.close();
		}
		void issueitem(string roll, string id)
		{
			issued[issuedcount].rollno = roll;
			issued[issuedcount].itemid = id;
			issuedcount++;
			cout << "------item issued------ " << endl;
		}

		void returnitem(int dayslate)
		{
			if (dayslate > 0)
			{
				throw overdueexception(dayslater * 100);
			}
			cout << "item returned sucessfully" << endl;
		}

	};
	int main()
	{
		library lib;
		book b1("b121", "oop", "haseeb", 2025, "3243-56546", "programming", 5);
		Journal j1("J101", "AI Journal", "Ahmed", 2024, "ISSN-111", 2, 5);
		lib.additem(&b1);
		lib.additem(&j1);

		lib.searchbytitle("oop");
		lib.savetofie();
		lib.loadfromfile();
		lib.issueitem("25-cs-066", "b101");
		try
		{
			library.returnitem(5);
		}
		catch (overexception e)
		{
			e.message();
		}
		return 0;
	}








	};



































};
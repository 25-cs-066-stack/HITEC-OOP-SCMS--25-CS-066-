#ifndef FINANCE_H
#define FINANCE_H//header guard.h files k liya ta same name k funtions repaeat ho k error na aaja a
#include<iostream>
#include<string>
using namespace std;

constant int MAXITEMS = 3;//number of items fixed rakhna k liaya  
class feerecord
{
private:
	string studentref;
	double semesterfee;
	double hostelfee;
	double libraryfine;
	double totalpaid;
	double balance;
	
	void calculatebalance()
	{
		totalpaid = 0;
		balance = semesterfee + hostelfee + libraryfine;
    }
public:
	feerecord(string ref, double sem, double hostel, double fine)
	{
		studentref = ref;
		semesterfee = sem;
		hostelfee = hostel;
		libraryfine = fine;
	}
	feerecode(const feerecord& obj)
	{
		studentref = obj.studentref;
		semesterfee = obj.semesterfee;
		hostelfee = obj.hostelfee;
		libraryfine = obj.libraryfine;
		totalpaid = obj.totalpaid;
		balance = obj.balance;

	}
	//Ye Copy Assignment Operator hai. Jab ek existing object ki values doosre existing object mein copy karni hoti hain (obj1 = obj2;), tab ye function automatically call hota hai.
		//Ye obj ki saari data members ko current object mein copy karta hai aur return *this current object ko wapas return karta hai.
	FeeRecord& operator=(const FeeRecord& obj)
	{
		if (this != &obj)
		{
			studentref = obj.studentref;
			semesterfee = obj.semesterfee;
			hostelfee = obj.hostelfee;
			libraryfine = obj.libraryfine;
			totalpaid = obj.totalpaid;
			balance = obj.balance;
		}
		retrun* this;
		}
	void operator-=(double payment)//Ye obj ki saari data members ko current object mein copy karta hai aur return *this current object ko wapas return karta hai.
	{
		totalpaid += payment;
		balance -= payment;
	}
	void display()
	{
		cout << "Student Reference : " << studentRef << endl;
		cout << "Semester Fee : " << semesterFee << endl;
		cout << "Hostel Fee : " << hostelFee << endl;
		cout << "Library Fine : " << libraryFine << endl;
		cout << "Total Paid : " << totalPaid << endl;
		cout << "Balance : " << balance << endl;
	}
};
class invoice
{
private:
	static  int invoicecounter;//static isliye use kiya hai taake sirf ek hi invoiceCounter bane aur woh sabhi Invoice objects ke liye common ho.
	int invoiceid;
	string date;
	string* items;//string *items ek pointer hai. Hum new se dynamically memory banate hain aur items us memory ko point karta hai. Isliye destructor mein delete[] items; use karke memory free karte hain.
	double totalamount;
public:
	invoice(string d, string list[], double total)
	{
		invoice counter++;
		invoiceid = invoicecounter;

		date = d;
		totalamount = total;

		item = new string[MAXITEMS];
		for (int i = 0;i <MAXITEMS;i++)
		{
			items[i] = list[i];
		}
//Pehle total amount store ki jati hai. Phir new se items ke liye dynamic memory banai jati hai, aur for loop ki madad se constructor mein aane wale items us memory mein copy kar diye jate hain.
	}
	~invoice()
	{
		delete[] items;
	}
	static int getinvoicecounter()
	{
		return invoicecounter;
    }
	void display()
	{
		cout << "invoice id" << invoiceid << endl;
		cout << "date" << date << endl;

		cout << "items" << endl;
		for (int i = items[i] < MAXITEMS;i++)
		{
			cout << items[i] << endl;
		}
		cout << "total amount  " << totalamount << endl;
	}
};
int invoice::invoicecounter = 0;
int main()
{
	feerecord student1("25-cs-066", 50000, 10000, 500);
	student1.dsplay();

	student1 -= 10000;
	student1.display();//using operator

	feerecord student2(student1);
	student2.display();

	feerecord student3("25-cs-131", 600000, 20000, 1000);//copy assignment operator
	student3 = student1;
	student3.display();

	//invoice item------------
	string list12[MAXITEMS]
	{
		"semester fee",
		"hostel fee",
		"library fine"
	};
	invoice in1("20-june-2026", list1, 60500);
	invoice in2("21-june-2026", list1, 60500);

	in1.display();
	in2.display();

	cout << invoice::getinvoicecounter() << endl;

	return 0;

}
#include<iostream>
#include"src/person/person.h"
#include"src/course/course.h"
#include"src/hostel/hostel.h"
#include"src/finance/finance.h"
#include"src/library/library.h"
#include"src/utilities/utilities.h"
using namespace std;

int main()
{
    cout << " SCMS" << endl;
   

    //  Person module...
    utlis util;
    util.formattitle("PERSON MODULE");

    string studentCourses[3] = { "OOP", "DSA", "DBMS" };
    student s1("Haseeb", "11111-1111111-1", 20, "03001234567",
        "25-CS-066", 4, 3.8, studentCourses);
    s1.displayinfo();

    string facultyCourses[3] = { "OOP", "PF", "DLD" };
    faculty f1("Naveed", "12345-1234567-1", 50, "03009999999","F-1014", "Computer Science", "Professor", facultyCourses);
    f1.displayinfo();

    staff st1("Ali", "S-001", "22222-2222222-2", 35,"03005556677", "Security", 45000);
    st1.displayinfo();

    //  COURSE MODULE ...
    util.formattitle("COURSE MODULE");

    course c1("CS201", "OOP", 3, &f1, 2);
    course c2("CS201", "OOP", 3, &f1, 5);

    if (c1 == c2)
    {
        cout << "Courses are same" << endl;
    }

    try
    {
        c1.enrollstudent(&s1);

        string courses2[3] = { "OOP", "DSA", "DBMS" };
        student s2("Ahmed", "22222-2222222-2", 21, "03007654321","25-CS-067", 4, 3.5, courses2);
        c1.enrollstudent(&s2);

        student s3("Hassan", "33333-3333333-3", 20, "03003334444","25-CS-068", 4, 3.2, courses2);
        c1.enrollstudent(&s3); // This throws
    }
    catch (capacityexceededexception e)
    {
        e.message();
    }
    cout << c1;

    enrollment e1(&s1, &c1, "20-06-2026", 'A');
    e1.display();

    // hostel module... 
    util.formattitle("HOSTEL MODULE");

    hostelmanager manager("A Block");
    manager.allocateroom(&s1, 101);
    manager.generatereport();
    manager.vacateroom(&s1, 101);

    // finance module...
    util.formattitle("FINANCE MODULE");

    feerecord fee1("25-CS-066", 50000, 10000, 500);
    fee1.display();
    fee1 -= 10000;
    fee1.display();

    string list[3] = { "Semester Fee", "Hostel Fee", "Library Fine" };
    invoice inv1("20-06-2026", list, 60500);
    inv1.display();
    cout << "Total Invoices: " << invoice::getinvoicecounter() << endl;

     // LIBRARY MODULE 
    util.formattitle("LIBRARY MODULE");

    library lib;
    book b1("B101", "OOP Book", "Haseeb", 2025,"ISBN-001", "Programming", 5);
    journal j1("J101", "AI Journal", "Ahmed", 2024,"ISSN-111", 2, 5);

    lib.additem(&b1);
    lib.additem(&j1);
    lib.searchbytitle("OOP Book");
    lib.savetofile();
    lib.loadfromfile();
    lib.issueitem("25-CS-066", "B101");

    try
    {
        lib.returnitem(5);
    }
    catch (overdueexception e)
    {
        e.message();
    }
    util.formattitle("UTILITIES MODULE");

    reports report;
    report.campusreport();
    report.pdfreport();
    util.displaydate();

    double gpa[5] = { 3.2, 3.9, 2.8, 3.5, 3.0 };
    util.sortGPA(gpa, 5);

    string books[5] = { "OOP", "DSA", "DBMS", "AI", "Networking" };
    util.searchBook(books, 5, "DBMS");

    return 0;
}
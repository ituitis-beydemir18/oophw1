#include <iostream>
#include <string>
#include "Instructorlist.h"
using namespace std;

class real {
	int array_index = 0;
	int choice;
	InstructorList list;
	
public:
	real(){
		Instructor a("Yrd. Doc. Dr.", "Gulsen", "CebirogluEryigit", "2853503", 3303, "gulsenc", "gulsenc@itu.edu.tr", "BLG252,BLG888,BLG999");
		Instructor b("DoC. Dr.", "Feza", "Buzluca", "2853502", 5310, "buzluca", "buzluca@itu.edu.tr", "BLG231,BLG666,BLG777");
		Instructor c("Ogr. Gor.", "H. Turgut", "Uyar", "2853632", 2422, "uyar", "uyar@itu.edu.tr", "BIL103,BLG112");
		list.addFirstThree(a, b, c);
		array_index += 3;
	}
	
	void printChoices(){
		
		cout << endl << "1. Add a new instructor\n2. Delete an instructor\n3. List all instructors\n4. Search by Name";
		cout << endl << "5. Search by Surname\n6. Search by Telephone Number\n7. Search by Room Number\n8. Exit";
		cout << endl << "Enter the number for operation you want to perform: " << endl;
		cin >> choice;
	}
	void make_operation(){
		char a;
		bool end = false;
		printChoices();
		while (1) {
			switch (choice)
			{
				case 1: list.addIns(array_index); array_index++; break;
				case 2: list.delIns(array_index); array_index--; break;
				case 3: list.printIns(array_index);				 break;
				case 4: list.search_fname(array_index);			 break;
				case 5: list.search_lname(array_index);			 break;
				case 6: list.search_telno(array_index);			 break;
				case 7: list.search_roomno(array_index);		 break;
				case 8: end = true; break;
				default:printChoices();
			} //switch
			if (end == true)
				break;
			cout << "Do you want to perform another operation?(Y/N)" << endl;
			cin >> a;
			if (a == 'Y' || a=='y')
				printChoices();
			else if (a == 'N' || a=='n')
				choice = 8;
		} 
	}//make_op
};

int main(){
	real r;
	r.make_operation();
	

	return 0;
}


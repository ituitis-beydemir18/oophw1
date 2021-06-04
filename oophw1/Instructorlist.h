#include "Instructor.h"
#include <string.>


class InstructorList{
	int size;
	char s1[10], s2[15], s3[25], s4[20], s5[15], s6[30];
	int a1;
	string b1;
	bool access=true;

public:
	int selector;
	Instructor *ins;
	InstructorList(){ //default array size
		ins = new Instructor[5];
		size = 5;
	}
	InstructorList(int a){ //given array size
		ins = new Instructor[a];
		size = a;
	}
void addFirstThree(Instructor &a, Instructor &b, Instructor &c){ //İLK 3 INSTRUCTORU EKLİYORUM
	ins[0] = a;
	ins[1] = b;
	ins[2] = c;
}
	void addIns(int a){
		cout << endl;
		cout << "Enter the Title of the new instructor. If you don't have this information press Enter" << endl;
		cin >> s1;
		cout << "Enter the name of the new instructor. If you don't have this information press Enter" << endl;
		cin >> s2;
		cout << "Enter the last name of the new instructor. If you don't have this information press Enter" << endl;
		cin >> s3;
		cout << "Enter the telephone number of the new instructor. If you don't have this information press Enter" << endl;
		cin >> s4;
		cout << "Enter the room number of the new instructor. If you don't have this information press Enter" << endl;
		cin >> a1;
		cout << "Enter the username of the new instructor. If you don't have this information press Enter" << endl;
		cin >> s5;
		cout << "Enter the email of the new instructor. If you don't have this information press Enter" << endl;
		cin >> s6;
		cout << "Enter the courses of the new instructor. If you don't have this information press Enter" << endl;
		cin >> b1;

		
		//This method should ensure that there is no duplicated instructors in the InstructorList.
		for (int i = 0; i < a; i++){
			if (strcmp(s2, ins[i].get_fName()) == 0 && strcmp(s3, ins[i].get_lName()) == 0){
				cout << endl << "This instructor has already been added. You can't add twice." << endl;
				access = false;
				break;
			}
		}//for

		if (access == true){
				ins[a].set_Title(s1);
				ins[a].set_fName(s2);
				ins[a].set_lName(s3);
				ins[a].set_telnumber(s4);
				ins[a].set_roomNumber(a1);
				ins[a].set_userName(s5);
				ins[a].set_email(s6);
				ins[a].set_courses(b1);
			cout << "New instructor is added!" << endl;
			ins[0];
			ins[1];
			ins[2];
			ins[3];
			ins[4];
	}//access
		access = true;
		//If the array is already full, then this method should be able to extend the size of the array to store the information about this new instructor.
		if (a+1 == size){ //Array dolu ise temp array oluşturup (2 katı büyüklüğünde) bilgileri buraya atıyorum sonra eski arrayimi delete ve add yaparak 2 katı büyüklüğünde tekrar
			size *= 2;			 //oluşturup temp'dekileri yeni arrayime alıyorum.
			Instructor *temp = new Instructor[size];
			for (int i = 0; i < size / 2; i++)
				temp[i] = ins[i];
			delete[] ins;
			ins = new Instructor[size];
			for (int i = 0; i < size / 2; i++)
				ins[i] = temp[i];
			delete[] temp;
		}
		
	}//add

	void delIns(int b){
		cout << "Enter the first name of the record to be deleted:" << endl;
		cin >> s1;
		cout << "Enter the last name of the record to be deleted:" << endl;
		cin >> s2;

		for (int i = 0; i < b; i++){
			if (strcmp(s1, ins[i].get_fName()) == 0 && strcmp(s2, ins[i].get_lName()) == 0){
				for (int j = i; j < b-1; j++)
					ins[j] = ins[j + 1];
				cout << "Record has been deleted!" << endl;
			}//if
		}//for
	}//delete

	void printIns(int c){
		cout << "----------List of all Instructors in Computer Engineering of ITU----------" << endl;
		for (int i = 0; i < c; i++){
			ins[i].printInstructor();
			cout << "--------------------------------------" << endl;
		}
	}

	void search_fname(int d){
		cout << "Enter the first name:" << endl;
		cin >> s1;
		for (int i = 0; i < d; i++){
			if (strcmp(s1, ins[i].get_fName()) == 0){
				ins[i].printInstructor();
				break;
			}//if
		}//for
	}//search

	void search_lname(int e){
		cout << "Enter the last name:" << endl;
		cin >> s1;
		for (int i = 0; i < e; i++){
			if (strcmp(s1, ins[i].get_lName()) == 0){
				ins[i].printInstructor();
				break;
			}//if
		}//for
	}//search

	void search_telno(int f){
		cout << "Enter the telephone number:" << endl;
		cin >> s1;
		for (int i = 0; i < f; i++){
			if (strcmp(s1, ins[i].get_telnumber()) == 0){
				ins[i].printInstructor();
				break;
			}//if
		}//for
	}//search

	void search_roomno(int g){
		cout << "Enter the room number:" << endl;
		cin >> a1;
		for (int i = 0; i < g; i++){
			if (a1==ins[i].get_roomNumber()){
				ins[i].printInstructor();
				break;
			}//if
		}//for
	}//search
};
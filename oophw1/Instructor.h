#include <iostream>
#include <string>
using namespace std;

class Instructor{
	char* Title;
	char* fName;
	char* lName;
	char* telnumber;
	int roomNumber;
	char* userName;
	char* email;
	string courses[5];

public:
	int array_index = 0;
//constructors
	Instructor(){
		Title = "";
		fName = "";
		lName = "";
		telnumber = "";
		roomNumber = 0;
		userName = "";
		email = "";
	};
	Instructor(char* a, char* b, char* c, char* d, int e, char* f, char* g, string h)
	{
		Title = a;
		fName = b;
		lName = c;
		telnumber = d;
		roomNumber = e;
		userName = f;
		email = g;
		courses[0] = h; array_index++;

	};
	Instructor(char *a, char *b, int c, char *t="", char *tele="", char *user="", char* em="") // Ad-Soyad-Oda numarası 
	{
		Title = t;
		fName = a;
		lName = b;
		telnumber = tele;
		roomNumber = c;
		userName = user;
		email = em;
	}; 
	Instructor(char *a, char *b, char *c, string d="", char *t="", char *tele="", int room = 0, char *user="") //Ad-Soyad-email-Verdiği Dersler
	{
		Title = t;
		fName = a;
		lName = b;
		telnumber = tele;
		roomNumber = room;
		userName = user;
		email = c;
		courses[0] = d; array_index++;
	}; 
//getter methods
	char *get_Title(){
		return Title;
	}
	char *get_fName(){
		return fName;
	}
	char *get_lName(){
		return lName;
	}
	char *get_telnumber(){
		return telnumber;
	}
	int get_roomNumber(){
		return roomNumber;
	}
	char *get_userName(){
		return userName;
	}
	char *get_email(){
		return email;
	}
	string get_courses(){
		string all="[";
		for (int i = 0; i < array_index; i++)
			all.append(courses[i] + ", ");
		all.erase(all.end() - 2, all.end()); //sondaki virgülü ve boşluğu siler
		all.append("]");
		return all;
	}
//setter methods
	void set_Title(char *a){
		Title = new char[10];
		for (int i = 0; i<strlen(a); i++)
			Title[i] = a[i];
		Title[strlen(a)] = '\0';
	}
	void set_fName(char *a){
		fName = new char[15];
		for (int i = 0; i<strlen(a); i++)
			fName[i] = a[i];
		fName[strlen(a)] = '\0';
	}
	void set_lName(char *a){
		lName = new char[25];
		for (int i = 0; i<strlen(a); i++)
			lName[i] = a[i];
		lName[strlen(a)] = '\0';
	}
	void set_telnumber(char *a){
		telnumber = new char[20];
		for (int i = 0; i<strlen(a); i++)
			telnumber[i] = a[i];
		telnumber[strlen(a)] = '\0';
	}
	void set_roomNumber(int a){
		roomNumber = a;
	}
	void set_userName(char *a){
		userName = new char[15];
		for (int i = 0; i<strlen(a); i++)
			userName[i] = a[i];
		userName[strlen(a)] = '\0';
	}
	void set_email(char *a){
		email = new char[30];
		for (int i = 0; i<strlen(a); i++)
			email[i] = a[i];
		email[strlen(a)] = '\0';
	}
	void set_courses(string b){
		courses[array_index] = b;
		array_index++;
	}
//------	
	void printInstructor()
	{
		cout << endl;
		cout << "Title: " << get_Title() << endl;
		cout << "First Name: " << get_fName() << endl;
		cout << "Surname: " << get_lName() << endl;
		cout << "Telephone Number: " << get_telnumber() << endl;
		cout << "Room Number: " << get_roomNumber() << endl;
		cout << "User Name: " << get_userName() << endl;
		cout << "Email: " << get_email() << endl;
		cout << "Courses: " << get_courses() << endl;
	};
	Instructor operator=(Instructor &obj){
		Title = obj.get_Title();
		fName = obj.get_fName();
		lName = obj.get_lName();
		telnumber = obj.get_telnumber();
		roomNumber = obj.get_roomNumber();
		userName = obj.get_userName();
		email = obj.get_email();
		courses[0] = obj.get_courses();
		array_index++;
		return *this;
	}
};
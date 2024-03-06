#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

	struct Students {
	string Firstname;
	string Lastname;
	int year;
	string section;
	string course;
};
	int Mainmenu();
	Students InputStudent();
	
	void AddStudent(Students students[], int &student);
	void ShowStudent(const Students students[], int student);
	void DeleteStudent(Students students[], int &student);
	
	int main() {
	Students students[100];
	int student = 0;
	int choice;

	do {
	
	choice = Mainmenu();
	
	switch (choice) {
		
	case 1:
		AddStudent(students, student);
	break;
	case 2:
		
		ShowStudent(students, student);
	break;
	default:
	cout << "Invalid choice!";
}
} while (true);
return 0;
}
	int Mainmenu() {
	int choice;
	cout<<"------------------------------------------\n"
		<<"          STUDENT INFORMATION\n"
		"------------------------------------------\n\n";         
	cout << "(1) Add Student\n"
		<< "(2) Show Student Info\n"
		<< "Enter choice: ";
	cin >> choice;
		system("cls");
	return choice;
}
	Students InputStudent() {
	Students tempStudents;
	cout << "Enter Firstname: ";
	cin >> tempStudents.Firstname;
	cout << "Enter Lastname: ";
	cin >> tempStudents.Lastname;
	cout << "Input year: ";
	cin >> tempStudents.year;
	cout << "Input section: ";
	cin >> tempStudents.section;
	cout << "Input course: ";
	cin >> tempStudents.course;
	return tempStudents;
}
	void AddStudent(Students students[], int &student) {
	if (student < 100) {
	students[student] = InputStudent();
	student++;
	cout << "Student added successfully!" << endl;
}
		else {
	cout << "No more space for new students!" << endl;
}
	system("pause");
	system("cls");
}
	void ShowStudent(const Students STUDENTS[], int student) {
    int count;
    int pageNum = 0;
    int pageSize = 5;
    int totalPages = (student + pageSize - 1) / pageSize; 

    if (student > 0) {
        string input;
        do {
            system("cls");
            cout << "Student List (Page " << pageNum + 1 << "/" << totalPages << "):\n\n";
            cout << setw(15) << left << "Firstname" << setw(15) << left << "Lastname" << setw(10) << left << "Year" << setw(10) << left << "Section" << setw(15) << left << "Course" << endl;
            cout << "---------------------------------------------------------------------\n";
            for (count = pageNum * pageSize; count < (pageNum + 1) * pageSize && count < student; ++count) {
                cout << setw(15) << left << STUDENTS[count].Firstname << setw(15) << left << STUDENTS[count].Lastname << setw(10) << left << STUDENTS[count].year << setw(10) << left << STUDENTS[count].section << setw(15) << left << STUDENTS[count].course << endl;
            }
            cout << "\n";
            if (pageNum > 0)
                cout << "[P]revious ";
            if (pageNum < totalPages - 1)
                cout << "[N]ext ";
                cout<< "[E]xit ";
           
            getline(cin, input);

            if (input == "E" || input == "e")
                break;
            else if ((input == "P" || input == "p") && pageNum > 0)
                pageNum--; 
            else if ((input == "N" || input == "n") && pageNum < totalPages - 1)
                pageNum++; 
        } while (true);
        system("cls");
    }
    else {
        cout << "No students to show!" << endl;
        system("pause");
        system("cls");
    }
}

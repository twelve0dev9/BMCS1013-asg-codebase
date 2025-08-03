#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
	return 0;
}
string username = " ";
struct experts
{
	string name;
	string services_provide = " ";
		
};

void payment(){
	//pending
}
void displayCalendar(){
	//pending
}
void viewbookedSchedule(){
	//pending
}
void customerFunctionalities()
{
	int menu_choice = 0, services_choice = 0, expert = 0, bookingTime = 0;	
	string bookingStatus[2] = {"Successful", "Failed"};
	string services[4] = {"Haircuts & Trims", "Bread grooming", "Facial skin care", "Massage therapy"};

	cout << "Men's LOOKMAXXIN Spa" << endl;;
	cout << "DESC\n" << 
		"Operating hours : \nMonday--Saturday  | 12PM - 1AM\n"
		<< "Contact email : lookmaxxin2day@gmail.com\nContact phone : 03-3788 46567";
	cout << "Welcome " << username << "!\n";
	cout << "1. View our serivces\n2. Book an appointment\n3. View booked schedule\n4. Exit";
	cin >> menu_choice;
	switch(menu_choice)
	{
	case 1:
		cout << "Our available services : " << services;
		break;
	case 2:
		cout << "Pick one serivces : " << services;
		// a for loop to iterate thru the service array in numbered list
		//use structure, array, pointers to filter out expert w\ relevant services only
		if (services_choice == 1) {
			cout << "Choose one of our experts" << expert;
			cin >> expert;
		}
		else if (services_choice == 2) {
			cout <<
		}
		break;
	case 3:
		viewbookedSchedule();
		break;
	case 4:

	}
		
}

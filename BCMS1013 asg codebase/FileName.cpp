#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {

	return 0;
}

struct users {
	string userID;
	string username;
	int age;
	char gender;
	string user_email;
	string user_password;
	string user_Type[3] = {"admin", "expert", "customer"};
	string Specialization[4];
	int working_days[5];
};
users expert1 = {"001", "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102"};
struct appointments {
	string expert_assigned; // dis is gon be the username of experts
	string services;
	int time_slot;

};
void login(){
}
//void admin_login() {
//	string username;
//	string password;
//	string admin_user = "ansel";
//	string admin_pass = "iu123";
//	cout << "             ADMIN LOGIN             " << endl;
//	cout << "------------------------------------" << endl;
//	cout << "Enter username : ";
//	cin >> username;
//	cout << "Enter password : ";
//	cin >> password;
//	if (username != admin_user || password != admin_pass) {
//		cout << "Invalid username or password." << endl;
//		cout << "Returning to main menu..." << endl;
//		main_menu();
//	}
//	else {
//		cout << endl;
//		cout << "Admin Login Successful" << endl;
//		cout << "Welcome, " << username << ".";
//		cout << endl;
//		admin_menu();
//	}
//	//return;
//}
//void main_menu() {
//	int login_type;
//	cout << "     MAIN MENU      " << endl;
//	cout << "--------------------" << endl;
//	cout << "Select Login: " << endl;
//	cout << "1. Customer Login" << endl;
//	cout << "2. Administrator Login" << endl;
//	cout << "3. Expert Login" << endl;
//	cout << "4. Exit Program" << endl;
//	cout << "-------------------" << endl;
//	cout << ">";
//	cin >> login_type;
//	switch (login_type) {
//	case 1:
//		customerFunctionalities();
//		break;
//	case 2:
//		admin_login();
//		break;
//	case 3:
//		expert_login();
//		break;
//	case 4:
//		cout << "=== PROGRAM END ===";
//		break;
//	default:
//		cout << "Invalid Input, please enter a value from 1-4" << endl;
//		main_menu();
//		break;
//	}
//	return;
//}
void alphanumInputs_validation(string x) {
	// validates if the input provided is alphenumeric or not similar to that of Python
	char x[];
	for 
}
void payment(){
	//payment module
	//display & input prompts, fake(:verb) the credentials
	//returns a true bool
}
void displayCalendar(){
	//display the calendar & highlights days that our experts have slots for customer to view
	const int row = 5, col = 8;
	int time_slotsDay[5][8] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0, 0}
	};
	string hourly_timeSlots[6] = { //we keep it fixed for now, maybe in the future we'll make the hourly time slots more varrying idk
		"1. 12:00--15:00", 
		"2. 14:00--17:00", 
		"3. 16:00--19:00", 
		"4. 18:00--21:00", 
		"5. 21:00--00:00", 
		"6. 22:00--01:00"
	};
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (time_slotsDay[i][j] == 0) continue;
			if (time_slotsDay[i][j] == 12) // condition for days whr there are available time 
				cout << "\033[1;4m" << time_slotsDay[i][j] << "\033[0m ";
			else
				cout << time_slotsDay[i][j] << " ";
		}
		cout << endl;
	}
}
void viewbookedSchedule(){
}
void customerFunctionalities()
{
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0;
	string bookingStatus[2] = {"Successful", "Failed"};
	string services[4] = {"Haircuts & Trims", "Bread grooming", "Facial skin care", "Massage therapy"};

	cout << setw(8) << "Men's LOOKMAXXIN Spa" 
		<< "-------------------------------------------------"
		<< endl;
	cout << "\033[1mWhere Style Meets Self-Care.\033[0m\n"
		<< "Welcome to Men’s LOOKMAXXIN Spa, as our name suggests, We WILL make you LOOKMAXXING.\n"
		<< "A premium grooming spa designed exclusively for men who value sharp style, total relaxation, and modern self-care.\n"
		<< "We offer a full range of services—from precision haircuts and classic straight-razor shaves to revitalizing facials, deep tissue massages, and expert beard grooming.\n"
		<< "Our space blends the sophistication of a gentleman’s club with the tranquility of a day spa, providing a relaxing environment where you can unwind, refresh, and leave feeling your absolute best.\n"
		<< "Whether you're preparing for a big event, need routine maintenance, or just deserve a break—our skilled barbers, aestheticians, and therapists are here to elevate your grooming experience.\n"
		<< "\n\nOperating hours : \nMonday--Saturday  | 12PM - 1AM"
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
		// use structure, array, pointers to filter out expert w\ relevant services only
		if (services_choice == 1) {
			cout << "Choose one of our experts" << ;
			cin >> expert;
		}
		else if (services_choice == 2) {
			cout ;
		}
		break;
	case 3:
		viewbookedSchedule();
		break;
	case 4:
		cout << "Exitting ...";
	}
}
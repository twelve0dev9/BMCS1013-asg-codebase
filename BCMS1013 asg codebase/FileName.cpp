#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {

	return 0;
}

enum UserType { admin, expert, customer };
enum Specialization { Haircuts_Trims, Beard_Grooming, FacialSkinCare, MassageTherapy };
//enum HourlyTimeSlots { 1, 2, 3, 4, 5, 6};

struct users {
	int userID = 0;
	string username = " ";
	int age = 0;
	char gender = ' ';
	string user_email = " ";
	string user_password = " ";
	UserType user_Type;
	Specialization specialization[2]; // 2 because dis it makes more sense, ain't no way u gon have experts serving > 2 services duhh
};
users niama[] = {
	{1, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {MassageTherapy, Haircuts_Trims}}, 
	{2, "SashimmiMI", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {Beard_Grooming, FacialSkinCare}}
};
//the users records might put under sum kind of function 
//no point in importing the user records from the file globally when not in use
struct bookings { //for hourly time slots variable
	struct users expert_info;
	bool booking_status = 0; // by default it shudn't be booked unless changed

};

void login(){
	//read all from "User records.txt" file
		//if possible find ways to read from user records w\ username entered by user only, instead of reading all of the records

	//compare the credentials with the read records
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
void appointment(){
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
	int hourlyTimeSlots_booked = 0;
	cout << setw(8) << "December" << endl 
		<< "-------------------------------------";
	for (int i = 0; i < row; ++i) { // calendar display
		for (int j = 0; j < col; ++j) {
			if (time_slotsDay[i][j] == 0) continue;
			if (time_slotsDay[i][j] == 12) // condition for days whr there are available time 
				cout << "\033[1;4m" << time_slotsDay[i][j] << "\033[0m ";
			else
				cout << time_slotsDay[i][j] << " ";
		}
		cout << endl;
	}
	// processing for the constraints of booking appointments
	switch (hourlyTimeSlots_booked) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	}
}
void viewbookedSchedule(){
}
void customerFunctionalities()
{
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0;
	string services[4] = {"1. Haircuts & Trims", "2. Bread grooming", "3. Facial skin care", "4. Massage therapy"};

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
	
	cin >> choice_menu;
	
	switch(choice_menu)
	{
	case 1:
		cout << "Our available services : \n" << "--------------------------------";
		for (int i = 0; i < 4; ++i)
			cout << services[i] << endl;
		break;
	case 2:
		cout << "Pick one serivces : \n" << "------------------------------";
		for (int i = 0; i < 4; ++i) // a for loop to iterate thru the service array in numbered list
			cout << services[i] << endl;
		cin >> choice_service;
		// use structure, array, pointers to filter out expert w\ relevant services only
		switch(choice_service)
		{
		case 1:
			cout << "Choose experts you'd like to book an appointment with (>O<) : " << endl;
			if (niama[10].specialization == 0) {
				
			}
			cout << niama[1].specialization; //access the member value of specilization 
			cin >> choice_expert;
			break;
		case 2:
			cout ;
			break;
		}
		break;
	case 3:
		viewbookedSchedule();
		break;
	case 4:
		cout << "Exitting ...";
	}
}
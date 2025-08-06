#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {

	return 0;
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
enum UserType { admin, expert, customer };
typedef int hourly_timeSlots;
	hourly_timeSlots slot1 = 1;
	hourly_timeSlots slot2 = 2;
	hourly_timeSlots slot3 = 3;
	hourly_timeSlots slot4 = 4;
	hourly_timeSlots slot5 = 5;
	hourly_timeSlots slot6 = 6;
hourly_timeSlots time_Slots[6] = {slot1, slot2, slot3, slot4, slot5, slot6}; // might endup having another struct for dis TO implement varrying time slots (not fixed at 3 hours)

struct services {
	int serviceID = 0;
	string service_name = " ";
	float serviceTime = 0.00; //unit is Hours
};
struct users {//the users records might put under sum kind of function 
//no point in importing the user records from the file globally when not in use
	int userID = 0;
	string username = " ";
	int age = 0;
	char gender = ' ';
	string user_email = " ";
	string user_password = " ";
	UserType user_Type;
	services * specialization[2] ;
}; //we might need to divide the users struct into more nested struct, considering need to do sum manipulation w\ the emails,passwords, names, etc. If member access & pointers makes it difficult to access for modification
struct bookings {
	users * book_byCustomer;
	users * expert_booked;
	bool booking_status = 0; // by default it shudn't be booked unless changed
	int booked_day; //have sum control structures for telling customer user to input valid date of booking this
	hourly_timeSlots * booked_timeSlot;
	services * service_booked;
};




string hourly_timeSlotss[6] = { //we keep it fixed for now, maybe in the future we'll make the hourly time slots more varrying idk
	"1. 12:00--15:00",
	"2. 14:00--17:00",
	"3. 16:00--19:00",
	"4. 18:00--21:00",
	"5. 21:00--00:00",
	"6. 22:00--01:00"
};
void login(){
	//read all from "User records.txt" file`
		//if possible find ways to read from user records w\ username entered by user only, instead of reading all of the records

	//compare the credentials with the read records
}
void alphanumInputs_validation(string x) {
	// validates if the input provided is alphenumeric or not similar to that of Python

	//this part use C-string functions	
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
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1;
	const int arrySize_services = 4;
	services services_available[arrySize_services] = {
		{1, "Haircuts & Trims", 3},
		{2, "Bread Grooming", 3},
		{3, "Facial Skin Care", 3},
		{4, "Massage Therapy", 3}
	};
	users experts[] = {
		{1, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}}
	};
	users customer_users[] = {
		{4, "John", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", customer},
		{5, "Wayne", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
	};
	bookings booked_appointments[] = {
		{&customer_users[0], &experts[0], true, 28, &time_Slots[0], &services_available[0]},
		{&customer_users[1], &experts[0], true, 23, &time_Slots[3], &services_available[3]}
	};

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
	cout << "Welcome " << experts->username << "!\n";
	cout << "1. View our serivces\n2. Book an appointment\n3. View booked schedule\n4. Exit";
	
	cin >> choice_menu;
	
	switch (choice_menu)
	{
	case 1:
		cout << "Our available services : \n" << "--------------------------------";
		for (int i = 0; i < 4; ++i) {
			cout << numberedlist << ". " << services_available[i].service_name << endl;
			++numberedlist;
		}
		break;
	case 2:
		cout << "Pick one serivces : \n" << "------------------------------";
		for (int i = 0; i < 4; ++i) {
			cout << numberedlist << ". " << services_available[i].service_name << endl;
			++numberedlist;
		}
		cin >> choice_service;
		// use structure, array, pointers to filter out expert w\ relevant services only
		switch(choice_service) {
		case 1:
			cout << "Choose experts you'd like to book an appointment with (>O<) : " << endl;
			for (int i = 0; i < arrySize_services;++i) {
				if (experts[i].specialization[0]->serviceID == choice_service) 
{
					for (int j = 0; j < i; ++j)
					{
						cout << numberedlist << ". " << experts[i].username << endl;
						++numberedlist;
					}
				} else if (experts[i].specialization[1]->serviceID == choice_service) {

				}
			}
			if (experts[1].specialization[0]->serviceID == choice_service /*the services ID starts from 1, so it matches the choice_service*/) {
				
			}
			cout << experts[1].specialization; //access the member value of specilization 
			cin >> choice_expert;
			break;
		case 2:
			cout ;
			break;
		default : 
			cout << "Enter the valid choice please !! " //use for loop to iterate for the valid option
		}
		break;
	case 3:
		viewbookedSchedule();
		break;
	case 4:
		cout << "Exitting ...";
	}
}
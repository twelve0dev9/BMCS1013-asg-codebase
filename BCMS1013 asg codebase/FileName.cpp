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
	services* specialization[2];
}; //we might need to divide the users struct into more nested struct, considering need to do sum manipulation w\ the emails,passwords, names, etc. If member access & pointers makes it difficult to access for modification
struct timeSlots {
	int timeslotID; // dis is gon correspond to the number
	double hours_start; //24 hours time format
	double hours_end; //24 hours time format
};
struct bookings {
	timeSlots* timeslot;
	bool booking_status = 0;
	int booking_date; //have sum control structures for telling customer user to input valid date of booking this
	users* book_byCustomer;
	users* expert_booked;
	services* service_booked;
};


void login() {
	//read all from "User records.txt" file`
		//if possible find ways to read from user records w\ username entered by user only, instead of reading all of the records

	//compare the credentials with the read records
}
void alphanumInputs_validation(string x) {
	// validates if the input provided is alphenumeric or not similar to that of Python

	//this part use C-string functions	
}
void payment() {
	//payment module
	//display & input prompts, fake(:verb) the credentials
	//returns a true bool
}
void viewAvailable_days(int choice_expert, services services_available[],
	users experts[], users customers[], bookings appointments_schedule[], int arrySize_bookings) {
	//display the calendar & highlights days that our experts have slots for customer to view
	const int row = 5, col = 8;
	int i = 0, j = 0, date_available;
	int time_slotsDay[5][8] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0, 0}
	};
	cout << setw(8) << "December" << endl
		<< "-------------------------------------";
	for (int k = 0; k < sizeof(appointments_schedule); ++k)
	{
		//goes over the bookings list iteratively
		if (appointments_schedule[k].booking_date == time_slotsDay[i][j] && appointments_schedule[k].booking_status == true)
			date_available = appointments_schedule[k].booking_date;
	}
	for (i = 0; i < row; ++i)
	{
		// calendar display
		for (j = 0; j < col; ++j)
		{
			if (time_slotsDay[i][j] == 0) continue;
			if (time_slotsDay[i][j] == date_available) // condition for days whr there are available time 
				cout << "\033[1;4m" << time_slotsDay[i][j] << "\033[0m ";
			else
				cout << time_slotsDay[i][j] << " ";
		}
		cout << endl;
	}
}
void bookAppointment() {
	//processing for the constraints of booking appointments
	int hourlyTimeSlots_booked = 0;
	/*switch (hourlyTimeSlots_booked) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	}*/
}
void viewbookedSchedule() {
}
void customerFunctionalities()
{
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1;
	int* ptr_numberliste = &numberedlist;
	const int arrySize_experts = 10, arrySize_bookings = 10;

	services services_available[4] = {
		{1, "Haircuts & Trims", 3},
		{2, "Bread Grooming", 3},
		{3, "Facial Skin Care", 3},
		{4, "Massage Therapy", 3}
	};
	users experts[arrySize_experts] = {
		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}},
		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}},
		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}},
		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}}
	};
	users customer_users[] = {
		{4, "Blaze", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", customer},
		{5, "Wayne", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
	};
	timeSlots hourly_timeSlots[6] = {
		{1, 12.00, 15.00},
		{2, 14.00, 17.00},
		{3, 16.00, 19.00},
		{4, 18.00, 21.00},
		{5, 21.00, 0.00},
		{6, 22.00, 1.00}
	};
	bookings appointments_schedule[arrySize_bookings] = {
		{&hourly_timeSlots[0], true, 18, &customer_users[0], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 29, &customer_users[1], &experts[2], &services_available[3]}
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
		cout << "Pick one serivces : \n" << "------------------------------\n";
		for (int i = 0; i < 4; ++i) {
			cout << numberedlist << ". " << services_available[i].service_name << endl;
			++numberedlist;
		}
		*ptr_numberliste = 1;
		cout << endl;
		cin >> choice_service;
		// use structure, array, pointers to filter out expert w\ relevant services only
		cout << "\nOur experts that provides " << services_available[choice_service - 1].service_name << ": \n";
		for (int i = 0; i <= 5; ++i) {
			//cout << i << endl;
			users& expert = experts[i];
			services* spec0 = expert.specialization[0];
			services* spec1 = expert.specialization[1];
			if ((spec0 && spec0->serviceID == choice_service) || (spec1 && spec1->serviceID == choice_service)) {//the services ID starts from 1, so it matches the choice_service
				cout << numberedlist << ". " << experts[i].username << endl;
				++numberedlist;
			}
		}
		cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
		cin >> choice_expert;
		viewAvailable_days(choice_expert, services_available, experts, customer_users, appointments_schedule, arrySize_bookings);
	case 3:
		viewbookedSchedule();
		break;
	case 4:
		cout << "Exitting ...";
	}
}
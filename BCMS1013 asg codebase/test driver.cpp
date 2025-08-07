#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

enum UserType { admin, expert, customer };
typedef int hourly_timeSlots;
hourly_timeSlots slot1 = 1;
hourly_timeSlots slot2 = 2;
hourly_timeSlots slot3 = 3;
hourly_timeSlots slot4 = 4;
hourly_timeSlots slot5 = 5;
hourly_timeSlots slot6 = 6;
hourly_timeSlots time_Slots[6] = { slot1, slot2, slot3, slot4, slot5, slot6 }; // might endup having another struct for dis TO implement varrying time slots (not fixed at 3 hours)

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
struct bookings {
	timeSlots timeslot;
	users* book_byCustomer;
	users* expert_booked;
	services* service_booked;
};
struct timeSlots {
	int timeslotID; // dis is gon correspond to the number
	bool booking_status = 0;
	int booked_day; //have sum control structures for telling customer user to input valid date of booking this
	double hours_start; //24 hours time format
	double hours_end; //24 hours time format
};
void appointment(int choice_expert, services services_available[], 
	users experts[], users customers[], bookings booked_appointments[], int arrySize_bookings) {
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
	for (int i = 0; i < arrySize_bookings; ++i) {
		//goes over the bookings list iteratively
		if (bookings[i].booking_status == true &&) {

		}
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
int main() {
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1;
	int* ptr_numberliste = &numberedlist;
	const int arrySize_experts = 10, arrySize_bookings = 10;
	string hourly_timeSlotss[6] = { //we keep it fixed for now, maybe in the future we'll make the hourly time slots more varrying idk
		"1. 12:00--15:00",
		"2. 14:00--17:00",
		"3. 16:00--19:00",
		"4. 18:00--21:00",
		"5. 21:00--00:00",
		"6. 22:00--01:00"
	};
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
	{4, "John", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", customer},
	{5, "Wayne", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
	};
	/*bookings booked_appointments[] = {
		{&customer_users[0], &experts[0], true, 28, &time_Slots[0], &services_available[0]},
		{&customer_users[1], &experts[0], true, 23, &time_Slots[3], &services_available[3]}
	};*/
	bookings appointments_schedule[] = {
		{1, true, 18, 16.00, 19.00, &customer_users[0], &experts[0], &services_available[0]},
		{1, true, 18, 16.00, 19.00, &customer_users[0], &experts[0], &services_available[3]},
	};
	cout << appointments_schedule[1].timeslot.timeslotID
		<< appointments_schedule[1].timeslot.booking_status
		<< appointments_schedule[1].timeslot.booked_day
		<< appointments_schedule[1].timeslot.hours_start
		<< appointments_schedule[1].timeslot.hours_end << endl
		<< appointments_schedule[1].book_byCustomer->username
		<< appointments_schedule[1].expert_booked->username
		<< appointments_schedule[1].expert_booked->specialization[0]
		<< appointments_schedule[1].expert_booked->specialization[1];
	//cout << "Pick one serivces : \n" << "------------------------------\n";
	//for (int i = 0; i < 4; ++i) {
	//	cout << numberedlist << ". " << services_available[i].service_name << endl;
	//	++numberedlist;
	//}
	//*ptr_numberliste = 1;
	//cout << endl;
	//cin >> choice_service;
	//// use structure, array, pointers to filter out expert w\ relevant services only
	//cout << "\nOur experts that provides " << services_available[choice_service - 1].service_name << ": \n";
	//for (int i = 0; i <= 5; ++i) {
	//	//cout << i << endl;
	//	users& expert = experts[i];
	//	services* spec0 = expert.specialization[0];
	//	services* spec1 = expert.specialization[1];
	//	if ((spec0 && spec0->serviceID == choice_service) || (spec1 && spec1->serviceID == choice_service)) {//the services ID starts from 1, so it matches the choice_service
	//		cout << numberedlist << ". " << experts[i].username << endl;
	//		++numberedlist;
	//	}
	//}
	//cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
	//cin >> choice_expert;
	//appointment(choice_expert, services_available, experts, customer_users, booked_appointments, arrySize_bookings);
	return 0;
}
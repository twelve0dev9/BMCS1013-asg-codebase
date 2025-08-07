#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

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
void viewAvailable_days(int choice_expert, services services_available[], 
	users experts[], users customers[], bookings appointments_schedule[]) {
	//display the calendar & highlights days that our experts have slots for customer to view
	const int row = 5, col = 8, totalDays = 31, totalSlotsperDay = 6;
	int i = 0, j = 0, bookingsPerDay[32] = {0};
	int time_slotsDay[5][8] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0, 0}
	};
	for (int k = 0; k < sizeof(appointments_schedule); ++k)
	{
		//goes over the bookings list iteratively
		if (appointments_schedule[k].expert_booked->userID == experts[choice_expert].userID && appointments_schedule[k].booking_status == true)
		{
			int date = appointments_schedule[k].booking_date;
			if (date >= 1 && date <= 31)
				++bookingsPerDay[date];
		}
	}
	cout << setw(23) << "December" << endl
		<< "-------------------------------------\n";
	for (i = 0; i < row; ++i) 
	{ 
		// calendar display
		for (j = 0; j < col; ++j) 
		{
			int date = time_slotsDay[i][j];
			if (date == 0) continue;
			if (bookingsPerDay[date] < totalSlotsperDay) // condition for days whr there are available time 
				cout << "\033[48;2;255;165;0m\033[38;2;0;0;0m" << setw(4) << date << "\033[0m ";
			else
				cout << setw(4) << date << " ";
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
int main() {
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1;
	int* ptr_numberliste = &numberedlist;
	//const int arrySize_experts = 10, arrySize_bookings = 10;

	services services_available[4] = {
		{1, "Haircuts & Trims", 3},
		{2, "Bread Grooming", 3},
		{3, "Facial Skin Care", 3},
		{4, "Massage Therapy", 3}
	};
	services* P_services_available = services_available;
	users experts[] = {
		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}},
		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}},
		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}},
		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}}
	};
	users* P_experts = experts;
	users customer_users[] = {
		{4, "Blaze", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", customer},
		{5, "Thomas", 16, 'M', "thomaswayne@gmail.com", "utc4kt6d8vcuj", customer},
		{6, "Bruce Wayne", 16, 'M', "brucewayne@gmail.com", "kyu6fv485k7f8tyu6+", customer},
		{8, "Tommy", 16, 'M', "peakblinders4peak@gmail.com", "68kdcty786yuf", customer},
		{9, "Jeremy", 16, 'M', "whostheboss@gmail.com", "yuf1h23vjk78y9i", customer},
		{56, "Jeremiah", 16, 'M', "justanothercopy@gmail.com", "qwet786xfgh534", customer},
		{12, "Harley", 16, 'F', "harleyquinnsucktbh@gmail.com", "ub78i6312ic6gh78k", customer},
		{7, "Ashton Hall", 16, 'M', "ashtonhallunclosetoishowmeeat@gmail.com", "45pgyuijbk73po5ui", customer},
		{5, "iShoeSpeed", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
	};
	users* P_customers = customer_users;
	timeSlots hourly_timeSlots[] = {
		{1, 12.00, 15.00},
		{2, 14.00, 17.00},
		{3, 16.00, 19.00},
		{4, 18.00, 21.00},
		{5, 21.00, 0.00},
		{6, 22.00, 1.00}
	};
	timeSlots* P_hourlyTimeSlots = hourly_timeSlots;
	bookings appointments_schedule[] = {
		{&hourly_timeSlots[0], true, 18, &customer_users[2], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 18, &customer_users[4], &experts[1], &services_available[1]},
		{&hourly_timeSlots[2], true, 18, &customer_users[0], &experts[3], &services_available[2]},
		{&hourly_timeSlots[3], true, 18, &customer_users[2], &experts[4], &services_available[3]},
		{&hourly_timeSlots[4], true, 18, &customer_users[7], &experts[1], &services_available[2]},
		{&hourly_timeSlots[5], true, 18, &customer_users[8], &experts[2], &services_available[1]},
		{&hourly_timeSlots[2], true, 18, &customer_users[6], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 5, &customer_users[3], &experts[2], &services_available[0]},
		{&hourly_timeSlots[1], true, 29, &customer_users[1], &experts[2], &services_available[1]},
		{&hourly_timeSlots[1], true, 12, &customer_users[1], &experts[2], &services_available[2]}
	};
	bookings* P_appointments_schedule = appointments_schedule;
	//for (int i = 0; i < 2; ++i) {
	//	bookings& appointments = appointments_schedule[i];

	//	cout << fixed << setprecision(2) << showpoint << appointments.timeslot->timeslotID << endl 
	//		<< appointments.timeslot->hours_start << ' ' << appointments.timeslot->hours_end << endl
	//		<< appointments.booking_status << endl << "Dec " << appointments.booking_date << " 2025" << endl
	//		<< appointments.book_byCustomer->username << ' ' << appointments.expert_booked->username << ' '
	//		<< appointments.service_booked->service_name << endl << endl << endl;
	//}
	cout << "Pick one serivces : \n" << "------------------------------\n";
	for (int i = 0; i < 4; ++i) {
		cout << numberedlist << ". " << P_services_available[i].service_name << endl;
		++numberedlist;
	}
	*ptr_numberliste = 1;
	cout << endl;
	cin >> choice_service;
	// use structure, array, pointers to filter out expert w\ relevant services only
	cout << "\nOur experts that provides " << P_services_available[choice_service - 1].service_name << ": \n";
	//for (int i = 0; i < sizeof(experts) ; ++i) {
	//	users& expert = experts[i];
	//	services* spec0 = expert.specialization[0];
	//	services* spec1 = expert.specialization[1];
	//	if ((spec0 && spec0->serviceID == choice_service) || (spec1 && spec1->serviceID == choice_service)) {//the services ID starts from 1, so it matches the choice_service
	//		cout << numberedlist << ". " << expert.username << endl;
	//		++numberedlist;
	//	}
	//}
	cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
	cin >> choice_expert;
	viewAvailable_days(choice_expert, services_available, experts, customer_users, appointments_schedule);
	
	return 0;
}
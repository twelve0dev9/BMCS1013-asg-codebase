#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;

enum UserType { admin, expert, customer };

struct services {
	int serviceID = 0;
	string service_name = " ";
	float serviceTime = 0.00; //unit is Hours
	double servicePrice = 0.00;
};
struct users {
	//the users records might put under sum kind of function 
	//no point in importing the user records from the file globally when not in use
	int userID = 0;
	string username = " ";
	int age = 0;
	char gender = ' ';
	string user_email = " ";
	string user_password = " ";
	UserType user_Type;
	services* specialization[2];
	double serviceCharge = 0.00;
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
void login();
bool isAlphabet(const char* stringVar);
bool isAlphaNum(const char* stringVar);
//bool payment(int* choice_services, services services_available[], users experts[]);
void viewAvailable_days(int* choice_expert, services services_available[],
	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings);
void bookAppointment(int* numberofTimeSlots, int* numberedlist, int* choice_timeSlot, int* choice_services,
	services services_available[], users experts[], timeSlots hourly_timeSlots[]);
void viewbookedSchedule();
void customerFunctionalities(int* numberofAppointments, int* numberofExperts, int* numberofServices, int* numberofTimeSlots,
	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[], bookings appointments_schedule[]);
int main() {
	services services_available[4] = {
		{1, "Haircuts & Trims", 3, 70.00},
		{2, "Bread Grooming", 3, 100.00},
		{3, "Facial Skin Care", 3, 120.00},
		{4, "Massage Therapy", 3, 200.00}
	}; services* P_services_available = services_available;
	users experts[] = {
		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}, 100.00},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}, 200.00},
		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}, 250.00},
		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}, 70.00},
		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}, 200.00}
	}; users* P_experts = experts;
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
	}; users* P_customers = customer_users;
	timeSlots hourly_timeSlots[] = {
		{1, 12.00, 15.00},
		{2, 14.00, 17.00},
		{3, 16.00, 19.00},
		{4, 18.00, 21.00},
		{5, 21.00, 0.00},
		{6, 22.00, 1.00}
	}; timeSlots* P_hourlyTimeSlots = hourly_timeSlots;
	bookings appointments_schedule[] = {
		{&hourly_timeSlots[0], true, 18, &customer_users[2], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 18, &customer_users[4], &experts[0], &services_available[0]},
		{&hourly_timeSlots[2], true, 18, &customer_users[0], &experts[0], &services_available[3]},
		{&hourly_timeSlots[3], true, 18, &customer_users[2], &experts[0], &services_available[0]},
		{&hourly_timeSlots[4], true, 18, &customer_users[7], &experts[0], &services_available[3]},
		{&hourly_timeSlots[5], true, 18, &customer_users[8], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 18, &customer_users[6], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 5, &customer_users[3], &experts[2], &services_available[0]},
		{&hourly_timeSlots[1], true, 29, &customer_users[1], &experts[2], &services_available[1]},
		{&hourly_timeSlots[1], true, 12, &customer_users[1], &experts[2], &services_available[2]},
		// Fully booked days (9 days × 6 slots each = 54 bookings total)
		{&hourly_timeSlots[0], true, 2, &customer_users[0], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 2, &customer_users[1], &experts[0], &services_available[1]},
		{&hourly_timeSlots[2], true, 2, &customer_users[2], &experts[0], &services_available[2]},
		{&hourly_timeSlots[3], true, 2, &customer_users[3], &experts[0], &services_available[3]},
		{&hourly_timeSlots[4], true, 2, &customer_users[4], &experts[0], &services_available[0]},
		{&hourly_timeSlots[5], true, 2, &customer_users[5], &experts[0], &services_available[1]},

		{&hourly_timeSlots[0], true, 5, &customer_users[6], &experts[0], &services_available[2]},
		{&hourly_timeSlots[1], true, 5, &customer_users[7], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 5, &customer_users[8], &experts[0], &services_available[0]},
		{&hourly_timeSlots[3], true, 5, &customer_users[0], &experts[0], &services_available[1]},
		{&hourly_timeSlots[4], true, 5, &customer_users[1], &experts[0], &services_available[2]},
		{&hourly_timeSlots[5], true, 5, &customer_users[2], &experts[0], &services_available[3]},

		{&hourly_timeSlots[0], true, 29, &customer_users[3], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 29, &customer_users[4], &experts[0], &services_available[1]},
		{&hourly_timeSlots[2], true, 29, &customer_users[5], &experts[0], &services_available[2]},
		{&hourly_timeSlots[3], true, 29, &customer_users[6], &experts[0], &services_available[3]},
		{&hourly_timeSlots[4], true, 29, &customer_users[7], &experts[0], &services_available[0]},
		{&hourly_timeSlots[5], true, 29, &customer_users[8], &experts[0], &services_available[1]},

		{&hourly_timeSlots[0], true, 14, &customer_users[0], &experts[0], &services_available[2]},
		{&hourly_timeSlots[1], true, 14, &customer_users[1], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 14, &customer_users[2], &experts[0], &services_available[0]},
		{&hourly_timeSlots[3], true, 14, &customer_users[3], &experts[0], &services_available[1]},
		{&hourly_timeSlots[4], true, 14, &customer_users[4], &experts[0], &services_available[2]},
		{&hourly_timeSlots[5], true, 14, &customer_users[5], &experts[0], &services_available[3]},

		{&hourly_timeSlots[0], true, 15, &customer_users[6], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 15, &customer_users[7], &experts[0], &services_available[1]},
		{&hourly_timeSlots[2], true, 15, &customer_users[8], &experts[0], &services_available[2]},
		{&hourly_timeSlots[3], true, 15, &customer_users[0], &experts[0], &services_available[3]},
		{&hourly_timeSlots[4], true, 15, &customer_users[1], &experts[0], &services_available[0]},
		{&hourly_timeSlots[5], true, 15, &customer_users[2], &experts[0], &services_available[1]},

		{&hourly_timeSlots[0], true, 18, &customer_users[3], &experts[0], &services_available[2]},
		{&hourly_timeSlots[1], true, 18, &customer_users[4], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 18, &customer_users[5], &experts[0], &services_available[0]},
		{&hourly_timeSlots[3], true, 18, &customer_users[6], &experts[0], &services_available[1]},
		{&hourly_timeSlots[4], true, 18, &customer_users[7], &experts[0], &services_available[2]},
		{&hourly_timeSlots[5], true, 18, &customer_users[8], &experts[0], &services_available[3]},

		{&hourly_timeSlots[0], true, 26, &customer_users[1], &experts[0], &services_available[0]},
		{&hourly_timeSlots[1], true, 26, &customer_users[2], &experts[0], &services_available[1]},
		{&hourly_timeSlots[2], true, 26, &customer_users[3], &experts[0], &services_available[2]},
		{&hourly_timeSlots[3], true, 26, &customer_users[4], &experts[0], &services_available[3]},
		{&hourly_timeSlots[4], true, 26, &customer_users[5], &experts[0], &services_available[0]},
		{&hourly_timeSlots[5], true, 26, &customer_users[6], &experts[0], &services_available[1]},

		{&hourly_timeSlots[0], true, 30, &customer_users[7], &experts[0], &services_available[2]},
		{&hourly_timeSlots[1], true, 30, &customer_users[8], &experts[0], &services_available[3]},
		{&hourly_timeSlots[2], true, 30, &customer_users[0], &experts[0], &services_available[0]},
		{&hourly_timeSlots[3], true, 30, &customer_users[1], &experts[0], &services_available[1]},
		{&hourly_timeSlots[4], true, 30, &customer_users[2], &experts[0], &services_available[2]},
		{&hourly_timeSlots[5], true, 30, &customer_users[3], &experts[0], &services_available[3]},

		// Partial bookings for the rest of the month (just a few slots booked)
		{&hourly_timeSlots[0], true, 6, &customer_users[4], &experts[0], &services_available[0]},
		{&hourly_timeSlots[2], true, 9, &customer_users[5], &experts[0], &services_available[1]},
		{&hourly_timeSlots[4], true, 14, &customer_users[6], &experts[0], &services_available[2]},
		{&hourly_timeSlots[1], true, 28, &customer_users[7], &experts[0], &services_available[3]}
	}; bookings* P_appointments_schedule = appointments_schedule;
	int numberofAppointments = sizeof(appointments_schedule) / sizeof(appointments_schedule)[0],
		numberofExperts = sizeof(experts) / sizeof(experts)[0],
		numberofServices = sizeof(services_available) / sizeof(services_available)[0],
		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0];
	login();
	customerFunctionalities(&numberofAppointments, &numberofExperts, &numberofServices, &numberofTimeSlots,
		services_available, experts, customer_users, hourly_timeSlots, appointments_schedule);
	return 0;
}
void customerFunctionalities(int* numberofAppointments, int* numberofExperts, int* numberofServices, int* numberofTimeSlots,
	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[], bookings appointments_schedule[])
{
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1;
	cout << setw(35) << "Men's LOOKMAXXIN Spa\n"
		<< "-------------------------------------------------"
		<< endl;
	cout << "\033[1mWhere Style Meets Self-Care.\033[0m\n"
		<< "Welcome to Men's LOOKMAXXIN Spa, as our name suggests, We WILL make you LOOKMAXXING.\n"
		<< "A premium grooming spa designed exclusively for men who value sharp style, total relaxation, and modern self-care.\n"
		<< "We offer a full range of services from precision haircuts and classic straight-razor shaves to revitalizing facials, deep tissue massages, and expert beard grooming.\n"
		<< "Our space blends the sophistication of a gentlemen's club with the tranquility of a day spa, providing a relaxing environment where you can unwind, refresh, and leave feeling your absolute best.\n"
		<< "Whether you're preparing for a big event, need routine maintenance, or just deserve a break. Our skilled barbers, aestheticians, and therapists are here to elevate your grooming experience.\n"
		<< "\n\nOperating hours : | 12PM - 1AM\n" << setw(37) << "| Monday--Saturday\n"
		<< "Contact email : lookmaxxin2day@gmail.com\nContact phone : 03-3788 46567\n\n";
	cout << "Welcome " << experts->username << "!\n";
	cout << "1. View our serivces\n2. Book an appointment\n3. View booked schedule\n4. Exit\n\n";
	cin >> choice_menu;
	while (choice_menu < 1 || choice_menu > 4 || isalnum(choice_menu) == true)
		cin >> choice_menu;
	switch (choice_menu)
	{
	case 1:
		cout << "Our available services : \n" << "--------------------------------";
		for (int i = 0; i < *numberofServices; ++i)
		{
			cout << numberedlist << ". " << services_available[i].service_name << endl;
			++numberedlist;
		}
		numberedlist = 1;
		break;
	case 2:
		cout << "Pick one serivces : \n" << "------------------------------\n";
		for (int i = 0; i < *numberofServices; ++i)
		{
			// list the number of services available
			cout << numberedlist << ". " << services_available[i].service_name << endl;
			++numberedlist;
		}
		numberedlist = 1;
		cout << endl;
		cin >> choice_service; // input validation pending
		cout << "\nOur experts that provides " << services_available[choice_service - 1].service_name << ": \n";
		for (int i = 0; i < *numberofExperts; ++i)
		{
			// display of experts accordingly in a numbered list based-on matching specialization w\ the services customer has chosen
			if ((experts[i].specialization[0] && experts[i].specialization[0]->serviceID == choice_service) ||
				(experts[i].specialization[1] && experts[i].specialization[1]->serviceID == choice_service)) // since our the experts' specialization member is an array of pointers, we check the 1st & the 2nd pointer points to corresponding services or not
			{
				cout << numberedlist << ". " << experts[i].username << endl;
				++numberedlist;
			}
		}
		numberedlist = 1;
		cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
		cin >> choice_expert;
		viewAvailable_days(&choice_expert, services_available, experts, customers, appointments_schedule, numberofAppointments);
		bookAppointment(numberofTimeSlots, &numberedlist, &choice_timeSlot, &choice_service, services_available, experts, hourly_timeSlots);
		break;
	case 3:
		viewbookedSchedule();
		break;
	case 4:
		cout << "Exitting ...";
	}
}
void viewAvailable_days(int* choice_expert, services services_available[],
	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings)
{
	// display available days of chosen expert
	const int row = 5, col = 8, totalSlotsperDay = 6;
	int i = 0, j = 0, bookingsPerDay[32] = { 0 };
	int time_slotsDay[5][8] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0, 0}
	};
	cout << endl << endl;
	for (int k = 0; k < *totalBookings; ++k) //goes over the bookings list iteratively
	{							//dis compares if the appointments' booked expert is the same as what user choosed
			//in dis case is our choice_expert, but becuz of 0-based indices, i tolak satu to account for 0-based indices
		if (appointments_schedule[k].expert_booked->userID == experts[*choice_expert - 1].userID && appointments_schedule[k].booking_status == true)
		{										// display the availability of chosen expert's schedule in December
			if (appointments_schedule[k].booking_date >= 1 &&
				appointments_schedule[k].booking_date <= 31)
			{
				bookingsPerDay[appointments_schedule[k].booking_date]++;
			}
		}
	}
	cout << experts[*choice_expert - 1].username << " is available for the following days : \n" << setw(23) << "December" << endl
		<< "-------------------------------------\n";
	for (i = 0; i < row; ++i)
	{
		// calendar display
		for (j = 0; j < col; ++j)
		{
			int date = time_slotsDay[i][j];
			std::ostringstream oss;
			oss << setw(3) << date;
			if (date == 0) continue;

			if (bookingsPerDay[date] < totalSlotsperDay) // condition for days whr there are available time 
				cout << " " << oss.str() << " ";
			else
				cout << " " << "\033[101;30m" << oss.str() << "\033[0m ";
		}
		cout << endl;
	}
	cout << "\nLEGEND | \033[101;30mUnavailable\033[0m, Available\n\n";
}
void bookAppointment(int* numberofTimeSlots, int* numberedlist, int* choice_timeSlot, int* choice_services,
	services services_available[], users experts[], timeSlots hourly_timeSlots[])
{
	int book_Date = 0;
	cout << "Pick the day you'd like to book : ";
	cin >> book_Date;
	cout << "Pick your time slots for the day : ";
	for (int i = 0; i < *numberofTimeSlots; ++i)
	{
		cout << numberedlist << hourly_timeSlots[i].hours_start << "-" << hourly_timeSlots[i].hours_end << endl;
		++numberedlist;
	}
	cout << endl;
	*numberedlist = 1;
	cin >> *choice_timeSlot;
	//payment(choice_services, services_available, experts);
	//if (payment == 1)
	//{
	//	cout << "\nBooking an appointment right away !!\n";
	//	//for loops that writes into Appointments.txt
	//}
	//else
	//{
	//	while (payment == 0 && makepayment == Y)
	//	{
	//		cout << "Try to make payment again? (y = Yes | n = No)\n";
	//		cin >> makepayment;
	//	}
	//}
}
void login() {
	//read all from "User records.txt" file`
		//if possible find ways to read from user records w\ username entered by user only, instead of reading all of the records

	//compare the credentials with the read records
}
bool isAlphabet(const char* stringVar) // to check if the input is Alphabet or not
{
	for (int i = 0; stringVar[i] != '\0'; ++i)
	{
		if (!isalpha(stringVar[i])) 
		{
			return false;
		}
	}
	return true;
}
bool isAlphaNum(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
{
	for (int i = 0; stringVar[i] != '\0'; ++i)
	{
		if (!isalnum(stringVar[i])) 
		{
			return false;
		}
	}
	return true;
}
//bool payment(int* choice_services, services services_available[], users experts[]) {
//	//payment module
//	//display & input prompts, fake(:verb) the credentials
//	int choice_payment;
//	bool paid = true;
//	cout << "------------------ Payment ------------------ \n"
//		<< customername << endl
//		<< "Selected package : " << services_available[choice_services].serviceName << endl
//		<< "Service Charge : RM" << experts[choice_expert - 1].serviceCharge << endl
//		<< "Base Price : RM" << services_available[choice_service - 1].servicePrice << endl
//		<< "----------------------------------------------- ";
//	cout << "Select payment method : \n" << "[1] Credit Card\n[2] Online Banking\n[3] E-Wallet\n[4] Cancel Payment"
//		<< "Enter your choice : ";
//	cin >> choice_payment;
//	if (choice_payment == 1)
//	{
//		cout << "Enter Cardholder Name : ";
//		cin >> name;
//		cout << "\nEnter Card Number (16 digits) : ";
//		cin >> cardnumber;
//		cout << "\nEnter Expiry Date (MM/YY) : ";
//		cin >> cardExpiryDate;
//		cout << "\nProcessing payment...\n";
//		cout << "Payment successful!"
//	}
//	else if (choice_payment == 2)
//	{
//		cout << "Enter your bank : ";
//		// maybe a list of bank enums, typedef, of array to choose from, list it out for user to choose
//		// and just an int for user to choose like in the customer menus
//		cin >> bankname;
//		cout << "Enter your username : ";
//		cin >> name;
//		cout << "Enter your password : ";
//		cin >> password;
//		cout << "Authorization request sent to the bank app, approve the authorization...";
//		cout << "\napproved?...";
//		cin >> approved;
//		cout << "\nProcessing payment...\n";
//		cout << "Payment successful!"
//	}
//	else if (choice_payment == 3)
//	{
//		cout << "Scan the QR below : ";
//		cout << "QR Code";
//		cout << "\nProcessing payment...\n";
//		cout << "Payment successful!"
//	}
//	else
//	{
//		cout << "Payment cancelled";
//		paid = false;
//	}
//	return paid;
//}
void viewbookedSchedule() {

}
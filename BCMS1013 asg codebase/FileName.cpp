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
void custlogin();
void main_menu();
bool isAlphabet(const char* stringVar);
bool isAlphaNum(const char* stringVar);
bool isNumeric(const char* stringVar);
bool payment(int* choice_services, int* choice_expert, services services_available[], users experts[], users customers[], int* numberedlist);
int getInput(int* P_numberedlist);
bool cardExpiryDatevalidformat(const string& cardExpiryDate);
void viewAvailable_days(int* choice_expert, services services_available[],
	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings);
void bookAppointment(int* numberofTimeSlots, int* numberedlist, int* choice_timeSlot, int* choice_services, int* choice_expert, 
	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[]);
void viewbookedSchedule();
void viewServices();
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
	main_menu();
	customerFunctionalities(&numberofAppointments, &numberofExperts, &numberofServices, &numberofTimeSlots,
		services_available, experts, customer_users, hourly_timeSlots, appointments_schedule);
	return 0;
}
void customerFunctionalities(int* numberofAppointments, int* numberofExperts, int* numberofServices, int* numberofTimeSlots,
	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[], bookings appointments_schedule[])
{
	int choice, choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1, 
		* P_numberedlist = &numberedlist, * P_choiceExpert = &choice_expert;
	cout << setw(35) << 
		R"(
$$\      $$\                     $$\                 $$\        $$$$$$\   $$$$$$\  $$\   $$\ $$\      $$\  $$$$$$\  $$\   $$\ $$\   $$\ $$$$$$\ $$\   $$\        $$$$$$\                      
$$$\    $$$ |                    $  |                $$ |      $$  __$$\ $$  __$$\ $$ | $$  |$$$\    $$$ |$$  __$$\ $$ |  $$ |$$ |  $$ |\_$$  _|$$$\  $$ |      $$  __$$\                     
$$$$\  $$$$ | $$$$$$\  $$$$$$$\  \_/  $$$$$$$\       $$ |      $$ /  $$ |$$ /  $$ |$$ |$$  / $$$$\  $$$$ |$$ /  $$ |\$$\ $$  |\$$\ $$  |  $$ |  $$$$\ $$ |      $$ /  \__| $$$$$$\   $$$$$$\  
$$\$$\$$ $$ |$$  __$$\ $$  __$$\     $$  _____|      $$ |      $$ |  $$ |$$ |  $$ |$$$$$  /  $$\$$\$$ $$ |$$$$$$$$ | \$$$$  /  \$$$$  /   $$ |  $$ $$\$$ |      \$$$$$$\  $$  __$$\  \____$$\ 
$$ \$$$  $$ |$$$$$$$$ |$$ |  $$ |    \$$$$$$\        $$ |      $$ |  $$ |$$ |  $$ |$$  $$<   $$ \$$$  $$ |$$  __$$ | $$  $$<   $$  $$<    $$ |  $$ \$$$$ |       \____$$\ $$ /  $$ | $$$$$$$ |
$$ |\$  /$$ |$$   ____|$$ |  $$ |     \____$$\       $$ |      $$ |  $$ |$$ |  $$ |$$ |\$$\  $$ |\$  /$$ |$$ |  $$ |$$  /\$$\ $$  /\$$\   $$ |  $$ |\$$$ |      $$\   $$ |$$ |  $$ |$$  __$$ |
$$ | \_/ $$ |\$$$$$$$\ $$ |  $$ |    $$$$$$$  |      $$$$$$$$\  $$$$$$  | $$$$$$  |$$ | \$$\ $$ | \_/ $$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |$$$$$$\ $$ | \$$ |      \$$$$$$  |$$$$$$$  |\$$$$$$$ |
\__|     \__| \_______|\__|  \__|    \_______/       \________| \______/  \______/ \__|  \__|\__|     \__|\__|  \__|\__|  \__|\__|  \__|\______|\__|  \__|       \______/ $$  ____/  \_______|
                                                                                                                                                                          $$ |                
                                                                                                                                                                          $$ |                
                                                                                                                                                                          \__|                )"
		<< endl;
	for (int i = 0; i < 100; ++i)
		cout << '=';
	cout << endl << endl;
	cout << "\033[1mWhere Style Meets Self-Care.\033[0m\n"
		<< "Welcome to Men's LOOKMAXXIN Spa, as our name suggests, We WILL make you LOOKMAXXING.\n"
		<< "A premium grooming spa designed exclusively for men who value sharp style, total relaxation, and modern self-care.\n"
		<< "We offer a full range of services from precision haircuts and classic straight-razor shaves to revitalizing facials, deep tissue massages, and expert beard grooming.\n"
		<< "Our space blends the sophistication of a gentlemen's club with the tranquility of a day spa, providing a relaxing environment where you can unwind, refresh, and leave feeling your absolute best.\n"
		<< "Whether you're preparing for a big event, need routine maintenance, or just deserve a break. Our skilled barbers, aestheticians, and therapists are here to elevate your grooming experience.\n"
		<< "\n\nOperating hours : | 12PM - 1AM\n" << setw(37) << "| Monday--Saturday\n"
		<< "Contact email : lookmaxxin2day@gmail.com\nContact phone : 03-3788 46567\n\n";
	cout << "Welcome " << experts->username << "!\n";
	cout << "1. View our serivces\n2. Book an appointment\n3. View booked appointment\n4. View appointment availability\n5. Exit\n\n";
	*P_numberedlist = 6;
	choice = getInput(P_numberedlist);
	*P_numberedlist = 1;
	switch (choice)
	{
	case 1:
		cout << "Our available services : \n" << "--------------------------------";
		for (int i = 0; i < *numberofServices; ++i)
		{
			cout << *P_numberedlist << ". " << services_available[i].service_name << endl;
			++*P_numberedlist;
		}
		*P_numberedlist = 1;
		break;
	case 2:
		cout << "Pick one serivces : \n" << "------------------------------\n";
		for (int i = 0; i < *numberofServices; ++i)
		{// list the number of services available
			cout << *P_numberedlist << ". " << services_available[i].service_name << endl;
			++*P_numberedlist;
		}
		cout << endl;
		choice = getInput(P_numberedlist);
		*P_numberedlist = 1;
		cout << "\nOur experts that provides " << services_available[choice_service - 1].service_name << ": \n";
		for (int i = 0; i < *numberofExperts; ++i)
		{
			// display of experts accordingly in a *P_numbered list based-on matching specialization w\ the services customer has chosen
			if ((experts[i].specialization[0] && experts[i].specialization[0]->serviceID == choice_service) ||
				(experts[i].specialization[1] && experts[i].specialization[1]->serviceID == choice_service)) // since our the experts' specialization member is an array of pointers, we check the 1st & the 2nd pointer points to corresponding services or not
			{
				cout << *P_numberedlist << ". " << experts[i].username << endl;
				++*P_numberedlist;
			}
		}
		cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
		choice = getInput(P_numberedlist);
		*P_numberedlist = 1;
		viewAvailable_days(&choice, services_available, experts, customers, appointments_schedule, numberofAppointments);
		bookAppointment(numberofTimeSlots, &numberedlist, &choice_timeSlot, &choice_service, &choice_expert, services_available, experts, customers, hourly_timeSlots);
		break;
	case 3:
		viewbookedSchedule();
		break;
	case 4: 
		cout << "\nWhat experts would you like check for their availability ?\n\n";
		cin >> *P_choiceExpert;
		viewAvailable_days(&choice_expert, services_available, experts, customers, appointments_schedule, numberofAppointments);
		break;
	case 5:
		cout << "=== PROGRAM END ===";
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
	for (int k = 0; k < *totalBookings; ++k)
	{
		if (appointments_schedule[k].expert_booked->userID == experts[*choice_expert - 1].userID && appointments_schedule[k].booking_status == true)
		{
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
void bookAppointment(int* numberofTimeSlots, int* numberedlist, int* choice_timeSlot, int* choice_services, int* choice_expert, 
	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[])
{
	int book_Date = 0; char makepayment = ' ';
	cout << "Pick the day you'd like to book : ";
	cin >> book_Date;
	cout << "Pick your time slots for the day : ";
	for (int i = 0; i < *numberofTimeSlots; ++i)
	{
		cout << numberedlist << ". " << fixed << setprecision(2) << hourly_timeSlots[i].hours_start << "--" << hourly_timeSlots[i].hours_end << endl;
		++numberedlist;
	}
	cout << endl;
	*numberedlist = 1;
	cin >> *choice_timeSlot;
	if (payment(choice_services, choice_expert, services_available, experts, customers, numberedlist) == true)
	{
		cout << "\nBooking an appointment right away !!\n";
		//for loops that writes into Appointments.txt
	}
	else
	{
		while (payment(choice_services, choice_expert, services_available, experts, customers, numberedlist) == true)
		{
			cout << "Try to make payment again? (Y = Yes | n = No)\n";
			

		}
	}
}
void custlogin() {
	//read all from "User records.txt" file`
		//if possible find ways to read from user records w\ username entered by user only, instead of reading all of the records
	string username = " ", password = " ", choice;
	cout << "Already got an account?\n1. Login\n2. Guest\n\n";
	getline(cin, choice);
	while (choice.empty() == true || isAlphabet(choice.c_str()) == true || isAlphaNum(choice.c_str()) == false
		|| stoi(choice) < 1 || stoi(choice) > 2)
	{
		cout << "Invalid input. Please enter again. \n" << "Already got an account?\n1. Login\n2. Guest";
	}
	//compare the credentials with the read records
}
bool isAlphabet(const char* stringVar) // to check if the input is Alphabet or not
{
	for (int i = 0; stringVar[i] != '\0'; ++i) {
		if (!isalpha(stringVar[i]))
			return false;}
	return true;
}
bool isAlphaNum(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
{
	for (int i = 0; stringVar[i] != '\0'; ++i) {
		if (!isalnum(stringVar[i])) 
			return false; }
	return true;
}
bool isNumeric(const char* stringVar) // false : Is not numeric
{
	for (int i = 0; stringVar[i] != '\0'; ++i) {
		if (!isdigit(stringVar[i]))
			return false;}
	return true;
}
int getInput(int* P_numberedlist) {
	string input;
	cout << "Enter your option (1 - " << *P_numberedlist - 1 << ") : ";
	while (true) {
		getline(cin, input);
		// check contains alphabet or not
		if (isAlphabet(input.c_str()) == true) {
			cout << "\nInvalid input. Input contains letters, please enter option 1 - " << *P_numberedlist - 1 << " only : ";
			continue;
		}
		// check for invalid symbols
		if (isNumeric(input.c_str()) == false) {
			cout << "\nInvalid input. Input contains symbols, or alphanumeric, please enter option 1 - " << *P_numberedlist - 1 << " only : ";
			continue;
		}
		// check if input is empty 
		if (input.empty()) {
			cout << "\nInput is empty, please provide option 1 - " << *P_numberedlist - 1 << " : ";
			continue;
		}
		char* endPtr;
		long long value = strtoll(input.c_str(), &endPtr, 10);
		// check if the parsed string is all int
		// check for overflow (out of range) issue
		if (value < numeric_limits<int>::min() || value > numeric_limits<int>::max()) {
			cout << "\nOverflow, input too large for integer, bruh only 1 to " << *P_numberedlist - 1 << " : ";
			continue;
		}

		if (value < 1 || value > *P_numberedlist - 1) {
			cout << "\nInvalid range, only option between 1 and " << *P_numberedlist - 1 << " : ";
			continue;
		}
		return static_cast<int>(value);
	}
}
bool payment(int* choice_services, int* choice_expert, services services_available[], users experts[], users customers[], int* numberedlist) {
	//payment module
	//display & input prompts, fake(:verb) the credentials
	string choice_payment, multiusestring, 
		Banks[] = { "Ambank", "HongLeong Bank", "Public Bank", "Maybank", "Alliance Bank" };
	int choice_bank = 0;
	cout << "------------------ Payment ------------------ \n"
		<< "Customer name : " << setw(20) << customers[1].username << endl
		<< "Selected package : " << services_available[*choice_services].service_name << endl
		<< "Service Charge : RM" << experts[*choice_expert - 1].serviceCharge << endl
		<< "Base Price : RM" << services_available[*choice_services - 1].servicePrice << endl
		<< "----------------------------------------------- ";
	cout << "Select payment method : \n" << "[1] Credit Card\n[2] Online Banking\n[3] E-Wallet\n[4] Cancel Payment"
		<< "Enter your choice : ";
	cin >> choice_payment;
	while (isAlphabet(choice_payment.c_str()) == true || isAlphaNum(choice_payment.c_str())
		|| stoi(choice_payment) < 1 || stoi(choice_payment) > 4) 
	{
		cout << "Invalid input. Please enter again : \n\n";
		cin >> choice_payment;
	}
	int choice_payment1 = (choice_payment[0] - '0');
	switch (choice_payment1) {
	case 1 : 
		cout << "Enter Cardholder Name : ";
		cin >> multiusestring;
		cout << "\nEnter Card Number (16 digits) : ";
		cin >> multiusestring;
		while (multiusestring.length() < 17) {
			cout << numberedlist << "Enter valid format !!!\nEnter Card Number (16 digits) : ";
			cin >> multiusestring;
		}
		cout << "\nEnter Expiry Date (MM/YY) : ";
		cin >> multiusestring;
		while (cardExpiryDatevalidformat(multiusestring) == false) {
			cout << "\nInvalid format. Please enter card Expiry Date in valid format (MM/YY) : ";
			cin >> multiusestring;
		}
		cout << "\n\nProcessing payment...\n\n";
		cout << "\nPayment successful!";
		return true;
		break;
	case 2 : 
		cout << "Select your bank\n-----------------------\n";
		for (int i = 0; i < sizeof(Banks) / sizeof(Banks)[0]; ++i)
		{
			cout << numberedlist << ". " << Banks[i] << endl;
			++numberedlist;
		}
		cin >> choice_bank;
		cout << "\nEnter your username : ";
		cin >> multiusestring;
		cout << "\nEnter your password : ";
		cin >> multiusestring;
		cout << "Authorization request sent to the bank app, approve the authorization...";
		cout << "\napproved?... (Y = Yes | N = No) : ";
		cin >> multiusestring;
		while (multiusestring.length() > 1 || isAlphabet(multiusestring.c_str()) == false || isAlphaNum(multiusestring.c_str()) == false) 
		{
			cout << "Invalid input.\n" << "\napproved?... (Y = Yes | N = No) : ";
			cin >> multiusestring;
		}
		if (multiusestring == "Y") {
			cout << "\n\nProcessing payment...\n\n";
			cout << "Payment successful!";
			return true;
		}
		else
		{
			cout << "Authorization failed !! Please try again.";
			return false;
		}
		break;
	case 3 : 
		cout << "Scan the QR below : ";
		cout << "QR Code";
		cout << "\nProcessing payment...\n";
		cout << "Payment successful!";
		return true;
		break;
	case 4:
		cout << "Payment cancelled";
		return false;
	}
}
bool cardExpiryDatevalidformat(const string& cardExpiryDate)
{
	if (cardExpiryDate.length() != 5) return false;
	else if (cardExpiryDate[2] != '/') return false;
	else for (int i = 0; i < cardExpiryDate.length(); ++i) {
		if (i == 2) continue;
		if (!isdigit(cardExpiryDate[i]))
			return false;
	}
	int month = (cardExpiryDate[0] - '0') * 10 + (cardExpiryDate[1] - '0');
	if (month < 1 || month > 12) return false;

	return true;
}
void viewbookedSchedule() {

}
void main_menu()
{
	int login_type = 0;
	while (login_type < 1 || login_type > 4)
	{
		cout << "     MAIN MENU      " << endl;
		cout << "--------------------" << endl;
		cout << "Select Login: " << endl;
		cout << "1. Customer Login" << endl;
		cout << "2. Administrator Login" << endl;
		cout << "3. Expert Login" << endl;
		cout << "4. Exit Program" << endl;
		cout << "-------------------" << endl;
		cout << ">";
		cin >> login_type;
	}
	while (true)
	{
		cout << "     MAIN MENU      " << endl;
		cout << "--------------------" << endl;
		cout << "Select Login: " << endl;
		cout << "1. Customer Login" << endl;
		cout << "2. Administrator Login" << endl;
		cout << "3. Expert Login" << endl;
		cout << "4. Exit Program" << endl;
		cout << "-------------------" << endl;
		cout << ">";
		cin >> login_type;
		system("cls");
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter integers only." << endl;
		}
		else
			break;
	}
	switch (login_type) {
	case 1:
		custlogin();
		break;
	case 2:
		//admin_login();
		break;
	case 3:
		//expert_login();
		break;
	case 4:
		cout << "=== PROGRAM END ===";
		break;
	}
}

void viewServices() {

}
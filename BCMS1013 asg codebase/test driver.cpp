#define NOMINMAX
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<fstream>
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
	int book_byCustomer;
	users* expert_booked;
	services* service_booked;
};

bool isAlphabet(const char* stringVar) // to check if the input is Alphabet or not
{
	for (int i = 0; stringVar[i] != '\0'; ++i)	{
		if (!isalpha(stringVar[i]))
			return false;}
	return true;
}
bool isAlphaNum(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
{
	for (int i = 0; stringVar[i] != '\0'; ++i) {
		if (!isalnum(stringVar[i]))
	 		return false;}
	return true;
}
bool isNumeric(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
{
	for (int i = 0; stringVar[i] != '\0'; ++i) {
		if (!isdigit(stringVar[i]))
	 		return false;}
	return true;
}
int getInput(int* P_numberedlist);
//void viewUserAppointments(users loggedIn_customerUser, timeSlots* hourlyTimeSlots,
//	users* experts, services* services_available);
void viewExperts(int choice[], int* numberofExperts, int* P_numberedlist,
	int* filternumlist, int filteredIndices[], users experts[], services services_available[]);
void viewAvailable_days(int choice[], int filteredIndices[], services services_available[],
	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings);
void viewServices(int* numberofServices, int* P_numberedlist, services services_available[],
	users experts[], int* numberofExperts);

int main()
{
	services services_available[4] = {
		{1, "Haircuts & Trims", 3, 70.00},
		{2, "Bread Grooming", 3, 100.00},
		{3, "Facial Skin Care", 3, 120.00},
		{4, "Massage Therapy", 3, 200.00}
	};
	users experts[] = {
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}, 200.00},
		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}, 250.00},
		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}, 100.00},
		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}, 70.00},
		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}, 200.00}
	};
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
	timeSlots hourly_timeSlots[] = {
		{1, 12.00, 15.00},
		{2, 14.00, 17.00},
		{3, 16.00, 19.00},
		{4, 18.00, 21.00},
		{5, 21.00, 0.00},
		{6, 22.00, 1.00}
	};
	bookings appointments_schedule[] = {
		{&hourly_timeSlots[0], true, 18, 3, &experts[2], &services_available[0]},
		{&hourly_timeSlots[1], true, 18, 3, &experts[2], &services_available[0]},
		{&hourly_timeSlots[2], true, 18, 1, &experts[2], &services_available[3]},
		{&hourly_timeSlots[3], true, 18, 3, &experts[2], &services_available[0]},
		{&hourly_timeSlots[4], true, 18, 8, &experts[2], &services_available[3]},
		{&hourly_timeSlots[5], true, 18, 9, &experts[2], &services_available[3]},
		{&hourly_timeSlots[2], true, 18, 7, &experts[2], &services_available[3]},
		{&hourly_timeSlots[2], true, 5, 4, &experts[2], &services_available[0]},
		{&hourly_timeSlots[1], true, 29, 2, &experts[2], &services_available[1]},
		{&hourly_timeSlots[1], true, 12, 2, &experts[2], &services_available[2]}
	}; bookings* P_appointments_schedule = appointments_schedule;
	int totalCustomers = 0, totalExperts = 0,
		numberofAppointments = sizeof(appointments_schedule) / sizeof(appointments_schedule)[1], 
		numberofExperts = sizeof(experts) / sizeof(experts)[1], 
		numberofServices = sizeof(services_available) / sizeof(services_available)[0],
		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0], 
		choice[] = { 0, 0, 0, 0 }, filternumlist = 0, filteredIndices[100], 
		numberedlist = 1, * P_numberedlist = &numberedlist;
	
	//users* customer_users = new users[totalCustomers];
	//users* experts = new users[totalExperts];
	users loggedIn_customerUser = { 3, "Bruce Wayne", 16, 'M', "brucewayne@gmail.com", "kyu6fv485k7f8tyu6+", customer };

	viewServices(&numberofServices, P_numberedlist, services_available, experts, &numberofExperts);
	cout << "\nPick one services (1 - " << *P_numberedlist - 1 << ") : ";

	choice[1] = getInput(P_numberedlist);
	*P_numberedlist = 1;

	cout << "\nOur experts that provides " << services_available[choice[1] - 1].service_name << ": \n";
	for (int i = 0; i < numberofExperts; ++i)
	{
		if ((experts[i].specialization[0]->serviceID == choice[1])
		 || (experts[i].specialization[1]->serviceID == choice[1]))
		{ // since our the experts' specialization member is an array of pointers, 
			// we check the 1st & the 2nd pointer points to corresponding services or not
			cout << *P_numberedlist << ". " << experts[i].username << endl;
			filteredIndices[filternumlist] = i;
			++filternumlist; ++*P_numberedlist;
		}
	}
	//cout << "Pick one serivces : \n" << "------------------------------\n";
	//for (int i = 0; i < *numberofServices; ++i)
	//{
	//	// list the number of services available
	//	cout << numberedlist << ". " << services_available[i].service_name << endl;
	//	++numberedlist;
	//}
	//numberedlist = 1;
	//cout << endl;
	//cin >> choice_service; // input validation pending
	//cout << "\nOur experts that provides " << services_available[choice_service - 1].service_name << ": \n";
	//for (int i = 0; i < *numberofExperts; ++i)
	//{
	//	// display of experts accordingly in a numbered list based-on matching specialization w\ the services customer has chosen
	//	if ((experts[i].specialization[0] && experts[i].specialization[0]->serviceID == choice_service) ||
	//		(experts[i].specialization[1] && experts[i].specialization[1]->serviceID == choice_service)) // since our the experts' specialization member is an array of pointers, we check the 1st & the 2nd pointer points to corresponding services or not
	//	{
	//		cout << numberedlist << ". " << experts[i].username << endl;
	//		++numberedlist;
	//	}
	//}
	//numberedlist = 1;
	//cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
	//cin >> choice_expert;

	/*viewExperts(choice, &numberofExperts, P_numberedlist, &filternumlist, filteredIndices, experts, services_available);*/
	//cout << "\nWhat experts would you like check for their availability ? (1 - " << *P_numberedlist - 1 << ") : ";
	//choice[2] = getInput(P_numberedlist);
	//*P_numberedlist = 1;
	//viewAvailable_days(choice, filteredIndices, services_available, experts, customer_users, appointments_schedule, &numberofAppointments);

	return 0;
}
int getInput(int* P_numberedlist) 
{
	string input;
	while (true) {
		getline(cin, input);
		// check contains alphabet or not
		if (isAlphabet(input.c_str()) == true) {
			cout << "\n\033[93mInvalid input. Input contains letters, please enter option 1 - " << *P_numberedlist - 1 << " only : \033[0m";
			continue;
		}
		// check for invalid symbols
		if (isNumeric(input.c_str()) == false) {
			cout << "\n\033[31mInvalid input. Input contains symbols, or alphanumeric, please enter option 1 - " << *P_numberedlist - 1 << " only : \033[0m";
			continue;
		}
		// check if input is empty 
		if (input.empty()) {
			cout << "\n\033[101;30mInput is empty, please provide option 1 - " << *P_numberedlist - 1 << " : \033[0m";
			continue;
		}
		char* endPtr;
		long long value = strtoll(input.c_str(), &endPtr, 10);
		// check if the parsed string is all int
		// check for overflow (out of range) issue
		if (value < numeric_limits<int>::min() || value > numeric_limits<int>::max()) {
			cout << "\n\033[31mOverflow, input too large for integer, bruh only 1 to " << *P_numberedlist - 1 << " : \033[0m";
			continue;
		}

		if (value < 1 || value > *P_numberedlist - 1) {
			cout << "\n\033[96mInvalid range, only option between 1 and " << *P_numberedlist - 1 << " : \033[0m";
			continue;
		}
		return static_cast<int>(value);
	}
}
void viewExperts(int choice[], int* numberofExperts, int* P_numberedlist,
	int* filternumlist, int filteredIndices[], users experts[], services services_available[])
{ // display experts based-on matching services with what was chosen by user
	cout << "\nOur experts that provides " << services_available[choice[1] - 1].service_name << ": \n";
	for (int i = 0; i < *numberofExperts; ++i)
	{
		if ((experts[i].specialization[0] && experts[i].specialization[0]->serviceID == choice[1] - 1)
		 || (experts[i].specialization[1] && experts[i].specialization[1]->serviceID == choice[1] - 1))
		{ // since our the experts' specialization member is an array of pointers, 
			// we check the 1st & the 2nd pointer points to corresponding services or not
			cout << *P_numberedlist << ". " << experts[i].username << endl;
			filteredIndices[*filternumlist] = i;
			++*filternumlist; ++*P_numberedlist;
		}
	}
}
void viewAvailable_days(int choice[], int filteredIndices[], services services_available[],
	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings)
{
	// display available days of chosen expert
	const int row = 5, col = 8, totalSlotsperDay = 6;
	int bookingsPerDay[32] = { 0 },
		time_slotsDay[5][8] = {
			{1, 2, 3, 4, 5, 6, 7},
			{8, 9, 10, 11, 12, 13, 14},
			{15, 16, 17, 18, 19, 20, 21},
			{22, 23, 24, 25, 26, 27, 28},
			{29, 30, 31, 0, 0, 0, 0, 0}
	};
	cout << endl << endl;
	for (int k = 0; k < *totalBookings; ++k)
	{ // goes through the booking list iteratively
						// check if the userID of expert booked in bookings arry is the same as the one in expert array
		if (appointments_schedule[k].expert_booked->userID == experts[filteredIndices[choice[2] - 1]].userID &&
			appointments_schedule[k].booking_status == true)
		{					// range check for the bookings' date, shud be between 1 & 31
			if (appointments_schedule[k].booking_date >= 1 && appointments_schedule[k].booking_date <= 31)
				// if booking date is valid, then post-increment the kth element in bookingsPerDay arry
				bookingsPerDay[appointments_schedule[k].booking_date]++;
			// for each kth element in appointments_schedule, refer to its booking date, 
			// use the booking date as the nth element in bookingsPerDay array to update the nth accumulator
		}
	}
	cout << experts[filteredIndices[choice[2] - 1]].username << " is available for the following days : \n"
		<< setw(23) << "December" << endl
		<< "-------------------------------------\n";
	for (int i = 0; i < row; ++i)
	{ // calendar display
		for (int j = 0; j < col; ++j)
		{
			int date = time_slotsDay[i][j];
			ostringstream oss; // put the printables dates into buffer to prevent uneven spaces, setw() is insufficient
			oss << setw(3) << date;
			if (date == 0) continue;

			if (bookingsPerDay[date] < totalSlotsperDay) // condition for days whr there are available time 
				cout << " " << oss.str() << " "; // print the days date like usual
			else
				cout << " " << "\033[101;30m" << oss.str() << "\033[0m "; // print the unavaibale days w\ specified formatting
		}
		cout << endl;
	}
	cout << "\nLEGEND | \033[101;30mUnavailable\033[0m, Available\n\n";
}
void viewServices(int* numberofServices, int* P_numberedlist, services services_available[],
	users experts[], int* numberofExperts)
{
	cout << "\nOur available services : \n" << string(90, '-') << endl;

	for (int i = 0; i < *numberofServices; ++i) {
		cout << *P_numberedlist << ". \033[1;4m" << services_available[i].service_name
			<< "\033[0m  (Base Price: RM" << fixed << setprecision(2)
			<< services_available[i].servicePrice << ")\n";

		// Show experts who can perform this service
		bool expertFound = false;
		for (int j = 0; j < *numberofExperts; ++j)
		{
			if ((experts[j].specialization[0] && experts[j].specialization[0]->serviceID == services_available[i].serviceID)
				|| (experts[j].specialization[1] && experts[j].specialization[1]->serviceID == services_available[i].serviceID))
			{
				expertFound = true;
				double extraCharge = experts[j].serviceCharge;
				double finalPrice = services_available[i].servicePrice + extraCharge;

				cout << "   -> Expert: " << experts[j].username
					<< " | Extra Charge: RM" << extraCharge
					<< " | Final Price: RM" << finalPrice << "\n";
			}
		}

		if (!expertFound)
			cout << "   (No experts currently provide this service)\n";

		cout << string(90, '-') << endl;
		++*P_numberedlist;
	}
}
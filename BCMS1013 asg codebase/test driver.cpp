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
int countAppointmentsInFile();
int loadAppointments(bookings* appointments, int totalRecords,
	timeSlots* hourlyTimeSlots, users* experts, services* services_available);
void viewUserAppointments(users loggedIn_customerUser, bookings* appointments, int totalRecords);
bool parseAppointmentRecord(const string& Fetched_Record, bookings& appointment,
	timeSlots* hourlyTimeSlots, users* experts, services* services_available);
void writetoAppointmentRecords(bookings newAppointment,
	timeSlots hourly_timeSlots[], users experts[], services services_available[]);

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
	int totalCustomers = 0, totalExperts = 0, 
		numberofServices = sizeof(services_available) / sizeof(services_available)[0],
		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0], 
		choice[] = { 0, 0, 0, 0 }, filternumlist = 0, filteredIndices[100], 
		numberedlist = 1, * P_numberedlist = &numberedlist;
	
	//users* customer_users = new users[totalCustomers];
	//users* experts = new users[totalExperts];
	users loggedIn_customerUser = { 3, "Bruce Wayne", 16, 'M', "brucewayne@gmail.com", "kyu6fv485k7f8tyu6+", customer };


	int totalBookings = countAppointmentsInFile();
	if (totalBookings == 0) 
	{
		cout << "No appointments in file.\n";
		return 0;
	}
	bookings* appointments = new bookings[totalBookings];
	int loaded = loadAppointments(appointments, totalBookings, hourly_timeSlots, experts, services_available);
	cout << loaded << " appointment records loaded.\n";

	viewUserAppointments(loggedIn_customerUser, appointments, loaded);
	delete[] appointments;
	
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
//void viewUserAppointments(timeSlots* hourlyTimeSlots, bookings* appointments,
//	users* experts, services* services_available, users loggedIn_customerUser)
//{
//	ifstream rAppointments("Appointments.txt");
//	if (!rAppointments.is_open()) {
//		cout << "Error: Could not open Appointments.txt" << endl;
//		return;
//	}
//
//	// Count records first
//	int totalRecords = 0;
//	string Fetched_Record;
//	while (getline(rAppointments, Fetched_Record)) {
//		if (!Fetched_Record.empty()) totalRecords++;
//	}
//	rAppointments.close();
//
//	if (totalRecords == 0) {
//		cout << "No appointments found in the file.\n";
//		return;
//	}
//
//	// Allocate dynamically
//	/*bookings* appointments = new bookings[totalRecords];*/
//
//	// Parse into array
//	rAppointments.open("Appointments.txt");
//	int index = 0;
//	while (getline(rAppointments, Fetched_Record)) 
//	{
//		if (Fetched_Record.empty()) continue;
//		parseAppointmentRecord(Fetched_Record, appointments[index++], hourlyTimeSlots, experts, services_available);
//	}
//	rAppointments.close();
//
//	// Display for logged-in user
//	cout << "\n===== Your Appointments =====\n";
//	int recordCount = 0;
//	for (int i = 0; i < totalRecords; i++)
//	{
//		if (appointments[i].book_byCustomer == loggedIn_customerUser.userID) {
//			recordCount++;
//			cout << "Appointment #" << recordCount << "\n";
//			cout << " Date (Day): " << appointments[i].booking_date << "\n";
//			cout << " Time: " << fixed << setprecision(2)
//				<< appointments[i].timeslot->hours_start << " - " << appointments[i].timeslot->hours_end << "\n";
//			cout << " Expert: " << appointments[i].expert_booked->username << "\n";
//			cout << " Service: " << appointments[i].service_booked->service_name
//				<< " ($" << appointments[i].service_booked->servicePrice << ")\n";
//			cout << " Status: " << (appointments[i].booking_status ? "Confirmed" : "Pending") << "\n";
//			cout << "-----------------------------\n";
//		}
//	}
//
//	if (recordCount == 0) {
//		cout << "No appointments found for you.\n";
//	}
//
//	delete[] appointments; // cleanup
//}
bool parseAppointmentRecord(const string& Fetched_Record, bookings& appointment, 
	timeSlots* hourlyTimeSlots, users* experts, services* services_available)
{
	size_t start = Fetched_Record.find('{');
	size_t end = Fetched_Record.find('}');
	if (start == string::npos || end == string::npos) return false;

	string inside = Fetched_Record.substr(start + 1, end - start - 1);
	stringstream ss(inside);

	string temp;

	// timeslot index
	getline(ss, temp, ',');
	size_t pos = temp.find('[');
	size_t pos2 = temp.find(']');
	int timeslotIndex = stoi(temp.substr(pos + 1, pos2 - pos - 1));

	// booking_status
	getline(ss, temp, ',');
	appointment.booking_status = (temp.find("true") != string::npos);

	// booking_date
	getline(ss, temp, ',');
	appointment.booking_date = stoi(temp);

	// bookedBy customer
	getline(ss, temp, ',');
	appointment.book_byCustomer = stoi(temp);

	// expert index
	getline(ss, temp, ',');
	pos = temp.find('[');
	pos2 = temp.find(']');
	int expertIndex = stoi(temp.substr(pos + 1, pos2 - pos - 1));

	// service index
	getline(ss, temp, ',');
	pos = temp.find('[');
	pos2 = temp.find(']');
	int serviceIndex = stoi(temp.substr(pos + 1, pos2 - pos - 1));

	// assign pointers directly
	appointment.timeslot = &hourlyTimeSlots[timeslotIndex];
	appointment.expert_booked = &experts[expertIndex];
	appointment.service_booked = &services_available[serviceIndex];

	return true;
}
int loadAppointments(bookings* appointments, int totalRecords, 
	timeSlots* hourlyTimeSlots, users* experts, services* services_available)
{
	ifstream rAppointments("Appointments.txt");
	if (!rAppointments.is_open()) {
		cout << "Error: Could not open file!" << endl;
		return 0;
	}

	string Fetched_Record;
	int index = 0;

	while (getline(rAppointments, Fetched_Record) && index < totalRecords) {
		if (Fetched_Record.empty()) continue;
		parseAppointmentRecord(Fetched_Record, appointments[index++], hourlyTimeSlots, experts, services_available);
	}

	rAppointments.close();
	return index; // number of records successfully loaded
}
int countAppointmentsInFile() 
{
	ifstream rAppointments("Appointments.txt");
	if (!rAppointments.is_open()) 
	{
		cout << "Error: Could not open file!" << endl;
		return 1;
	}

	string Fetched_Record;
	int count = 0;
	while (getline(rAppointments, Fetched_Record))
		if (!Fetched_Record.empty()) count++;
	rAppointments.close();
	return count;
}
void viewUserAppointments(users loggedIn_customerUser, bookings* appointments, int totalRecords) 
{
    cout << "\n===== Your Appointments =====\n";

    cout << left << setw(12) << "No."
         << setw(12) << "Date"
         << setw(15) << "Time"
         << setw(15) << "Expert"
         << setw(25) << "Service"
         << setw(12) << "Status" << "\n";

    cout << string(91, '-') << endl;

    int recordCount = 0;

    for (int i = 0; i < totalRecords; i++) {
        if (appointments[i].book_byCustomer == loggedIn_customerUser.userID) {
            recordCount++;

            stringstream timeStr;
            timeStr << fixed << setprecision(2)
                    << appointments[i].timeslot->hours_start
                    << "-" << appointments[i].timeslot->hours_end;

            cout << left << setw(12) << recordCount
                 << setw(12) << appointments[i].booking_date
                 << setw(15) << timeStr.str()
                 << setw(15) << appointments[i].expert_booked->username
                 << setw(25) << appointments[i].service_booked->service_name
                 << "\n";
        }
    }

	if (recordCount == 0) {
		cout << "No appointments found for you.\n";
	}
}
void writetoAppointmentRecords(bookings newAppointment,
	timeSlots hourly_timeSlots[], users experts[], services services_available[])
{
	ofstream wAppointments("Appointments.txt", ios::app);
	if (!wAppointments.is_open()) {
		cout << "Error: Could not open Appointments.txt for writing!" << endl;
		return;
	}

	// Write appointment in a structured format
	wAppointments << "{"
		<< "[ " << (newAppointment.timeslot - hourly_timeSlots) << " ], " // store timeslot index
		<< (newAppointment.booking_status ? "true" : "false") << ", "
		<< newAppointment.booking_date << ", "
		<< newAppointment.book_byCustomer << ", "
		<< "[ " << (newAppointment.expert_booked - experts) << " ], "     // store expert index
		<< "[ " << (newAppointment.service_booked - services_available) << " ]"
		<< "}" << endl;

	wAppointments.close();
}
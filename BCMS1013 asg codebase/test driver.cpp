#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#define NOMINMAX
#include<windows.h>
#include<fstream>
#include<sstream>
#include<cctype>
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
};
struct timeSlots {
	int timeslotID; // dis is gon correspond to the number
	double hours_start; //24 hours time format
	double hours_end; //24 hours time format
};
struct bookings {
	timeSlots* timeslot;
	bool booking_status = 0;
	int booking_date; //have sum control structures for telling customer user to input valid date of booking this
	int customerID;
	int expertID;
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
bool parseUserRecord(const string& Fetched_Record, users& loggedin_customerUser);

int main()
{
	services services_available[4] = {
		{1, "Haircuts & Trims", 3, 70.00},
		{2, "Bread Grooming", 3, 100.00},
		{3, "Facial Skin Care", 3, 120.00},
		{4, "Massage Therapy", 3, 200.00}
	}; services* P_services_available = services_available;
	timeSlots hourly_timeSlots[] = {
		{1, 12.00, 15.00},
		{2, 14.00, 17.00},
		{3, 16.00, 19.00},
		{4, 18.00, 21.00},
		{5, 21.00, 0.00},
		{6, 22.00, 1.00}
	}; timeSlots* P_hourlyTimeSlots = hourly_timeSlots;
	int totalCustomers = 0, totalExperts = 0, totalBookings = 0, 
		numberofServices = sizeof(services_available) / sizeof(services_available)[0],
		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0], 
		choice[] = { 0, 0, 0, 0 }, varyingsize[] = { 0, 0 },
		numberedlist = 1, * P_numberedlist = &numberedlist;
	
	users* customer_users = new users[totalCustomers];
	users* experts = new users[totalExperts];
	users loggedIn_customerUser;
	bookings* appointments_schedules = new bookings[totalBookings];
	
	string Fetched_Record;
	bool found = false, loginStatus = 0;

	char yesno = ' ';
	string loginCredential = " ", password = " ";

	ifstream inFile("User records.txt");
	if (!inFile) {
		cerr << "Error: Could not open file!" << endl;
		return 1;
	}

	cout << "Enter username or email: ";
	getline(cin, loginCredential);
	cout << loginCredential << endl;
	
	string capitalizedCredential = loginCredential;
	for (size_t i = 0; i < capitalizedCredential.length(); i++) {
		capitalizedCredential[i] = toupper((unsigned char)loginCredential[i]);
	}
	cout << capitalizedCredential << endl;
	
	while (getline(inFile, Fetched_Record)) 
	{
		string capitalizedFetchedRecord = Fetched_Record;
		for (size_t i = 0; i < Fetched_Record.length(); ++i) {
			capitalizedFetchedRecord[i] = toupper((unsigned char)capitalizedFetchedRecord[i]);
		}		
		cout << capitalizedFetchedRecord << endl;
			// comparison of the credential
		if (capitalizedFetchedRecord.find(capitalizedCredential) != string::npos) 
		{			
			if (parseUserRecord(Fetched_Record, loggedIn_customerUser)) 
			{
				found = true;
				break; // stop after first match
			}
		}
	}
	inFile.close();
	
	if (found)
	{
		parseUserRecord(Fetched_Record, loggedIn_customerUser);
		cout << "Found user:\n";
		cout << loggedIn_customerUser.userID << " | "
			<< loggedIn_customerUser.username << " | "
			<< loggedIn_customerUser.age << " | "
			<< loggedIn_customerUser.gender << " | "
			<< loggedIn_customerUser.user_email << " | "
			<< loggedIn_customerUser.user_password << " | "
			<< (loggedIn_customerUser.user_Type == customer ? "Customer" : "Expert")
			<< endl;
	}
	else
		cout << "\nNo such username or email found." << endl;
	
	// loop over the cstring password, it has to match by case letter, symbols, everything
	while (true) 
	{
		cout << "\nEnter password: ";
		getline(cin, password);
		if (password != loggedIn_customerUser.user_password)
		{
			cout << "\nWrong password.\n1. Try again?\n2. Exit to main menu\n : ";
			
			*P_numberedlist = 3;
			choice[0] = getInput(P_numberedlist);
			*P_numberedlist = 1;
		
			if (choice[0] == 1)
				continue;
			else if(choice[0] == 2)
				break;
		}
		else 
		{
			cout << "\nLogged in!\nWelcome " << loggedIn_customerUser.username << "!";
			break;
		}
		// boolean to break to main menu
	}

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
bool parseUserRecord(const string& Fetched_Record, users& loggedin_customerUser) 
{
	size_t start = Fetched_Record.find('{');
	size_t end = Fetched_Record.find('}');
	if (start == string::npos || end == string::npos) return false;

	string inside = Fetched_Record.substr(start + 1, end - start - 1);
	stringstream ss(inside);
	cout << ss.str() << '\n';
	string temp;

	// userID
	ss >> loggedin_customerUser.userID;
	ss.ignore(2);

	// username
	getline(ss, loggedin_customerUser.username, ',');
	if (!loggedin_customerUser.username.empty() && loggedin_customerUser.username.front() == '"')
		loggedin_customerUser.username = loggedin_customerUser.username.substr(1, loggedin_customerUser.username.size() - 2);

	// age
	ss >> loggedin_customerUser.age;
	ss.ignore(3); 

	// gender
	ss >> loggedin_customerUser.gender;
	ss.ignore(2);

	// email
	getline(ss, loggedin_customerUser.user_email, ',');
	if (!loggedin_customerUser.user_email.empty() && loggedin_customerUser.user_email.front() == '"')
		loggedin_customerUser.user_email = loggedin_customerUser.user_email.substr(1, loggedin_customerUser.user_email.size() - 2);

	// password
	ss.ignore(1);
	getline(ss, loggedin_customerUser.user_password, ',');
	if (!loggedin_customerUser.user_password.empty() && loggedin_customerUser.user_password.front() == '"')
		loggedin_customerUser.user_password = loggedin_customerUser.user_password.substr(1, loggedin_customerUser.user_password.size() - 2);

	// user type
	ss >> temp;
	loggedin_customerUser.user_Type = (temp.find("customer") != string::npos) ? customer : expert;

	return true;
}
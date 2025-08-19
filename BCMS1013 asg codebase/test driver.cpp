#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#define NOMINMAX
#include<windows.h>
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
bool payment(int* choice, int* numberedlist, services services_available[], users experts[], users customers[]);

int main()
{
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
	int numberofServices = sizeof(services_available) / sizeof(services_available)[0],
		numberofExperts = sizeof(experts) / sizeof(experts)[0],
		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0], 
		numberedlist = 1, * P_numberedlist = &numberedlist, choice = 0;
	char yesno = ' ';
	
	while (true)
	{
		if (payment(&choice, &numberedlist, services_available, experts, customer_users)) 
		{
			cout << "\n\nAppointment booked !";
			break;
		}
		else {
			cout << "\n\nPayment failed.";
			while (true) 
			{
				cout << "\nTry again? (Y = Yes | N = No) : ";
				cin >> yesno;
				//system("CLS"); // system cls clear the whole terminal tho, later it clears ur entire cust menus

				if (cin.peek() != '\n') // Peek next character to check if user typed more
				{ 
					cout << "Invalid input. Only one character allowed.\n";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				if (toupper(yesno) == 'Y' || toupper(yesno) == 'N')   // type check 
				{													//& char value check
					cout << endl << endl;		
					break;
				}
				cout << "Invalid input. Please enter 'Y' or 'N'.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (toupper(yesno) == 'Y')
				continue;
			else if (toupper(yesno) == 'N')
				break;
		}
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
bool payment(int* choice, int* numberedlist, services services_available[], users experts[], users customers[])
{
	//payment module
	//display & input prompts, fake the credentials
	string multiusestring, Banks[] = { "Ambank", "HongLeong Bank", "Public Bank", "Maybank", "Alliance Bank" };
	LPCWSTR url = L"https://i.pinimg.com/736x/b7/c7/10/b7c71079775659e3f1413213706e6b0b.jpg";

	//cout << "------------------ Payment ------------------ \n"
	//	<< "Customer name : " << setw(20) << customers[1].username << endl
	//	<< "Selected package : " << services_available[*choice - 1].service_name << endl
	//	<< "Service Charge : RM" << experts[*choice - 1].serviceCharge << endl
	//	<< "Base Price : RM" << services_available[*choice - 1].servicePrice << endl
	//	<< "----------------------------------------------- ";
	cout << "Available payment method\n----------------------------------\n"
		<< "[1] Credit Card\n[2] Online Banking\n[3] E-Wallet\n[4] Cancel Payment\n"
		<< "\nEnter your choice : ";
	*numberedlist = 5;
	*choice = getInput(numberedlist);
	*numberedlist = 1;

	switch (*choice) {
	case 1:
		cout << "Enter Cardholder Name : ";
		getline(cin, multiusestring);
		
		cout << "\nEnter Card Number (16 digits) : ";
		getline(cin, multiusestring);
		//auto enter space after each 4 digits
		while (multiusestring.length() < 16) { // format check
			cout << "Enter valid format !!!\nEnter Card Number (16 digits) : ";
			cin >> multiusestring;
		}

		while (true) 
		{
			bool gotAlphabet = 0;
			cout << "\nEnter Expiry Date (MM/YY) : ";
			getline(cin, multiusestring);
			if (multiusestring.empty())
			{
				cout << "\nInput empty, please provide input.";
				continue;
			}
			if (multiusestring.length() != 5 || multiusestring[2] != '/') {
				cout << "\nInvalid format! More than 5 characters & no frontslash to separate the month & year. ";
				continue;
			}
			else for (int i = 0; i < multiusestring.length(); ++i) {
				if (i == 2) continue;
				if (!isdigit(multiusestring[i]))
					gotAlphabet = 1;
			}
			if (gotAlphabet)
			{
				cout << "\nInvalid format! Contains alphabets, please try again. ";
				continue;
			}
			int month = (multiusestring[0] - '0') * 10 + (multiusestring[1] - '0');
			if (month < 1 || month > 12)
			{
				cout << "\nMonth out of range! Please try again.";
				continue;
			}
			break;
		}

		cout << "\n\nProcessing payment...";
		cout << "\nPayment successful!";

		return true;
		break;
	case 2:
		cout << "\nSelect a bank\n-----------------------\n";
		for (int i = 0; i < sizeof(Banks) / sizeof(Banks)[0]; ++i)
		{
			cout << *numberedlist << ". " << Banks[i] << endl;
			++*numberedlist;
		}
		cout << ": ";
		*choice = getInput(numberedlist);
		*numberedlist = 1;
		
		while (true)
		{
			cout << "\nEnter your username : ";
			getline(cin, multiusestring);
			if (multiusestring.empty()) 
			{
				cout << "\nInput is empty, please provide input.";
				continue;
			}
			break;
		}
		while (true)
		{
			cout << "\nEnter your password : ";
			getline(cin, multiusestring);
			if (multiusestring.empty()) 
			{
				cout << "\nInput is empty, please provide input.";
				continue;
			}
			break;
		}
		cout << "\nAuthorization request sent to the bank app, approve the authorization...";
		while (true) 
		{
			cout << "\napproved?... (Y = Yes | N = No) : ";
			getline(cin, multiusestring);
			
			if (multiusestring.empty()) 
			{
				cout << "\nInput is empty, please provide input.";
				continue;
			}
			if (multiusestring.length() > 1 || isAlphabet(multiusestring.c_str()) == false
				/*|| isNumeric(multiusestring.c_str()) == true*/) 
			{
				cout << "\nInvalid. Yes or No? (Y = Yes | N = No) : ";
				continue;
			}
			if ( toupper(multiusestring[0]) == 'Y' )
			{
				cout << "\nProcessing payment...";
				cout << "\nPayment successful!";
				break;
			} 
			else if ( toupper(multiusestring[0]) == 'N' ) 
			{
				cout << "\nResent authorization? (Y = Yes | N = No) : ";
				getline(cin, multiusestring);

				if (toupper(multiusestring[0]) == 'Y')
					continue;
				else if (toupper(multiusestring[0]) == 'N')
				{	cout << "Authorization failed !! Please try again.";
					return false;
					break;
				}
			}
			else {
				cout << "\nInvalid, y or n for yes or no only.";
				continue;
			}
		}
		return true;
		break;
	case 3:
		cout << "Scan the QR below : ";
		ShellExecute(0, L"open", url, 0, 0, SW_SHOWNORMAL);
		cout << "\n\nProcessing payment...";
		cout << "\nPayment successful!";
		return true;
		break;
	case 4:
		cout << "Payment cancelled";
		return false;
	}
	return true;
}
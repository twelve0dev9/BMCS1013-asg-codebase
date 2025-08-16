#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
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
	int numberofServices = sizeof(services_available) / sizeof(services_available)[0], 
		numberofExperts = sizeof(experts) / sizeof(experts)[0], 
		numberedlist = 1, * P_numberedlist = &numberedlist, 
		choice = 0;

	cout << "Pick one services : \n" << "------------------------------\n";
	for (int i = 0; i < numberofServices; ++i)
	{
		// list the number of services available
		cout << *P_numberedlist << ". " << services_available[i].service_name << endl;
		++*P_numberedlist;
	}
	cout << endl;
	choice = getInput(P_numberedlist);
	*P_numberedlist = 1;
	cout << "\nOur experts that provides " << services_available[choice - 1].service_name << ": \n";
	for (int i = 0; i < numberofExperts; ++i)
	{
		// display of experts accordingly in a *P_numbered list based-on matching specialization w\ the services customer has chosen
		if ((experts[i].specialization[0] && experts[i].specialization[0]->serviceID == choice) ||
			(experts[i].specialization[1] && experts[i].specialization[1]->serviceID == choice)) // since our the experts' specialization member is an array of pointers, we check the 1st & the 2nd pointer points to corresponding services or not
		{
			cout << *P_numberedlist << ". " << experts[i].username << endl;
			++*P_numberedlist;
		}
	}
	cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
	choice = getInput(P_numberedlist);
	*P_numberedlist = 1;
	cout << endl << choice;

	return 0;
}
int getInput(int* P_numberedlist) 
{
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
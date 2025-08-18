//#include<iostream>
//#include<iomanip>
//#include<string>
//#include<cstdlib>
//using namespace std;
//
//enum UserType { admin, expert, customer };
//struct services {
//	int serviceID = 0;
//	string service_name = " ";
//	float serviceTime = 0.00; //unit is Hours
//	double servicePrice = 0.00;
//};
//struct users {
//	//the users records might put under sum kind of function 
//	//no point in importing the user records from the file globally when not in use
//	int userID = 0;
//	string username = " ";
//	int age = 0;
//	char gender = ' ';
//	string user_email = " ";
//	string user_password = " ";
//	UserType user_Type;
//	services* specialization[2];
//	double serviceCharge = 0.00;
//};
//struct timeSlots {
//	int timeslotID; // dis is gon correspond to the number
//	double hours_start; //24 hours time format
//	double hours_end; //24 hours time format
//};
//
//bool isAlphabet(const char* stringVar) // to check if the input is Alphabet or not
//{
//	for (int i = 0; stringVar[i] != '\0'; ++i)	{
//		if (!isalpha(stringVar[i]))
//			return false;}
//	return true;
//}
//bool isAlphaNum(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
//{
//	for (int i = 0; stringVar[i] != '\0'; ++i) {
//		if (!isalnum(stringVar[i]))
//	 		return false;}
//	return true;
//}
//bool isNumeric(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
//{
//	for (int i = 0; stringVar[i] != '\0'; ++i) {
//		if (!isdigit(stringVar[i]))
//	 		return false;}
//	return true;
//}
//int getInput(int* P_numberedlist);
//void bookAppointment(int* numberofTimeSlots, int* P_numberedlist, int* choice,
//	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[]);
//int main()
//{
//	services services_available[4] = {
//		{1, "Haircuts & Trims", 3, 70.00},
//		{2, "Bread Grooming", 3, 100.00},
//		{3, "Facial Skin Care", 3, 120.00},
//		{4, "Massage Therapy", 3, 200.00}
//	}; services* P_services_available = services_available;
//	users experts[] = {
//		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}, 100.00},
//		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}, 200.00},
//		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}, 250.00},
//		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}, 70.00},
//		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}, 200.00}
//	}; users* P_experts = experts;
//	users customer_users[] = {
//		{4, "Blaze", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", customer},
//		{5, "Thomas", 16, 'M', "thomaswayne@gmail.com", "utc4kt6d8vcuj", customer},
//		{6, "Bruce Wayne", 16, 'M', "brucewayne@gmail.com", "kyu6fv485k7f8tyu6+", customer},
//		{8, "Tommy", 16, 'M', "peakblinders4peak@gmail.com", "68kdcty786yuf", customer},
//		{9, "Jeremy", 16, 'M', "whostheboss@gmail.com", "yuf1h23vjk78y9i", customer},
//		{56, "Jeremiah", 16, 'M', "justanothercopy@gmail.com", "qwet786xfgh534", customer},
//		{12, "Harley", 16, 'F', "harleyquinnsucktbh@gmail.com", "ub78i6312ic6gh78k", customer},
//		{7, "Ashton Hall", 16, 'M', "ashtonhallunclosetoishowmeeat@gmail.com", "45pgyuijbk73po5ui", customer},
//		{5, "iShoeSpeed", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
//	}; users* P_customers = customer_users;
//	timeSlots hourly_timeSlots[] = {
//		{1, 12.00, 15.00},
//		{2, 14.00, 17.00},
//		{3, 16.00, 19.00},
//		{4, 18.00, 21.00},
//		{5, 21.00, 0.00},
//		{6, 22.00, 1.00}
//	}; timeSlots* P_hourlyTimeSlots = hourly_timeSlots;
//	int numberofServices = sizeof(services_available) / sizeof(services_available)[0],
//		numberofExperts = sizeof(experts) / sizeof(experts)[0],
//		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0], 
//		numberedlist = 1, * P_numberedlist = &numberedlist, 
//		choice = 0;
//
//	cout << "\nOur available services\n------------------------------\n";
//	for (int i = 0; i < numberofServices; ++i)
//	{
//		// list the number of services available
//		cout << *P_numberedlist << ". " << services_available[i].service_name << endl;
//		++*P_numberedlist;
//	}
//	cout << "\nPick one services (1 - " << *P_numberedlist - 1<< ") : ";
//	choice = getInput(P_numberedlist);
//	*P_numberedlist = 1;
//	cout << "\nOur experts that provides " << services_available[choice - 1].service_name << ": \n";
//	for (int i = 0; i < numberofExperts; ++i)
//	{
//		// display of experts accordingly in a *P_numbered list based-on matching specialization w\ the services customer has chosen
//		if ((experts[i].specialization[0] && experts[i].specialization[0]->serviceID == choice) ||
//			(experts[i].specialization[1] && experts[i].specialization[1]->serviceID == choice)) // since our the experts' specialization member is an array of pointers, we check the 1st & the 2nd pointer points to corresponding services or not
//		{
//			cout << *P_numberedlist << ". " << experts[i].username << endl;
//			++*P_numberedlist;
//		}
//	}
//	cout << "\nWhat experts would you like to book an appointment with ? (1 - " << *P_numberedlist - 1 << ") : ";
//	choice = getInput(P_numberedlist);
//	*P_numberedlist = 1;
//	bookAppointment(&numberofTimeSlots, P_numberedlist, &choice, services_available, experts, customer_users, hourly_timeSlots);
//	cout << endl << choice << endl << endl;
//
//	return 0;
//}
//
//
//int getInput(int* P_numberedlist) 
//{
//	string input;
//	while (true) {
//		getline(cin, input);
//		// check contains alphabet or not
//		if (isAlphabet(input.c_str()) == true) {
//			cout << "\n\033[93mInvalid input. Input contains letters, please enter option 1 - " << *P_numberedlist - 1 << " only : \033[0m";
//			continue;
//		}
//		// check for invalid symbols
//		if (isNumeric(input.c_str()) == false) {
//			cout << "\n\033[31mInvalid input. Input contains symbols, or alphanumeric, please enter option 1 - " << *P_numberedlist - 1 << " only : \033[0m";
//			continue;
//		}
//		// check if input is empty 
//		if (input.empty()) {
//			cout << "\n\033[101;30mInput is empty, please provide option 1 - " << *P_numberedlist - 1 << " : \033[0m";
//			continue;
//		}
//		char* endPtr;
//		long long value = strtoll(input.c_str(), &endPtr, 10);
//		// check if the parsed string is all int
//		// check for overflow (out of range) issue
//		if (value < numeric_limits<int>::min() || value > numeric_limits<int>::max()) {
//			cout << "\n\033[31mOverflow, input too large for integer, bruh only 1 to " << *P_numberedlist - 1 << " : \033[0m";
//			continue;
//		}
//
//		if (value < 1 || value > *P_numberedlist - 1) {
//			cout << "\n\033[96mInvalid range, only option between 1 and " << *P_numberedlist - 1 << " : \033[0m";
//			continue;
//		}
//		return static_cast<int>(value);
//	}
//}
//void bookAppointment(int* numberofTimeSlots, int* P_numberedlist, int* choice,
//	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[])
//{
//	int book_Date = 0; char makepayment = ' ';
//	*P_numberedlist = 32;
//	cout << "\nPick the day you'd like to book (1 - " << *P_numberedlist - 1 << ") : ";
//	book_Date = getInput(P_numberedlist);
//	cout << "\nTimeslots available at " << book_Date << "th : \n----------------------------------------\n";
//	*P_numberedlist = 1;
//	for (int i = 0; i < *numberofTimeSlots; ++i)
//	{
//		cout << *P_numberedlist << ". " << fixed << setprecision(2) 
//			<< setw(5) << setfill('0') << hourly_timeSlots[i].hours_start 
//			<< "--" << setw(5) << setfill('0') << hourly_timeSlots[i].hours_end << endl;
//		++*P_numberedlist;
//	}
//	cout << "\n	Pick your time slots for the day (1 - " << *P_numberedlist - 1 << ") : ";
//	*choice = getInput(P_numberedlist);
//	*P_numberedlist = 1;
//}
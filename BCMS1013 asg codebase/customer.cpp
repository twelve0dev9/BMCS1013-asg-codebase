//#define NOMINMAX
//#include<iostream>
//#include<iomanip>
//#include<string>
//#include<cstdlib>
//#include<cstring>
//#include<cctype>
//#include<sstream>
//#include<array>
//#include<Windows.h>
//#include<fstream>
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
//}; //we might need to divide the users struct into more nested struct, considering need to do sum manipulation w\ the emails,passwords, names, etc. If member access & pointers makes it difficult to access for modification
//struct timeSlots {
//	int timeslotID; // dis is gon correspond to the number
//	double hours_start; //24 hours time format
//	double hours_end; //24 hours time format
//};
//struct bookings {
//	timeSlots* timeslot;
//	bool booking_status = 0;
//	int booking_date; //have sum control structures for telling customer user to input valid date of booking this
//	int book_byCustomer;
//	users* expert_booked;
//	services* service_booked;
//};
//
//void main_menu(int choice[], int* P_numberedlist);
//bool isAlphabet(const char* stringVar);
//bool isNumeric(const char* stringVar);
//int getInput(int* P_numberedlist);
//bool customerFunctionalities(int choice[], int* P_numberedlist, bool* exitStatus, 
//	int* numberofAppointments, int* numberofExperts, int* numberofServices, int* numberofTimeSlots,
//	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[], bookings appointments_schedule[]);
//int custcreateacc(int* P_numberedlist, string loginCredential, string password, users newCustomerUser);
//bool custlogin(users* loggedIn_customerUser, string loginCredential, string password, 
//	int* P_numberedlist, int choice[]);
//bool parseUserRecord(const string& Fetched_Record, users& loggedIn_customerUser);
//void viewServices(int* numberofServices, int* P_numberedlist, services services_available[],
//	users experts[], int *numberofExperts);
//void viewExperts(int choice[], int* numberofExperts, int* P_numberedlist, int* filternumlist, int filteredIndices[], users experts[], services services_available[]);
//void viewAvailable_days(int choice[], int filteredIndices[], services services_available[],
//	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings);
//void bookAppointment(int* numberofTimeSlots, int* numberofAppointments, int* P_numberedlist, int choice[],
//	int filteredIndices[], services services_available[], users experts[], users customers[], users loggedIn_customerUser,
//	timeSlots hourly_timeSlots[], bookings appointments_schedule[]);
//bool payment(int choice[], int* numberedlist, services services_available[], users experts[], users customers[], users loggedIn_customerUser);
//void viewbookedSchedule(int* numberofAppointments, bookings appointments_schedule[], timeSlots* hourly_timeSlots,
//	users loggedIn_customerUser, users* experts, services* services_available);
//int countAppointmentsInFile();
//int loadAppointments(bookings* appointments, int totalRecords,
//	timeSlots* hourly_timeSlots, users* experts, services* services_available);
//void viewUserAppointments(users loggedIn_customerUser, bookings* appointments, int totalRecords);
//bool parseAppointmentRecord(const string& Fetched_Record, bookings& appointment, 
//	timeSlots* hourly_timeSlots, users* experts, services* services_available);
//void writetoAppointmentRecords(bookings newAppointment,
//	timeSlots hourly_timeSlots[], users experts[], services services_available[]);
//
//
//int main() {
//	services services_available[4] = {
//		{1, "Haircuts & Trims", 3, 70.00},
//		{2, "Beard Grooming", 3, 100.00},
//		{3, "Facial Skin Care", 3, 120.00},
//		{4, "Massage Therapy", 3, 200.00}
//	}; services* P_services_available = services_available;
//	users experts[] = {
//		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}, 200.00},
//		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}, 250.00},
//		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}, 100.00},
//		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}, 70.00},
//		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}, 200.00}
//	}; users* P_experts = experts;
//	users customer_users[] = {
//		{1, "Blaze", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", customer},
//		{2, "Thomas", 16, 'M', "thomaswayne@gmail.com", "utc4kt6d8vcuj", customer},
//		{3, "Bruce Wayne", 16, 'M', "brucewayne@gmail.com", "kyu6fv485k7f8tyu6+", customer},
//		{4, "Tommy", 16, 'M', "peakblinders4peak@gmail.com", "68kdcty786yuf", customer},
//		{5, "Jeremy", 16, 'M', "whostheboss@gmail.com", "yuf1h23vjk78y9i", customer},
//		{6, "Jeremiah", 16, 'M', "justanothercopy@gmail.com", "qwet786xfgh534", customer},
//		{7, "Harley", 16, 'F', "harleyquinnsucktbh@gmail.com", "ub78i6312ic6gh78k", customer},
//		{8, "Ashton Hall", 16, 'M', "ashtonhallunclosetoishowmeeat@gmail.com", "45pgyuijbk73po5ui", customer},
//		{9, "iShoeSpeed", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
//	}; users* P_customers = customer_users;
//	timeSlots hourly_timeSlots[] = {
//		{1, 12.00, 15.00},
//		{2, 14.00, 17.00},
//		{3, 16.00, 19.00},
//		{4, 18.00, 21.00},
//		{5, 21.00, 0.00},
//		{6, 22.00, 1.00}
//	}; timeSlots* P_hourly_timeSlots = hourly_timeSlots;
//	bookings appointments_schedule[] = {
//		{&hourly_timeSlots[0], true, 18, 3, &experts[2], &services_available[0]},
//		{&hourly_timeSlots[1], true, 18, 3, &experts[2], &services_available[0]},
//		{&hourly_timeSlots[2], true, 18, 1, &experts[2], &services_available[3]},
//		{&hourly_timeSlots[3], true, 18, 3, &experts[2], &services_available[0]},
//		{&hourly_timeSlots[4], true, 18, 8, &experts[2], &services_available[3]},
//		{&hourly_timeSlots[5], true, 18, 9, &experts[2], &services_available[3]},
//		{&hourly_timeSlots[2], true, 18, 7, &experts[2], &services_available[3]},
//		{&hourly_timeSlots[2], true, 5, 4, &experts[2], &services_available[0]},
//		{&hourly_timeSlots[1], true, 29, 2, &experts[2], &services_available[1]},
//		{&hourly_timeSlots[1], true, 12, 2, &experts[2], &services_available[2]}
//	}; bookings* P_appointments_schedule = appointments_schedule;
//	int choice[] = { 0, 0, 0, 0 }, numberedlist = 1,
//// index 0 for general menu | index 1 for service chosen | index 2 for expert chosen | index 3 for timeSlots chosen
//// array's number of elements/records | used in control structures that need to iterate thru our sample records
//		numberofAppointments = sizeof(appointments_schedule) / sizeof(appointments_schedule)[0],
//		numberofExperts = sizeof(experts) / sizeof(experts)[0],
//		numberofServices = sizeof(services_available) / sizeof(services_available)[0],
//		numberofTimeSlots = sizeof(hourly_timeSlots) / sizeof(hourly_timeSlots)[0];
//	bool exitStatus = 0;
//
//	do {
//		main_menu(choice, &numberedlist);
//		switch (choice[0]) {
//		case 1:
//			do {
//				exitStatus = customerFunctionalities(choice, &numberedlist, &exitStatus,
//					&numberofAppointments, &numberofExperts, &numberofServices, &numberofTimeSlots,
//					services_available, experts, customer_users, hourly_timeSlots, appointments_schedule);
//			} while (exitStatus == 0); // keep on looping dis as long as exitStatus is still 0, which my cust function will return 1 as true, after breaking the selection structures in there
//			break;
//		case 2:
//			//admin_login();
//			break;
//		case 3:
//			//expert_login();
//			break;
//		case 4:
//			cout << "\n\n=== PROGRAM END ===\n\n";
//			break;
//		}
//	} while (choice[0] != 4);
//	return 0;
//}
//void main_menu(int choice[], int* P_numberedlist)
//{
//	cout << "     MAIN MENU      " << endl;
//	cout << "--------------------" << endl;
//	cout << "Select Login: " << endl;
//	cout << "1. Customer Login" << endl;
//	cout << "2. Administrator Login" << endl;
//	cout << "3. Expert Login" << endl;
//	cout << "4. Exit Program" << endl;
//	cout << "-------------------" << endl;
//	cout << ">";
//	*P_numberedlist = 5;
//	choice[0] = getInput(P_numberedlist);
//	*P_numberedlist = 1;
//}
//bool customerFunctionalities(int choice[], int* P_numberedlist, bool* exitStatus, 
//	int* numberofAppointments, int* numberofExperts, int* numberofServices, int* numberofTimeSlots,
//	services services_available[], users experts[], users customers[], timeSlots hourly_timeSlots[], bookings appointments_schedule[])
//{
//	int filternumlist = 0, filteredIndices[10];
//	cout << setw(35) << 
//		R"(
//$$\      $$\                     $$\                 $$\        $$$$$$\   $$$$$$\  $$\   $$\ $$\      $$\  $$$$$$\  $$\   $$\ $$\   $$\ $$$$$$\ $$\   $$\        $$$$$$\                      
//$$$\    $$$ |                    $  |                $$ |      $$  __$$\ $$  __$$\ $$ | $$  |$$$\    $$$ |$$  __$$\ $$ |  $$ |$$ |  $$ |\_$$  _|$$$\  $$ |      $$  __$$\                     
//$$$$\  $$$$ | $$$$$$\  $$$$$$$\  \_/  $$$$$$$\       $$ |      $$ /  $$ |$$ /  $$ |$$ |$$  / $$$$\  $$$$ |$$ /  $$ |\$$\ $$  |\$$\ $$  |  $$ |  $$$$\ $$ |      $$ /  \__| $$$$$$\   $$$$$$\  
//$$\$$\$$ $$ |$$  __$$\ $$  __$$\     $$  _____|      $$ |      $$ |  $$ |$$ |  $$ |$$$$$  /  $$\$$\$$ $$ |$$$$$$$$ | \$$$$  /  \$$$$  /   $$ |  $$ $$\$$ |      \$$$$$$\  $$  __$$\  \____$$\ 
//$$ \$$$  $$ |$$$$$$$$ |$$ |  $$ |    \$$$$$$\        $$ |      $$ |  $$ |$$ |  $$ |$$  $$<   $$ \$$$  $$ |$$  __$$ | $$  $$<   $$  $$<    $$ |  $$ \$$$$ |       \____$$\ $$ /  $$ | $$$$$$$ |
//$$ |\$  /$$ |$$   ____|$$ |  $$ |     \____$$\       $$ |      $$ |  $$ |$$ |  $$ |$$ |\$$\  $$ |\$  /$$ |$$ |  $$ |$$  /\$$\ $$  /\$$\   $$ |  $$ |\$$$ |      $$\   $$ |$$ |  $$ |$$  __$$ |
//$$ | \_/ $$ |\$$$$$$$\ $$ |  $$ |    $$$$$$$  |      $$$$$$$$\  $$$$$$  | $$$$$$  |$$ | \$$\ $$ | \_/ $$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |$$$$$$\ $$ | \$$ |      \$$$$$$  |$$$$$$$  |\$$$$$$$ |
//\__|     \__| \_______|\__|  \__|    \_______/       \________| \______/  \______/ \__|  \__|\__|     \__|\__|  \__|\__|  \__|\__|  \__|\______|\__|  \__|       \______/ $$  ____/  \_______|
//                                                                                                                                                                          $$ |                
//                                                                                                                                                                          $$ |                
//                                                                                                                                                                          \__|                )"
//		<< endl;
//	for (int i = 0; i < 100; ++i)
//		cout << '=';
//	cout << endl << endl;
//	cout << "\033[1mWhere Style Meets Self-Care.\033[0m\n"
//		<< "Welcome to Men's LOOKMAXXIN Spa, as our name suggests, We WILL make you LOOKMAXXING.\n"
//		<< "A premium grooming spa designed exclusively for men who value sharp style, total relaxation, and modern self-care.\n"
//		<< "We offer a full range of services from precision haircuts and classic straight-razor shaves to revitalizing facials, deep tissue massages, and expert beard grooming.\n"
//		<< "Our space blends the sophistication of a gentlemen's club with the tranquility of a day spa, providing a relaxing environment where you can unwind, refresh, and leave feeling your absolute best.\n"
//		<< "Whether you're preparing for a big event, need routine maintenance, or just deserve a break. Our skilled barbers, aestheticians, and therapists are here to elevate your grooming experience.\n"
//		<< "\n\nOperating hours : | 12PM - 1AM\n" << setw(37) << "| Monday--Saturday\n"
//		<< "Contact email : lookmaxxin2day@gmail.com\nContact phone : 03-3788 46567";
//	
//	users loggedIn_customerUser;
//	users newCustomerUser;
//	string loginCredential = " ", password = " ";
//	int custmenuchoice;
//	do {
//		cout << "\n1. Login\n2. Guest\n3. Create an account\n4. Exit to main menu\n\n";
//		*P_numberedlist = 5;
//		custmenuchoice = getInput(P_numberedlist);
//		*P_numberedlist = 1;
//
//		switch (custmenuchoice)
//		{
//		case 1:
//			//compare the credentials with the read records
//			if (custlogin(&loggedIn_customerUser, loginCredential, password, P_numberedlist, choice))
//			{
//				int loggedinchoice;
//				do 
//				{
//					cout << "\nWelcome " << loggedIn_customerUser.username << "!\n" << string(38, '-') << endl;
//					cout << "1. View our services\n2. Book an appointment\n3. View booked appointment\n4. View appointment availability\n5. Back to customer menu\n";
//
//					*P_numberedlist = 6;
//					cout << "\nEnter your choice (1 - " << *P_numberedlist - 1 << ") : ";
//					loggedinchoice = getInput(P_numberedlist);
//					*P_numberedlist = 1;
//
//					switch (loggedinchoice)
//					{
//					case 1:
//						viewServices(numberofServices, P_numberedlist, services_available, experts, numberofExperts);
//						*P_numberedlist = 1;
//						break;
//					case 2:
//
//						viewServices(numberofServices, P_numberedlist, services_available, experts, numberofExperts);
//						cout << "\nPick one services (1 - " << *P_numberedlist - 1 << ") : ";
//
//						choice[1] = getInput(P_numberedlist);
//						*P_numberedlist = 1;
//
//						viewExperts(choice, numberofExperts, P_numberedlist, &filternumlist, filteredIndices, experts, services_available);
//						cout << "\nWhat experts would you like to book an appointment with ? (1 - " << *P_numberedlist - 1 << ") : ";
//						choice[2] = getInput(P_numberedlist);
//						*P_numberedlist = 1;
//
//						viewAvailable_days(choice, filteredIndices, services_available, experts, customers, appointments_schedule, numberofAppointments);
//
//						bookAppointment(numberofTimeSlots, numberofAppointments, P_numberedlist, choice,
//							filteredIndices, services_available, experts, customers, loggedIn_customerUser, hourly_timeSlots, appointments_schedule);
//						cin.ignore();
//
//						break;
//					case 3:
//						viewbookedSchedule(numberofAppointments, appointments_schedule, hourly_timeSlots, loggedIn_customerUser, experts, services_available);
//						break;
//					case 4:
//						viewServices(numberofServices, P_numberedlist, services_available, experts, numberofExperts);
//						cout << "\nPick one services (1 - " << *P_numberedlist - 1 << ") : ";
//
//						choice[1] = getInput(P_numberedlist);
//						*P_numberedlist = 1;
//						viewExperts(choice, numberofExperts, P_numberedlist, &filternumlist, filteredIndices, experts, services_available);
//						cout << "\nWhat experts would you like check for their availability ? (1 - " << *P_numberedlist - 1 << ") : ";
//						choice[2] = getInput(P_numberedlist);
//						*P_numberedlist = 1;
//						
//						viewAvailable_days(choice, filteredIndices, services_available, experts, customers, appointments_schedule, numberofAppointments);
//						break;
//					case 5: // upon exiting to customer main menu, drop the logged in user's data
//						loggedIn_customerUser.userID = 0;
//						loggedIn_customerUser.username = "";
//						loggedIn_customerUser.age = 0;
//						loggedIn_customerUser.gender = ' ';
//						loggedIn_customerUser.user_email = "";
//						loggedIn_customerUser.user_password = "";
//						loggedIn_customerUser.user_Type = customer;  // default, can change if needed
//						loggedIn_customerUser.specialization[0] = nullptr;
//						loggedIn_customerUser.specialization[1] = nullptr;
//						loggedIn_customerUser.serviceCharge = 0.0;
//						break;
//					}
//				} while (loggedinchoice != 5);
//			}
//			else
//			{
//				int caccCHOICE;
//				cout << "\n\nMaybe create an account?\n1. Create an account\n2. Back to customer menu";
//				*P_numberedlist = 3;
//				caccCHOICE = getInput(P_numberedlist);
//				*P_numberedlist = 1;
//				if (caccCHOICE == 1)
//					custcreateacc(P_numberedlist, loginCredential, password, newCustomerUser);
//			}
//			break;
//		case 2:
//			int guestchoice;
//			do 
//			{
//				cout << "\nWelcome, to our dearest customer!\n" << string(40, '-') << endl;
//				cout << "1. View our services\n2. View appointment availability\n3. Back to customer menu\n";
//
//				*P_numberedlist = 4;
//				cout << "\nEnter your choice (1 - " << *P_numberedlist - 1 << ") : ";
//				guestchoice = getInput(P_numberedlist);
//				*P_numberedlist = 1;
//
//				switch (guestchoice)
//				{
//				case 1:
//					cout << endl << endl;
//					viewServices(numberofServices, P_numberedlist, services_available, experts, numberofExperts);
//					*P_numberedlist = 1;
//					break;
//				case 2: // update pending
//					cout << "\nWhat experts would you like check for their availability ?\n\n";
//					choice[2] = getInput(P_numberedlist);
//					viewAvailable_days(choice, filteredIndices, services_available, experts, customers, appointments_schedule, numberofAppointments);
//					break;
//				}
//			} while (guestchoice != 3);
//			break;
//		case 3:
//			custcreateacc(P_numberedlist, loginCredential, password, newCustomerUser);
//			break;
//		case 4:
//			return true;
//		}
//	} while (custmenuchoice != 4);
//	
//	return false;
//}
//void viewServices(int* numberofServices, int* P_numberedlist, services services_available[], 
//	users experts[], int* numberofExperts)
//{
//	cout << "\nOur available services : \n" << string(90, '-') << endl;
//
//	for (int i = 0; i < *numberofServices; ++i) {
//		cout << *P_numberedlist << ". \033[1;4m" << services_available[i].service_name
//			<< "\033[0m  (Base Price: RM" << fixed << setprecision(2)
//			<< services_available[i].servicePrice << ")\n";
//
//		// Show experts who can perform this service
//		bool expertFound = false;
//		for (int j = 0; j < *numberofExperts; ++j) 
//		{
//			if ((experts[j].specialization[0] && experts[j].specialization[0]->serviceID == services_available[i].serviceID)
//			 || (experts[j].specialization[1] && experts[j].specialization[1]->serviceID == services_available[i].serviceID))
//			{
//				expertFound = true;
//				double extraCharge = experts[j].serviceCharge;
//				double finalPrice = services_available[i].servicePrice + extraCharge;
//
//				cout << "   -> Expert: " << experts[j].username
//					<< " | Extra Charge: RM" << extraCharge
//					<< " | Final Price: RM" << finalPrice << "\n";
//			}
//		}
//
//		if (!expertFound)
//			cout << "   (No experts currently provide this service)\n";
//
//		cout << string(90, '-') << endl;
//		++*P_numberedlist;
//	}
//}
//void viewExperts(int choice[], int* numberofExperts, int* P_numberedlist, 
//	int* filternumlist, int filteredIndices[], users experts[], services services_available[]) 
//{
//	for (int i = 0; i < 7; ++i)
//	{ // clear data in filteredIndices for each session of the same logged in user
//		filteredIndices[i] = -1;
//	} // reset this accumulator as well
//	*filternumlist = 0;
//
//	cout << "\nOur experts that provides " << services_available[choice[1] - 1].service_name << ": \n";
//	for (int i = 0; i < *numberofExperts; ++i)
//	{
//		if ((experts[i].specialization[0]->serviceID == choice[1]) ||
//			(experts[i].specialization[1]->serviceID == choice[1]))
//		{
//			cout << *P_numberedlist << ". " << experts[i].username << endl;
//			filteredIndices[*filternumlist] = i;
//			++*filternumlist; ++*P_numberedlist;
//		}
//	}
//}
//void viewAvailable_days(int choice[], int filteredIndices[], services services_available[],
//	users experts[], users customers[], bookings appointments_schedule[], int* totalBookings)
//{
//	// display available days of chosen expert
//	const int row = 5, col = 8, totalSlotsperDay = 6;
//	int bookingsPerDay[32] = { 0 },
//		time_slotsDay[5][8] = {
//			{1, 2, 3, 4, 5, 6, 7},
//			{8, 9, 10, 11, 12, 13, 14},
//			{15, 16, 17, 18, 19, 20, 21},
//			{22, 23, 24, 25, 26, 27, 28},
//			{29, 30, 31, 0, 0, 0, 0, 0}
//		};
//
//	// count how many records exist in file
//	int totalAppointmentRecords = countAppointmentsInFile();
//	if (totalAppointmentRecords <= 0) {
//		cout << "\nNo appointments found in file.\n";
//		return;
//	}
//
//	// load them dynamically
//	bookings* appointments = new bookings[totalAppointmentRecords];
//	int totalRecords = loadAppointments(appointments, totalAppointmentRecords, nullptr, experts, services_available);
//
//	// accumulate bookings per day for the selected expert
//	for (int k = 0; k < totalRecords; ++k) 
//	{ // goes through the fetched booking list iteratively
//		// check if the userID of expert booked in appointments' record is the same as the one in experts
//		if (appointments[k].expert_booked->userID == experts[filteredIndices[choice[2] - 1]].userID
//		 && appointments[k].booking_status == true)
//		{ // range check for the bookings' date, shud be between 1 & 31
//			if (appointments[k].booking_date >= 1 && appointments[k].booking_date <= 31)
//			// if booking date is valid, then post-increment the kth element in fetched appointments records
//				bookingsPerDay[appointments[k].booking_date]++;
//			// for each kth element in appointments, refer to its booking date, 
//			// use the booking date as the nth element in bookingsPerDay array to update the nth accumulator
//		}
//	}
//
//	// calendar display
//	cout << experts[filteredIndices[choice[2] - 1]].username
//		<< " is available for the following days : \n"
//		<< setw(23) << "December" << endl
//		<< "-------------------------------------\n";
//
//	for (int i = 0; i < row; ++i) {
//		for (int j = 0; j < col; ++j) {
//			int date = time_slotsDay[i][j];
//			ostringstream oss;
//			oss << setw(3) << date;
//			if (date == 0) continue;
//
//			if (bookingsPerDay[date] < totalSlotsperDay)
//				cout << " " << oss.str() << " ";
//			else
//				cout << " " << "\033[101;30m" << oss.str() << "\033[0m ";
//		}
//		cout << endl;
//	}
//	cout << "\nLEGEND | \033[101;30mUnavailable\033[0m, Available\n\n";
//
//	delete[] appointments;
//}
//void bookAppointment(int* numberofTimeSlots, int* numberofAppointments, int* P_numberedlist, int choice[], 
//	int filteredIndices[], services services_available[], users experts[], users customers[], users loggedIn_customerUser, 
//	timeSlots hourly_timeSlots[], bookings appointments_schedule[])
//{
//	int book_Date = 0, 
//		totalBookings = countAppointmentsInFile();
//	char yesno = ' '; 
//	bookings newAppointment, 
//		* existingAppointments = new bookings[totalBookings];
//	
//	
//	*P_numberedlist = 32;
//	while (true)
//	{ // unavailable days won't be valid as input
//		int loaded = loadAppointments(existingAppointments, totalBookings, hourly_timeSlots, experts, services_available);
//		// fetch appointments records
//
//		cout << "\nPick the day you'd like to book (1 - " << *P_numberedlist - 1 << ") : ";
//		book_Date = getInput(P_numberedlist); // input prompt
//		// count bookings for this expert on the chosen day
//		int bookingsForDay = 0;
//		for (int i = 0; i < loaded; ++i) 
//		{
//			if (existingAppointments[i].expert_booked->userID == experts[filteredIndices[choice[2] - 1]].userID
//			 && existingAppointments[i].booking_status == true
//			 && existingAppointments[i].booking_date == book_Date)
//				bookingsForDay++;
//		}
//
//		if (bookingsForDay >= 6) // total slots per days
//		{ // validate for unavailble days
//			cout << endl << book_Date << "th December is unavailble!";
//			continue;
//		}
//		else break;
//	}
//	*P_numberedlist = 1;
//
//	cout << "\nTimeslots available at " << book_Date << "th : \n" << string(80, '-') << endl;
//	for (int i = 0; i < *numberofTimeSlots; ++i)
//	{
//		bool isBooked = false;
//
//		// check if this slot is already booked on the chosen day
//		for (int j = 0; j < totalBookings; ++j) 
//		{
//			if (existingAppointments[j].expert_booked->userID == experts[filteredIndices[choice[2] - 1]].userID
//			 && existingAppointments[j].booking_status == true
//			 && existingAppointments[j].booking_date == book_Date
//			 && existingAppointments[j].timeslot->timeslotID == hourly_timeSlots[i].timeslotID)
//			{
//				isBooked = true;
//				break;
//		}
//			}
//
//		if (!isBooked)
//		{
//			cout << *P_numberedlist << ". " 
//				<< fixed << setprecision(2)
//				<< setw(5) << setfill('0') << hourly_timeSlots[i].hours_start
//				<< "--" << setw(5) << setfill('0') << hourly_timeSlots[i].hours_end 
//				<< setfill(' ') << endl;
//			++(*P_numberedlist);
//		}
//	}
//	cout << "\nPick your time slots for the day (1 - " << *P_numberedlist - 1 << ") : ";
//	choice[3] = getInput(P_numberedlist);
//	*P_numberedlist = 1;
//
//	delete[] existingAppointments;
//
//	while (true)
//	{
//		if (payment(choice, P_numberedlist, services_available, experts, customers, loggedIn_customerUser))
//		{
//			newAppointment.timeslot = &hourly_timeSlots[choice[3] - 1];
//			newAppointment.booking_status = true;
//			newAppointment.booking_date = book_Date;
//			newAppointment.book_byCustomer = loggedIn_customerUser.userID;
//			newAppointment.expert_booked = &experts [filteredIndices[choice[2] - 1]];
//			newAppointment.service_booked = &services_available[choice[1] - 1];
//			writetoAppointmentRecords(newAppointment, hourly_timeSlots, experts, services_available);
//			cout << "\n\nAppointment booked !";
//			break;
//		}
//		else 
//		{
//			cout << "\n\nPayment failed.";
//			while (true)
//			{
//				cout << "\nTry again? (Y = Yes | N = No) : ";
//				cin >> yesno;
//				//system("CLS"); // system cls clear the whole terminal tho, later it clears ur entire cust menus
//
//				if (cin.peek() != '\n') // Peek next character to check if user typed more
//				{
//					cout << "Invalid input. Only one character allowed.\n";
//					cin.ignore(numeric_limits<streamsize>::max(), '\n');
//					continue;
//				}
//				if (toupper(yesno) == 'Y' || toupper(yesno) == 'N')   // type check 
//				{													//& char value check
//					cout << endl << endl;
//					break;
//				}
//				cout << "Invalid input. Please enter 'Y' or 'N'.\n";
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			}
//			if (toupper(yesno) == 'Y')
//				continue;
//			else if (toupper(yesno) == 'N')
//			{
//				cout << "Book appointment failed.\n\n";
//				break;
//			}
//		}
//	}
//}
//bool payment(int choice[], int* numberedlist, services services_available[], users experts[], users customers[], users loggedIn_customerUser)
//{
//	//payment module
//	//display & input prompts, fake the credentials
//	string multiusestring, Banks[] = { "Ambank", "HongLeong Bank", "Public Bank", "Maybank", "Alliance Bank" };
//	LPCWSTR url = L"https://i.pinimg.com/736x/b7/c7/10/b7c71079775659e3f1413213706e6b0b.jpg";
//
//	cout << "------------------ Payment ------------------ \n"   // dis customer[1] thing change | display based on loggedIn_customerUser
//		<< "Customer name : " << setw(10) << loggedIn_customerUser.username << endl
//		<< "Selected package : " << setw(10) << services_available[choice[1] - 1].service_name << endl
//		<< "Service Charge : " << setw(10) << "RM" << experts[choice[2] - 1].serviceCharge << endl
//		<< "Base Price : " << setw(10) << "RM" << services_available[choice[1] - 1].servicePrice << endl
//		<< "----------------------------------------------- \n";
//	cout << "Available payment method\n----------------------------------\n"
//		<< "[1] Credit Card\n[2] Online Banking\n[3] E-Wallet\n[4] Cancel Payment\n"
//		<< "\nEnter your choice : ";
//	*numberedlist = 5;
//	choice[0] = getInput(numberedlist);
//	*numberedlist = 1;
//
//	switch (choice[0]) {
//	case 1:
//		cout << "Enter Cardholder Name : ";
//		getline(cin, multiusestring);
//
//		cout << "\nEnter Card Number (16 digits) : ";
//		getline(cin, multiusestring);
//		//auto enter space after each 4 digits
//		while (multiusestring.length() < 16) { // format check
//			cout << "Enter valid format !!!\nEnter Card Number (16 digits) : ";
//			cin >> multiusestring;
//		}
//
//		while (true)
//		{
//			bool gotAlphabet = 0;
//			cout << "\nEnter Expiry Date (MM/YY) : ";
//			getline(cin, multiusestring);
//			if (multiusestring.empty())
//			{
//				cout << "\nInput empty, please provide input.";
//				continue;
//			}
//			if (multiusestring.length() != 5 || multiusestring[2] != '/') {
//				cout << "\nInvalid format! More than 5 characters & no frontslash to separate the month & year. ";
//				continue;
//			}
//			else for (int i = 0; i < multiusestring.length(); ++i) {
//				if (i == 2) continue;
//				if (!isdigit(multiusestring[i]))
//					gotAlphabet = 1;
//			}
//			if (gotAlphabet)
//			{
//				cout << "\nInvalid format! Contains alphabets, please try again. ";
//				continue;
//			}
//			int month = (multiusestring[0] - '0') * 10 + (multiusestring[1] - '0');
//			if (month < 1 || month > 12)
//			{
//				cout << "\nMonth out of range! Please try again.";
//				continue;
//			}
//			break;
//		}
//
//		cout << "\n\nProcessing payment...";
//		cout << "\nPayment successful!";
//
//		return true;
//		break;
//	case 2:
//		cout << "\nSelect a bank\n-----------------------\n";
//		for (int i = 0; i < sizeof(Banks) / sizeof(Banks)[0]; ++i)
//		{
//			cout << *numberedlist << ". " << Banks[i] << endl;
//			++*numberedlist;
//		}
//		cout << ": ";
//		choice[0] = getInput(numberedlist);
//		*numberedlist = 1;
//
//		while (true)
//		{
//			cout << "\nEnter your username : ";
//			getline(cin, multiusestring);
//			if (multiusestring.empty())
//			{
//				cout << "\nInput is empty, please provide input.";
//				continue;
//			}
//			break;
//		}
//		while (true)
//		{
//			cout << "\nEnter your password : ";
//			getline(cin, multiusestring);
//			if (multiusestring.empty())
//			{
//				cout << "\nInput is empty, please provide input.";
//				continue;
//			}
//			break;
//		}
//		cout << "\nAuthorization request sent to the bank app, approve the authorization...";
//		while (true)
//		{
//			cout << "\napproved?... (Y = Yes | N = No) : ";
//			getline(cin, multiusestring);
//
//			if (multiusestring.empty())
//			{
//				cout << "\nInput is empty, please provide input.";
//				continue;
//			}
//			if (multiusestring.length() > 1 || isAlphabet(multiusestring.c_str()) == false
//				/*|| isNumeric(multiusestring.c_str()) == true*/)
//			{
//				cout << "\nInvalid. Yes or No? (Y = Yes | N = No) : ";
//				continue;
//			}
//			if (toupper(multiusestring[0]) == 'Y')
//			{
//				cout << "\nProcessing payment...";
//				cout << "\nPayment successful!";
//				break;
//			}
//			else if (toupper(multiusestring[0]) == 'N')
//			{
//				cout << "\nResent authorization? (Y = Yes | N = No) : ";
//				getline(cin, multiusestring);
//
//				if (toupper(multiusestring[0]) == 'Y')
//					continue;
//				else if (toupper(multiusestring[0]) == 'N')
//				{
//					cout << "Authorization failed !! Please try again.";
//					return false;
//					break;
//				}
//			}
//			else {
//				cout << "\nInvalid, y or n for yes or no only.";
//				continue;
//			}
//		}
//		return true;
//		break;
//	case 3:
//		cout << "Scan the QR below : ";
//		ShellExecute(0, L"open", url, 0, 0, SW_SHOWNORMAL);
//		cout << "\n\nProcessing payment...";
//		cout << "\nPayment successful!";
//		return true;
//		break;
//	case 4:
//		cout << "Payment cancelled";
//		return false;
//	}
//	return true;
//}
//void viewbookedSchedule(int* numberofAppointments, bookings appointments_schedule[], timeSlots* hourly_timeSlots,
//	users loggedIn_customerUser, users* experts, services* services_available)
//{
//	int totalBookings = countAppointmentsInFile();
//	if (totalBookings == 0)
//		cout << "No appointments in file.\n";
//	bookings* appointments = new bookings[totalBookings];
//	int loaded = loadAppointments(appointments, totalBookings, hourly_timeSlots, experts, services_available);
//	cout << loaded << " appointment records loaded.\n";
//
//	viewUserAppointments(loggedIn_customerUser, appointments, loaded);
//	delete[] appointments;
//}
//bool isAlphabet(const char* stringVar) // to check if the input is Alphabet or not
//{
//	for (int i = 0; stringVar[i] != '\0'; ++i) {
//		if (!isalpha(stringVar[i]))
//			return false;}
//	return true;
//}
//bool isNumeric(const char* stringVar) // false : Is not numeric
//{
//	for (int i = 0; stringVar[i] != '\0'; ++i) {
//		if (!isdigit(stringVar[i]))
//			return false;}
//	return true;
//}
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
//bool parseUserRecord(const string& Fetched_Record, users& loggedIn_customerUser)
//{ // decode the Fetched User record data
//	size_t start = Fetched_Record.find('{');
//	size_t end = Fetched_Record.find('}');
//	if (start == string::npos || end == string::npos) return false;
//
//	string inside = Fetched_Record.substr(start + 1, end - start - 1);
//	stringstream ss(inside);
//	string temp;
//
//	// userID
//	ss >> loggedIn_customerUser.userID;
//	ss.ignore(2);
//
//	// username
//	getline(ss, loggedIn_customerUser.username, ',');
//	if (!loggedIn_customerUser.username.empty() && loggedIn_customerUser.username.front() == '"')
//		loggedIn_customerUser.username = loggedIn_customerUser.username.substr(1, loggedIn_customerUser.username.size() - 2);
//
//	// age
//	ss >> loggedIn_customerUser.age;
//	ss.ignore(3);
//
//	// gender
//	ss >> loggedIn_customerUser.gender;
//	ss.ignore(2);
//
//	// email
//	getline(ss, loggedIn_customerUser.user_email, ',');
//	if (!loggedIn_customerUser.user_email.empty() && loggedIn_customerUser.user_email.front() == '"')
//		loggedIn_customerUser.user_email = loggedIn_customerUser.user_email.substr(1, loggedIn_customerUser.user_email.size() - 2);
//
//	// password
//	ss.ignore(1);
//	getline(ss, loggedIn_customerUser.user_password, ',');
//	if (!loggedIn_customerUser.user_password.empty() && loggedIn_customerUser.user_password.front() == '"')
//		loggedIn_customerUser.user_password = loggedIn_customerUser.user_password.substr(1, loggedIn_customerUser.user_password.size() - 2);
//
//	// user type
//	ss >> temp;
//	loggedIn_customerUser.user_Type = (temp.find("customer") != string::npos) ? customer : expert;
//
//	return true;
//}
//bool custlogin(users* loggedIn_customerUser, string loginCredential, string password,
//	int* P_numberedlist, int choice[])
//{
//	bool found = 0;
//
//	ifstream rUserRecords("User records.txt");
//	string Fetched_Record;
//	
//	if (!rUserRecords) {
//		cout << "Error: Could not open file!" << endl;
//		return 1;
//	}
//
//	cout << "Enter username or email: ";
//	getline(cin, loginCredential);
//	string capitalizedCredential = loginCredential;
//	
//	for (size_t i = 0; i < capitalizedCredential.length(); i++) 
//	{ // capitalize loginCredential provided by user, for later case-insensitive comparison
//		capitalizedCredential[i] = toupper((unsigned char)loginCredential[i]);
//	} 
//	while (getline(rUserRecords, Fetched_Record)) // keep on fetching until found is true, getline will stop at newline char '\n', so it goes thru the record line-by-line
//	{ // fetch User records.txt data to Fetched_Record for processing & comparison for login Credential (name or email)
//		string capitalizedFetchedRecord = Fetched_Record;
//		for (size_t i = 0; i < Fetched_Record.length(); ++i) 
//		{  // capitalize all chars of the fetched line for case-insensitive comparison for login credential
//			capitalizedFetchedRecord[i] = toupper((unsigned char)capitalizedFetchedRecord[i]);
//		}
//		// comparison of the credential
//		if (capitalizedFetchedRecord.find(capitalizedCredential) != string::npos) 
//		{
//			if (parseUserRecord(Fetched_Record, *loggedIn_customerUser)) 
//			{
//				found = true;
//				break; // stop after first match
//			}			
//		} 
//	}
//	if (found == 0)
//	{
//		cout << "No user found.";
//		return false;
//	}
//	rUserRecords.close();
//	while (true)
//	{
//		cout << "Enter password: ";
//		getline(cin, password);
//
//		if (password != loggedIn_customerUser->user_password)
//		{
//			cout << "\nWrong password.\n1. Try again?\n2. No\n : ";
//
//			*P_numberedlist = 3;
//			choice[0] = getInput(P_numberedlist);
//			*P_numberedlist = 1;
//
//			if (choice[0] == 1)
//				continue;
//			else if (choice[0] == 2)
//				return false;
//				break;
//		}
//		else
//		{
//			cout << "\nLogged in!";
//			return true;
//			break;
//		}
//	}
//}
//int custcreateacc(int* P_numberedlist, string loginCredential, string password, users newCustomerUser)
//{
//	fstream rwUserRecord("User records.txt", ios::in | ios::app);
//	if (!rwUserRecord) {
//		cout << "Error: Could not open file!" << endl;
//		return 1;
//	} 
//	// get login credential 
//	cout << "\nEnter username or email: ";
//	getline(cin, loginCredential, '\n');
//	
//	if (loginCredential.find('@') != string::npos)
//	{	// check if the credential provided is an email, if so write into user struct var email field
//		newCustomerUser.user_email = loginCredential;
//		cout << "Enter username for your new account >o<_/-  ";
//		getline(cin, newCustomerUser.username, '\n'); // get username from user if they create account w\ email
//	} // me lazy to add another function to edit for account details not enuf time dy)
//	else
//		newCustomerUser.username = loginCredential;
//	while (true)
//	{
//		cout << "Enter password : ";
//		getline(cin, password);
//		string password1 = " ";
//		// double confirm password entered is correct
//		cout << "Enter password again : ";
//		getline(cin, password1);
//		if (password1 != password)
//		{
//			cout << "\nPassword entered does not match! Try again.\n";
//			continue;
//		}
//		else break;
//	}
//	newCustomerUser.user_password = password;
//	// populate as customer
//	newCustomerUser.user_Type = customer;
//	// input prompt & populate for age
//	cout << "Enter your age : ";
//	*P_numberedlist = 100;
//	newCustomerUser.age = getInput(P_numberedlist);
//	*P_numberedlist = 1;
//	// input prompt & populate for gender
//	do {
//		cout << "What's your gender? (M = Male or F = Female): ";
//		cin >> newCustomerUser.gender;
//		newCustomerUser.gender = toupper(newCustomerUser.gender);
//		if (newCustomerUser.gender != 'M' && newCustomerUser.gender != 'F')
//			cout << "\nEnter valid value!";
//	} while (newCustomerUser.gender != 'M' && newCustomerUser.gender != 'F');
//
//	// section of code for getting the last line's userID
//		// --- move to end ---
//	rwUserRecord.seekg(0, ios::end);
//	int fileSize = rwUserRecord.tellg();
//	if (fileSize == 0)
//	{
//		newCustomerUser.userID = 1;  // empty file means first user
//	}
//	else
//	{
//		char ch;
//		string lastLine = "";
//
//		// start reading from the last index of the entire file
//		for (int i = fileSize - 1; i >= 0; i--)
//		{
//			rwUserRecord.seekg(i);
//			rwUserRecord.get(ch);
//
//			if (ch == '\n' && !lastLine.empty()) break;
//			lastLine.insert(lastLine.begin(), ch);
//		}
//
//		// string manipultion TO cut the delimiters or separators TO extract userID from last line
//		size_t start = lastLine.find('{');
//		size_t end = lastLine.find('}');
//		if (start != string::npos && end != string::npos)
//		{
//			string inside = lastLine.substr(start + 1, end - start - 1);
//			stringstream ss(inside);
//
//			int lastID;
//			ss >> lastID;
//			newCustomerUser.userID = ++lastID;
//		}
//		else
//			newCustomerUser.userID = 1; // fallback
//	}
//	rwUserRecord.clear(); // clear EOF status
//	rwUserRecord.seekp(0, ios::end);
//	// write into User records.txt
//	rwUserRecord << endl;
//	rwUserRecord << "{"
//		<< newCustomerUser.userID << ", "
//		<< "\"" << newCustomerUser.username << "\", "
//		<< newCustomerUser.age << ", "
//		<< "'" << newCustomerUser.gender << "', "
//		<< "\"" << newCustomerUser.user_email << "\", "
//		<< "\"" << newCustomerUser.user_password << "\", "
//		<< (newCustomerUser.user_Type == customer ? "customer" : "expert")
//		<< "},";
//	rwUserRecord.close();
//
//	return 0;
//}
//bool parseAppointmentRecord(const string& Fetched_Record, bookings& appointment,
//	timeSlots* hourly_timeSlots, users* experts, services* services_available)
//{
//	size_t start = Fetched_Record.find('{');
//	size_t end = Fetched_Record.find('}');
//	if (start == string::npos || end == string::npos) return false;
//
//	string inside = Fetched_Record.substr(start + 1, end - start - 1);
//	stringstream ss(inside);
//	string temp;
//
//	// timeslot index
//	getline(ss, temp, ',');
//	size_t pos = temp.find('[');
//	size_t pos2 = temp.find(']');
//	int timeslotIndex = stoi(temp.substr(pos + 1, pos2 - pos - 1));
//
//	// booking_status
//	getline(ss, temp, ',');
//	appointment.booking_status = (temp.find("true") != string::npos);
//
//	// booking_date
//	getline(ss, temp, ',');
//	appointment.booking_date = stoi(temp);
//
//	// bookedBy customer
//	getline(ss, temp, ',');
//	appointment.book_byCustomer = stoi(temp);
//
//	// expert index
//	getline(ss, temp, ',');
//	pos = temp.find('[');
//	pos2 = temp.find(']');
//	int expertIndex = stoi(temp.substr(pos + 1, pos2 - pos - 1));
//
//	// service index
//	getline(ss, temp, ',');
//	pos = temp.find('[');
//	pos2 = temp.find(']');
//	int serviceIndex = stoi(temp.substr(pos + 1, pos2 - pos - 1));
//
//	// assign pointers directly
//	appointment.timeslot = &hourly_timeSlots[timeslotIndex];
//	appointment.expert_booked = &experts[expertIndex];
//	appointment.service_booked = &services_available[serviceIndex];
//
//	return true;
//}
//int loadAppointments(bookings* appointments, int totalRecords,
//	timeSlots* hourly_timeSlots, users* experts, services* services_available)
//{
//	ifstream rAppointments("Appointments.txt");
//	if (!rAppointments.is_open()) {
//		cout << "Error: Could not open file!" << endl;
//		return 0;
//	}
//
//	string Fetched_Record;
//	int index = 0;
//
//	while (getline(rAppointments, Fetched_Record) && index < totalRecords) {
//		if (Fetched_Record.empty()) continue;
//		parseAppointmentRecord(Fetched_Record, appointments[index++], hourly_timeSlots, experts, services_available);
//	}
//
//	rAppointments.close();
//	return index; // number of records successfully loaded
//}
//int countAppointmentsInFile()
//{ 
//	ifstream rAppointments("Appointments.txt");
//	if (!rAppointments.is_open())
//	{
//		cout << "Error: Could not open file!" << endl;
//		return 1;
//	}
//
//	string Fetched_Record;
//	int count = 0;
//	while (getline(rAppointments, Fetched_Record))
//		if (!Fetched_Record.empty()) count++;
//	rAppointments.close();
//	return count;
//}
//void viewUserAppointments(users loggedIn_customerUser, bookings* appointments, int totalRecords)
//{
//	cout << string(28, '=') << " Your Appointments " << string(28, '=') << endl;
//
//	cout << left << setw(12) << "No."
//		<< setw(12) << "Date"
//		<< setw(15) << "Time"
//		<< setw(15) << "Expert"
//		<< setw(25) << "Service" << endl;
//
//	cout << string(74, '-') << endl;
//
//	int recordCount = 0;
//
//	for (int i = 0; i < totalRecords; i++) {
//		if (appointments[i].book_byCustomer == loggedIn_customerUser.userID) {
//			recordCount++;
//
//			stringstream timeStr;
//			timeStr << fixed << setprecision(2)
//				<< appointments[i].timeslot->hours_start
//				<< "-" << appointments[i].timeslot->hours_end;
//
//			cout << left << setw(12) << recordCount
//				<< setw(12) << appointments[i].booking_date
//				<< setw(15) << timeStr.str()
//				<< setw(15) << appointments[i].expert_booked->username
//				<< setw(25) << appointments[i].service_booked->service_name
//				<< "\n";
//		}
//	}
//
//	if (recordCount == 0) {
//		cout << "No appointments found for you.\n";
//	}
//}
//void writetoAppointmentRecords(bookings newAppointment,
//	timeSlots hourly_timeSlots[], users experts[], services services_available[])
//{
//	ofstream wAppointments("Appointments.txt", ios::app);
//	if (!wAppointments.is_open()) {
//		cout << "Error: Could not open Appointments.txt for writing!" << endl;
//		return;
//	}
//	cout << endl << endl << newAppointment.expert_booked;
//	cout << endl << newAppointment.expert_booked - experts << endl;
//	// Write appointment in a structured format
//	wAppointments << endl << "{"
//		<< "&hourly_timeSlots[" << (newAppointment.timeslot - hourly_timeSlots) << "], "
//		<< (newAppointment.booking_status ? "true" : "false") << ", "
//		<< newAppointment.booking_date << ", "
//		<< newAppointment.book_byCustomer << ", "
//		<< "&experts[" << (newAppointment.expert_booked - experts) << "], "
//		<< "&services_available[" << (newAppointment.service_booked - services_available) << "]"
//		<< "},";
//
//	wAppointments.close();
//}
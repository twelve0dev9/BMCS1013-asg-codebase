//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <sstream>
//using namespace std;
//
//enum UserType { admine, experte, customere };
//
//struct services {
//    int serviceID = 0;
//    string service_name = " ";
//    float serviceTime = 0.00; //unit is Hours
//};
//
//struct users {
//    int userID = 0;
//    string username = " ";
//    int age = 0;
//    char gender = ' ';
//    string user_email = " ";
//    string user_password = " ";
//    UserType user_Type;
//    services* specialization[2];
//};
//
//struct timeSlots {
//    int timeslotID;
//    double hours_start; //24 hours time format
//    double hours_end; //24 hours time format
//};
//
//struct bookings {
//    timeSlots* timeslot;
//    bool booking_status = 0;
//    int booking_date;
//    users* book_byCustomer;
//    users* expert_booked;
//    services* service_booked;
//};
//
//
//services services_available[4] = {
//    {1, "Haircuts & Trims", 3},
//    {2, "Bread Grooming", 3},
//    {3, "Facial Skin Care", 3},
//    {4, "Massage Therapy", 3}
//};
//
//users experts[5] = {
//    {29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", UserType::experte, {&services_available[0], &services_available[2]}},
//    {3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", UserType::experte, {&services_available[1], &services_available[3]}},
//    {41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", UserType::experte, {&services_available[1], &services_available[2]}},
//    {42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", UserType::experte, {&services_available[2], &services_available[3]}},
//    {10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", UserType::experte, {&services_available[0], &services_available[1]}}
//};
//
//users customer_users[9] = {
//    {4, "Blaze", 16, 'M', "expertschaoheweui@gmail.com", "apopejakicetruck-89632", UserType::customere},
//    {5, "Thomas", 16, 'M', "thomaswayne@gmail.com", "utc4kt6d8vcuj", UserType::customere},
//    {6, "Bruce Wayne", 16, 'M', "brucewayne@gmail.com", "kyu6fv485k7f8tyu6+", UserType::customere},
//    {8, "Tommy", 16, 'M', "peakblinders4peak@gmail.com", "68kdcty786yuf", UserType::customere},
//    {9, "Jeremy", 16, 'M', "whostheboss@gmail.com", "yuf1h23vjk78y9i", UserType::customere},
//    {56, "Jeremiah", 16, 'M', "justanothercopy@gmail.com", "qwet786xfgh534", UserType::customere},
//    {12, "Harley", 16, 'F', "harleyquinnsucktbh@gmail.com", "ub78i6312ic6gh78k", UserType::customere},
//    {7, "Ashton Hall", 16, 'M', "ashtonhallunclosetoishowmeeat@gmail.com", "45pgyuijbk73po5ui", UserType::customere},
//    {5, "iShoeSpeed", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", UserType::customere}
//};
//
//timeSlots hourly_timeSlots[6] = {
//    {1, 12.00, 15.00},
//    {2, 14.00, 17.00},
//    {3, 16.00, 19.00},
//    {4, 18.00, 21.00},
//    {5, 21.00, 0.00},
//    {6, 22.00, 1.00}
//};
//
//bookings appointments_schedule[] = {
//		{&hourly_timeSlots[0], true, 18, &customer_users[2], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[1], true, 18, &customer_users[4], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[2], true, 18, &customer_users[0], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[3], true, 18, &customer_users[2], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[4], true, 18, &customer_users[7], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[5], true, 18, &customer_users[8], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[2], true, 18, &customer_users[6], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[2], true, 5, &customer_users[3], &experts[2], &services_available[0]},
//		{&hourly_timeSlots[1], true, 29, &customer_users[1], &experts[2], &services_available[1]},
//		{&hourly_timeSlots[1], true, 12, &customer_users[1], &experts[2], &services_available[2]},
//		// Fully booked days (9 days × 6 slots each = 54 bookings total)
//		{&hourly_timeSlots[0], true, 2, &customer_users[0], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[1], true, 2, &customer_users[1], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[2], true, 2, &customer_users[2], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[3], true, 2, &customer_users[3], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[4], true, 2, &customer_users[4], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[5], true, 2, &customer_users[5], &experts[0], &services_available[1]},
//
//		{&hourly_timeSlots[0], true, 5, &customer_users[6], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[1], true, 5, &customer_users[7], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[2], true, 5, &customer_users[8], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[3], true, 5, &customer_users[0], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[4], true, 5, &customer_users[1], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[5], true, 5, &customer_users[2], &experts[0], &services_available[3]},
//
//		{&hourly_timeSlots[0], true, 29, &customer_users[3], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[1], true, 29, &customer_users[4], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[2], true, 29, &customer_users[5], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[3], true, 29, &customer_users[6], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[4], true, 29, &customer_users[7], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[5], true, 29, &customer_users[8], &experts[0], &services_available[1]},
//
//		{&hourly_timeSlots[0], true, 14, &customer_users[0], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[1], true, 14, &customer_users[1], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[2], true, 14, &customer_users[2], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[3], true, 14, &customer_users[3], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[4], true, 14, &customer_users[4], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[5], true, 14, &customer_users[5], &experts[0], &services_available[3]},
//
//		{&hourly_timeSlots[0], true, 15, &customer_users[6], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[1], true, 15, &customer_users[7], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[2], true, 15, &customer_users[8], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[3], true, 15, &customer_users[0], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[4], true, 15, &customer_users[1], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[5], true, 15, &customer_users[2], &experts[0], &services_available[1]},
//
//		{&hourly_timeSlots[0], true, 18, &customer_users[3], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[1], true, 18, &customer_users[4], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[2], true, 18, &customer_users[5], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[3], true, 18, &customer_users[6], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[4], true, 18, &customer_users[7], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[5], true, 18, &customer_users[8], &experts[0], &services_available[3]},
//
//		{&hourly_timeSlots[0], true, 26, &customer_users[1], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[1], true, 26, &customer_users[2], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[2], true, 26, &customer_users[3], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[3], true, 26, &customer_users[4], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[4], true, 26, &customer_users[5], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[5], true, 26, &customer_users[6], &experts[0], &services_available[1]},
//
//		{&hourly_timeSlots[0], true, 30, &customer_users[7], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[1], true, 30, &customer_users[8], &experts[0], &services_available[3]},
//		{&hourly_timeSlots[2], true, 30, &customer_users[0], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[3], true, 30, &customer_users[1], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[4], true, 30, &customer_users[2], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[5], true, 30, &customer_users[3], &experts[0], &services_available[3]},
//
//		// Partial bookings for the rest of the month (just a few slots booked)
//		{&hourly_timeSlots[0], true, 6, &customer_users[4], &experts[0], &services_available[0]},
//		{&hourly_timeSlots[2], true, 9, &customer_users[5], &experts[0], &services_available[1]},
//		{&hourly_timeSlots[4], true, 14, &customer_users[6], &experts[0], &services_available[2]},
//		{&hourly_timeSlots[1], true, 28, &customer_users[7], &experts[0], &services_available[3]}
//};
//
//int customer();
//int admin();
//int expert();
//void viewPersonalSchedule(string expertName);
//void viewAssignedCustomers(string expertName);
//void viewEarnings(string expertName);
//
//int login() {
//	int login_type;
//	cout << "     LOGIN      " << endl;
//	cout << "----------------" << endl;
//	cout << "Select Login: " << endl;
//	cout << "1. Customer" << endl;
//	cout << "2. Administrator" << endl;
//	cout << "3. Expert" << endl;
//	cin >> login_type;
//	if (login_type != 1 and login_type != 2 and login_type != 3) {
//		cout << "Invalid Input, please enter 1 (Customer), 2 (Admin) or 3 (Expert)" << endl;
//		login();
//	}
//	else if (login_type == 1) {
//		customer();
//	}
//	else if (login_type == 2) {
//		admin();
//	}
//	else if (login_type == 3) {
//		expert();
//	}
//	return 0;
//}
//
//int expert() {
//    string expertName;
//    cout << "Enter your expert name: ";
//    cin >> expertName;
//
//    // Verify expert exists
//    bool expertFound = false;
//    for (int i = 0; i < 5; i++) {
//        if (experts[i].username == expertName) {
//            expertFound = true;
//            break;
//        }
//    }
//
//    if (!expertFound) {
//        cout << "Expert not found! Please try again.\n";
//        return 0;
//    }
//
//    int choice;
//    do {
//        cout << endl << "--------------------------" << endl;
//        cout << "Welcome " << expertName << endl;
//        cout << "--------------------------" << endl;
//        cout << "1. View Personal Schedule" << endl;
//        cout << "2. View Assigned Customers" << endl;
//        cout << "3. View Earnings & Bonus" << endl;
//        cout << "4. Logout" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            viewPersonalSchedule(expertName);
//            break;
//        case 2:
//            viewAssignedCustomers(expertName);
//            break;
//        case 3:
//            viewEarnings(expertName);
//            break;
//        case 4:
//            cout << "Logging out..." << endl;
//            break;
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (choice != 4);
//
//    return 0;
//}
//
//int customer() {
//    cout << "Customer login successful." << endl;
//    return 0;
//}
//
//int admin() {
//    cout << "Admin login successful." << endl;
//    return 0;
//}
//
//void viewPersonalSchedule(string expertName) {
//    // Find the expert in the experts array
//    users* currentExpert = nullptr;
//    for (int i = 0; i < 5; i++) {
//        if (experts[i].username == expertName) {
//            currentExpert = &experts[i];
//            break;
//        }
//    }
//
//    if (!currentExpert) {
//        cout << "Expert not found!" << endl;
//        return;
//    }
//
//    cout << "\nPersonal Schedule for " << expertName << ":\n";
//    cout << "----------------------------------------\n";
//
//    // Display all bookings for this expert
//    bool hasBookings = false;
//    for (int i = 0; i < 54; i++) {
//        if (appointments_schedule[i].expert_booked &&
//            appointments_schedule[i].expert_booked->userID == currentExpert->userID &&
//            appointments_schedule[i].booking_status) {
//
//            hasBookings = true;
//            cout << "Date: " << appointments_schedule[i].booking_date << "\n";
//            cout << "Time: " << fixed << setprecision(2)
//                << appointments_schedule[i].timeslot->hours_start << " - "
//                << appointments_schedule[i].timeslot->hours_end << "\n";
//            cout << "Customer: " << appointments_schedule[i].book_byCustomer->username << "\n";
//            cout << "Service: " << appointments_schedule[i].service_booked->service_name << "\n";
//            cout << "----------------------------------------\n";
//        }
//    }
//
//    if (!hasBookings) {
//        cout << "No appointments scheduled.\n";
//    }
//}
//
//void viewAssignedCustomers(string expertName) {
//    users* currentExpert = nullptr;
//    for (int i = 0; i < 5; i++) {
//        if (experts[i].username == expertName) {
//            currentExpert = &experts[i];
//            break;
//        }
//    }
//
//    if (!currentExpert) {
//        cout << "Expert not found!" << endl;
//        return;
//    }
//
//    cout << "\nAssigned Customers for " << expertName << ":\n";
//    cout << "----------------------------------------\n";
//
//    bool hasCustomers = false;
//    for (int i = 0; i < 54; i++) {
//        if (appointments_schedule[i].expert_booked &&
//            appointments_schedule[i].expert_booked->userID == currentExpert->userID &&
//            appointments_schedule[i].booking_status) {
//
//            hasCustomers = true;
//            cout << "Customer: " << appointments_schedule[i].book_byCustomer->username << "\n";
//            cout << "Email: " << appointments_schedule[i].book_byCustomer->user_email << "\n";
//            cout << "Service: " << appointments_schedule[i].service_booked->service_name << "\n";
//            cout << "Appointment Date: " << appointments_schedule[i].booking_date << "\n";
//            cout << "Time: " << fixed << setprecision(2)
//                << appointments_schedule[i].timeslot->hours_start << " - "
//                << appointments_schedule[i].timeslot->hours_end << "\n";
//            cout << "----------------------------------------\n";
//        }
//    }
//
//    if (!hasCustomers) {
//        cout << "No customers assigned.\n";
//    }
//}
//
//void viewEarnings(string expertName) {
//    cout << "Earnings & bonus for " << expertName << " will appear here." << endl;
//}
//
//int main() {
//    login();
//    return 0;
//}
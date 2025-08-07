#include <iostream>
#include <iomanip>
using namespace std;

// Initial Function Declarations
void clearscreen();

void customer_login();
void customer_menu();

void admin_login();
void admin_menu();
void view_individual_expert_schedule();
void view_overall_schedule();
void view_customer_list();
void generate_sales_reports();
void view_expert_bonus_entitlements();

void expert_login();
void expert_menu();

void main_menu();

// 
void clearscreen() {
	system("CLS");
	return;
}

//CUSTOMER MENU
void customer_login() {}
void customer_menu() {}

//ADMIN MENU
void view_individual_expert_schedule() {
	//view schedules of any selected expert
	//weekly and daily breakdown of working hours and service sessions
	int select_expert;
	int exit;
	cout << "View Individual Expert Schedule" << endl;
	cout << "-------------------------------" << endl;
	cout << "1. Mr. Tan" << endl;
	cout << "2. Ms. Lee" << endl;
	cout << "3. Exit" << endl;
	cout << "-------------------------------" << endl;
	cout << ">";
	cin >> select_expert;
	clearscreen();
	switch (select_expert) {
	case 1:
		cout << "           Mr. Tan's Schedule           " << endl;
		cout << "-------------------------------------" << endl;
		cout << "           Working Hours             " << endl;
		cout << "Monday    :  9:00 a.m. to  5:00 p.m." << endl;
		cout << "Tuesday   :  9:00 a.m. to  5:00 p.m" << endl;
		cout << "Wednesday :  9:00 a.m. to  5:00 p.m" << endl;
		cout << "Thurday   :  9:00 a.m. to  5:00 p.m" << endl;
		cout << "Friday    :  9:00 a.m. to  3:00 p.m" << endl;
		cout << "-------------------------------------" << endl;
		cout << "      This Week's Booked Sessions    " << endl;
		cout << "1. Tuesday  : 11:00 a.m. to 12:00 p.m." << endl;
		cout << "   Customer Name : Lee Yong Shen" << endl;
		cout << endl;
		cout << "2. Friday   :  1:00 p.m. to  2:00 p.m." << endl;
		cout << "   Customer Name : Tay Wei Jing" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Enter any value to exit: ";
		cin >> exit;
		clearscreen();
		view_individual_expert_schedule();
		break;
	case 2:
		cout << "           Ms. Lee's Schedule           " << endl;
		cout << "-------------------------------------" << endl;
		cout << "           Working Hours             " << endl;
		cout << "Friday    :  2:00 p.m. to  9:00 p.m" << endl;
		cout << "Saturday  : 11:00 a.m. to  6:00 p.m" << endl;
		cout << "Sunday    : 11:00 a.m. to  6:00 p.m" << endl;
		cout << "-------------------------------------" << endl;
		cout << "      This Week's Booked Sessions    " << endl;
		cout << "1. Saturday : 11:00 a.m. to 12:00 p.m." << endl;
		cout << "   Customer Name : Lavinish" << endl;
		cout << endl;
		cout << "2. Sunday   :  1:00 p.m. to  2:00 p.m." << endl;
		cout << "   Customer Name : Leong Kar Ting" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Enter any value to exit: ";
		cin >> exit;
		clearscreen();
		view_individual_expert_schedule();
		break;
	case 3:
		admin_menu();
		break;
	default:
		cout << "Invalid Input. Please select a number from 1-4.";
		view_individual_expert_schedule();
		break;
	}
	return;
}
void view_overall_schedule() {
	int exit;
	cout << "           Overall Schedule          " << endl;
	cout << "-------------------------------------" << endl;
	cout << "           Working Hours             " << endl;
	cout << "Monday    :  9:00 a.m. to  5:00 p.m." << endl;
	cout << "Tuesday   :  9:00 a.m. to  5:00 p.m" << endl;
	cout << "Wednesday :  9:00 a.m. to  5:00 p.m" << endl;
	cout << "Thurday   :  9:00 a.m. to  5:00 p.m" << endl;
	cout << "Friday    :  9:00 a.m. to  9:00 p.m" << endl;
	cout << "Saturday  : 11:00 a.m. to  6:00 p.m" << endl;
	cout << "Sunday    : 11:00 a.m. to  6:00 p.m" << endl;
	cout << "-------------------------------------" << endl;
	cout << "      This Week's Booked Sessions    " << endl;
	cout << "1. Tuesday  : 11:00 a.m. to 12:00 p.m." << endl;
	cout << "   Customer Name : Lee Yong Shen" << endl;
	cout << "   Expert : Mr. Tan" << endl;
	cout << endl;
	cout << "2. Friday   :  1:00 p.m. to  2:00 p.m." << endl;
	cout << "   Customer Name : Tay Wei Jing" << endl;
	cout << "   Expert : Mr. Tan" << endl;
	cout << endl;
	cout << "3. Saturday : 11:00 a.m. to 12:00 p.m." << endl;
	cout << "   Customer Name : Lavinish" << endl;
	cout << "   Expert : Ms. Lee" << endl;
	cout << endl;
	cout << "4. Sunday   :  1:00 p.m. to  2:00 p.m." << endl;
	cout << "   Customer Name : Leong Kar Ting" << endl;
	cout << "   Expert : Ms. Lee" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Enter any value to exit : ";
	cin >> exit;
	clearscreen();
	admin_menu();
	return;
}
void view_customer_list() {
	return;
}
void generate_sales_reports() {}
void view_expert_bonus_entitlements() {}
void admin_menu() {
	int feature_type;
	cout << "             ADMIN MENU             " << endl;
	cout << "------------------------------------" << endl;
	cout << "1. View Individual Expert Schedule" << endl;
	cout << "2. View Overall Schedule          " << endl;
	cout << "3. View Customer List             " << endl;
	cout << "4. Generate Sales Reports         " << endl;
	cout << "5. View Expert Bonus Entitlements " << endl;
	cout << "6. Logout            " << endl;
	cout << "------------------------------------" << endl;
	cout << ">";
	cin >> feature_type;
	clearscreen();
	cout << endl;
	switch (feature_type) {
	case 1:
		view_individual_expert_schedule();
		break;
	case 2:
		view_overall_schedule();
		break;
	case 3:
		view_customer_list();
		break;
	case 4:
		generate_sales_reports();
		break;
	case 5:
		view_expert_bonus_entitlements();
		break;
	case 6:
		main_menu();
		break;
	default:
		cout << "Invalid Input, please enter a value between 1-6." << endl;
		admin_menu();
		break;
	}
	return;
}
void admin_login() {
	string username;
	string password;
	string admin_user = "ansel";
	string admin_pass = "iu123";
	cout << "             ADMIN LOGIN             " << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter username : ";
	cin >> username;
	cout << "Enter password : ";
	cin >> password;
	clearscreen();
	if (username != admin_user || password != admin_pass) {
		cout << "Invalid username or password." << endl;
		cout << "Returning to main menu..." << endl;
		main_menu();
	}
	else {
		cout << endl;
		cout << "Admin Login Successful" << endl;
		cout << "Welcome, " << username << ".";
		cout << endl;
		admin_menu();
	}
	return;
}
//EXPERT MENU
void expert_login() {}
void expert_menu() {}

// LOGIN AND MAIN
void main_menu() {
	int login_type = 0;
	while (login_type < 1 || login_type > 4) {
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
		clearscreen();
		if (login_type < 1 || login_type > 4) {
			cout << "Invalid Input (1-4 Only). Try again." << endl;
		}
		else {
			switch (login_type) {
			case 1:
				customer_login();
				break;
			case 2:
				admin_login();
				break;
			case 3:
				expert_login();
				break;
			case 4:
				cout << " ==== PROGRAM END === " << endl;
				break;
			}
		}
	}
	return;
}


int main() {
	main_menu();
	return 0;
}
#include<iostream>
using namespace std;

enum UserType { admin, expert, customer };
struct services {
	int serviceID = 0;
	string service_name = " ";
	float serviceTime = 0.00; //unit is Hours
};
struct users {
	int userID = 0;
	string username = " ";
	int age = 0;
	char gender = ' ';
	string user_email = " ";
	string user_password = " ";
	UserType user_Type;
	services * specialization[2];
};
int main() {
	int choice_menu = 0, choice_service = 0, choice_expert = 0, choice_timeSlot = 0, numberedlist = 1;
	int* ptr_numberliste = &numberedlist;
	const int arrySize_experts = 10;
	services services_available[4] = {
		{1, "Haircuts & Trims", 3},
		{2, "Bread Grooming", 3},
		{3, "Facial Skin Care", 3},
		{4, "Massage Therapy", 3}
	};
	users experts[arrySize_experts] = {
		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}}, 
		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}}, 
		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}}, 
		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}}
	};
	cout << "Pick one serivces : \n" << "------------------------------\n";
	for (int i = 0; i < 4; ++i) {
		cout << numberedlist << ". " << services_available[i].service_name << endl;
		++numberedlist;
	}
	*ptr_numberliste = 1;
	cout << endl;
	cin >> choice_service;
	// use structure, array, pointers to filter out expert w\ relevant services only
	cout << "\nOur experts that provides " << services_available[choice_service - 1].service_name << ": \n";
	for (int i = 0; i <= 5; ++i) { //using for loop is kinda slow, optimize this
		//cout << i << endl;
		users& expert = experts[i];
		services* spec0 = expert.specialization[0];
		services* spec1 = expert.specialization[1];
		if ((spec0 && spec0->serviceID == choice_service) || (spec1 && spec1->serviceID == choice_service)) {//the services ID starts from 1, so it matches the choice_service
			cout << numberedlist << ". " << experts[i].username << endl;
			++numberedlist;
		}
	}
	cout << "\nWhat experts would you like to book an appointment with ? (enter the corresponding number)\n";
	cin >> choice_expert;
	return 0;
}
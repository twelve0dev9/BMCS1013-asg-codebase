#include<iostream>
using namespace std;
struct users {
	int userID = 0;
	string username = " ";
	int age = 0;
	char gender = ' ';
	string user_email = " ";
	string user_password = " ";
	UserType user_Type;
	services* specialization[2];
};
struct services {
	int serviceID = 0;
	string service_name = " ";
	float serviceTime = 0.00; //unit is Hours
};
int main() {
	services services_available[10] = {
		{1, "Haircuts & Trims", 3},
		{2, "Bread Grooming", 3},
		{3, "Facial Skin Care", 3},
		{4, "Massage Therapy", 3}
	};
	users experts[] = {
		{1, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}}
	};
	int numberedlist = 1;
	const int arrySize_services = 4;
	for (int i = 0; i < 4; ++i){
		cout << numberedlist << ". " << services_available[i].service_name << endl;
		++numberedlist;
	}
	for (int i = 0; i < arrySize_services;++i) {
		if (experts[i].specialization[0]->serviceID == choice_service)
		{
			for (int j = 0; j < i; ++j)
			{
				cout << numberedlist << ". " << experts[i].username << endl;
				++numberedlist;
			}
		}
		else if (experts[i].specialization[1]->serviceID == choice_service) {

		}
	}
	return 0;
}
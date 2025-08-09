#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

enum UserType { admin, expert, customer };
struct services {
	int serviceID = 0;
	string service_name = " ";
	float serviceTime = 0.00; //unit is Hours
};
struct users {//the users records might put under sum kind of function 
	//no point in importing the user records from the file globally when not in use
	int userID = 0;
	string username = " ";
	int age = 0;
	char gender = ' ';
	string user_email = " ";
	string user_password = " ";
	UserType user_Type;
	services* specialization[2];
};
void niga(users experts1[]);
void niga2(users experts2[]);
int main() {
	int choice_expert = 0;
	services services_available[4] = {
		{1, "Haircuts & Trims", 3},
		{2, "Bread Grooming", 3},
		{3, "Facial Skin Care", 3},
		{4, "Massage Therapy", 3}
	};
	users experts[] = {
		{29, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {&services_available[0], &services_available[2]}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {&services_available[1], &services_available[3]}},
		{41, "John", 34, 'M', "johnwaynecas@gmail.com", "apovusbg876trds9", expert, {&services_available[1], &services_available[2]}},
		{42, "Beyonce", 34, 'F', "diddyparty@gmail.com", "nobabyoil", expert, {&services_available[2], &services_available[3]}},
		{10, "Hela", 30, 'M', "helathor@gmail.com", "oyud6759iu41", expert, {&services_available[0], &services_available[1]}}
	};
	users* pExpert = experts;
	cout << sizeof(*pExpert);
	niga(experts);
	return 0;
}
void niga(users experts1[]) {
	for (int i = 0; i < sizeof(*experts1) / sizeof(experts1)[0]; ++i)
	{
		cout << experts1[i].userID << ' ' << experts1[i].username << endl;
		cout << sizeof(*experts1) << "+++" << sizeof(experts1)[0] << endl;
	}
	niga2(experts1);
}
void niga2(users experts2[]) {
	for (int i = 0; i < sizeof(*experts2) / sizeof(experts2)[0]; ++i)
	{
		cout << experts2[i].userID << ' ' << experts2[i].username << endl;
	}
}
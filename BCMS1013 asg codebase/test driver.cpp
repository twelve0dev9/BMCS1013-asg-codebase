#include<iostream>
using namespace std;

enum UserType { admin, expert, customer };
enum Specialization { Haircuts_Trims, Beard_Grooming, FacialSkinCare, MassageTherapy };
enum hourly_timeSlots { slot1, slot2, slot3, slot4, slot5, slot6 };

struct services {
	int serviceID = 0;
	string service_name = " ";
	float serviceTime = 0.00; //unit is Hours
};
services services_available[10] = {
	{1, "Haircuts & Trims", 3},
	{2, "Bread Grooming", 3},
	{3, "Facial Skin Care", 3},
	{4, "Massage Therapy", 3}
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
	Specialization specialization[2]; // 2 because dis it makes more sense, ain't no way u gon have experts serving > 2 services duhh
	services services_specializing_at[10];
};
struct bookings { //for hourly time slots variable
	users book_byCustomer; // pointer (i want the customer name only)
	users expert_booked; // pointer
	bool booking_status = 0; // by default it shudn't be booked unless changed
	int booked_day; //have sum control structures for telling customer user to input valid date of booking this
	hourly_timeSlots booked_timeSlot;
	services service_booked; // smtg connected or linked to the services array we had idk but maybe can apply pointer here
};
int main(){
	users experts[] = {
		{1, "Aina", 24, 'F', "aina2312@gmail.com", "passwordbruh102", expert, {MassageTherapy, Haircuts_Trims}},
		{3, "Hitler", 23, 'M', "sashimidelicious@gmail.com", "anitam4xw8n", expert, {Beard_Grooming, FacialSkinCare}, /*i think dis is whr we need to use pointer*/}
	};																			//to point to the array struct var which we have it as a record for services available on the spa
	users customer_users[] = {
		{4, "pukimakkau", 16, 'M', "expertschaoheweui@gmail.com", "birdbidshit-89632", customer},
		{5, "ishowmeat", 20, 'M', "ishowmeatfrfr@gmail.com", "uncsucks666", customer}
	};
	bookings booked_appointments[] = {
		{customer_users[0], experts[0], 1, 28, slot3, services_available[1]},
		{customer_users[1], experts[0], 1, 23, slot2, services_available[1]}
	};
}
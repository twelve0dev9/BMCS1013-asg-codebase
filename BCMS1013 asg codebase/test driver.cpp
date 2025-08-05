
#include<iostream>
using namespace std;

int main(){
	enum UserType { admin, expert, customer };
	enum Specialization { Haircuts_Trims, Beard_Grooming, FacialSkinCare, MassageTherapy };
	//enum HourlyTimeSlots { 1, 2, 3, 4, 5, 6};

	struct users {
		int userID;
		string username;
		int age;
		char gender;
		string user_email;
		string user_password;
		UserType user_Type;
		Specialization specialization[2]; // 2 because dis it makes more sense, ain't no way u gon have experts serving > 2 services duhh
	};
	users niama;
}
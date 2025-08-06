#include<iostream>
using namespace std;
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
	int numberedlist = 1;
	for (int i = 0; i < 4; ++i){
		cout << numberedlist << ". " << services_available[i].service_name << endl;
		++numberedlist;
	}
	return 0;
}
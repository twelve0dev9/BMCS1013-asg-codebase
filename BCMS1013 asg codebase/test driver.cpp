
#include<iostream>
using namespace std;

int main(){
	struct services {
		int serviceID = 0;
		string service_name = " ";
		float serviceTime = 0.00; // unit : Hours
	};
	services services_available[10] = {
		{1, "Massage Therapy", 3}
	};
	cout << services_available[0].service_name;
}
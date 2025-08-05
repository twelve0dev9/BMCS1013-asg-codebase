#include<iostream>
using namespace std;

int main(){

	enum hourly_timeSlots { slot1, slot2, slot3, slot4, slot5, slot6 };
	int niga[5] = { 1, 2, 3, 4, 5 };
	int * ptr =  hourly_timeSlots;
	for (int i = 0; i < 5; ++i) {
		cout << ptr[i];
	}

	return 0;
}
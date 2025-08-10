#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;

bool checkAlpha(const string& stringVar)
{ // validates if the input provided is alphenumeric or not similar to that of Python
	cout << "Function called .... \n";
	bool yesalnum = 0;
	for (char ch : stringVar) {
		if (isdigit(static_cast<unsigned>(ch)))
		{
			cout << "true";
			yesalnum = 1;
		}
	}
	return yesalnum;
}
int main() {
	int choice_menu;
	cout << "1. View our serivces\n2. Book an appointment\n3. View booked schedule\n4. Exit\n\n";
	cin >> choice_menu;
	cout << checkAlpha(to_string(choice_menu));
	//while (choice_menu < 1 || choice_menu > 4 || checkAlpha(to_string(choice_menu)) == false)
	//{
	//	cout << "Enter valid choice !! : ";
	//	cin >> choice_menu;
	//}
	return 0;
}
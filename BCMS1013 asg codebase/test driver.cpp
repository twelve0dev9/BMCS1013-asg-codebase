#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;

bool isAlphabet(const char* str) // to check if the input is Alphabet or not
{
	for (int i = 0; str[i] != '\0'; ++i) 
	{
		if (!isalpha(str[i])) {
			return false;
		}
	}
	return true;
}
bool isAlphaNum(const char* str) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
{
	for (int i = 0; str[i] != '\0'; ++i) 
	{
		if (!isalnum(str[i])) {
			return false;
		}
	}
	return true;
}
int main() {
	int choice_menu;
	string choice_menuu;
	cout << "1. View our serivces\n2. Book an appointment\n3. View booked schedule\n4. Exit\n\n";
	cin >> choice_menuu;
	//cout << checkAlpha(to_string(choice_menu));
	cout << isAlphabet(choice_menuu.c_str()) << endl;
	while (isAlphabet(choice_menuu.c_str()) == true || 
		isAlphaNum(choice_menuu.c_str()) == false || 
		stoi(choice_menuu) < 1 || stoi(choice_menuu) > 4)
	{
		cout << "Enter valid choice !! : ";
		cin >> choice_menuu;
	}
	return 0;
}
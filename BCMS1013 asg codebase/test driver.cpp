#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;

bool isAlphabet(const char* stringVar) // to check if the input is Alphabet or not
{
	for (int i = 0; stringVar[i] != '\0'; ++i)	{
		if (!isalpha(stringVar[i]))
			return false;}
	return true;
}
bool isAlphaNum(const char* stringVar) // to check if the input has *&%(*& symbols, non-alphabet, & non-numeric
{
	for (int i = 0; stringVar[i] != '\0'; ++i) {
		if (!isalnum(stringVar[i]))
	 		return false;}
	return true;
}
int convertNumeric(const char* stringVar) {
	int choice = stoi(stringVar);
	return choice;
}
int getInput() {
	string input; 
	cout << "Enter an integer between 1 & 4 : ";
	while (true) {
		getline(cin, input);
		// check contains alphabet or not
		if (isAlphabet(input.c_str()) == true) {
			cout << "\nInvalid input. Input contains letters, please enter option 1-4 only : ";
			continue;
		}
		// check for invalid symbols
		if (isAlphaNum(input.c_str()) == false) {
			cout << "\nInvalid input. Input contains symbols, please enter option 1-4 only : ";
			continue;
		}
		// check if input is empty 
		if (input.empty()) {
			cout << "\nInput is empty, please provide option 1-4 : ";
			continue;
		}
		char* endPtr;
		long value = strtol(input.c_str(), &endPtr, 10);
		return static_cast<int>(value);
	}
}
int main()
{
	int choice = getInput();
	cout << endl << choice;

	return 0;
}
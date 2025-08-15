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
	while (true) {
		cout << "Enter an integer between 1 & 4 : ";
		getline(cin, input);
		// check contains alphabet or not
		if (isAlphabet(input.c_str()) == false) {
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

	}
}
int main()
{
	string choice = " ";
	getline(cin, choice);
	cout << isAlphabet(choice.c_str()) << endl << isAlphaNum(choice.c_str()) << endl
		/*<< convertNumeric(choice.c_str()) << endl*/;
	while (true) {
		int choice1;
		
		if ( choice.length() == 1 && isAlphabet(choice.c_str()) == false )
			choice1 = atoi(choice.c_str());
		else
			cout << "unable to convert\n";

		if (   isAlphabet(choice.c_str()) == false
			|| isAlphaNum(choice.c_str()) == false
			|| choice1 < 1 || choice1 > 4 ) {
			cout << "valid input\n";
			break;
		}
		else {
			cout << "Invalid input. Please enter integer only, within 1-4, don't provide alphabets or symbols.\n";
			cin >> choice;
		}
	}
	/*while (isAlphabet(choice.c_str()) == true || isAlphaNum(choice.c_str()) == false
		|| convertNumeric(choice.c_str()) < 1 || convertNumeric(choice.c_str()) > 4) {
	}*/
	//while (true) {
	//	cin >> n;
	//	if (cin.fail()) {
	//		cin.clear();
	//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//		cout << "Please enter integer only\n";
	//		
	//	} else
	//		break;
	//}
	cout << endl << choice;

	return 0;
}
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
int main()
{
	int n = 0; 
	cin >> n;
	cout << isAlphabet(to_string(n).c_str());
	//while (isAlphabet(cstr) == true) {
	//	cout << "Invalid input, integer only.\n";
	//	cin >> n;
	//}
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
	cout << endl << n;

	return 0;
}
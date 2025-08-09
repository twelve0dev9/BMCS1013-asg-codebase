//#include<iostream>
//#include<iomanip>
//#include<string>
//using namespace std;
//
//void customerFunctionalities(int* ptr_numberedList, int* address_numberedList, int numberedList);
//
//int main() {
//	int numberedList = 1;
//	int* ptr_numberedList = &numberedList;
//	cout << ptr_numberedList << endl << &ptr_numberedList << endl << endl;
//	customerFunctionalities(ptr_numberedList, &numberedList, numberedList);
//	return 0;
//}
//
//void customerFunctionalities(int* ptr_numberedList, int* address_numberedList, int numberedList) {
//	cout << "value of numberedList by dereferencing via ptr_numberedList : " << *ptr_numberedList << endl
//		<< ptr_numberedList << endl
//		<< "address of ptr_numberedList : " << &ptr_numberedList << endl
//		<< "value of numberedList (pass by value) : " << numberedList << endl
//		<< "address of numberedList w\ & operator : " << address_numberedList << endl;
//}
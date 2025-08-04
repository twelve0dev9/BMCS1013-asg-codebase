#include<iostream>
using namespace std;

int main() {
	const int row = 5, col = 8;
	int date_day[5][8] = { 
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0, 0} 
	};
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (date_day[i][j] == 0) continue;
			if (date_day[i][j] == 12)
				cout << "\033[1;4m" << date_day[i][j] << "\033[0m ";
			else
				cout << date_day[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
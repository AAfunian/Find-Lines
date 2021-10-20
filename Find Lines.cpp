// Find Lines
// 10.20.2021
// Amir Afunian

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// Looks for specific string in input file, outputs line containing said string
//		with line number in new file
int main() {
	string fname;
	string str;
	cout << "Enter a file name, followed by a word to search for: ";
	cin >> fname >> str;
	ifstream ist{ fname };
	ofstream ost{ "newdata.txt" };
	string temp;
	string temp2;
	string store;
	int line = 0;
	while (true) {
		if (ist.bad() || !ist) {
			cout << "Error! (1)";
			return -1;
		}
		line++;
		getline(ist, temp);
		temp2 = temp;
		for (char& x : temp2) {
			x = tolower(x);
		}
		istringstream is{ temp2 };
		while (is >> store) {
			if (store == str) {
				ost << line << '\t' << temp << '\n';
			}
		}
		if (ist.eof()) return 0;
	}

	return 0;
}
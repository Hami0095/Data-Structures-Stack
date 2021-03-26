// Task 5 : 

#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>


using namespace std;


/*
Create an object of the STL stack of type character. Use this stack to detect whether a string of
0’s and 1’s entered by the user is such a string that it is a repetition of a certain number of
zeroes following by an equal number of ones. For example, the following strings are all of this
type:
01
001101
00110100011101
*/
bool isBinary(char i) {
	if (i == '0' || i == '1')
		return true;
	return false;
}

void Task_5_Part_A() {

	stack<char> s;
	int count_For_Zeros = 0;
	int count_For_Ones = 0;
	string str;


	
	bool flag = false;
	
	// loop to check str is binary or not? 
	getline(cin, str, '\n');

	int Size = str.size();
	int i = 0;
	while (i < Size) {
		if (str[i] == '1' || str[i] == '0') {
			i++;
			continue;
		}
		else {
			cout << "Not a binary string, Enter again : " << endl;
			str.clear();
			getline(cin, str, '\n');
			Size = str.size();
			i = 0;
		}
		
	}

	// putting str in stack
	for (int i = 0; i < Size ; i++) {
		s.push(str[i]);
	}

	// lets check wether str is valid or not?
	while (!s.empty()) {
		if ((s.top() != '0') && (count_For_Zeros == 0)) {
			count_For_Ones++;
			s.pop();
		}
		else if ((s.top() != '0') && (count_For_Zeros != 0)) {
			count_For_Ones = 1;
			count_For_Zeros = 0;
			s.pop();
		}
		else if ((s.top() != '0') && (count_For_Zeros != 0)) {
			if (count_For_Ones != count_For_Zeros) {
				cout << "Invalid String" << endl;
				return;
			}
		}
		else {
			count_For_Zeros++;
			s.pop();
		}
	}
	cout << endl << "Valid String";

}

int main() {
	Task_5_Part_A();
	return 0;
}

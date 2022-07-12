#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <regex>
#include <iomanip>

using namespace std;

string to_lower(string txt) {
	transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
	return txt;
}

//CHECK THIS FUNCTION
int exponentiation(int a, int b) { // a -> first_number(основание степени); b -> second_number(показатель степени)
	for (int i = 1; i < b; ++i) {
		a *= a;
	}
	return a;
}


class Calculator {
private:
	int first_number;
	int second_number;
public:
	//function for words of bot
	void Message_from_bot(string text, double number) {
		cout << "[BOT]: " << text  << fixed << setprecision(1) << number << endl;
		cout << endl;
	}

	//function for user
	void userAsk() {
		cout << "[USER]: ";
	}

	void Calculation(string problem) {
		
		//Variables for work
		string first_n;
		string second_n;
		double result;
		char func; // for find function
		int i = 0;// go through the string
		/*
		//Finding function
		int space = problem.find(' ');
		func = problem[space + 1];

		//finding first number
		first_n = problem.substr(0, space);
		int first_number = atoi(first_n.c_str());
		problem.erase(0, space + 1);

		space = problem.find(' ');

		//finding second number
		second_n = problem.substr(space + 1, problem.length() - 1);
		int second_number = atoi(second_n.c_str());

		//Choose function
		//1 means that we work with functions
		//0 means that we work just with words*/
		int j = 0; // substr numbers

		//parsing the string
		//find first number
		while (problem[j] >= 48 && problem[j] <= 57) {
			j++;
		}
		first_n = problem.substr(0, j);
		int first_number = atoi(first_n.c_str());

		//find the function
		while (problem[j] == ' ') {
			j++;
		}
		func = problem[j];

		//find second number
		j++;
		while (problem[j] == ' ') {
			j++;
		}
		int k = j; //last limit of string of second number
		while (problem[k] >= 48 && problem[k] <= 57) {
			k++;
		}
		second_n = problem.substr(j, k);
		int second_number = atoi(second_n.c_str());


		switch (func)
		{
		case '+':
			result = first_number + second_number;
			Message_from_bot("Result of your problem: ", result);
			break;
		case '-':
			result = first_number - second_number;
			Message_from_bot("Result of your problem: ", result);
			break;
		case '/':
			result = (double)first_number / second_number;
			Message_from_bot("Result of your problem: ",result);
			break;
		case '*':
			result = first_number * second_number;
			Message_from_bot("Result of your problem: ",result);
			break;
		case '^':
			result = exponentiation(first_number, second_number);
			Message_from_bot("Result of your problem: ", result);
			break;
		default:
			cout << "[BOT]: You have a mistake, check your problem" << endl;
			cout << endl;
			break;
		}
	}

};


int main() {
	string problem;
	//Draw a start script
	Calculator object_calcul;
	cout << "[BOT]: Hello, I am smart calculator and i can help you!" << endl << endl;
	for (int i = 0; i < 90; ++i) {
		cout << '-';
	}
	cout << endl;

 
	while (true) {
		object_calcul.userAsk();
		getline(cin, problem);
		cout << endl;
		object_calcul.Calculation(problem);
	}
	
	
}
	
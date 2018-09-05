#include <iostream>

using namespace std;

int main(){
	//Message to the user
	int n;
	cout<<"Enter an integer between 2 and 30,000 as your upper bound."<<endl;
	cin>>n;
	//Check if input is within bounds
	if(n < 2 || n > 30000){
		cout<<"Out of range."<<endl;
		return 0;
	}
	//If the user inputs a non-integer value, it will be truncated, and if no
	//input is given, the program will not continue, so the "Nan" and "Missing
	//Argument" messages are unnecessary.

	return 0;
}

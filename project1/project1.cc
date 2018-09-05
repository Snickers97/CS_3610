#include <iostream>

using namespace std;

int main(){
	//Message to the user
	int n;
	cout<<"Enter an integer between 2 and 30,000 as your upper bound."<<endl;
	cin>>n;
	if(n < 2 || n > 30000){
		cout<<"Out of range."<<endl;
		return 0;
	}
	return 0;
}

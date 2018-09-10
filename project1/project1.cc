#include <iostream>

using namespace std;

/*I found it easier to implement the sieve without using a list structure, and
instead just using a bool array and the loop counter to mark which numbers are
prime and composite*/

int main(){
	int n;
	//Message to the user
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

	//Mark all integers as true initially
	bool isprime[n+1];
	for(int i = 0; i < n+2; i++){
		isprime[i] = true;
	}
	//Set 2 as the first value of p
	for(int p = 2; p*p <= n; p++){
		if(isprime[p]){
			//For each prime, iterate through array and mark multiples of p as
			//composite
			for(int i = p*2; i <= n; i+=p){
				isprime[i] = false;
			}
		}
	}
	//Print all primes
	cout<<"Primes: ";
	for(int i = 2; i <=n; i++){
		if(isprime[i])
			cout<<i<<" ";
	}
	//Print all composites
	cout<<endl<<"Composites: ";
	for(int i = 2; i <=n; i++){
		if(!isprime[i])
			cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}

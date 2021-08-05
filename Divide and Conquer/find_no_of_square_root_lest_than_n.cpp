// find number of perfect squares less than n 
// for example if n = 9 then  1, 4 are only possible perfect square upto 8 
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int find_perfect_squares(int n)
{
	
	// the number of perfect squares which are less than n is nothing but square root of n-1
	int ans = ((sqrt(n-1)));
	return ans;

}

int main()
{
	int n;
	cin>>n;
	cout<<find_perfect_squares(n)<<endl;
	return 0;
}

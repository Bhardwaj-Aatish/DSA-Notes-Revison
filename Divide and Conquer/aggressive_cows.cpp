
// Questions link 
// https://www.spoj.com/problems/AGGRCOW/


#include <iostream>
#include<algorithm>
using namespace std;

bool is_possible(long long arr[], long long n ,long long number_of_cows,long long curr_min)
{
   long long cow_count = 1;
   long long last_cow = arr[0];
   for(long long i=1;i<n;i++)
   {
   	  if(arr[i] - last_cow >= curr_min)
   	  {
           cow_count++;
           last_cow = arr[i];
           if(cow_count == number_of_cows)
           {
           	return true;
           }
   	  }

   }
   return false;
}
long long maximise_distance(long long arr[], long long n , long long number_of_cows)
{
	long long s=0;
	long long e= arr[n-1];
	long long ans = 0;
	while(s<=e)
	{
		long long mid = (s+e)/2;
		if(is_possible(arr, n, number_of_cows ,mid))
		{
		// cout<<"hello"<<endl;
		// cout<<mid<<endl;
			ans = mid;
			s= mid+1;
		}
		else
		{
			// cout<<mid<<endl;
			e= mid-1;
		}
	}
	return ans;
}
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long number_of_cows;
		cin>>number_of_cows;

		long long arr[n];
		for(long long i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr, arr+n);

		cout<<maximise_distance(arr,n, number_of_cows)<<endl;

	}
	return 0;
}
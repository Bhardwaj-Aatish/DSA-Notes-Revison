// question link
// https://www.spoj.com/problems/EKO/

// learning agar sab kuch shi kia ho fir bhi test case pass ho rhe hai
// then use long or long long  instead of int 
#include<iostream>
using namespace std;

bool is_possible(long arr[], long n, long m, long H)
{
	long possible_length=0;

	for(long i=0;i<n;i++)
	{
		if(arr[i] - H > 0)
		{
			possible_length += arr[i]-H;
		}
	}
	if(possible_length>=m)
	{
		return true;
	}
	return false;
}

long find_max_height(long arr[], long n, long m)
{
	long sum =0;
	for(long i=0;i<n;i++)
	{
		sum+=arr[i];
	}

	long s=0;
	long e =sum;
	long ans=0;

	while(s<=e)
	{
		long mid= (s+e)/2;

		if(is_possible(arr,n,m,mid))
		{
			ans = mid;
			s= mid+1;
		}
		else
			e=mid-1;
	}
	return ans;
}
int main()
{
	long n,m;
	cin>>n>>m;
    // n is tree numbers in row and m is required wood length in meter
	long arr[n];
	for(long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<find_max_height(arr,n, m)<<endl;
	return 0;
}
// painter partition problem gfg

#include<iostream>
using namespace std;
bool can_paint_in_this_time(int arr[], int n, int k, long long curr_time)
{
	long long painter_done = 1;
	long long board_done  = arr[0];
	
	if(curr_time<arr[0])
			return false;

	for(int i=1;i<n;i++)
	{
		if(curr_time<arr[i])
			return false;

		// above was the corner case i missed in intern test

		if(arr[i] + board_done > curr_time)
		{
            painter_done++;
            board_done = arr[i];

            if(painter_done> k)
            {
            	return false;
            }
		}
		else
			board_done+=arr[i];
	}
	return true;
}
long long minTime(int arr[], int n, int k)
{
	 long long sum = 0;
	 for(int i=0;i<n;i++)
	 {
	 	sum+=arr[i];
	 }

	 long long s =0;
	 long long e = sum;
	 long long ans = -1;
	 while(s<=e)
	 {
	 	long long mid = (s+e)/2;
	 	if(can_paint_in_this_time(arr,n, k, mid))
	 	{
	 		ans = mid;
	 		e= mid-1;
	 	}
	 	else
	 		s= mid+1;
	 }
	 return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<minTime(arr,n,k)<<endl;
    
	return 0;
}
// Question link
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
bool can_allocate(int arr[], int n , int m ,int curr_pages)
{
	int student_done =1;
	int pages_done= 0;

 	for(int i=0;i<n;i++)
 	{
 		if(arr[i]> curr_pages)
 			return false;

 		//  it was due to the absence of the  above case we are unable to  take s = 0 in starting 
 		if(arr[i]+ pages_done > curr_pages)
 		{ 
           student_done++;
           pages_done= arr[i];
           if(student_done > m)
           {
           	   return false;
           }
 		}
 		else{
 			pages_done+=arr[i];
 			// cout<<"hello"<<endl;
 		}
 	}
 	  
 	return true;
}
int findPages(int arr[], int n, int m)
{

	if(n<m)
	{
		return -1;
	}

	// sort(arr, arr+n);
	int sum=0;
	int maximum= 0;
    for(int i=0;i<n;i++)
    {
    	sum+=arr[i];
    	maximum = max(maximum, arr[i]);
    }

    // sort(arr,arr+n);
	// int s = maximum;
	int s=0;
	// start can be low than this 
	// if i want to use start as 0 then i have to put another condition in can_allocate function
	// if(arr[i]>curr_min)
	// return false;
	int e = sum;
	int ans = INT_MAX;
	while(s<=e)
	{
		int mid = (s+e)/2;

		if(can_allocate(arr, n ,m, mid))
		{
			ans = mid;
			// ans = min(ans, mid);
			e = mid-1;
		}
		else
		{
			s = mid+1;
		}
	}

	return ans;

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		// sort(arr, arr+n);

		// m is the number of students
		int m;
		cin>>m;

		cout<<findPages(arr, n, m)<<endl;
	}
	return 0;
}
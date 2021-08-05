


#include<iostream>
using namespace std;

bool can_make(int arr[], int n, int pratha , int curr_time)
{
	int paratha_cooked = 0;
    for(int i=0;i<n;i++)
    {
        int curr_cook_time=0;
        int j=1;
        while(curr_cook_time+ arr[i]*j <= curr_time)
        {
        	curr_cook_time+=arr[i]*j;
        	j++;
        	paratha_cooked++;
        }
        // cout<<paratha_cooked<<" ";

    }	
    // cout<<endl;
    if(paratha_cooked <pratha)
    {
    	return false;
    }
    return true;
}

int find_minimum_pratha(int arr[], int n , int pratha)
{
	int s=0;
	int e = INT_MAX;
    int minimum_time = 0;


    while(s<=e)
    {
    	int mid = (s+e)/2;
    	if(can_make(arr, n, pratha, mid))
    	{
    		minimum_time= mid;
    		e= mid-1;
    	}
    	else
    	{
    		s=mid+1;
    	}
    }
    // can_make(arr,n,pratha,7);
    return minimum_time;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int pratha;
		cin>>pratha;

		int n;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		cout<<find_minimum_pratha(arr,n,pratha)<<endl;

	}
	return 0;
}
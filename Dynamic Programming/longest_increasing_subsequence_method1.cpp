#include<iostream>
#include<algorithm>
using namespace std;

int findSubsequence(int arr[], int n)
{
	int dp[n];

    // for(int i=0;i<n;i++)
    // {
    // 	cout<<dp[i]<<" ";
    // }
    // cout<<endl;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<=arr[i])
			{
				// dp[i]= max(dp[i],dp[j]+1);
				if(dp[i]<=dp[j])
				{
					dp[i]= dp[j]+1;
				}
			}
		}
		// dp[i]= dp[i]+1;
	}
    

	int lis=0;

	for(int i=0;i<n;i++)
	{
       lis = max(lis, dp[i]);
       // cout<<dp[i]<<" ";
	}
	// cout<<endl;

	return lis;
}
int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<findSubsequence(arr,n);

	return 0;
}
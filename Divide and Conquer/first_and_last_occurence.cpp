#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// vector<int> find_with_stl_function(int arr[], int n, int x)
// {
// 	vector<int> result; 

// 	int first_occurence =-1;
// 	int last_occurence= -1;

//     result.push_back(first_occurence);
//     result.push_back(last_occurence);


// i have to check whether element is present or not with the help of binary search 


//     if(!binary_search(arr,arr+n,x))
//     {
//     	// cout<<"hello"<<endl;
//     	return result;
//     }

// 	auto fs= lower_bound(arr,arr+n, x);
// 	auto ls = upper_bound(arr, arr+n, x);

//     result[0] = fs - arr;
//     result[1] = ls - arr-1;


//     return result;
     
// }

vector<int> find(int arr[] , int n ,int x)
{
	vector<int> result;
	int first_occurence=-1;
	int last_occurence = -1;
	int s = 0;
	int e = n-1;
	while(s<=e)
	{
 		int mid = (s+e)/2;
 		if(arr[mid]==x)
 		{   
 			first_occurence = mid;
 			e = mid-1;
 		}
 		else if(arr[mid]>x)
            e = mid-1;
 		else
 		 s= mid+ 1;
	}

    
    s= 0;
    e = n-1;
	while(s<=e)
	{
 		int mid = (s+e)/2;
 		if(arr[mid]==x)
 		{   
 			last_occurence = mid;
 			s = mid+1;
 		}
 		else if(arr[mid]>x)
            e = mid-1;
 		else
 		 s= mid+ 1;
	}

	result.push_back(first_occurence);
	result.push_back(last_occurence);
	return result;
}
int main()
{
	int n,key;
	cin>>n>>key;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	vector<int> result = find(arr, n, key);
	for(auto x: result)
	{
		cout<<x<<" ";
	}


	 return 0;
}
#include<iostream>
using namespace std;
int search(int A[], int n, int l , int h , int key)
{

     int ans = -1;
     while(l<=h)
     {
         int mid = (l+h)/2;

         if(A[mid]==key)
           {
                 ans = mid;
                 break;
           }
         else if(A[mid]>=A[l])
           {
            
             if(A[mid]>key && key >=A[l] )
             {
                 h = mid-1;
             }
             else 
             {
                 l = mid+1;
             }
           }
         else{
           
             if(A[mid]<key && key<= A[h])
             {
                 l= mid+1;
             }
             else
             {
                 h = mid-1;
             }
             
         }
     }
     
     return ans;	
}
int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}

	int key;
	cin>>key;

	cout<<search(A, n, 0 , n-1, key)<<endl;

	return 0;
}
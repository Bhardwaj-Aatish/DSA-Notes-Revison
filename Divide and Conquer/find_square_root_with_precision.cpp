#include<iostream>
using namespace std;

double find_square_root(int n, int precision)
{
   	double ans = 0;
   	int s = 0;
   	int e = n;
   	while(s<=e)
   	{
   		int mid = (s+e)/2;
   		if(mid*mid== n)
   		{
   			ans = mid;
   			break;
   		}
   		else if(mid*mid < n)
   		{
   			ans = mid;
   			s= mid+1;
   		}
   		else
   		{
   			e =mid-1;
   		}
   	}
     
    double inc= 0.1; 
   	for(int i=1;i<=precision;i++)
   	{
   		while(ans*ans <= n)
   		{
   			ans = ans+ inc;
   			// cout<<ans<<" ";
   		}

   		ans = ans - inc;
        // cout<<inc<<endl;
    	inc = inc/10;

   	}

   	return ans;
}
int main()
{
	int n;
	cin>>n;

	int precision;
	cin>>precision;

	double result = find_square_root(n,precision);
	// cout<<result*result<<endl;
	cout<<result<<endl;

	return 0;
}
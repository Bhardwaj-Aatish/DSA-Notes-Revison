// test case
//  no of student  , no of tokens,   no of required token,  token can be earned by other (y)
   // 5   10   2   1   =>    all five will get scholar 
   // 3   5    5   6    =>   only two will get scholarship

#include <iostream>
using namespace std;
bool isPossible(int n, int m, int x, int y, int students)
{
	 if(students*x <= m + (n - students)*y)
	 {
	 	return true;
	 }
	 return false;
}
int find_no_of_students(int n, int m, int x, int y)
{
	int s = 0;
	int e = n;
	int ans =0;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(isPossible(n,m,x,y,mid))
		{
			ans = mid;
			s= mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return ans;
}
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	cout<<find_no_of_students(n, m, x, y)<<endl;
	return 0;
} 
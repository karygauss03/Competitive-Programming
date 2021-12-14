// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        vector <long long> dp(n + 1, 0);
        
        int mod = 1e9 + 7;
        
        //n-th person have two choices :
            // 1- be single -> n - 1 persons left
            // 2- make a pair -> (N - 1) possibilities -> n - 2 persons left
        
        dp[0] = 1, dp[1] = 1;
        
        for (int i = 2 ; i <= n ; i++){
            dp[i] = ((i - 1) * dp[i - 2] + dp[i - 1]) % mod;
        }
        return dp[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
	return (a>b?a:b);
}
int lis(vector<int> &num, int id, int n){
	vector<int> dp(n,0);
	dp[0] = 1;
	for(int i = id+1;i < id+n; i++){
		for(int j = id;j < i;j++){
			if(num[j] < num[i]){
				dp[i-id] = max(dp[i-id], dp[j-id]);
			}
		}
		dp[i-id]++;
	}
	
	for(int i = 1;i < n;i++)
		dp[0] = max(dp[0],dp[i]);
	
	return dp[0];
}

int main(){
	int t,n,ans;
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		vector<int> num(2*n);
		
		for(int i = 0;i < n;i++){
			cin>>num[i];
			num[i+n] = num[i];
		}
		
		for(int i = 0;i < n;i++)
			ans = max(ans, lis(num,i,n));
		cout<<"\n"<<ans;
	}
}


#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
	return (a>b?a:b);
}

int zigzag(vector<int> &num, int n){
	vector<vector<int> > dp(n, vector<int>(2,0));
	dp[0][0] = dp[0][1] = 1;
	
	for(int i = 1;i < n;i++){
		for(int j = 0;j < i;j++){
			if(num[j] < num[i]){
				dp[i][0] = max(dp[i][0], dp[j][1]);
			}
			else if(num[j] > num[i]){
				dp[i][1] = max(dp[i][1], dp[j][0]);
			}
		}
		dp[i][0]++, dp[i][1]++;
	}
	
	for(int i = 0;i < n;i++){
		dp[0][0] = max(dp[0][0], max(dp[i][0], dp[i][1]));
	}
	return dp[0][0];
}

int main(){
	int n, res = 0;
	cin>>n;
	vector<int> a(n);
	
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	
	res = zigzag(a, n);
	cout<<"\n"<<res;
	return 0;
}

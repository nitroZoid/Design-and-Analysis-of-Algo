#include<bits/stdc++.h>
#define ll long long
using namespace std;
int max(int a, int b){
	return (a>b?a:b);
}

ll numWays(int w, int h, string b){
	vector<vector<ll> > dp(h+1, vector<ll>(w+1, 0));
	vector<vector<int> > side(h+1, vector<int>(w+1, 0));
	vector<int> a(4,0);
	int i = 1, j = 0, num;
	
	while(i != b.size()){
		
		if(b[i] == ','){
			a[j] = num;
			num = 0;
			j = 0;
			
			if(a[1] == a[3]){
				if(side[a[1]][max(a[0], a[2])] == 0) 
					side[a[1]][max(a[0], a[2])] = 1;
				else
					side[a[1]][max(a[0], a[2])] = 3;
			}
			else{
				if(side[max(a[1], a[3])][a[0]] == 0) 
					side[max(a[1], a[3])][a[0]] = 2;
				else
					side[max(a[1], a[3])][a[0]] = 3;
				
			}
			
		}
		else if(b[i] == ' ') a[j++] = num,num = 0;
		else if(b[i] == '\"');
		else{
			num *= 10;
			num += (b[i]-'0');
		}
		
		i++;
	}
	
	dp[0][0] = 1;
	for(int i = 0;i <= h;i++){
		for(int j = 0;j <= w;j++){
			
			if(i == 0 || j == 0){
				
				if(i == 0 && j == 0) continue;
				if(side[i][j] != 0) dp[i][j] = 0;
				else dp[i][j] = (i == 0)?dp[0][j-1]:dp[i-1][0];
				
			}
			else{
				
				if(side[i][j] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
				else if(side[i][j] == 1) dp[i][j] = dp[i-1][j];
				else if(side[i][j] == 2) dp[i][j] = dp[i][j-1];
				
			}
			
		}
	}	
return dp[h][w];
}

int main(){
	int w,h;
	string b;
	cin>>w>>h;
	cin.ignore();
	getline(cin, b);
	b[b.size()-1] = ',';
	
	
	ll ans = numWays(w,h,b);
	cout<<ans;
	return 0;
}

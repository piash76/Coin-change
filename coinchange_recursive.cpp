
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[] = {1, 5 , 10 , 25 , 50 };  ///by taking infinitely
ll dp[6][30001], n, ans;
ll calc(int k , int coin)
{
if(k==5)return 0;
if ( coin <0)return 0;
	if(coin == 0)return 1;  ///for 0 ans is 1

	if(dp[k][coin]!= -1)return dp[k][coin];
	ll ret = 0;

    ret = calc(k,coin - c[k])+calc( k+1,coin);

	return dp[k][coin]=ret;
}
int main() {
memset(dp,-1,sizeof dp);
	while(scanf("%lld" , &n)){
		//memset(dp , -1 , sizeof dp);
	//	dp[1] = 1;
		ans = calc(0,n);
		if(ans != 1)
			printf("There are %lld ways to produce %lld cents change.\n" , ans , n);
		else
			printf("There is only 1 way to produce %lld cents change.\n" , n);
	}
	return 0;
}

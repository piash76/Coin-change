
#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
//
//from a loser
ll dp[105][10005];
ll coins[105];
ll coinchange(ll x,ll n)
{
      for(ll i=0; i <=x; i++){
            dp[i][0] = 1;
        }
        for(ll i=1; i <= x; i++){
            for(ll j=1; j <= n ; j++){
                if(coins[i-1] > j){
                    dp[i][j] = (dp[i-1][j])%mod;
                }
                else{
                    dp[i][j] =( (dp[i][j-coins[i-1]])%mod + (dp[i-1][j])%mod )%mod;
                }
            }
        }
    return dp[x][n];
}

int main()
{

    ll i,j,t,n,k,cas=0;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n>>k;
        for(i=0;i<n;i++) cin>>coins[i];

        ll ans=(coinchange(n,k))%mod;

     printf("Case %lld: %lld\n",++cas,ans%mod);


    }



}

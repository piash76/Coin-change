
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e15;
const int mod=1e9+7;


const int N=500005;

ll dp[10005][22];
ll coins[22];

ll solve(ll i,ll j)
{
    if(i<0) return 0;

    if(j>21) return 0;

    if(i==0) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

   /// ll s=solve(i-j,j)+solve( i,(j+1)*(j+1)*(j+1) );  ///include or exclude
     ll s=solve(i-coins[j],j)+solve( i,(j+1) );  ///include or exclude

    return dp[i][j]=s;


}


int main()
{


    ll t,i,j;

    memset(dp,-1,sizeof(dp));

    for(i=1;i<=21;i++) coins[i]=(i*i*i);

    ll n;
    while(scanf("%lld",&n)!=EOF)
    {

   /// memset(dp,-1,sizeof(dp))

        ll ans=solve(n,1);

        printf("%lld\n",ans);

    }

    return 0;

}





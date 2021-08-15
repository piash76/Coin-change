


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


const int N=8005;

ll coins[]={0,1,5,10,25,50};
ll dp[N][10];


int main()
{

    ll t,i,j;

    ll n;
    while(scanf("%lld",&n)!=EOF)
    {
       /// memset(dp,0,sizeof(dp));

        ll m=5;

        for(i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }

        for(j=0;j<=m;j++)
        {
            dp[0][j]=1;
        }


        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i-coins[j]>=0) dp[i][j]=dp[i][j-1]+dp[i-coins[j]][j];
                else  dp[i][j]=dp[i][j-1];
            }
        }

        ll ans=dp[n][m];

        ///cout<<"ANS "<<ans<<endl;

        printf("%lld\n",ans);






    }

    return 0;

}

/*

17
11
4

*/



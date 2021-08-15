
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


const int N=40005;


ll coins[] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
ll dp[N][15];

int main()
{

    ll t,i,j;

    while(1)
    {
        double x;
        scanf("%lf",&x);

        ll n=round(x*100);

        if(n==0) break;


        ll m=11;

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

        ///cout<<"ANS "<<dp[n][m]<<endl;



        printf("%6.2f%17lld\n",x,dp[n][m]);


    }

    return 0;

}





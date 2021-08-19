

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

ll dp[20005][105];
ll coins[105];

int main()
{

    ll t,i,j;
    scanf("%lld",&t);

    while(t--)
    {
        ll n;scanf("%lld",&n);

        ll m;scanf("%lld",&m);

        for(i=1;i<=m;i++) scanf("%lld",&coins[i]);

        for(i=0;i<=20000;i++) dp[i][0]=inf;

        for(i=0;i<=m;i++) dp[0][i]=0;

        for(i=1;i<=20000;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i-coins[j]>=0)
                {
                    dp[i][j]=min( dp[i][j-1],dp[i-coins[j]][j-1]+1 );

                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }


       /* for(i=0;i<=n+5;i++)
        {
            for(j=0;j<=m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/

        ll ans1,ans2;


        for(i=n;i<=20000;i++)
        {

            if(dp[i][m]!=inf)
            {
                ///cout<<"Dp "<<dp[i][m]<<endl;

                ans1=i;
                ans2=dp[i][m];
                break;
            }
        }


        printf("%lld %lld\n",ans1,ans2);




    }

    return 0;

}




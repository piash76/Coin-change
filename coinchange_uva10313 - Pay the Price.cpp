
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
ll a[N];
ll dp[305][305][305]; ///money , coin , ways

///corner case is 0 for which ans is 0 cause using 0 coins we can make value 0 for 0 ways


ll solve(ll i,ll j,ll k)
{
    if(i<0) return 0;

    if(j>300) return 0;

    if(k<0) return 0;

    if(i==0 and k==0) return 1;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    ll s=solve(i-j,j,k-1)+solve(i,j+1,k);  ///include or exclude

    return dp[i][j][k]=s;


}

char s[25];

int main()
{

    ll t,i,j;

    memset(dp,-1,sizeof(dp));

    while(gets(s))
    {
        ll n,L1,L2;
        ll sz=sscanf(s,"%lld %lld %lld",&n,&L1,&L2);

        ll ans=0;

       ///*
        if(sz==1)
        {
            ll lft=1,rt=300;

            if(n==0) ans=1;
            else
            {
                for(i=lft;i<=rt;i++)
                {
                    ans+=solve(n,1,i);
                }
            }
        }
        else if(sz==2)
        {

            ll lft=1,rt=min(300ll,L1);

            if(n==0) ans=1;
            else
            {
                for(i=lft;i<=rt;i++)
                {
                    ans+=solve(n,1,i);
                }
            }
        }
        else if(sz==3)
        {
           ll lft=L1,rt=min(300ll,L2);

            if(n==0 and L1==0) ans=1;
            else
            {
                for(i=lft;i<=rt;i++)
                {
                    ans+=solve(n,1,i);
                }
            }
        }


       /// cout<<"ANS "<<ans<<endl;

        printf("%lld\n",ans);

       /// */

    }

    return 0;

}



/*


6
6 3
6 2 5
6 1 6


*/

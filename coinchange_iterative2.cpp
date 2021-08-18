#include<bits/stdc++.h>
#define ll long long

using namespace std;


///minimum number of coins to make a change(by taking each coin infinitely )

ll coins[5000];
ll dp[5000][5000];


ll coin_change(ll value,ll coin_no)
{

    for(ll i = 0; i <=coin_no; i++)
    {
         dp[i][0] = 0;
    }




    for(ll j=0;j<=value;j++)
        {
             dp[0][j] =LLONG_MAX;
        }



        ///dp[i][j-1],1+dp[i-coin[j]][j]

    for(ll i = 1; i <=coin_no; i++)
    {
        for(ll j = 1; j <=value; j++)
        {
            if(coins[i] > j)  // cannot pick the highest coin:
                dp[i][j] = dp[i - 1][j];
            else  // choosing the best option:
                dp[i][j] = min(1 + dp[i][j - coins[i]], dp[i -1][j]);
        }
    }
    /*for(ll i=0;i<=coin_no;i++)
    {
        for(ll j=0;j<=value;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[coin_no][value];


}

int main()
{
    memset(dp,0,sizeof(dp));
    ll coin_no;
    cin>>coin_no;
    for(ll i=1;i<=coin_no;i++) cin>>coins[i];  ///idexing from 1;

    ll value;
    cin>>value;

    ll ans=coin_change(value,coin_no);
    cout<<ans<<endl;






    return 0;
}

/*
4
1 5 6 8
11

*/



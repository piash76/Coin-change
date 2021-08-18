#include<bits/stdc++.h>
#define ll long long
using namespace std;
//
//from a loser

/// number of ways to make a value by taking coins (taking each coin infinitely )
ll dp[5000][5000];
ll coins[5000];
ll coinchange(ll value,ll coin_no)
{
      for(ll i=0; i <=coin_no; i++){
            dp[i][0] = 1;
        }
        for(ll i=1; i <= coin_no; i++){
            for(ll j=1; j <= value; j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
            }
        }
      /*  for(ll i=0;i<=coin_no;i++)
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

    ll i,j,t,n;

    while(1)
    {
        memset(dp,0,sizeof(dp));
        ll coin_no;
        cin>>coin_no;
        for(ll i=0;i<coin_no;i++) cin>>coins[i];   ///order doesnot matter ///indexing from 0
        ll value;
        cin>>value;

       ll ans=coinchange(value,coin_no);

    cout<<ans<<endl;
    //if(ans==1) cout << "There is only 1 way to produce " << n << " cents change."<<endl;
    //else  cout << "There are " << ans << " ways to produce " <<n << " cents change."<<endl;

    }



}
/*

2
1 3
2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
  // ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
    ll t,T;
    cin>>t;
    T=t;
    while(t--){
        ll n,i,j,k;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        ll m;
        cin>>m;
        ll b[m];
        for(i=0;i<m;i++)
            cin>>b[i];

        ll dp[n+1][m+1];


        if(a[0]!=b[0])
            dp[0][0]=0;
        else
            dp[0][0]=1;

        for(i=1;i<m;i++){
            if(a[0]!=b[i])
                dp[0][i]=dp[0][i-1];
            else
                dp[0][i]=dp[0][i-1]+1;
        }
        for(i=1;i<n;i++){
            if(b[0]!=a[i])
                dp[i][0]=dp[i-1][0];
            else
                dp[i][0]=dp[i-1][0]+1;
        }


        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else 
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<dp[n-1][m-1]<<"\n ";


    }
  return 0;
}


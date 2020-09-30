#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void editdistance(){
    string a,b;
    cin>>a>>b;
    int n,m;
    n=a.size();
    m=b.size();

    ll dp[n][m];
    ll i,j;
    if(a[n-1]==b[m-1])
        dp[n-1][m-1]=0;
    else
        dp[n-1][m-1]=1;

    for(i=m-2;i>=0;i--){
        if(a[n-1]==b[i])
            dp[n-1][i]=dp[n-1][i+1];
        else
            dp[n-1][i]=dp[n-1][i+1]+1;
    }
    for(i=n-2;i>=0;i--){
        if(b[m-1]==a[i])
            dp[i][m-1]=dp[i+1][m-1];
        else
            dp[i][m-1]=dp[i+1][m-1]+1;
    }

    for(i=n-1;i>=0;i--){
        for(j=m-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j]=dp[i+1][j+1];
            }
            else {
                dp[i][j]=min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]))+1;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[0][0]<<"\n ";
}

int main(){
  // ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
    ll t,T;
    cin>>t;
    T=t;
    while(t--){
        editdistance();
    }
}
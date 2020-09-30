#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool sortbyno(pair<pair<ll,ll>,ll>&a,pair<pair<ll,ll>,ll>&b){
  return (a.second<b.second);
}
bool sortbysec(pair<pair<ll,ll>,ll>&a,pair<pair<ll,ll>,ll>&b){
  return (a.first.second<b.first.second);
}
bool sortsec(pair<ll,ll>&a,pair<ll,ll>&b){
  return (a.second<b.second);
}
int main(){  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  ll t;
  cin>>t;
  ll T=t;
  while(t--){
    ll n;
    cin>>n;
    char ans[n];
    // string ans="#";
    vector<pair<pair<ll,ll>,ll>>vpp;
    ll i;
    for(i=0;i<n;i++){
      ll x,y;
      ans[i]='a';
      cin>>x>>y;
      vpp.push_back(make_pair(make_pair(x,y),i));
      // ans[i]='J';
    } 

    sort(vpp.begin(),vpp.end(),sortbysec);

    ans[vpp[0].second]='C';
    i=0;
    ll k=0;
    // char c='C';
    ll check=0;
    ll j;
    for(j=1;j<n;j++){
      if(i>=k){
        if(vpp[j].first.first>=vpp[i].first.second){
          ans[vpp[j].second]='C';
          i=j;
        }
        else if(vpp[j].first.first>=vpp[k].first.second || k==0){
          ans[vpp[j].second]='J';
          k=j;
        }
        else{
          check=1;
          break;
        }
      }
      else{
        if(vpp[j].first.first>=vpp[k].first.second){
          ans[vpp[j].second]='J';
          k=j;
        }
        else if(vpp[j].first.first>=vpp[i].first.second){
          ans[vpp[j].second]='C';
          i=j;
        }
        else{
          check=1;
          break;
        }
      }
    }
    ans[n]='\0';


    cout<<"Case #"<<T-t<<": ";
    if(check==1)
      cout<<"IMPOSSIBLE\n";
    else{
      cout<<ans;
      cout<<"\n";
    }
  }
}
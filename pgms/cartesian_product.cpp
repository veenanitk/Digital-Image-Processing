#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll M=998244353;

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
}
ll power(ll x,ll y){
    ll res=1;
    x=x%M;
    if(x==0)
        return 0;
    while(y>0){
        if(y&1)
            res=(res*x)%M;
        y=y>>1;
        x=(x*x)%M;
    }
    return res%M;
}

ll modInverse(ll a)
{
    ll m0=998244353, m=998244353;
    ll y = 0, x = 1;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0)
    x += m0;

    return x;
}

void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        cout<<a<<endl;  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(a, l+1, r);  
            //backtrack  
            // swap(a[l], a[i]);  
            // cout<<l<<" "<<r<<" "<<a<<" no \n";
        }  
    }  
} 

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,T;
    cin>>t;
    T=t;
    while(t--){
        ll m;
        cin>>m;
        ll a[m];
        ll mul[m+1];
        mul[0]=1;
        ll i,j;
        vector<ll>v[m];
        for(i=0;i<m;i++){
            cin>>a[i];
            mul[i+1]=mul[i]*a[i];
            for(j=0;j<a[i];j++){
                ll x;
                cin>>x;
                v[i].push_back(x);
            }
        }

        // for(i=0;i<m;i++){
        //     // cout<<a[i]<<" ";
        //     for(j=0;j<a[i];j++)
        //         cout<<v[i][j]<<" ";
        //     cout<<"\n";
        // }


        ll x,y,z;
        vector<ll>ans;
        for(i=0;i<mul[m];i++){
            for(j=0;j<m;j++){
                ll k=(i/mul[j])%a[j];
                ans.push_back(v[j][k]);
            }
            for(auto aa:ans)
                cout<<aa<<" ";
            cout<<"\n";
            ans.clear();
        }
    }
  return 0;
}




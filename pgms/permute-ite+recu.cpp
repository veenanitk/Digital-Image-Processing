#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll M=998244353;


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
            swap(a[l], a[i]);  
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
        string a1,a2;
        cin>>a1;
        a2=a1;
        for(i=0;i<m;i++){
            mul[i+1]=mul[i]*(m-i);
        }

        // for(i=0;i<=m;i++){
        //     cout<<mul[i]<<" ";
        // }
        cout<<"\n";

        for(i=0;i<mul[m];i++){
            for(j=0;j<m;j++){
                ll k=(i/mul[j])%(m-j);
                cout<<k<<" ";
                // cout<<" "<<m-1-j<<"\n";
                swap(a2[m-1-j],a2[m-1-j-k]);
            }
            cout<<a2;
            cout<<"\n";      
            a2=a1;  
        }
    }
  return 0;
}


// [0,0,0] -> 123
// [0,0,1] -> 132 (swap a[2] by a[1])
// [0,0,2] -> 321 (swap a[2] by a[0])
// [0,1,0] -> 213 (swap a[1] by a[0])
// [0,1,1] -> 312 (swap a[2] by a[1] then a[1] by a[0])
// [0,1,2] -> 231 (swap a[2] by a[0] then a[1] by a[0])

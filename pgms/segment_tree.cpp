#include <bits/stdc++.h>
// #include<algorithm.h>
// #include<math.h>

using namespace std;
#define ll long long int
ll n;
ll a[7];
ll maxsize=2*pow(2,(int)ceil(log2(6)))-1;
ll st[10000];

void update(ll x,ll val,ll start,ll end,ll cur){
    if(x<start || x>end)
        return;
    st[cur]+=val;
    
    if(start!=end){
        int mid=(start+end)/2;
        update(x,val,start,mid,cur*2+1);
        update(x,val,mid+1,end,cur*2+2);
    }
}

ll query(ll start,ll end,ll l,ll r,ll cur){
    if(l<=start && r>=end)
        return st[cur];
    if(l>end || r<start)
        return 0;
    int mid=(start+end)/2;
    return query(start,mid,l,r,cur*2+1)+query(mid+1,end,l,r,cur*2+2);
}

ll build(ll start,ll end,ll cur){
    if(start==end){
        st[cur]=a[start];
        // cout<<cur<<" "<<st[cur]<<"\n";
        return st[cur];
    }
    int mid=(start+end)/2;
    st[cur]=build(start,mid,cur*2+1)+build(mid+1,end,cur*2+2);
    return st[cur];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
    ll i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,n-1,0);
    ll l,r;
    // cin>>l>>r;
    // cout<<"query : "<<l<<" "<<r<<" : "<<query(0,n-1,l,r,0)<<"\n";
    
    for(i=0;i<maxsize;i++)
        cout<<st[i]<<" ";
    cout<<"\n";
    ll x,val;
    cin>>x>>val;
    val=val-a[x];
    update(x,val,0,n-1,0);
    cin>>l>>r;
    cout<<"query : "<<l<<" "<<r<<" : "<<query(0,n-1,l,r,0)<<"\n";
    
    
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    for(i=0;i<maxsize;i++)
        cout<<st[i]<<" ";
	return 0;
}
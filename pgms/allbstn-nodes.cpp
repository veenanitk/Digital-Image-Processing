#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node{
  ll key;
  struct node *left,*right;
};

struct node *newnode1(ll item){
  struct node *temp = new node;
  temp->key=item;
  temp->left=temp->right=NULL;
  return temp;
}

void preorder(struct node *root){
  if(root!=NULL){
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

vector<struct node*> construct(ll s, ll e){
  vector<struct node *> ans;
  if(s>e){
    ans.push_back(NULL);
    return ans;
  }
  ll i,j,k;
  for(i=s;i<=e;i++){
    vector<struct node *>ansleft = construct(i+1,e);
    vector<struct node *>ansright = construct(s,i-1);
    for(j=0;j<ansleft.size();j++){
      struct node *left = ansleft[j];
      for(k=0;k<ansright.size();k++){
        struct node *right = ansright[k];
        struct node *node = newnode1(i);
        node->left=left;
        node->right=right;
        ans.push_back(node);
      }
    }
  }
  return ans;
}


int main(){
  ll n;
  cin>>n;
  ll i;
  vector<struct node*> tt = construct ((ll)1,n);
  for(i=0;i<tt.size();i++){
    preorder(tt[i]);
    cout<<"\n";
  }
  cout<<"\n";
  // for(i=0;i<tt1.size();i++){
  //   preorder(tt1[i]);
  //   cout<<"\n";
  // }
  return 0;
}
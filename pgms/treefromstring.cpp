#include<bits/stdc++.h>
using namespace std;
class TNode 
{ 
	public: 
	char data; 
	TNode* left; 
	TNode* right; 
};
vector<char>s; 
TNode* newNode(char data) 
{ 
	TNode* node = new TNode(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
}

void printLevelOrder(int t,TNode *node,int c)  
{  if (node == NULL) 
		return; 	
	if(t==c){
		s.push_back(node->data);
	}	
		printLevelOrder(t-1,node->left,c);
		printLevelOrder(t+1,node->right,c);
} 

int findIndex(string str, int si, int ei) 
{ 
    if (si > ei) 
        return -1;  
    stack<char> s; 
    if(str[si+1]=='.'){
        return si+1;
    } 
    for (int i = si; i <= ei; i++) {  
        if (str[i] == '(') 
            s.push(str[i]);  
        else if (str[i] == ')') {
            if (s.top() == '(') { 
                s.pop(); 

  
                if (s.size()==1){
                	// cout<<i<<endl;
                    return i; 
                }
            } 
        } 
    } 
    return -1; 
} 
  
TNode* treeFromString(string str, int si, int ei) 
{ 
    if (si > ei) 
        return NULL;
        if(str[si]=='.'){
        	return NULL;
        } 
    TNode* root = newNode(str[si]); 
    int index = -1; 
  
    if (si + 1 <= ei && str[si + 1] == '(') 
        index = findIndex(str, si + 1, ei); 
  
    if (index != -1) { 
        root->left = treeFromString(str, si + 2, index - 1); 
  
        root->right = treeFromString(str, index + 1, ei - 1); 
    } 
    return root; 
}

int main(){
	int c;
	cin>>c;
	string s1;
	cin>>s1;

	TNode *root= treeFromString(s1,0,s1.length()-1);
	// preOrder(root); 
	 printLevelOrder(0,root,c);

	 sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	// while(!s.empty()){
	// 	cout<<s.top()<<" ";
	// 	s.pop();
	// }
	return 0;

}
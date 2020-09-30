#include<bits/stdc++.h>
using namespace std;

 bool isnotchar(string x){
 	if(x=="(" || x==")" || x=="+" || x=="*")
 		return false;
 	return true;
 }

  bool ischar(string x){
 	if(x=="(" || x==")" || x=="+" || x=="*")
 		return true;
 	return false;
 }

int preexpe(vector<string>ex){
	stack<string>s;
	int n=ex.size();
	if(ex.size()==1){
		int x=stoi(ex[0]);
		return x;
	}
	for(int i=0;i<n;i++){
		if(ex[i]=="(")
			s.push(ex[i]);
		else if(ex[i]=="+" || ex[i]=="*" || (isnotchar(ex[i]) && ischar(s.top()))){
			s.push(ex[i]);
			
			}
		else if(isnotchar(ex[i]) && isnotchar(s.top())){
			int x=stoi(s.top());
			int y=stoi(ex[i]);
			s.pop();
			string op=s.top();
			s.pop();
			if(op=="+"){
				int ans =x+y;
				if(i+1<n && isnotchar(ex[i+1]))
					s.push(op);
				string str= to_string(ans);
				s.push(str);
			}
			else if(op=="*"){
				int ans =x*y;
				if(i+1<n && isnotchar(ex[i+1]))
					s.push(op);
				string str= to_string(ans);
				s.push(str);
			}
		}
		else{
			int ans;
			while(1){
				ans=stoi(s.top());
				s.pop();
				if(s.top()=="(")
					break;
				int x=stoi(s.top());
				int y=ans;
				s.pop();
				string op=s.top();
				s.pop();
				if(op=="+"){
					ans =x+y;
					if(i+1<n && isnotchar(ex[i+1]))
						s.push(op);
					string str= to_string(ans);
					s.push(str);
				}
				else if(op=="*"){
					ans =x*y;
					if(i+1<n && isnotchar(ex[i+1]))
						s.push(op);
					string str= to_string(ans);
					s.push(str);
				}
			}

			s.pop();
			string str= to_string(ans);
			s.push(str);
		}
			
	}
		int ans=stoi(s.top());
		return ans;
}
			
			
		
int main(){
	int n;
	cin>>n;
	vector<string>v;
	int  i;
	for(i=0;i<n;i++){
		string x;
		cin>>x;
		v.push_back(x);
	}
	cout<<preexpe(v)<<"\n";
}

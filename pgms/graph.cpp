#include<bits/stdc++.h>
using namespace std;
class Graph 
{ 
    int V; 
    list<int> *adj;    
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
    void BFS(int s);   
};   
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
    adj[w].push_back(v); 
}  
void Graph::BFS(int s) 
{ 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
    list<int> queue; 
    int time=0;
    int ans=0,ans1=0,x=0;  
    visited[s] = true; 
    queue.push_back(s); 
    list<int>::iterator i;   
    while(!queue.empty() && time<=ans) 
    { 
        s = queue.front();
        cout<<s+1<<endl; 
        queue.pop_front();    	
    	 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i);

                cout<<"asd"<<(*i)+1<<endl;
                if(x==0){
                	ans++; 
            	}
            	ans1++;
            } 
        }
        x++; 
        time++;
    }
    cout<<ans1; 
} 
int main(){
	int n,e;
	cin>>n>>e;
	Graph g(n);
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		g.addEdge(a-1,b-1);
	}
	int m;
	cin>>m;
	g.BFS(m-1);
	return 0;


}
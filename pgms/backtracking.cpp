#include<bits/stdc++.h>
using namespace std;
#define MAX 50 
int N;
bool solve(int a[][MAX], int x, int y,int visited[][MAX]); 
bool isSafe(int a[][MAX], int x, int y) 
{ 
	if (x >= 0 && x < N && y >= 0 && 
	y < N && a[x][y] != 0) 
		return true; 
	return false; 
} 
bool solve(int a[][MAX], int x, int y,int visited[][MAX],int ans[][MAX]) 
{ 
	if (x == N - 1 && y == N - 1) {
		visited[x][y] = 1; 
		return true; 
	} 
	if (isSafe(a, x, y) == true && visited[x][y]==0) { 
		visited[x][y] = 1; 
		for (int i = 1; i <= a[x][y] && i < N; i++) { 


			if (solve(a, x, y + i, visited,ans) == true){
				ans[x][y]=i; 
				return true; 
			}
			if (solve(a, x + i, y, visited,ans) == true){
				ans[x][y]=i; 
				return true; 
			}			
			if (solve(a, x, y - i, visited,ans) == true ){
				ans[x][y]=i; 
				return true; 
			}
			if (solve(a, x - i, y, visited,ans) == true ){
				ans[x][y]=i; 
				return true; 
			}  
		} 
		visited[x][y] = 0; 
		return false; 
	} 
	return false; 
} 
int main(){
	int i,j;
	cin>>N;
	int a[N][MAX];
	int visited[N][MAX];
	int ans[N][MAX];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin>>a[i][j];
			visited[i][j]=0;
			ans[i][j]=0;
		}
	}
	solve(a, 0, 0, visited,ans);

	ans[N-1][N-1]=1;
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", ans[i][j]); 
		printf("\n"); 
	} 

	return 0;
}
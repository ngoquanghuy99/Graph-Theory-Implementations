/*
Author: Ngo Quang Huy
Problem: Counting the number of paths in an unweighted undirected graph
*/
#include<iostream>
using namespace std;

int const MAX = 1001;
int arr[MAX][MAX], n;
bool unused[MAX];
void init(){
	cin>>n;
	for(int i=1; i<=n; i++){
		unused[i] = true;
		for(int j=1; j<=n; j++)
			cin>>arr[i][j];
	}
}
void DFS(int u){
	cout<<u<<" ";
	unused[u] = false;
	for(int v=1; v<=n; v++){
		if(arr[u][v]==1 && unused[v])
			DFS(v);
	}
}
int main(){
	int count = 0;
	init();
	for(int i=1; i<=n; i++)
		if(unused[i]){
			count++;
			cout<<"TPLT "<<count<<": ";
			DFS(i);
			cout<<endl;
		}
}

#include<iostream>
#include<vector>
using namespace std;
int const nMAX = 100001;
int n, m;
vector <int> ke[nMAX];
bool unused[nMAX];
void input(){
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int u, v;
		cin>>u>>v;
		ke[u].push_back(v);
	//	ke[v].push_back(u);  remove "//" if the graph is undirected
	}
	for(int i=1; i<=n; i++)
		unused[i] = true;
}
void DFS(int u){
	int v;
	cout<<u<<" ";
	unused[u] = false;
	for(int i=0; i<ke[u].size(); i++){
		v = ke[u][i];
		if(unused[v]){
			DFS(v);
		}
	}
	
}
int main(){
	input();
	DFS(1);
	return 0;
}

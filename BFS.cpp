/************************************************\
*                                               *
*	you know that i can't stop thinkin bout you *
*	you're the source of everything i do        *
*                                               *
\************************************************/


#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int> > adj;
bool unused[110];

void init(){
	int u, v;
	cin >>n >> m; 
	adj.resize(n+1);
	while (m--){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void BFS(int u){
	memset(unused, true, sizeof unused);
	queue <int> Q;
	Q.push(u);
	unused[u] = false;
	while(!Q.empty()){
		u = Q.front();
		cout << u << " ";
		Q.pop();
		for(int i = 0; i <adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				Q.push(v);
				unused[v] = false;
			}
		}
	}
}
int main(){
	init();
	BFS(1);
}

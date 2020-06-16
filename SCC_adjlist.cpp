#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int n, m;
const int Max = 100001;
vector <int> adj[Max];
bool unused[Max];

void init(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	//	adj[v].push_back(u);
	}
}

void reinit(){
	for(int i = 1; i <= n; i++) unused[i] = true;
}

void BFS(int u){
	queue <int> Q;
	unused[u] = false;
	Q.push(u);
	while (!Q.empty()){
		u = Q.front();
		Q.pop();
	//	cout << u << " ";
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				Q.push(v);
				unused[v] = false;
			}
		}
	}
}

bool UnVisitedVertex(){
	for(int i = 1; i <= n; i++)
		if(unused[i]) return true;
	return false;
}
bool SCC(){
	init(); reinit();
	for(int i = 1; i <= n; i++){
		BFS(i);
		if(UnVisitedVertex()) return false;
		reinit();
	}
	return true;
}
int main(){
	if(SCC()) cout << "Strongly connected!";
	else cout << "Weakly connected!";
}

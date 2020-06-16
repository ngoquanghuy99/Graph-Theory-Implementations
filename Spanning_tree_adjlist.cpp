/*
Author: Ngo Quang Huy
Problem: Xay dung cay khung cua do thi
*/

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
vector < vector <int> > adj(105);
vector < vector <int> > tree(105);
bool unused[1005];
void init(){
	for(int i = 1; i <= n; i++) unused[i] = true;
}
void DFS(int u){
	unused[u] = false;
	stack <int> S;
	S.push(u);
	while (!S.empty()){
		u = S.top();
		S.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if(unused[v]){
				tree[u].push_back(v);
				tree[v].push_back(u);
				unused[v] = false;
				S.push(u);
				S.push(v);
				break;
			}
		}
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; for(int i = 1; i <= m; i++){int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);	}
	init();
	DFS(1);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < tree[i].size(); i++){
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}
}

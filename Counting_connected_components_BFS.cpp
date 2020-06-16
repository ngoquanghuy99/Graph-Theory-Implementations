/************************************************\
*                                               *
*	you know that i can't stop thinkin bout you *
*	you're the source of everything i do        *
*                                               *
\************************************************/

/* 
Author: Ngo Quang Huy
B17DCCN311
Problem: Counting number of connected components in a graph using BFS
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, a[110][110];
bool unused[110];

void BFS(int u){
	unused[u] = false;
	queue <int> Q;
	Q.push(u);
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i = 1; i <= n; i++){
			if(a[x][i] == 1 && unused[i]){
				Q.push(i);
				unused[i] = false;
			}
		}
	}
}
int TPLT_BFS(int a[][110]){
	memset(unused, true, sizeof unused);
	int connected_components = 0;
	for(int i = 1; i <= n; i++){
		if(unused[i]){
			connected_components++;
			BFS(i);
		}
	}
	return connected_components;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
	cout << TPLT_BFS(a);
}

/************************************************\
*                                               *
*	you know that i can't stop thinkin bout you *
*	you're the source of everything i do        *
*                                               *
\************************************************/

/* 
Author: Ngo Quang Huy
B17DCCN311
Problem: Counting number of connected components of a graph using DFS
*/

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
int n, a[110][110];
bool unused[110];
void DFS(int u){
	unused[u] = false;
	stack <int> S;
	S.push(u);
	while (!S.empty()){
		int x = S.top(); S.pop();
		for(int i = 1; i <= n; i++){
			if(a[x][i] == 1 && unused[i]){
				S.push(x);
				S.push(i);
				unused[i] = false;
				break;
			}
		}
	}
}
int TPLT_DFS(int a[][110]){
	memset(unused, true, sizeof unused);
	int connected_components = 0;
	for(int i = 1; i <= n; i++){
		if(unused[i]){
			connected_components++;
			DFS(i);
		}
	}
	return connected_components;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
	cout << TPLT_DFS(a);
}

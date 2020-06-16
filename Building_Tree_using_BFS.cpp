/************************************************\
*                                               *
*	you know that i can't stop thinkin bout you *
*	you're the source of everything i do        *
*                                               *
\************************************************/

/* 
Author: Ngo Quang Huy
B17DCCN311
Problem: Building a tree using BFS 
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, a[110][110];
bool unused[110];
pair <int, int> T[110];
int sc = 0;

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
				T[sc++] = make_pair(x,i);
			}
		}
	}
}

void display(){
	for(int i = 0; i < sc; i++) cout << T[i].first << " --> " << T[i].second << endl;
}
void T_BFS(int a[][110]){
	memset(unused, true, sizeof unused);
	BFS(1);
	if(sc < n-1) cout << "Do thi khong lien thong!";
	else display();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
	T_BFS(a);
	return 0;
}

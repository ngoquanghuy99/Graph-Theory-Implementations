/*
Author: Ngo Quang Huy
Problem: Find all the articulation points in an unweighted undirected graph
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#define i64 long long
#define pb push_back
#define FOR(i,a,b) for(i64 i=a; i<=b; i++)
#define FORD(i,a,b) for(i64 i=a; i=>b; i--)
#define pq priority_queue
#define mp make_pair;
#define fi first
#define se second

using namespace std;
const i64 mod = 1000000007;
typedef pair<i64,i64> pii;
typedef pair<i64, pii> pip;


/*
int fast_pow(i64 base, i64 n, i64 M){
    if(n==0)
       return 1;
    if(n==1)
    return base;
    i64 halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M){
    return fast_pow(n,M-2,M);
    // should not perform z = (x/y)%M; instead we should perform y2
    // y2 = findMMI_fermat(y,M) then z = (x*y2)%M
}
*/
int n, m, dem;
const int Max = 10001;
bool unused[Max];
vector <int> ke[Max];
void init(){
	cin >> n >> m;
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	FOR(i,1,n) unused[i] = true;
}
void DFS(int u){
	dem  = 1;
	stack <int> s;
	s.push(u);
//	cout << u << " ";
	unused[u] = false;
	while(!s.empty()){
		u = s.top();
		s.pop();
		FOR(i,0,ke[u].size()-1){
			int v = ke[u][i];
			if(unused[v]){
				dem ++;
//				cout << v << " ";
				unused[v] = false;
				s.push(u);
				s.push(v);
			}
		}
	}
}
void reinit(){
	FOR(i,1,n) unused[i] = true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	init();
	FOR(i,1,n){
		unused[i] = false;
		i == 1 ? DFS(2) : DFS(1);
		n - 1 == dem ? cout << "" : cout << i << " is an articulation point!" << endl;
		reinit();
	}
	return 0;
}







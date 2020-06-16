#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define fi first
#define se second
#define mp make_pair
#define FOR(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

const int oo = 1000000110;
typedef pair<int, int> pii;

vector <pii> adj[1001];
int n, m;

int d[1001];

void Dijkstra(){
    priority_queue <pii, vector<pii>, greater<pii> > pQ;
    int i, u, v, du, uv;
    FOR(i,1,n) d[i] = oo;
    d[1] = 0;
    pQ.push(mp(0,1));

    while (pQ.size()){
        u = pQ.top().se;
        du = pQ.top().fi;
        pQ.pop();
        if (du != d[u]) continue;

        for (i = 0; v = adj[u][i].se; i++){
            uv = adj[u][i].fi;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pQ.push(mp(d[v], v));
            }
        }
    }

}

int main(){
	ios_base::sync_with_stdio(false);
    int p, q, i, m, w;
    cin >> n >> m;
    while (m--){
        cin >> p >> q >> w;
        adj[p].push_back(mp(w,q));
        adj[q].push_back(mp(w,p));
    }
    FOR(i,1,n) adj[i].push_back(mp(0,0));
    Dijkstra();
    FOR(i,1,n) cout << "distance from " << 1 << "->" << i << ": " << d[i] << endl;
}

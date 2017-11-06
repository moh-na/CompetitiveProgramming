#include <bits/stdc++.h>

#define PI acos(-1)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define io  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen ("maxflow.in", "r", stdin),freopen ("maxflow.out", "w", stdout);
#define all(v) ((v).begin()), ((v).end())

using namespace std;

typedef pair<int, int> pii;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pli;

int dr[] = {0, 1};
int dc[] = {1, 0};

const int N = 50 * 50 + 5;
const int E = N * 12;
string a[55];

int n, m, cost, change, src, sink;

ll head[N], nxt[2 * E], to[2 * E], cap[2 * E], vis[N], ecnt, visId, all;



inline void addEdge(int u, int v, int c) {
  nxt[ecnt] = head[u];
  to[ecnt] = v;
  cap[ecnt] += c;
  head[u] = ecnt++;
}
inline void addAugEdge(int u, int v, int c) {
  addEdge(u, v, c);
  addEdge(v, u, 0);
}
ll dfs(int u, ll bn) {
  if(u == sink) {
    return bn;
  }
  if(vis[u] == visId) {
    return 0;
  }
  if(bn == 0) {
    return 0;
  }
  vis[u] = visId;
  for(ll k = head[u]; ~k; k = nxt[k]) {
    ll v = to[k];
    ll flow = dfs(v, min(bn, cap[k]));
    if(flow) {
      cap[k] -= flow;
      cap[k ^ 1] += flow;
      return flow;
    } }
  return 0;
}
ll maxFlow() {
  ll flow = 0, cur;
  do {
    visId++;
    cur = dfs(src, 1LL << 60);
    flow += cur;
  }while(cur > 0);
  return flow;
}

void init() {
  memset(head, -1, sizeof head);
}
bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main () {
#ifndef ONLINE_JUDGE
  freopen ("in.txt", "r", stdin);
#endif

  cin >> n >> m >> cost >> change;

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  init();

  src = n * m, sink = n * m + 1;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int u = i * m + j;
      if(a[i][j] == '.') {
        addAugEdge(src, u, change);
      }
      if(a[i][j] == '#') {
        addAugEdge(u, sink, change);
      }
      for(int dir = 0; dir < 2; dir++) {
        int xx = i + dr[dir], yy = j + dc[dir];
        if(!in(xx, yy)) {
          continue;
        }
        int v = xx * m + yy;
        addAugEdge(u, v, cost);
        addAugEdge(v, u, cost);
      }
    }
  }
  ll ans = maxFlow();
  cout << ans << endl;
  return 0;
}
close

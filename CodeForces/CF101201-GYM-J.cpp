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

const int N = 2e5 + 5;

vector <int> add[N], rem[N];

long long ans[N];
long long a[N];
int n, q;



int main () {
#ifndef ONLINE_JUDGE
  freopen ("in.txt", "r", stdin);
#endif
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  for(int i = 0; i < q; i++) {
    ll x;
    int L, R;
    scanf("%lld%d%d", &x, &L, &R);
    L--, R--;
    add[L].push_back(i);
    rem[R + 1].push_back(i);
    ans[i] = x;
  }
  set < pair <long long, int> > st;

  for(int i = 0; i < n; i++) {

    for(auto &x : add[i]) {
      st.insert(make_pair(ans[x], x));
    }

    for(auto &x :rem[i]) {
      st.erase(make_pair(ans[x], x));
    }

    while(true) {
     auto it = st.lower_bound(make_pair(a[i], 0));
      if(it != st.end()) {
        pair <ll, int> temp = *it;
        temp.fi %= a[i];
        ans[temp.se] = temp.fi;
        st.erase(it);
        st.insert(temp);
      } else {
        break;
      }
    }
  }

  for(int i = 0; i < q; i++) {
    printf("%lld\n", ans[i]);
  }

  return 0;
}

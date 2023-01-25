#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("blist");
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> Cows;
    int st, t, b;
    for (int i = 0; i < n; i++) {
        cin >> st >> t >> b;
        Cows.pb({{st, t}, b});
    }
    sort(all(Cows));
    int total = 0;
    for (int i = 0; i < n; i++) {
        int free = total;
        for (int e = i - 1; e >= 0; e--) {
            if (Cows[i].f.f <= Cows[e].f.s) {
                free -= Cows[e].s;
            }
        }
        total += max(0, Cows[i].s - free);
        }
        cout << total;
    return 0;
}

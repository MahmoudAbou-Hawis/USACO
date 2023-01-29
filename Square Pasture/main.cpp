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
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
struct Rect
{
    int x1,y1,x2,y2;
};
int main() {
    setIO("square");
    Rect first,Second;
    cin>>first.x1>>first.y1>>first.x2>>first.y2;
    cin>>Second.x1>>Second.y1>>Second.x2>>Second.y2;
    int l =max( (max(first.x2,Second.x2) - min(first.x1,Second.x1)) , 
                (max(first.y2,Second.y2) - min(first.y1,Second.y1)));
    cout<<l*l;
    return 0;
}

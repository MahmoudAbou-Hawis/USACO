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

int main() {
    setIO("cbarn");
    int n;
    cin>>n;
    vector<int>rooms(n);
    int min_dist = OO;
    int totalCows = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>rooms[i];
        totalCows+=rooms[i];
    }
    int reminder = 0;
    int totalDist = 0;
    for(int i = 0 ; i < n ; i++)
    {
        reminder = totalCows - rooms[i];
        totalDist = 0;
        for(int j = i+1 ; j < n+i ; j++)
        {
            totalDist += reminder;
            reminder-=rooms[j%n];
        }
        min_dist = min(min_dist , totalDist);
    }
    cout<<min_dist;

    return 0;
}

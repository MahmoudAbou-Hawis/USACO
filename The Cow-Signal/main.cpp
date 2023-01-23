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
    setIO("cowsignal");
    int x,y,z;
    cin>>x>>y>>z;
    string last;
    char ch;
    for(int i = 0 ;i < x ;i++)
    {
        for(int j = 0 ; j < y ;j++)
        {
            cin>>ch;
            for(int k = 0 ; k < z ; k++)
            {
                last+=ch;
            }
        }
        for(int q = 0 ; q < z ;q++)
        {
            cout<<last<<'\n';
        }
        last = "";
    }

    return 0;
}
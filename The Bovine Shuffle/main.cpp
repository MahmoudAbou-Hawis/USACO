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
    setIO("shuffle");
    int n;
    cin>>n;
    vector<int>pos(n+1),Cows(n),result(n);
    int num;
    for(int i = 0 ; i < n ;i++)
    {
        cin>>num;
        pos[num] = i;
    }

    for(int i = 0 ; i < n ;i++)
    {
        cin>>Cows[i];
    }
    int j , initialPos;
    for(int i = 0 ; i < n ; i++)
    {
        j = 0;
        initialPos = i;
        while(j < 3)
        {
            initialPos = pos[initialPos+1];
            j++;
        }
        result[initialPos] = Cows[i];
    }
    for(auto &i : result)
    {
        cout<<i<<'\n';
    }
    return 0;
}

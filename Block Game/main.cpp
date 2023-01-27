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
    setIO("blocks");
    int n;
    cin>>n;
    vector<int>alphapet(26,0);
    string firstPart,secondPart;
    for(int i =0; i < n ; i++)
    {
        cin >> firstPart >> secondPart;
        vector<pair<int,int>>freq(26);
        for(int j = 0 ; j < sz(firstPart) ; j++)
        {
            freq[firstPart[j]-'a'].first++;
        }
          for(int j = 0 ; j < sz(secondPart) ; j++)
        {
            freq[secondPart[j]-'a'].second++;
        }
        for(int j = 0 ; j < 26 ; j++)
        {
            alphapet[j] += max(freq[j].first , freq[j].second);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout<<alphapet[i]<<'\n';
    }
    

    return 0;
}

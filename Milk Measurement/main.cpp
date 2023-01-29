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
    setIO("measurement");
    int n;
    cin >> n;
    int MAX_Score,last = 7,current = 7,result =0;
    map<string,int>Cow = {{"Mildred" ,7},{"Elsie",7},{"Bessie",7}};
    vector<pair<int,pair<string,int>>>input(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>input[i].f >> input[i].s.f >> input[i].s.s ;
    }
    sort(all(input));
    for(int i = 0 ; i < n ; i++)
    {
        Cow[input[i].s.f] += input[i].s.s;
        MAX_Score = max(Cow["Mildred"] , max(Cow["Elsie"],Cow["Bessie"]));
        int idx = 0;
        for(auto &[cow,score] : Cow)
        {
            current = (score!=MAX_Score)?(current&~(1<<idx++)):(current|(1<<idx++));
        }
        if(current != last)result++;
        last = current;
    }
    cout<<result;
    return 0;
}

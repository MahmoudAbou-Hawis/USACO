#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
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
const long long int MOD=1e9 + 7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 7 ;

void setIO(string name = "") {
    Code By Abou_Hawis
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct Cow
{
    int start = 0;
    int end = 0;
    bool operator < (const Cow &cow) const
    {
        if(start != cow.start)
            return start < cow.start;
        else
            return end < cow.end;
    }
    bool operator == (const Cow &cow) const
    {
        return (start == cow.start && end == cow.end);
    }
};

Cow calculateRange(Cow first_point , Cow second_point)
{
    if(second_point.end <= first_point.end)
    {
        return first_point;
    }
    if(second_point.start <= first_point.end )
    {
        return {first_point.start , second_point.end};
    }
    else
    {
        return second_point;
    }
} 

int main()
{
    setIO("lifeguards");
    int number_of_lifeguards;
    cin >> number_of_lifeguards;
    vector<Cow>cows(number_of_lifeguards);
    for(int i = 0 ; i < number_of_lifeguards ; i++)
    {
        cin >> cows[i].start >> cows[i].end;
    }
    sort(all(cows));
    cows.pb({1005,1005});
    ll mx = 0;
    for(int i = 0 ; i < number_of_lifeguards ; i++)
    {
        Cow range = {0,0};
        ll temp = 0;
        for(int e = 0 ; e < number_of_lifeguards +1 ; e++)
        {
            if(e == i) continue;
            Cow NewRange = calculateRange(range ,cows[e]);
            if(NewRange == cows[e])
            {
                temp += (range.end - range.start);
            }
            range = NewRange;
        }
        mx = max(mx , temp);
    }
    cout << mx;
    return 0;   
}
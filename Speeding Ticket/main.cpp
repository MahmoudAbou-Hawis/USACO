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
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long long int LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const int N = 1e5 + 7;

void setIO(string name = "")
{
    Code By Abou_Hawis if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("speeding");
    
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> road_data(N);
    vector<pair<int, int>> cow_data(M);

    for(auto &i : road_data)
    {
        cin >> i.first;
        cin >> i.second;
    }

    for(auto &i : cow_data)
    {
        cin >> i.first;
        cin >> i.second;
    }

    int road_segment_ptr = 0;
    int cow_segment_ptr  = 0;

    int max_speed = 0;

    while(road_segment_ptr < N && cow_segment_ptr < M)
    {
        auto &[road_segment, road_speed] = road_data[road_segment_ptr];
        auto &[cow_segment, cow_speed] = cow_data[cow_segment_ptr];

        if(road_speed < cow_speed)
        {
            max_speed = max(max_speed , cow_speed - road_speed);
        }

        int remeining_segment = road_segment - cow_segment;

        if(remeining_segment > 0)
        {
            road_segment = remeining_segment;
            cow_segment_ptr++;
        }
        else if(remeining_segment == 0)
        {
            road_segment_ptr++;
            cow_segment_ptr++;
        }
        else
        {
            cow_segment = -remeining_segment;
            road_segment_ptr++;
        }
    }

    cout << max_speed;
    return 0;
}
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
    setIO("balancing");
    int number_of_pairs, max_size;
    cin >> number_of_pairs >> max_size;
    vector<pair<int, int>> pairs(number_of_pairs);
    for (int i = 0; i < number_of_pairs; i++)
    {
        cin >> pairs[i].first >> pairs[i].second;
    }

    int max_number_of_cows_in_region = INT32_MAX;
    for (int i = 0; i < number_of_pairs; i++)
    {
        for (int j = 0; j < number_of_pairs; j++)
        {
            pi two_fences_cross_at_the_point = {pairs[i].first + 1, pairs[j].second + 1};
            int top_right = 0;
            int top_left = 0;
            int down_right = 0;
            int down_left = 0;
            for (int e = 0; e < number_of_pairs; e++)
            {
                if (pairs[e].first < two_fences_cross_at_the_point.first &&
                    pairs[e].second < two_fences_cross_at_the_point.second)
                {
                    down_left++;
                }
                else if (pairs[e].first < two_fences_cross_at_the_point.first &&
                         pairs[e].second > two_fences_cross_at_the_point.second)
                {
                    top_left++;
                }
                else if (pairs[e].first > two_fences_cross_at_the_point.first &&
                         pairs[e].second > two_fences_cross_at_the_point.second)
                {
                    top_right++;
                }
                else if (pairs[e].first > two_fences_cross_at_the_point.first &&
                         pairs[e].second < two_fences_cross_at_the_point.second)
                {
                    down_right++;
                }
            }
            max_number_of_cows_in_region = min(max_number_of_cows_in_region,
                                               max({top_right,
                                                    top_left,
                                                    down_right,
                                                    down_left}));
        }
    }
    cout << max_number_of_cows_in_region;
    return 0;
}
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
    setIO("guess");
    int number_of_animal;
    cin >> number_of_animal;
    vector<set<string>> Animal_with_characteristic(number_of_animal);
    for (int i = 0; i < number_of_animal; i++)
    {
        string animal;
        cin >> animal;
        int number_of_characteristics;
        cin >> number_of_characteristics;
        string characteristic;
        for (int j = 0; j < number_of_characteristics; j++)
        {
            cin >> characteristic;
            Animal_with_characteristic[i].insert(characteristic);
        }
    }
    int max_yes = 0;
    for (int i = 0; i < number_of_animal; i++)
    {
        for (int j = i + 1; j < number_of_animal; j++)
        {
            int similarity = 0;
            for (auto &i : Animal_with_characteristic[i])
            {
                if (Animal_with_characteristic[j].find(i) != Animal_with_characteristic[j].end())
                {
                    similarity++;
                }
            }
            max_yes = max(max_yes, similarity);
        }
    }
    cout << max_yes + 1;
    return 0;
}
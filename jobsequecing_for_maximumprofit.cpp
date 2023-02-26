#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pint unsigned int
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int, int>
#define endl "\n"
#define nline cout << "\n"
#define print(x) cout << x << " "
#define siz(x) x.size()
#define trav(a) for (auto x : a)
#define trav2(a) for (auto y : a)
#define range(arr) arr.begin(), arr.end()
#define leftpoint "👈"
#define rightpoint "👉"
#define downpoint "👇"
#define uppoint "👆"
#define fire "🔥"
#define star "⭐"
#define smile "😃"
#define smile2 "👺"
#define debline(x) cout << "👉Line-" << __LINE__ << ": " << #x << " = " << x << endl
#define linebreak2(x) cout << "🟢" << #x << " = " << x << "________________🟢 " << endl
#define all(x) x.begin() x.end()
#define deb(x) cout << #x << "= " << x << "\n"
#define deb2(a, b) cout << #a << "= " << a << " | " << #b << "= " << b << "\n"
#define deb3(a, b, c) cout << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "=" << c << "\n"
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "\n"                              \
                        << "_______________________________" \
                        << "\n"                              \
                           "\n"
#define forn(i, start, n) for (auto i = start; i < n; i++)
#define io_faster                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int MOD = 1000000007;
double PI = 4 * atan(1);

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
void solve()
{
    // vector<Job> v = {{1, 4, 20},
    //                  {2, 1, 10},
    //                  {3, 1, 40},
    //                  {4, 1, 30}};
    vector<Job> v = {{1, 2, 100},
                     {2, 1, 19},
                     {3, 2, 27},
                     {4, 1, 25},
                     {5, 1, 15}};

    int maxslotavl = 0;
    trav(v)
    {
        deb3(x.id, x.dead, x.profit);
        maxslotavl = max(maxslotavl, x.dead);
    }
    sort(range(v), [](Job j1, Job j2)
         { 
        if(j1.profit<j2.profit) return 0;
        return 1; });

    linebreak1;
    trav(v)
    {
        deb3(x.id, x.dead, x.profit);
    }
    debline(maxslotavl);
    vi ans(maxslotavl, -1);
    int t = 0;
    int cnt = 0;
    trav(v)
    {
        int i = x.dead;
        while (i >= 1 and ans[i - 1] != -1)
            i--;
        if (i != 0)
        {

            ans[i - 1] = x.profit;
            t += x.profit;
            cnt++;
        }
    }
    debline(cnt);
    debline(t);
}

int main()
{
    io_faster
    file();
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
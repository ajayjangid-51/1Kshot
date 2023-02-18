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
#define size(x) x.size()
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
#define linebreak1 cout << "_______________________________" \
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
class LFUCache
{
private:
    map<int, int> valuem;
    map<int, int> freqm;
    map<int, list<int>> listm;
    int minf = 0; // minimum avialable frequency.
    int c = 0;

public:
    LFUCache(int capacity)
    {
        c = capacity;
    }

    int get(int key)
    {
        if (valuem.find(key) == valuem.end())
        {
            return -1;
        }
        int f = freqm[key];
        freqm[key]++;
        listm[f].remove(key);
        if (f == minf and size(listm[f]) == 0)
        {
            minf++;
        }

        listm[freqm[key]].push_back(key);

        return valuem[key];
    }

    void put(int key, int value)
    {
        if (c <= 0)
            return;
        // if key already present:-
        if (valuem.find(key) != valuem.end())
        {
            valuem[key] = value;
            get(key);
            return;
        }
        // if cache is full
        if (size(valuem) == c)
        {
            valuem.erase(listm[minf].front());
            listm[minf].pop_front();
        }
        valuem[key] = value;
        freqm[key] = 1;
        minf = 1;
        listm[freqm[key]].push_back(key);
    }
};
void solve()
{
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
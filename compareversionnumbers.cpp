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
vi fn(string s1)
{
    int n = size(s1);
    int i = 0, j = 0;
    vi v1;
    string s;
    while (j < n)
    {
        if (s1[j] == '.')
        {
            v1.push_back(stoi(s));
            i = j + 1;
            s.clear();
        }
        else
        {
            s.push_back(s1[j]);
        }
        j++;
    }
    v1.push_back(stoi(s));

    return v1;
}

void solve()
{
    string s1("1.32.3.500");
    string s2("1.32");
    vector<int> v1 = fn(s1), v2 = fn(s2);
    int n1 = size(v1), n2 = size(v2);
    int mx = max(n1, n2);

    for (int i = 0; i < mx; i++)
    {
        if (i >= n1)
            v1.push_back(0);
        if (i >= n2)
            v2.push_back(0);
        if (v1[i] < v2[i])
        {
            deb(i);
            deb("-1");
            return;
        }
        else if (v1[i] > v2[i])
        {
            deb("1");
            return;
        }
    }

    deb("true");
    // return;
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
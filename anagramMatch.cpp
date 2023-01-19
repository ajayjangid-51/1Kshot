#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
#define deb(x) cout << #x << " = " << x << endl
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
const int p = 31;
const int m = 1e9 + 9;

vector<long long> pow_p;
vector<long long> h;

void precompute_powers(int n)
{
    pow_p.resize(n);
    pow_p[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pow_p[i] = (p * pow_p[i - 1]) % m;
    }
}

void compute_hash(string s)
{
    int n = s.length();
    h.resize(n + 1);
    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * pow_p[i]) % m;
    }
}
vector<long long> compute_hashB(string B)
{
    int n = B.size();
    vector<long long> h(n + 1);
    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (B[i] - 'a' + 1) * pow_p[i]) % m;
    }
    return h;
}

long long get_hash(int l, int r)
{
    return (h[r] - h[l - 1] + m) % m;
}
void solve()
{
    string A = "jdlidfa";
    vector<string> B = {"daf", "fad", "ifd"};
    int n = A.length();
    precompute_powers(100001);
    compute_hash(A);
    trav(B)
    {
        int ans = 0;
        vector<long long> bh = compute_hashB(x);
        long long bhash = bh[x.size()];
        deb(bhash);
        for (int i = 0; i + x.size() - 1 < n; i++)
        {
            long long ahash = get_hash(i, i + x.size() - 1);
            if (ahash == bhash)
                ans++;
        }
        debline(ans);
    }
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
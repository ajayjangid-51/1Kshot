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

vector<int> prime_mapping(26);

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void precompute_mapping()
{
    prime_mapping[0] = 2;
    for (int i = 1; i < 26; i++)
    {
        prime_mapping[i] = prime_mapping[i - 1] + 1;
        while (!is_prime(prime_mapping[i]))
            prime_mapping[i]++;
    }
}

vector<long long> compute_hash(string s)
{
    int n = s.length();
    vector<long long> h(n + 1);
    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (prime_mapping[s[i] - 'a'])) % m;
    }
    return h;
}
long long get_hash(int l, int r, vector<long long> &h)
{
    // return (h[r] - h[l - 1] + m) % m;
    // deb(l);
    // deb(r);
    if (l == 0)
        return h[r + 1];
    // return (h[r] - h[l - 1] + m) % m;
    return (h[r + 1] - h[l]);
}

void solve()
{
    string A("jdlidfa");
    // string B("fad");
    vector<string> B = {"daf", "ifd", "dxzjbltsmufythgm", "l"};
    precompute_mapping();
    vector<long long> ah = compute_hash(A);
    linebreak1;
    trav(ah) print(x);
    linebreak1;

    trav(B)
    {
        if (x.size() > A.size())
        {
            deb("0");
            continue;
        }
        // deb(x);
        vector<long long> bh = compute_hash(x);
        trav(bh) print(x);
        nline;
        long long bhash = bh[x.size()];
        // debline(bhash);
        int cnt = 0;

        for (int i = 0; i < A.size(); i++)
        {
            long long assh = get_hash(i, i + x.size() - 1, ah);
            // deb(assh);
            if (bhash == assh)
            {
                cnt++;
            }
        }

        deb(cnt);
        linebreak1;
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
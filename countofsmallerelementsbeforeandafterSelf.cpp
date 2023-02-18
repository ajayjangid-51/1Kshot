#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
// #define size(x) x.size()

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
#define deb4(a, b, c, d) cout << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "=" << c << #d << "=" << d << "\n"
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
void fn(int i, int j, vector<pii> &A, vector<int> &count)
{
    if (i >= j)
    {
        return;
    }
    int mid = (i + j) / 2;
    fn(i, mid, A, count);
    fn(mid + 1, j, A, count);
    int i1 = i, j1 = mid + 1;
    int cnt = 0;
    // vi merged;
    vector<pii> merged;
    while (i1 <= mid and j1 <= j)
    {
        if (A[i1].first > A[j1].first)
        {
            cnt++;
            merged.push_back(A[j1]);
            j1++;
        }
        else
        {
            merged.push_back(A[i1]);
            count[A[i1].second] += cnt;
            i1++;
        }
    }

    while (i1 <= mid)
    {
        count[A[i1].second] += cnt;
        merged.push_back(A[i1++]);
    }
    while (j1 <= j)
    {
        merged.push_back(A[j1++]);
    }
    // linebreak1;
    // trav(merged) print(x);
    // linebreak1;
    int k = i;
    for (auto x : merged)
    {
        A[k++] = x;
    }
    // print(smile2);
    // trav(A) print(x);
    // linebreak1;
}

void solve()
{
    // vi A = {5, 2, 3, 4, 1};
    // vi A = {1};
    vi A = {1, 4, 9, 8, 3, 7, 6, 5, 2};
    vector<pii> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back({A[i], i});
    }

    int n = A.size();
    vi count(n, 0);
    fn(0, n - 1, v, count);
    linebreak1;
    trav(count) print(x);
    linebreak1;
    // return count;
    vi ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int sr = count[i];
        int sl = (A[i] - 1) - sr;

        int gr = (n - 1 - i) - sr;
        int gl = (n - A[i]) - gr;

        int t = (sl * sr) - (gl * gr);
        deb4(sl, sr, gl, gr);
        deb(t);
        if (t >= 0)
            ans[i] = 1;
        else
            ans[i] = -1;
    }
    linebreak1;
    trav(ans) print(x);
    linebreak1;
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
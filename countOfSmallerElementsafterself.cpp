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
// vector<int> fn(int i, int j, vi &A, map<int, int> &count)
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
    vi A = {5, 2, 5, 2, 1};
    // vi A = {26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83, 51, 98, 69, 81, 32, 78, 28, 94, 13, 2, 97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41};
    vi A2 = A;
    vector<pii> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back({A[i], i});
    }

    int n = A.size();
    vi count(n, 0);
    fn(0, n - 1, v, count);
    linebreak1;
    trav(count)
    {
        print(x);
    }
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
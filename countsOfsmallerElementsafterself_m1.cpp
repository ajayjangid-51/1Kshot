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
#define trav(A) for (auto x : A)
#define vi vector<int>
class Solution
{
public:
    vector<int> fn(int i, int j, vi &A, map<int, int> &count)
    {
        if (i >= j)
        {
            return {A[i]};
        }
        int mid = (i + j) / 2;
        vi left = fn(i, mid, A, count);
        vi right = fn(mid + 1, j, A, count);
        int i1 = 0, j1 = 0;
        int cnt = 0;
        vi merged;
        while (i1 < left.size() and j1 < right.size())
        {
            if (left[i1] > right[j1])
            {
                cnt++;
                merged.push_back(right[j1]);
                j1++;
            }
            else
            {
                merged.push_back(left[i1]);
                count[left[i1]] += cnt;
                i1++;
            }
        }
        while (i1 < left.size())
        {
            count[left[i1]] += cnt;
            merged.push_back(left[i1++]);
        }
        while (j1 < right.size())
        {
            merged.push_back(right[j1++]);
        }
        return merged;
    }

    vector<int> countSmaller(vector<int> &A)
    {
        int n = A.size();
        map<int, int> count;
        fn(0, n - 1, A, count);
        vi cnt(n);
        int i = 0;
        trav(A)
        {
            cnt[i++] = count[x];
        }
        return cnt;
    }
};
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
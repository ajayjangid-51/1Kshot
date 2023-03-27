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
int ans;
vi merge(vi &v1, vi &v2)
{

    vi v(v1.size() + v2.size());
    int k = 0;
    int i = 0, j = 0;
    while (i < v1.size() and j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            v[k++] = v1[i++];
        }
        else
        {
            v[k++] = v2[j++];
        }
    }
    while (i < v1.size())
    {
        v[k++] = v1[i++];
    }
    while (j < v2.size())
    {
        v[k++] = v2[j++];
    }
    // linebreak1;
    // trav(v) print(x);
    // linebreak1;
    // debline(v.size());
    return v;
}
vi reversepairs(int s, int e, vi &v)
{
    if (s > e)
        return {};

    if (s == e)
    {
        return {v[s]};
    }

    int mid = (s + e) / 2;
    vi v1 = reversepairs(s, mid, v);
    vi v2 = reversepairs(mid + 1, e, v);
    // compare
    int i = 0, j = 0;
    while (i < v1.size())
    {
        if (v1[i] > 2 * v2[j])
        {
            j++;
        }
        else
        {
            ans += j;
            i++;
        }
    }

    // merge
    return merge(v1, v2);
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // find reversepairs , mtlb (i,j) is reversepair if v[i]>2*v[j] and i<j(mtlb j should be in rightside of i).
    // give timecomplexity is nlogn, so mtlb here logn mtlb we have do divide-and-conquer startergy bcoz by this only we can achive logn time. so divide the array in two-parts and then see what can be done further:-
    // eg. 1 3 2 3 1
    // 1 3 2   and  3 1
    // now we can again use the same stargegy bcoz nothing has changed, bs array ki size choti huyi hai, mtlb we are on the subproblem of the given problem. so mtlb we can solve it recursively mtlb whereas "recursively" ka mtlb same logic bar-bar choti-se-choti subproblem meh lagana..

    ans = 0;
    reversepairs(0, n - 1, v);
    debline(ans);
}

int main()
{
    io_faster
    file();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
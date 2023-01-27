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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *fn(int i, int j, int &inx, vi &pre, vi &in)
{
    if (i > j)
        return NULL;
    TreeNode *node = NULL;
    for (int k = i; k <= j; k++)
    {
        if (inx < pre.size() and in[k] == pre[inx])
        {
            node = new TreeNode(pre[inx]);
            inx++;
            node->left = fn(i, k - 1, inx, pre, in);
            node->right = fn(k + 1, j, inx, pre, in);
        }
    }
    return node;
}
void preTrav(TreeNode *node)
{
    if (!node)
        return;
    print(node->val);
    preTrav(node->left);
    preTrav(node->right);
}
void solve()
{
    // vi pre = {3, 9, 20, 15, 7};
    // vi in = {9, 3, 15, 20, 7};
    vi pre = {1, 2};
    vi in = {1, 2};
    int n = pre.size();
    int inx = 0;

    TreeNode *rt = fn(0, n - 1, inx, pre, in);
    deb("HI");
    // preTrav(rt);
    deb(rt->val);
    deb(rt->left);
    deb(rt->right->val);
    deb(rt->right->left);
    deb(rt->right->right);
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
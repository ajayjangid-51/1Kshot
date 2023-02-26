#include <bits/stdc++.h>
using namespace std;

// #define ll long long
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// tuple<size , h, l>
tuple<int, int, int, int> po(TreeNode *node, int &sum)
{
    if (!node->left and !node->right)
    {
        debline(node->val);
        sum = max(sum, node->val);
        return {1, node->val, node->val, node->val};
    }
    // int sl = 0, hl = INT_MAX, ll = INT_MIN, suml = 0;
    // int sr = 0, hr = INT_MAX, lr = INT_MIN, sumr = 0; // hr(highest in right) , lr(lowest in right).
    int sl = 0, hl = INT_MIN, ll = INT_MAX, suml = 0;
    int sr = 0, hr = INT_MIN, lr = INT_MAX, sumr = 0; // hr(highest in right) , lr(lowest in right).
    if (node->left)
        tie(sl, hl, ll, suml) = po(node->left, sum);
    if (node->right)
        tie(sr, hr, lr, sumr) = po(node->right, sum);

    if (node->val > hl and node->val < lr)
    {
        deb3(node->val, hl, lr);
        debline(node->val);
        debline(sl + sr + 1);
        // troot = node;
        sum = max(sum, suml + sumr + node->val);
        deb2(sum, smile2);
        int H = max(hl, max(hr, node->val));
        int L = min(lr, min(ll, node->val));
        // return {sl + sr + 1, max(hl, hr), min(ll, lr), suml + sumr + node->val};
        return {sl + sr + 1, H, L, suml + sumr + node->val};
    }
    // return {0, INT_MIN, INT_MAX};
    return {0, INT_MAX, INT_MIN, 0};
}

int dfs(TreeNode *node)
{
    if (!node)
        return 0;
    return node->val + dfs(node->left) + dfs(node->right);
}
void solve()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);
    // root->left->left = new TreeNode(3);
    // // root->left->right = new TreeNode(NULL);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(3);
    // root->right = new TreeNode(8);
    // root->left->left = new TreeNode(3);
    // // root->left->right = new TreeNode();
    // // root->right->left = new TreeNode();
    // root->right->right = new TreeNode(7);
    // root->left->left->left = new TreeNode(1);
    // root->left->left->right = new TreeNode(4);
    // root->left->left->right->right = new TreeNode(5);
    // // root->left->right->left = new TreeNode();
    // root->right->right->right = new TreeNode(6);
    // root->right->right->right->left = new TreeNode(10);

    // TreeNode *troot = NULL;
    int sum = 0;
    int s, h, l, sm;
    tie(s, h, l, sm) = po(root, sum);
    deb3(s, h, l);
    // debline(troot->val);
    // debline(dfs(troot));
    debline(sum);
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
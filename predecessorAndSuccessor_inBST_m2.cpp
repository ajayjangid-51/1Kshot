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
struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : key(x), left(NULL), right(NULL) {}
};

void findPreSuc(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int k)
{

    // Your code goes here
    if (pre and suc)
        return;
    if (!root)
        return;
    findPreSuc(root->left, pre, suc, k);
    if (root->key < k)
    {
        debline(root->key);
        if (!pre)
            pre = root;
        else
        {
            if (pre->key < root->key)
            {
                pre = root;
            }
        }
    }
    else
    {
        // debline(root->key);
        if (suc)
            return;
        if (root->key == k)
        {
            suc = root->right;
        }
        else
        {
            suc = root;
        }
        // if(pre and suc) return;
    }
    findPreSuc(root->right, pre, suc, k);
}
void solve()
{
    TreeNode *root = new TreeNode(78);
    root->left = new TreeNode(34);
    root->right = new TreeNode(97);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(45);
    //    root->right->left = new TreeNode();
    // root->right->right = new TreeNode(85);
    //    root->left->left->left = new TreeNode();
    //    root->left->left->right = new TreeNode();
    //    root->left->right->left = new TreeNode();
    //    root->left->right->right = new TreeNode();
    TreeNode *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, 34);
    deb2(pre, suc);
    deb2(pre->key, suc->key);
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
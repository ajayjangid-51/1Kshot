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
struct TrieNode
{
    TrieNode *arr[26] = {NULL};
    bool end = false;
};
class Trie
{
private:
public:
    TrieNode *root = NULL;
    Trie()
    {
        root = new TrieNode;
    }
    void insert(string word)
    {
        TrieNode *currNode = root;
        int i = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (currNode->arr[word[i] - 'a'])
            {
                currNode = currNode->arr[word[i] - 'a'];
            }
            else
            {
                currNode->arr[word[i] - 'a'] = new TrieNode;
                currNode = currNode->arr[word[i] - 'a'];
            }
        }
        currNode->end = true;
    }
};
vector<string> ans;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

void dfs(int i, int j, vector<vector<char>> &board, TrieNode *&node, string s, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
    if (node->end)
    {
        ans.push_back(s);
        // return;
    }
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + x[k];
        int j1 = j + y[k];
        if (i1 >= 0 and i1 < board.size() and j1 >= 0 and j1 < board[0].size() and !visited[i1][j1] and node->arr[board[i1][j1] - 'a'])
        {
            string t(s);
            t.push_back(board[i1][j1]);
            dfs(i1, j1, board, node->arr[board[i1][j1] - 'a'], t, visited);
        }
    }

    visited[i][j] = false;
}

void solve()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    Trie t1;

    trav(words)
    {
        t1.insert(x);
    }

    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (t1.root->arr[board[i][j] - 'a'])
            {
                string s;
                s.push_back(board[i][j]);
                dfs(i, j, board, t1.root->arr[board[i][j] - 'a'], s, visited);
            }
        }
    }
    // print("Hll");
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
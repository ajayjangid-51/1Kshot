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
// #define size(x) x.size()
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
#include <bits/stdc++.h>

class Node
{
public:
    char data;
    Node *child[26];
    int wordEnd;
    int wordCount;
    Node(char data)
    {
        // char data = '/';
        wordEnd = 0;
        wordCount = 0;
        // this->data = data;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};
class Trie
{

private:
    Node *root = NULL;

public:
    Trie()
    {
        // Write your code here.
        root = new Node('/');
    }

    void insert(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (curr->child[ind] == NULL)
            {
                curr->child[ind] = new Node(word[i]);
            }
            curr = curr->child[ind];
            curr->wordCount++;
        }
        curr->wordEnd++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (!curr->child[ind] || curr->child[ind]->wordCount <= 0)
                return 0;
            curr = curr->child[ind];
        }
        return curr->wordEnd;
    }

    int countWordsStartingWith(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (curr->child[ind] == NULL || curr->child[ind]->wordCount <= 0)
                return 0;
            curr = curr->child[ind];
        }
        return curr->wordCount;
    }

    void erase(string &word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            curr = curr->child[ind];
            curr->wordCount--;
        }
        curr->wordEnd--;
    }
};
void solve()
{
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
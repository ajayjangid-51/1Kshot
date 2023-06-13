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
#define onered cout << "🔴"
#define twoblue cout << "🔵"
#define threeyellow cout << "🟡"
#define fourpurple cout << "🟣"
#define fivebrown cout << "🟤"
#define sixgreen cout << "🟢"
#define sevenwhite cout << "⚪"
#define eightwheel cout << "🛞"
#define ninering cout << "⭕"
#define tenpoint cout << "👉"
#define elevenhand cout << "🤚🏻"
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

class trieNode
{
public:
    trieNode *v[26] = {NULL};
    bool end = 0;
};
class WordDictionary
{
public:
    trieNode *root = NULL;

    WordDictionary()
    {
        root = new trieNode();
    }

    void addWord(string word)
    {
        trieNode *p = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ind = word[i] - 'a';
            if (p->v[ind] == NULL)
            {
                p->v[ind] = new trieNode();
                //    if(i ==word.size()-1) p->end = 1;
            }

            p = p->v[ind];
        }
        //    if(i ==word.size()-1) p->end = 1;
        p->end = 1;
    }

    bool find(int i, trieNode *p, string &word)
    {
        if (!p)
            return 0;
        if (i == word.size() - 1)
        {
            // cout << word[i] <<  '-' << word<< endl;
            int ind = word[i] - 'a';
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (p->v[j] and p->v[j]->end)
                        return 1;
                }
            }
            else
            {
                if (p->v[ind] and p->v[ind]->end)
                    return 1;
            }
            return 0;
        }
        int ind = word[i] - 'a';
        bool b = 0;
        if (word[i] == '.')
        {
            bool ans = 0;
            for (int j = 0; j < 26; j++)
            {
                if (p->v[j])
                {
                    ans |= find(i + 1, p->v[j], word);
                    if (ans)
                        return 1;
                }
            }
        }
        else
        {

            if (p->v[ind] != NULL)
                b |= find(i + 1, p->v[ind], word);
        }
        return b;
    }

    bool search(string word)
    {
        return find(0, root, word);
        // return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
void solve()
{
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
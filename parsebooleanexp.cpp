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

// recursion ka use krna mtlb only loop ki tarah repetation krna nhi hai, recursion ka original mtlb hai ki usko problem ki subproblem k liyeh bhi use kro. jaise abhi mene yaha kuch bhi krliya and now meh aageh move hone chahata hu but aage wali cheez meh mereko vohi krna hai jo mene just phle kiya tha, so then esi condition meh always use recursion for it. and whenever apn jab bhi recursive solution ka soche then always problem ko ekdam chota break krke dekho ki agr meri problem itni hi hoti tab meh kya krta. simply boleh toh base-bases phle dekho if you thinking of pure-recursion solution. (mean bottom-up approach).
// new subproblem

class c
{
public:
    bool fn(int &i, string &s)
    {
        // if(s[i] == ',')
        if (s[i] == 'f')
        {
            // i++;
            return false;
        }
        if (s[i] == 't')
        {
            // i++;
            return true;
        }
        if (s[i] == '!')
        {
            return notfn(i, s);
        }
        if (s[i] == '&')
        {
            return andfn(i, s);
        }
        else
        {
            return orfn(i, s);
        }
    }
    bool notfn(int &i, string &s)
    {
        i += 2;
        return !fn(i, s);
    }
    bool andfn(int &i, string &s)
    {
        i += 2;
        bool ans = fn(i, s);
        i++;
        while (s[i] != ')')
        {
            if (s[i] == ',')
                i++;
            ans = ans & fn(i, s);
            i++;
        }
        return ans;
    }
    bool orfn(int &i, string &s)
    {
        i += 2;
        bool ans = fn(i, s);
        i++;
        while (s[i] != ')')
        {
            if (s[i] == ',')
                i++;
            ans = ans or fn(i, s);
            i++;
        }
        return ans;
    }
};

void solve()
{
    string s("&(!(&(f,t)),!(|(t,f,&(t,f))))");
    cin >> s;
    int n = s.size();
    int i = 0;
    c c1;
    bool ans = c1.fn(i, s);
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
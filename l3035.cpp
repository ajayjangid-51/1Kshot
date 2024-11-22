#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
// #define size(x) x.size()

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
#define linebreak1 cout << "_______________________________" << "\n""\n"
#define forn(i, start, n) for (auto i = start; i < n; i++)
#define io_faster ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

const int MOD = 1000000007;
double PI = 4 * atan(1);

void file()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt","w", stdout);
#endif
}
void solve(){
    // vector<string> w = {"abc", "ab"};
    // vector<string> w = {"abbb","ba","aa"};
    // vector<string> w = {"cd","ef","a"};
    // vector<string> w = {"eebbb","cd", "mmmmmmnnnn", "aaaaaaa"};
    // vector<string> w = {"a", "a", "caa"};
    vector<string> w = {"rqfsx","kja","mx","r"};
    int i = 'a'-'a';
    cout << i << endl;
     int v[26] = {0};
        int oddSum = 0;
        int evenSum = 0;
        int oddlenStrings = 0;
        vector<int> lenarr;
        for(auto x:w){
            if(x.size()%2) oddlenStrings++;
            lenarr.push_back(x.size());
            for(auto y:x){
                
                int index = y-'a';
                print(index);
                v[index]++;

            }
        }
        for(int i =0;i<26;i++){
            // cout << v[i] << ',';
            if(v[i]%2){
                oddSum++;
                evenSum+= (v[i]-1);
            }else{
                evenSum+= v[i];
            }
        }
        deb(oddSum);
        deb(evenSum);
        deb(oddlenStrings);
        int ans = 0;
        for(auto &x:lenarr){
            print(x);
            if(oddSum> 0 and x%2){
                x = x-1;
                oddSum--;
            }

        }
        sort(lenarr.begin() , lenarr.end());
        cout << endl;
        for(auto &x:lenarr){
            print(x);
            if((x%2 ==0) and evenSum>=x){
                ans++;
                
                evenSum-=x;
                x-=x;

            }
           

        }
        for(auto x:lenarr){
            if(x%2 and evenSum>=x){
                ans++;
                evenSum-=x;
            }
        }
        deb(ans);
        // print(oddSum);
        // cout << "evensun" << endl;

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
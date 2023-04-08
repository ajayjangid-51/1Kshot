bool okay(string a, string b)
{
    int n = a.size(), m = b.size();
    if (m - n != 1)
        return 0;
    int i = 0, j = 0;
    while (j < m)
    {
        //   if(i< n and a[i]==b[j]){ or by default string will not equal if str[n+1] is compared.. with any lowercase character
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i == n and j == m;
}
int longestChain(int n, vector<string> &v)
{
    vi lis(n, 1);

    sort(range(v), [](string a, string b)
         { return a.size() < b.size(); });
    int maxi = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (okay(v[i], v[j]))
                lis[i] = max(lis[i], lis[j] + 1);
        }
        // nline;
        maxi = max(maxi, lis[i]);
    }
    return (maxi)
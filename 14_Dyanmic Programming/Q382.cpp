#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q382.) Edit Distance

INPUT:
2

geek gesek

gfg gfg

OUTPUT:
Case #1: 1
Case #2: 0

*/

class Solution
{
    int dp[102][102];
    int fun(string s, string t, int pos1, int pos2)
    {
        // If first string is empty, the only option is to
        // insert all characters of second string into first
        if (pos1 == 0)
        {
            return pos2;
        }
        // If second string is empty, the only option is to
        // remove all characters of first string
        if (pos2 == 0)
        {
            return pos1;
        }

        int &ans = dp[pos1][pos2];
        // If already calculated.
        if (ans != -1)
        {
            return ans;
        }
        // If last characters of two strings are same, nothing
        // much to do. Ignore last characters and get count for
        // remaining strings.
        if (s[pos1 - 1] == t[pos2 - 1])
        {
            return ans = fun(s, t, pos1 - 1, pos2 - 1);
        }
        // If last characters are not same, consider all three
        // operations on last character of first string, recursively
        // compute minimum cost for all three operations and take
        // minimum of three values.
        return ans = min({1 + fun(s, t, pos1, pos2 - 1), 1 + fun(s, t, pos1 - 1, pos2), 1 + fun(s, t, pos1 - 1, pos2 - 1)});
    }

public:
    int editDistance(string s, string t)
    {
        memset(dp, -1, sizeof(dp));
        int ans = fun(s, t, s.size(), t.size());
        return ans;
    }
};

void solve()
{
    string s, t;
    cin >> s >> t;
    Solution ob;
    int ans = ob.editDistance(s, t);
    cout << ans << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}
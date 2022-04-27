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
Q427.) Word Wrap Problem

INPUT:
2

4
3 2 2 5
6

3
3 2 2
4

OUTPUT:
Case #1: 10
Case #2: 5

*/

class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();
        int i, j;
        int currlen;
        int cost;
        vector<int> dp(n, 0);
        vector<int> ans(n, 0);
        dp[n - 1] = 0;
        ans[n - 1] = n - 1;
        for (i = n - 2; i >= 0; i--)
        {
            currlen = -1;
            dp[i] = INT_MAX;
            for (j = i; j < n; j++)
            {
                currlen += (nums[j] + 1);
                if (currlen > k)
                {
                    break;
                }
                if (j == n - 1)
                {
                    cost = 0;
                }
                else
                {
                    cost = (k - currlen) * (k - currlen) + dp[j + 1];
                }
                if (cost < dp[i])
                {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }
        int res = 0;
        i = 0;
        while (i < n)
        {
            int pos = 0;
            for (int j = i; j < ans[i] + 1; j++)
            {
                pos += nums[j];
            }
            int x = ans[i] - i;
            if (ans[i] + 1 != nums.size())
            {
                res += (k - x - pos) * (k - x - pos);
            }
            i = ans[i] + 1;
        }
        return res;
    }
};

void solve()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;
    Solution obj;
    cout << obj.solveWordWrap(nums, k) << endl;
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
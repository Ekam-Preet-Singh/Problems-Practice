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
Q270.) Partition of a set into K subsets with equal sum

INPUT:
2

5
2 1 4 5 6
3

5
2 1 5 5 6
3

OUTPUT:
Case #1: 1
Case #2: 0

*/

class Solution
{
public:
    int dp[(1 << 16) + 2];
    bool isKPartitionPossible(int nums[], int n, int k)
    {
        int sum = 0;
        fill(dp, dp + (1 << 16) + 2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % k)
        {
            return false;
        }
        int tar = sum / k;

        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[mask] == -1)
            {
                continue; // if current state is illegal, simply ignore it
            }
            for (int i = 0; i < n; i++)
            {
                if (!(mask & (1 << i)) && dp[mask] + nums[i] <= tar)
                { // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % tar;
                }
            }
        }
        return dp[(1 << n) - 1] == 0; // Your code here
    }
};

void solve()
{
    int n;

    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.isKPartitionPossible(a, n, k) << endl;
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
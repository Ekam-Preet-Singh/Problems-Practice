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
Q417.) Count All Palindromic Subsequence in a given String

INPUT:
3

bbabcbcab

abcd

aab

OUTPUT:
Case #1: 96
Case #2: 4
Case #3: 4

*/

class Solution
{
public:
    long long int add(long long int x, long long int y)
    {
        return ((x % mod) + (y % mod)) % mod;
    }
    long long int sub(long long int x, long long int y)
    {
        return ((x % mod) - (y % mod) + mod) % mod;
    }
    long long int countPS(string str)
    {
        long long int N = str.length();

        // create a 2D array to store the count of palindromic
        // subsequence
        long long int cps[N + 1][N + 1];
        memset(cps, 0, sizeof(cps));

        // palindromic subsequence of length 1
        for (long long int i = 0; i < N; i++)
            cps[i][i] = 1;

        // check subsequence of length L is palindrome or not
        for (long long int L = 2; L <= N; L++)
        {
            for (long long int i = 0; i <= N - L; i++)
            {
                long long int k = L + i - 1;
                if (str[i] == str[k])
                {
                    cps[i][k] = add(cps[i][k - 1], add(cps[i + 1][k], 1LL)) % mod;
                }
                else
                {
                    cps[i][k] = add(cps[i][k - 1], sub(cps[i + 1][k], cps[i + 1][k - 1])) % mod;
                }
            }
        }

        // return total palindromic subsequence
        return cps[0][N - 1] % mod;
    }
};

void solve()
{
    string str;
    cin >> str;
    Solution ob;
    long long int ans = ob.countPS(str);
    cout << ans << endl;
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
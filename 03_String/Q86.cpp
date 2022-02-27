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
Q86.) Transform One String to Another using Minimum Number of Given Operation

INPUT:
2

ABD BAD

EACBD EABCD

OUTPUT:
Case #1: 1
Case #2: 3

*/

class Solution
{
public:
    int transform(string A, string B)
    {
        // This parts checks whether conversion is
        // possible or not
        if (A.length() != B.length())
        {
            return -1;
        }

        unordered_map<char, int> m;
        int n = A.length();

        for (int i = 0; i < n; i++)
        {
            // count characters in A
            m[A[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            // Check if all counts become 0
            if (m[B[i]])
            {
                // subtract count for
                // every character in B
                m[B[i]]--;
            }
        }

        for (auto i : m)
        {
            if (i.second != 0)
            {
                return -1;
            }
        }

        int i = n - 1, j = n - 1;
        // This part calculates the number of operations required
        int res = 0;
        while (i >= 0 and j >= 0)
        {
            // If there is a mismatch, then keep incrementing
            // result 'res' until B[j] is not found in A[0..i]
            while (i >= 0 and A[i] != B[j])
            {
                i--;
                res++;
            }
            // If A[i] and B[j] match
            i--;
            j--;
        }

        return res;
    }
};

void solve()
{
    string A, B;
    cin >> A >> B;
    Solution ob;
    cout << ob.transform(A, B) << endl;
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
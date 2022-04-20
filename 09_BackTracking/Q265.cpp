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
Q265.) Find Maximum number possible by doing at-most K swaps

INPUT:
2

4
1234567

3
3435335

OUTPUT:
Case #1: 7654321
Case #2: 5543333

*/

class Solution
{
public:
    // Function to compare two strings and updating res
    // which stores the string with larger number.
    void match(string &str, string &res)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (res[i] > str[i])
                return;
            // if str[i] is greater, we update res as str or store
            // the larger value in res.
            if (res[i] < str[i])
            {
                res = str;
                return;
            }
        }
    }

    // Function to set highest possible digits at given index.
    void setDigit(string &str, int index, string &res, int k)
    {
        // base case
        if (k == 0 || index == str.size() - 1)
        {
            match(str, res);
            return;
        }

        int maxDigit = 0;

        // finding maximum digit for placing at given index.
        for (int i = index; i < str.size(); i++)
            maxDigit = max(maxDigit, str[i] - '0');

        // swapping isn't needed in this case.
        if (str[index] - '0' == maxDigit)
        {
            setDigit(str, index + 1, res, k);
            return;
        }

        for (int i = index + 1; i < str.size(); i++)
        {
            // if max digit is found at current index.
            if (str[i] - '0' == maxDigit)
            {
                // swapping to get the maximum digit at required index.
                swap(str[index], str[i]);

                // calling recursive function to set the next digit.
                setDigit(str, index + 1, res, k - 1);

                // backtracking
                swap(str[index], str[i]);
            }
        }
    }

    // Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string res = str;
        setDigit(str, 0, res, k);

        // returning the result.
        return res;
    }
};

void solve()
{
    int k;
    string str;
    cin >> k >> str;
    Solution ob;
    cout << ob.findMaximumNum(str, k) << endl;
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
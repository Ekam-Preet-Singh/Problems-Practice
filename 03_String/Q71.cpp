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
Q71.) Converting Roman Numerals to Decimal

INPUT:
3

V

III

CMXVI

OUTPUT:
Case #1: 5
Case #2: 3
Case #3: 916

*/

class Solution
{
    // This function returns value of a Roman symbol
    int value(char r)
    {
        if (r == 'I')
        {
            return 1;
        }
        else if (r == 'V')
        {
            return 5;
        }
        else if (r == 'X')
        {
            return 10;
        }
        else if (r == 'L')
        {
            return 50;
        }
        else if (r == 'C')
        {
            return 100;
        }
        else if (r == 'D')
        {
            return 500;
        }
        else
        {
            // M = 1000
            return 1000;
        }
    }

public:
    // Returns decimal value of roman numeral
    int romanToDecimal(string &str)
    {
        // Initialize result
        int res = 0;

        // Traverse given input
        for (int i = 0; i < str.length(); i++)
        {
            // Getting value of symbol s[i]
            int s1 = value(str[i]);

            if (i + 1 < str.length())
            {
                // Getting value of symbol s[i+1]
                int s2 = value(str[i + 1]);

                // Comparing both values
                if (s1 >= s2)
                {
                    // Value of current symbol is greater
                    // or equal to the next symbol
                    res = res + s1;
                }
                else
                {
                    res = res + s2 - s1;
                    i++; // Value of current symbol is
                         // less than the next symbol
                }
            }
            else
            {
                res = res + s1;
            }
        }
        return res;
    }
};

void solve()
{
    string s;
    cin >> s;
    Solution ob;
    cout << ob.romanToDecimal(s) << endl;
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
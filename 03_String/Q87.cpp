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
Q87.) Check if two given strings are isomorphic to each other

INPUT:
3

aab xxy

aab xyz

aitg dphc

OUTPUT:
Case #1: 1
Case #2: 0
Case #3: 1

*/

class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        int m = str1.length(), n = str2.length();

        if (m != n)
        {
            return false;
        }

        // using a boolean array to mark visited characters in str2.
        bool marked[256] = {false};

        // using map to store mapping of every character from str1 to
        // that of str2. Initializing all entries of map as -1.
        int map[256];
        memset(map, -1, sizeof(map));

        for (int i = 0; i < n; i++)
        {
            // if current character of str1 is seen first time in map.
            if (map[str1[i]] == -1)
            {
                // if current character of str2 is already
                // seen, one to one mapping is not possible.
                if (marked[str2[i]] == true)
                {
                    return false;
                }

                // marking current character of str2 as visited.
                marked[str2[i]] = true;

                // storing mapping of current characters.
                map[str1[i]] = str2[i];
            }

            // if this isn't first appearance of current character in str1 then
            // checking if previous appearance mapped to same character of str2.
            else if (map[str1[i]] != str2[i])
            {
                return false;
            }
        }
        return true;
    }
};

void solve()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    Solution obj;
    cout << obj.areIsomorphic(s1, s2) << endl;
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
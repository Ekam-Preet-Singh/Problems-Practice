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
Q84.) String matching where one string contains wildcard characters

INPUT:
3

ge?ks*
geeksforgeeks

ge*ks
geeks

geek*s?
geeks

OUTPUT:
Case #1: Yes
Case #2: Yes
Case #3: No

*/

class Solution
{
public:
    bool rec(string w, int i, int WSIZE, string p, int j, int PSIZE)
    {
        // If we reach at the end of both strings, we are done
        if (i == WSIZE && j == PSIZE)
        {
            return true;
        }
        if (w[i] == '*')
        {
            while (i + 1 < WSIZE && w[i + 1] == '*')
            {
                i++;
            }
        }
        // Make sure that the characters after '*' are present
        // in second string. This function assumes that the first
        // string will not contain two consecutive '*'
        if (w[i] == '*' && (i + 1) != WSIZE && j == PSIZE)
        {
            return false;
        }
        // If the first string contains '?', or current characters
        // of both strings match
        if (w[i] == '?' || w[i] == p[j])
        {
            return rec(w, i + 1, WSIZE, p, j + 1, PSIZE);
        }
        // If there is *, then there are two possibilities
        // a) We consider current character of second string
        // b) We ignore current character of second string.
        if (w[i] == '*')
        {
            return (rec(w, i, WSIZE, p, j + 1, PSIZE) || rec(w, i + 1, WSIZE, p, j, PSIZE));
        }
        return false;
    }
    // The main function that checks if two given strings
    // match. The first string may contain wildcard characters
    bool match(string w, string p)
    {
        int WSIZE = w.size();
        int PSIZE = p.size();
        bool flag = rec(w, 0, WSIZE, p, 0, PSIZE);
        return flag;
    }
};

void solve()
{
    string w, p;
    cin >> w >> p;

    Solution ob;
    if (ob.match(w, p))
        cout << "Yes\n";
    else
        cout << "No\n";
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
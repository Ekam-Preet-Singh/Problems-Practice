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
Q78.) Write a program to find the smallest window that contains all characters of string itself.

INPUT:
4

AABBBCBBAC

aaab

GEEKSGEEKSFOR

CCABBAbBCABB

OUTPUT:
Case #1: 3
Case #2: 2
Case #3: 8
Case #4: 4

*/

class Solution
{
public:
    const int no_of_chars = 256;
    // Function to find smallest window containing
    // all characters of 'pat'
    string findSubString(string str)
    {

        int len1 = str.length();
        string pat = "";

        set<char> s;
        for (int i = 0; i < len1; i++)
        {
            s.insert(str[i]);
        }
        for (auto i = s.begin(); i != s.end(); i++)
        {
            pat += (*i);
        }

        int len2 = pat.length();

        // check if string's length is less than pattern's
        // length. If yes then no such window can exist
        if (len1 < len2)
        {
            return "";
        }

        int hash_pat[no_of_chars] = {0};
        int hash_str[no_of_chars] = {0};

        // store occurrence ofs characters of pattern
        for (int i = 0; i < len2; i++)
        {
            hash_pat[pat[i]]++;
        }

        int start = 0, start_index = -1, min_len = INT_MAX;

        // start traversing the string
        int count = 0; // count of characters
        for (int j = 0; j < len1; j++)
        {
            // count occurrence of characters of string
            hash_str[str[j]]++;

            // If string's char matches with pattern's char
            // then increment count
            if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
            {
                count++;
            }

            // if all the characters are matched
            if (count == len2)
            {
                // Try to minimize the window i.e., check if
                // any character is occurring more no. of times
                // than its occurrence in pattern, if yes
                // then remove it from starting and also remove
                // the useless characters.
                while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
                {

                    if (hash_str[str[start]] > hash_pat[str[start]])
                    {
                        hash_str[str[start]]--;
                    }
                    start++;
                }

                // update window size
                int len_window = j - start + 1;
                if (min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        // If no window found
        if (start_index == -1)
        {
            return "";
        }

        // Return substring starting from start_index
        // and length min_len
        return str.substr(start_index, min_len);
    }
};

void solve()
{
    string str;
    cin >> str;
    Solution ob;
    cout << ob.findSubString(str).size() << endl;
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
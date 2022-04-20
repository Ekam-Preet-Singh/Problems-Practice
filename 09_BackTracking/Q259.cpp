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
Q259.) Print all palindromic partitions of a string

INPUT:
2

nitin

geeks

OUTPUT:
Case #1:
n i t i n
n iti n
nitin
Case #2:
g e e k s
g ee k s

*/

class Solution
{
public:
    // A utility function to check if str is palindroem
    bool isPalindrome(string str, int low, int high)
    {
        while (low < high)
        {
            if (str[low] != str[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    // Recursive function to find all palindromic partitions of str[start..n-1]
    // allPart --> A vector of vector of strings. Every vector inside it stores
    //             a partition
    // currPart --> A vector of strings to store current partition
    void allPalPartUtil(vector<vector<string>> &allPart, vector<string> &currPart,
                        int start, int n, string str)
    {
        // If 'start' has reached len
        if (start >= n)
        {
            allPart.push_back(currPart);
            return;
        }

        // Pick all possible ending points for substrings
        for (int i = start; i < n; i++)
        {
            // If substring str[start..i] is palindrome
            if (isPalindrome(str, start, i))
            {
                // Add the substring to result
                currPart.push_back(str.substr(start, i - start + 1));

                // Recur for remaining remaining substring
                allPalPartUtil(allPart, currPart, i + 1, n, str);

                // Remove substring str[start..i] from current
                // partition
                currPart.pop_back();
            }
        }
    }

    vector<vector<string>> allPalindromicPerms(string S)
    {
        int n = S.length();

        // To Store all palindromic partitions
        vector<vector<string>> allPart;

        // To store current palindromic partition
        vector<string> currPart;

        // Call recursive function to generate all partiions
        // and store in allPart
        allPalPartUtil(allPart, currPart, 0, n, S);

        return allPart;
    }
};

void solve()
{
    string S;

    cin >> S;

    Solution ob;
    vector<vector<string>> ptr = ob.allPalindromicPerms(S);

    for (int i = 0; i < ptr.size(); i++)
    {
        for (int j = 0; j < ptr[i].size(); j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}
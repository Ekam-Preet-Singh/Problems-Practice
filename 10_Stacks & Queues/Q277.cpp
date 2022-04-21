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
Q277.) Check the expression has valid or Balanced parenthesis or not.

INPUT:
2

{([])}

({)

OUTPUT:
Case #1: balanced
Case #2: not balanced

*/

class Solution
{
public:
    // Function to check if opening and closing brackets are of same type.
    bool cmp(char b, char c)
    {
        if (b == '{' && c == '}')
        {
            return true;
        }
        else if (b == '[' && c == ']')
        {
            return true;
        }
        else if (b == '(' && c == ')')
        {
            return true;
        }
        return false;
    }

    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;

        // iterating over the string.
        for (int i = 0; i < x.size(); i++)
        {
            // if opening bracket is encountered, we push it into stack.
            if (x[i] == '[' || x[i] == '{' || x[i] == '(')
            {
                s.push(x[i]);
            }

            // if closing bracket is encountered, we compare it with top of stack.
            else if (x[i] == ']' || x[i] == '}' || x[i] == ')')
            {
                // if top of stack has opening bracket of different
                // type, we return false.
                if (s.empty() || !cmp(s.top(), x[i]))
                {
                    return false;
                }
                // else we pop the top element from stack.
                else
                {
                    s.pop();
                }
            }
        }
        // if stack becomes empty, we return true else false.
        if (s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void solve()
{
    string a;
    cin >> a;
    Solution obj;
    if (obj.ispar(a))
        cout << "balanced" << endl;
    else
        cout << "not balanced" << endl;
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
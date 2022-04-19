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
Q252.) Find maximum sum possible equal sum of three stacks

INPUT:
1

5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

OUTPUT:
Case #1: 5

*/

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int maxSum(int stack1[], int stack2[], int stack3[], int n1, int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // Finding the initial sum of stack1.
    for (int i = 0; i < n1; i++)
    {
        sum1 += stack1[i];
    }

    // Finding the initial sum of stack2.
    for (int i = 0; i < n2; i++)
    {
        sum2 += stack2[i];
    }

    // Finding the initial sum of stack3.
    for (int i = 0; i < n3; i++)
    {
        sum3 += stack3[i];
    }

    // As given in question, first element is top
    // of stack..
    int top1 = 0, top2 = 0, top3 = 0;
    while (1)
    {
        // If any stack is empty
        if (top1 == n1 || top2 == n2 || top3 == n3)
        {
            return 0;
        }

        // If sum of all three stack are equal.
        if (sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }

        // Finding the stack with maximum sum and
        // removing its top element.
        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= stack1[top1++];
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= stack2[top2++];
        }
        else if (sum3 >= sum2 && sum3 >= sum1)
        {
            sum3 -= stack3[top3++];
        }
    }
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int stack1[a], stack2[b], stack3[c];
    for (int i = 0; i < a; i++)
        cin >> stack1[i];
    for (int i = 0; i < b; i++)
        cin >> stack2[i];
    for (int i = 0; i < c; i++)
        cin >> stack3[i];
    cout << maxSum(stack1, stack2, stack3, a, b, c) << endl;
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
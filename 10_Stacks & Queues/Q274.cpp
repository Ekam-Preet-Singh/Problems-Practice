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
Q274.) Implement two stacks in an array

INPUT:
1

6
1 1 2 1 1 3 2 1 4 1 2 2 2 2 2

OUTPUT:
Case #1: 3 4 -1

*/

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

// The idea is to start two stacks from two extreme corners of arr[].
// stack1 starts from the leftmost element, the first element in stack1 is
// pushed at index 0. The stack2 starts from the rightmost corner, the first
// element in stack2 is pushed at index (n-1). Both stacks grow (or shrink)
// in opposite direction. To check for overflow, all we need to check is for
// space between top elements of both stacks.

// Function to push an integer into the stack1.
void twoStacks ::push1(int x)
{
    // if there is space between the top of both stacks
    // we push the element at top1+1.
    if (top1 < top2 - 1)
    {
        top1++;
        arr[top1] = x;
    }
}

// Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    // if there is space between the top of both stacks
    // we push the element at top2-1.
    if (top1 < top2 - 1)
    {
        top2--;
        arr[top2] = x;
    }
}

// Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    // if top1==-1, stack1 is empty so we return -1 else we
    // return the top element of stack1.
    if (top1 >= 0)
    {
        int x = arr[top1];
        top1--;
        return x;
    }
    else
        return -1;
}

// Function to remove an element from top of the stack2.
int twoStacks ::pop2()
{
    // if top2==size of array, stack2 is empty so we return -1 else we
    // return the top element of stack2.
    if (top2 < size)
    {
        int x = arr[top2];
        top2++;
        return x;
    }
    else
        return -1;
}

void solve()
{
    twoStacks *sq = new twoStacks();

    int Q;
    cin >> Q;
    while (Q--)
    {
        int stack_no;
        cin >> stack_no;
        int QueryType = 0;
        cin >> QueryType;

        if (QueryType == 1)
        {
            int a;
            cin >> a;
            if (stack_no == 1)
                sq->push1(a);
            else if (stack_no == 2)
                sq->push2(a);
        }
        else if (QueryType == 2)
        {
            if (stack_no == 1)
                cout << sq->pop1() << " ";
            else if (stack_no == 2)
                cout << sq->pop2() << " ";
        }
    }
    cout << endl;
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
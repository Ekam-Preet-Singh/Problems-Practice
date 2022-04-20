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
Q275.) find the middle element of a stack

INPUT:
1

7
11 22 33 44 55 66 77

OUTPUT:
Case #1:
Item popped is 77
Item popped is 66
Item popped is 55
Middle Element is 33
Deleted Middle Element is 33
Middle Element is 22

*/

class DLLNode
{
public:
    DLLNode *prev;
    int data;
    DLLNode *next;
};

class myStack
{
public:
    DLLNode *head;
    DLLNode *mid;
    int count;
};

myStack *createMyStack()
{
    myStack *ms = new myStack();
    ms->count = 0;
    return ms;
};

void push(myStack *ms, int new_data)
{
    DLLNode *new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;

    new_DLLNode->prev = NULL;

    new_DLLNode->next = ms->head;

    ms->count += 1;

    if (ms->count == 1)
    {
        ms->mid = new_DLLNode;
    }
    else
    {
        ms->head->prev = new_DLLNode;

        if (!(ms->count & 1))
            ms->mid = ms->mid->prev;
    }

    ms->head = new_DLLNode;
}

int pop(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;
    if ((ms->count) & 1)
        ms->mid = ms->mid->next;

    free(head);

    return item;
}

int findMiddle(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}

int deletemiddle(myStack *ms)
{
    int temp = ms->mid->data;
    ms->mid->prev->next = ms->mid->next;
    ms->mid->next->prev = ms->mid->prev->next;

    delete ms->mid;
    ms->mid = ms->mid->next;
    return temp;
}

void solve()
{
    myStack *ms = createMyStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "Deleted Middle Element is " << deletemiddle(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
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
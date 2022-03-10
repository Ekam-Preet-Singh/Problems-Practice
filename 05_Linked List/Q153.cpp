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
Q153.) Sort a LL of 0's, 1's and 2's

INPUT:
2

8
1 2 2 1 2 0 2 2

4
2 2 0 1

OUTPUT:
Case #1: 0 1 1 2 2 2 2 2
Case #2: 0 1 2 2

*/

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(struct Node *head)
    {
        if (!head || !(head->next))
        {
            return head;
        }

        // creating three dummy nodes to point to beginning of three linked lists.
        Node *zeroD = new Node(0);
        Node *oneD = new Node(0);
        Node *twoD = new Node(0);

        // initializing current pointers for three lists.
        Node *zero = zeroD, *one = oneD, *two = twoD;

        // traversing over the list with a pointer.
        Node *curr = head;
        while (curr)
        {

            // we check data at current node and store the node in it's respective
            // list and update the link part of that list.
            if (curr->data == 0)
            {
                zero->next = curr;
                zero = zero->next;
                curr = curr->next;
            }
            else if (curr->data == 1)
            {
                one->next = curr;
                one = one->next;
                curr = curr->next;
            }
            else
            {
                two->next = curr;
                two = two->next;
                curr = curr->next;
            }
        }

        // attaching the three lists containing 0s,1s and 2s respectively.
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
        one->next = twoD->next;
        two->next = NULL;

        // updating the head of the list.
        head = zeroD->next;

        // deleting dummy nodes.
        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
    cout << endl;
}

void insert(int n)
{
    int value, i;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    insert(n);
    Solution ob;
    struct Node *newHead = ob.segregate(start);
    printList(newHead);
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
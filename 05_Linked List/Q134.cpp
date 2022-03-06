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
Q134.) Add two numbers represented by linked lists.

INPUT:
2

2
4 5
3
3 4 5

2
6 5
1
7

OUTPUT:
Case #1: 3 9 0
Case #2: 7 2

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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    // Function to reverse the linked list.
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // reversing both lists to simplify addition.
        first = reverse(first);
        second = reverse(second);

        Node *sum = NULL;
        int carry = 0;

        // using a loop till both lists and carry gets exhausted.
        while (first != NULL || second != NULL || carry != 0)
        {
            // using a variable to store sum of two digits along with carry.
            int newVal = carry;

            // if nodes are left in any list, we add their data in newVal.
            if (first)
            {
                newVal += first->data;
            }
            if (second)
            {
                newVal += second->data;
            }

            // updating carry.
            carry = newVal / 10;

            // using modulus to store only a single digit at that place.
            newVal = newVal % 10;

            // creating new node which gets connected with other nodes that
            // we get after calculating sum of respective digits.
            Node *newNode = new Node(newVal);

            // storing the previously made nodes in the link part of new node.
            newNode->next = sum;

            // making the new node as the first node of all previously made node.
            sum = newNode;

            // moving ahead in both lists.
            if (first)
            {
                first = first->next;
            }
            if (second)
            {
                second = second->next;
            }
        }
        return sum;
    }
};

void solve()
{
    int n, m;

    cin >> n;
    Node *first = buildList(n);

    cin >> m;
    Node *second = buildList(m);
    Solution ob;
    Node *res = ob.addTwoLists(first, second);
    printList(res);
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
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
Q132.) Write a Program to Move the last element to Front in a Linked List.

INPUT:
4

4
5 2 2 4

5
2 2 2 2 2

4
5 2 2 4

5
1 2 3 4 5

OUTPUT:
Case #1: 
Linked list before moving last to front
5 2 2 4 
Linked list after removing last to front
4 5 2 2 
Case #2: 
Linked list before moving last to front
2 2 2 2 2 
Linked list after removing last to front
2 2 2 2 2 
Case #3: 
Linked list before moving last to front
5 2 2 4 
Linked list after removing last to front
4 5 2 2 
Case #4: 
Linked list before moving last to front
1 2 3 4 5 
Linked list after removing last to front
5 1 2 3 4 

*/

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertionAtTail(Node *&head, int val)
{
    // allocate node
    Node *n = new Node(val);
    // Check if the given prev_node is NULL
    if (head == NULL)
    {
        n->next = head;
        head = n;
    }
    else
    {
        // Storing head node
        Node *temp = head;
        // traverse till the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Change the next of last node
        temp->next = n;
    }
}

void moveToFront(Node *&head_ref)
{
    /* If linked list is empty, or
    it contains only one node,
    then nothing needs to be done,
    simply return */
    if (head_ref == NULL || (head_ref)->next == NULL)
    {
        return;
    }

    /* Initialize second last
    and last pointers */
    Node *secLast = NULL;
    Node *last = head_ref;

    /*After this loop secLast contains
    address of second last node and
    last contains address of last node in Linked List */
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    /* Set the next of second last as NULL */
    secLast->next = NULL;

    /* Set next of last as head node */
    last->next = head_ref;

    /* Change the head pointer
    to point to last node now */
    head_ref = last;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void solve()
{
    Node *head = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertionAtTail(head, val);
    }
    cout << "\nLinked list before moving last to front\n";
    display(head);

    moveToFront(head);

    cout << "Linked list after removing last to front\n";
    display(head);
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
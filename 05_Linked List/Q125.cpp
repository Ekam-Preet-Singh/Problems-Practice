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
Q125.) Write a Program to reverse the Linked List. (Both Iterative and recursive)

INPUT:
2

5
1 2 3 4 5

10
0 1 2 3 4 5 6 7 8 9

OUTPUT:
Case #1:
List : 1 2 3 4 5
Iterative Reverse : 5 4 3 2 1
Recursion Reverse : 1 2 3 4 5
Case #2:
List : 0 1 2 3 4 5 6 7 8 9
Iterative Reverse : 9 8 7 6 5 4 3 2 1 0
Recursion Reverse : 0 1 2 3 4 5 6 7 8 9

*/

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

void insertionAtTail(Node *&head, int val)
{
    // allocate node
    Node *n = new Node(val);
    if (head == NULL)
    {
        // Make next of new node as head
        n->next = head;
        // move the head to point to the new node
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

Node *iterativeReverse(Node *&head)
{
    // taking three pointers to store the current, previous and next nodes.
    Node *current = head;
    Node *prev = NULL;
    Node *next = current->next;
    while (current != NULL)
    {
        // taking the next node as next.
        next = current->next;

        // storing the previous node in link part of current node.
        current->next = prev;

        // updating prev from previous node to current node.
        prev = current;

        // updating current node to next node.
        current = next;
    }
    return prev;
}

Node *recursionReverse(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    else
    {
        // reverse the rest list and put
        //  the first element at the end
        Node *rest = recursionReverse(head->next);
        head->next->next = head;
        head->next = NULL;
        // fix the head pointer
        return rest;
    }
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
    cout << "List : ";
    display(head);
    cout << "Iterative Reverse : ";
    head = iterativeReverse(head);
    display(head);
    cout << "Recursion Reverse : ";
    head = recursionReverse(head);
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}
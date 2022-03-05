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

class Node
{
public:
    int data;
    Node *next;
    // Constructor Function
    Node(int val)
    {
        // put in the data
        this->data = val;
        // Make next of new node as NULL
        next = NULL;
    }
};

void insertionAtHead(Node *&head, int val)
{
    // allocate node
    Node *temp = new Node(val);
    // Make next of new node as head
    temp->next = head;
    // move the head to point to the new node
    head = temp;
}

void insertionAtTail(Node *&head, int val)
{
    // Check if the given prev_node is NULL
    if (head == NULL)
    {
        insertionAtHead(head, val);
    }
    else
    {
        // allocate node
        Node *n = new Node(val);
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

void insertionAtMid(Node *&head, int pos, int val)
{
    // Check if the given prev_node is NULL
    if (head == NULL)
    {
        return;
    }
    else
    {
        // allocate node
        Node *n = new Node(val);
        // Storing head node
        Node *temp = head;
        --pos;
        // traverse till the Desired node
        while (pos--)
        {
            temp = temp->next;
        }
        //  Make next of new node as next of prev_node
        n->next = temp->next;
        // move the next of prev_node as new_node
        temp->next = n;
    }
}

void deleteAtHead(Node *&head)
{
    // Move the head pointer to the next node
    Node *temp = head;
    head = head->next;
    // Free memory
    delete (temp);
}

void deleteAtTail(Node *&head)
{
    // If linked list is empty
    if (head == NULL)
    {
        return;
    }
    // Check if the given prev_node is HEAD NODE
    else if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    else
    {
        // Store head node
        Node *temp = head;
        // Find the second last node
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        // Delete last node
        delete (temp->next);
        // Change next of second last
        temp->next = NULL;
    }
}

void deleteAtMidValue(Node *&head, int key)
{
    // If linked list is empty
    if (head == NULL)
    {
        return;
    }
    else
    {
        // Store head node
        Node *temp = head;
        Node *prev = NULL;
        // Search for the key to be deleted,
        // keep track of the previous node as we need to change 'prev->next'
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        // If key was not present in linked list
        if (temp == NULL)
        {
            return;
        }
        // Unlink the node from linked list
        prev->next = temp->next;
        // Free memory
        delete (temp);
    }
}

void deleteAtMidPosition(Node *&head, int pos)
{
    // If linked list is empty
    if (head == NULL)
    {
        return;
    }
    // Check if the given prev_node is HEAD NODE
    else if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    else
    {
        // Store head node
        Node *temp = head;
        --pos;
        while (temp != NULL && pos--)
        {
            temp = temp->next;
        }
        // If position is more than number of nodes
        if (temp == NULL || temp->next == NULL)
        {
            return;
        }
        // Node temp->next is the node to be deleted
        // Store pointer to the next of node to be deleted
        Node *n = temp->next->next;
        // Unlink the node from linked list
        delete (temp->next); // Free memory

        // Unlink the deleted node from list
        temp->next = n;
    }
}

void deleteAll(Node *&head)
{
    // deref head_ref to get the real head
    Node *temp, *current = head;
    while (current)
    {
        temp = current->next;
        delete (current);
        current = temp;
    }
    // deref head_ref to affect the real head back in the caller
    head = NULL;
    cout << "<----DELETED---->";
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
    int n, val = 0, pos;
    cin >> n;

    cout << "Insertion at Head : ";
    insertionAtHead(head, val);
    display(head);

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertionAtTail(head, val);
    }
    cout << "Insertion at Tail : ";
    display(head);

    cout << "Insertion at Mid : ";
    cin >> pos >> val;
    insertionAtMid(head, pos, val);
    display(head);

    cout << "Deletion at Head : ";
    deleteAtHead(head);
    display(head);

    cout << "Deletion at Tail : ";
    deleteAtTail(head);
    display(head);

    cout << "Deletion at Mid (Position) : ";
    cin >> pos;
    deleteAtMidPosition(head, pos);
    display(head);

    cout << "Deletion at Mid (Value) : ";
    cin >> val;
    deleteAtMidValue(head, val);
    display(head);

    cout << "Deletion at All : ";
    deleteAll(head);
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
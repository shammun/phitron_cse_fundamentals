#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree(){
    int val;
    cin >> val;
    Node* root;

    if(val == -1){
        root = NULL;
    } else{
        root = new Node(val);
    }

    queue<Node*> q;
    if(root){
        q.push(root);
    }

    while(!q.empty()){
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* myLeft;
        Node* myRight;

        if(l == -1){
            myLeft = NULL;
        } else{
            myLeft = new Node(l);
        }

        if(r == -1){
            myRight = NULL;
        } else{
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }

    return root;
}

void level_order(Node* root){
    queue<Node *> q; // Create a queue to store nodes in level order traversal order
    q.push(root); // Push the root node into the queue

    while(!q.empty()){ 
        Node* f = q.front(); 
        q.pop();
        cout << f->val << " "; // Print the value of the current node
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

void insert(Node* & root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    if(val < root->val){
        if(root->left == NULL){
            root->left = new Node(val);
        } else{
            insert(root->left, val);
        }
    }

    if(val > root->val){
        if(root->right == NULL){
            root->right = new Node(val);
        } else {
            insert(root->right, val);
        }
    }
}

Node* convert(int a[], int size, int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(a[mid]);
    Node* leftroot = convert(a, size, start, mid-1);
    Node* rightroot = convert(a, size, mid+1, end);
    root->left = leftroot;
    root->right = rightroot;
    return root;
}


int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    Node* root = convert(a, n, 0, n-1);

    // insert(root, val);
    level_order(root);
}
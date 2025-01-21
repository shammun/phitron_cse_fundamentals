/*

Print Leaf Nodes in Descending Order

Problem Statement

You will be given a binary tree as input in level order. You need to print the values of leaf nodes in descending order.

For example:

The output for the above tree will be: 60 50 40

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.

Constraints

1. 1<= Maximum number of nodes <= 10^5 
2. 1<= Node's value <= 1000

Output Format

Output the values of leaf nodes in descending order.

Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

Sample Output 0

60 50 40

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;

class Node {
    public:
        int val;     
        Node* left;  
        Node* right; 

    
    Node(int val) {
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
    } else {
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
        } else {
            myLeft = new Node(l);
        }

        if(r==-1){
            myRight = NULL;
        } else {
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

vector<int> all_leaf_nodes(Node* root, vector<int> &v){
    if(root == NULL){
        return v;
    }
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->val);
    }
    all_leaf_nodes(root->left, v);
    all_leaf_nodes(root->right, v);
    return v;
}


int main()
{
    // Write your code here
    Node* root = input_tree(); 

    vector<int> v;
    vector<int> ans = all_leaf_nodes(root, v);
    sort(ans.begin(), ans.end(), greater<int>());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
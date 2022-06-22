#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    //DFS
    //  Inorder: Left, Root, Right
    //  Preorder: Root, left, right
    //  Post order: left, right, root
        

    void inOrder(Node *root) {
        if (root != NULL){
            //Go to left subtree
            inOrder(root->left);
            //Print out node
            std::cout << root->data << " ";
            //Go to right subtree
            inOrder(root->right);
        }
    }

    void preOrder(Node *root) {
        if (root != NULL){
            //Print out node
            std::cout << root->data << " ";
            //Go to left subtree
            preOrder(root->left);
            //Go to right subtree
            preOrder(root->right);
        }
    }

    void postOrder(Node *root) {
        if (root != NULL){
            //Go to left subtree
            postOrder(root->left);
            //Go to right subtree
            postOrder(root->right);
            //Print out node
            std::cout << root->data << " ";
        }
    }


    //BFS
    //  Level order traversal: 
    void levelOrder(Node* root){
        if (root == NULL){
            return;
        }
        std::queue<Node*> node_queue;
        node_queue.push(root);

        while (!node_queue.empty()){
            Node* current_node = node_queue.front();
            node_queue.pop();
            std::cout << current_node->data << " ";

            if (current_node->left != NULL){
                node_queue.push(current_node->left);
            }
            if (current_node->right != NULL){
                node_queue.push(current_node->right);

            }
        }

    }


}; //End of Solution


const char*  testcase1 = 
"6\n"
"1 2 5 3 6 4\n";

int main() {
  
    std::streambuf *testcase;
    std::istringstream oss(testcase1);
    testcase = cin.rdbuf();
    cin.rdbuf(oss.rdbuf());

    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}

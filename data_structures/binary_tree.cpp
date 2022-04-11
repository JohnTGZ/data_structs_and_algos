#include <iostream>

struct Node{
    int key;
    Node* left;
    Node* right; 
};

class BTree{
public:
    BTree(){
        root_ = nullptr;
    }

    void Insert(int key){
        std::printf("Inserting %d \n", key);
        Insert(root_, key);
    }


    Node* Search(int key){
        return Search(root_, key);
    }

    void Insert(Node*& node, int key){
        if (node == nullptr){
            node = new Node{key, nullptr, nullptr};
            std::printf("   INSERTED %d \n", key);
            return;
        }
        
        if (key < node->key){
            std::printf("   Insert LEFT \n");
            Insert(node->left, key);
        }
        else{
            std::printf("   Insert RIGHT \n");
            Insert(node->right, key);
        } 
    }

    Node* Search(Node*& node, int key){
        if (node == nullptr){
            node = new Node{key, nullptr, nullptr};
        }
        if (node->key == key){
            return node;
        }

        if (key < node->key){
            return Search(node->left, key);
        }
        else {
            return Search(node->right, key);
        }
    }

private:
    Node* root_;

};


int main(){
    BTree tree;

    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);

    tree.Insert(2);
    tree.Insert(1);


    tree.Insert(10);
    tree.Insert(9);

    //       5
    //    3    7
    //   2    9 10
    //  1

    std::cout << tree.Search(7)->right->key << std::endl;

    return 0;

}
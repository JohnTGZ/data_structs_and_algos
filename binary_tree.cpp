#include <iostream>

struct Node{
    int key;
    Node* left;
    Node* right; 
};

class BTree{
public:
    void Insert(int key){
        //start from root node
        Insert(key, root_);
    }
    Node* Search(int key){
        //Search 
        return Search(key, root_);
    }
    void Delete(){
        Delete(root_);
    }

private:
    void Insert(int key, Node* leaf){
        if (key < leaf->key){
            if (leaf->left != nullptr){
                Insert(key, leaf->left);
            } else{
                leaf->left = new Node{key, nullptr,nullptr};
            }
        }
        else {
            if (leaf->right != nullptr){
                Insert(key, leaf->right);
            } else{
                leaf->right = new Node{key, nullptr,nullptr};
            }
        }
    }
    Node* Search(int key, Node* leaf){
        if (leaf == nullptr){
            return nullptr;
        }
        else if (leaf->key == key){
            return leaf;
        }

        if (key < leaf->key){
            Search(key, leaf->left);
        }
        else{
            Search(key, leaf->right);
        }

    }
    void Delete(Node* leaf){
        if (leaf == nullptr)
            return;
        Delete(leaf->left);
        Delete(leaf->right);

        delete leaf;
    }
    
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
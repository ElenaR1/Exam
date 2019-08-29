#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node(int data) : data(data) {}
};
void printTree(Node* str){
    cout<<str->data<<" ";
    for(int i=0;i<str->children.size();i++){
        printTree(str->children[i]);
    }
}

void dfsVisit(Node* root, int currentSum, int& maxSum) {
    if(root == NULL) {
        return;
    }

    if(currentSum+root->data > maxSum) {
            maxSum = currentSum+root->data;
    }

    for(int i=0;i<root->children.size();i++){
        dfsVisit(root->children[i],currentSum + root->data, maxSum);
    }

}

int main()
{
    Node* a =new Node(5);
    Node* b =new Node(9);
    Node* c =new Node(1);
    Node* d =new Node(4);
    Node* e =new Node(12);
    Node* f =new Node(42);

    a->children.push_back(b);
   a->children.push_back(c);
     c->children.push_back(d);
    c->children.push_back(e);
    c->children.push_back(f);

     printTree(a);
      cout<<endl;
     int max_sum=0;
    dfsVisit(a,0,max_sum);
     cout<<max_sum<<endl;

    return 0;
}

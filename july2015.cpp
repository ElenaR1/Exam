
#include <iostream>

using namespace std;

class Node {
    int data;
    Node** children;
    int size;
    int capacity;

    void resize() {
        Node** newChildren = new Node*[capacity*2];
        for(int i=0; i<size; i++) {
            newChildren[i]=children[i];
        }
        delete [] children;
        children=newChildren;
        capacity*=2;
    }
public:
    Node(int data) : data(data) {
        capacity = 1;
        children = new Node*[capacity];
        size = 0;
    }

    int getData() {
        return data;
    }

    Node** getChildren() {
        return children;
    }

    int getChildrenSize() {
        return size;
    }

    void addChild(Node* newChild) {
        if(size==capacity) {
            resize();
        }
        children[size++] = newChild;
    }

    void removeIthChild(int i) {
        delete children[i];
        children[i] = NULL;
    }

    void fixChildren() {
        Node** newChildren = new Node*[capacity];
        int idx=0;
        for(int i=0; i<size; i++) {
            if(children[i]==NULL) {
                continue;
            }
            newChildren[idx++] = children[i];
        }
        delete [] children;
        children = newChildren;
        size = idx;
    }

    ~Node() {
        for(int i=0; i<size; i++) {
            delete children[i];
        }
        delete [] children;
    }
};

bool member(Node* root, int x) {
    if(root == NULL) {
        return false;
    }else if (root->getData() == x){
        return true;
    }
    Node** children = root->getChildren();
    for(int i=0; i<root->getChildrenSize(); i++) {
        if(member(children[i], x)) {
            return true;
        }
    }
    return false;
}

void filterOddHelper(Node* crr, Node* parent, int indexInParent) {
    if(crr == NULL) {
        return;
    }else if(crr->getData() % 2 == 1) {
        parent->removeIthChild(indexInParent);
        return;
    }else {
        Node** children = crr->getChildren();
        for(int i=0; i<crr->getChildrenSize(); i++) {
            filterOddHelper(children[i], crr, i);
        }
        crr->fixChildren();
    }
}


void filterOdd(Node*& root) {
    if(root==NULL) {
        return;
    }else if(root->getData() % 2 == 1){
        delete root;
        root=NULL;
        return;
    }else {
        Node** children = root->getChildren();
        for(int i=0; i<root->getChildrenSize(); i++) {
            filterOddHelper(children[i], root, i);
        }
    }
}

void traverse(Node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->getData()<<endl;
    Node** children = root->getChildren();
    for(int i=0; i<root->getChildrenSize(); i++) {
        traverse(children[i]);
    }
}

int main()
{
    Node* root = new Node(6);

    Node* left = new Node(10);
    left->addChild(new Node(7));
    left->addChild(new Node(5));
    root->addChild(left);

   // cout<<left->getChildrenSize()<<endl;

    /*root->addChild(new Node(15));
    root->addChild(new Node(20));
    root->addChild(new Node(25));*/

    /*cout<<root.getData()<<endl;
    for(int i=0; i<root.getChildrenSize(); i++) {
        cout<<root.getChildren()[i]->getData()<<endl;
    }*/

    //cout<<member(root, 9)<<endl;
    traverse(root);
    cout<<"====================="<<endl;
    filterOdd(root);

    traverse(root);
}


//moe s vector
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
void member(Node* str,int d){
    if(str==NULL)
        return;
    else{
    if(str->data==d)
        cout<< "true";
    else{
        for(int i=0;i<str->children.size();i++){
             member(str->children[i],d);
    }
    }
    }
}

bool mem(Node* str,int d){

    if(str->data==d)
       return true;

    bool returnValue = false;
    for(int i=0;i<str->children.size();i++){
         if (mem(str->children[i],d)){
            returnValue=true;
            break;
         }
    }
    return returnValue;
}
void filterOdd(Node* str){
     for(int i=0;i<str->children.size();i++){

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
    member(a,12);
    cout<<mem(a,12)<<endl;

    return 0;
}

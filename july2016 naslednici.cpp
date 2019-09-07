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
    if(str==NULL){
        return;
    }
    cout<<str->data<<" ";
for(Node* child:str->children){
        cout<<1;
    }
}

Node* makeNode(istream& in) {
    cout<<"makeNode"<<endl;
    //char c;
    //in.get(c);
    //cout<<c<<endl;
    cout<<(char)in.peek()<<endl;
    if((char)in.peek() == ')')//Returns the next character in the input sequence, without extracting it: The character is left as the next character to be extracted from the stream.
        {
        cout<<"HERE"<<endl;
        return NULL;
    }
    //char cc;
    //in.get(cc);
    int top;
    in>>top;
    cout<<"top "<<top<<endl;
    Node* result = new Node(top);
    in.ignore(2);
    while( (char)in.peek() == '(') {
            cout<<"in while "<<(char)in.peek()<<endl;
        in.ignore();
        Node* child = makeNode(in);

        result->children.push_back(child);
        //cout<<"in while "<<top<<" "<<(char)in.peek()<<endl;
        in.ignore(2);
        if((char)in.peek() == ',') {
            in.ignore(2);
        }
    }

    return result;
}

Node* constructTree(char* filename) {
    ifstream in(filename);
    char c;
    if(in.eof()) {
        return NULL;
    }
   // in.get(c);
    //cout<<c<<endl;
    cout<<(char)in.peek()<<endl;
    in.ignore();
    //in.get(c);
    //cout<<c<<endl;
    Node* root = makeNode(in);
    in.ignore();

    in.close();
    return root;
}

void dfsVisit(Node* root, int currentSum, int& maxSum) {
    if(root == NULL) {
        return;
    }

    if(currentSum+root->data > maxSum) {
            maxSum = currentSum+root->data;
    }

    for(Node* child : root->children) {
        dfsVisit(child, currentSum + root->data, maxSum);
    }
}

int main()
{
    Node* node =constructTree("foo.txt");
     cout<<node->data<<endl;
     //printTree(node); zaciklq

    return 0;
}



//MOE, NO NE CQLOTO:
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

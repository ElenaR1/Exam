#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
    vector<char> v;
    ifstream input("foo.txt");
    while(true){
            //input.ignore(2);
        while((char)input.peek()=='(' or (char)input.peek()==')' or (char)input.peek()==','or (char)input.peek()==' '){
            input.ignore();
        }
        char cc=(char)input.peek();
        v.push_back(cc);
        cout<<cc<<endl;
        char c;
        input.get(c);
        if(input.fail()){
            break;
        }
    }
    input.close();

    cout<<"Vector: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"----------------------------"<<endl;
    ifstream in("foo.txt");
    if(in.eof()) {
        return NULL;
    }
   // in.get(c);
    //cout<<c<<endl;
    cout<<(char)in.peek()<<endl;
    in.ignore();
    //in.get(c);
    //cout<<c<<endl;

    in.ignore();

    in.close();
// AKO ISKAME DA GI VZIMAME KATO INT-OVE
    /*#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children;
    Node(int data) : data(data) {}
};

Node* makeNode(istream& in) {

    if((char)in.peek() == ')') {
        cout<<"HERE"<<endl;
        return NULL;
    }

    int top;
    in>>top;
    Node* result = new Node(top);
    in.ignore(2);
    while( (char)in.peek() == '(') {
        in.ignore();
        Node* child = makeNode(in);

        result->children.push_back(child);
        in.ignore(2);
        if((char)in.peek() == ',') {
            in.ignore(2);
        }
    }

    return result;
}

Node* constructTree(char* filename) {
    ifstream in(filename);

    if(in.eof()) {
        return NULL;
    }
    in.ignore();
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
    Node* node = constructTree("foo");
    int maxSum=0;
    dfsVisit(node, 0, maxSum);
    cout<<maxSum;
    return 0;
}
*/

    return 0;
}

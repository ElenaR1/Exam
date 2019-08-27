#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
    node* mid;
    node(char d): data(d),left(NULL),right(NULL),mid(NULL){}
    node(): left(NULL),right(NULL),mid(NULL){}
    node(char d, node*l, node*r ,node*m): data(d),left(l),right(r),mid(m){}
};

void print(node* ptr){
    if(ptr==NULL){
        return;
    }
    else{
        cout<<ptr->data<<endl;
        print(ptr->left);
        print(ptr->mid);
         print(ptr->right);
    }
}

int maxDepth(node* ptr){
    if(ptr==NULL){
        return 0;
    }
    else{
        int d1=max(maxDepth(ptr->left),maxDepth(ptr->mid));
        int d2=max(d1,maxDepth(ptr->right));
        return d2+1;
    }
}
void traverse(node* ptr, int curDepth, int depth){
    if(ptr==NULL){
        return;
    }
    if(curDepth==depth){
        cout<<ptr->data;
        return;
    }
    else{
        traverse(ptr->left,curDepth+1,depth);
        traverse(ptr->mid,curDepth+1,depth);
        traverse(ptr->right,curDepth+1,depth);
    }
}
void serializeHelper(node* root, ostream& out) {
    if(root==NULL) {
        out<<"*";
        return;
    }else {
        out<<"("<<root->data<<" ";
    }
    serializeHelper(root->left, out);
    out<<" ";
    serializeHelper(root->mid, out);
    out<<" ";
    serializeHelper(root->right, out);
    out<<")";
}


void serialize(node* root, char* filename){
    ofstream out;
    out.open(filename);
    serializeHelper(root, out);
    out.close();
}
int main()
{
    node* b=new node('b');
    node* x = new node('x');
    node* p = new node('p');
    node* q = new node('q');
    node* r = new node('r');
    node* c = new node('c');
    node* a = new node('a');
    node* y = new node('y');
    node* s = new node('s');
    node* t = new node('t');

    b->left=x;
    b->mid=y;
    x->left=p;
    x->mid=q;
    x->right=r;
    r->left=c;
    r->right=a;
    y->right=s;
    s->mid=t;

    print(b);
    int md=maxDepth(b);
    cout<<md<<endl;
    traverse(b,1,4);

    serialize(b, "tree.txt");


    ifstream infile;
   infile.open("tree.txt");

   cout << "Reading from the file" << endl;
   char data[100];
    infile >> data;
   while(!infile.eof()){
   // write the data at the screen.
   cout << data;
   infile >> data;
   }


   // close the opened file.
   infile.close();

   ifstream in;
   in.open("a.txt");

   cout << "Reading from the file" << endl;
   char d[100];
    in >> d;
   while(!in.eof()){
   // write the data at the screen.
    cout << d<<" ";
   in >> d;
   }
   while(!in.eof()){
   // write the data at the screen.
   string str;
    while(getline(in, str)) {
        cout<<str;
    }

   }
   in.close();

  /*int** m=new int*[3];
  for(int i=0; i<3; i++){
    m[i]=new int[3];
  }
  m[0]={1,2,3};
  cout<<m[0]<<endl;*/

  /*char *name = "name";
  cout<<name<<endl;

  char *a = new char[10];
  a="reg";
  cout<<a<<endl;

  char** m=new char*[3] {"ab","cd","ef"};
  /*m[0]={"abcferg, "fefr","ferrf"};

  m[1]="efgegr";
  m[2]="fvrrt";
  m[3]="fregt";*/
  /*
  cout<<m[0]<<endl;
  cout<<m[1]<<endl;
  cout<<m[2]<<endl;
  cout<<m[3]<<endl;
*/


    return 0;
}

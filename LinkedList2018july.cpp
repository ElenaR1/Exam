#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node* next;
    node* jump;
    node():next(NULL),jump(NULL){}
    node(int d, node* n,node* j): data(d),next(n),jump(j){}
    node(int d): data(d),next(NULL),jump(NULL){}
};

class LinkedList{
    public:
        node* head;
        node* curr;
        node* last;
        int size;
        int n;
        LinkedList(int nn){
            head=NULL;
            size=0;
            n=nn;
        }
        void insert(int data){
            if(head==NULL){
                head=new node(data);
            }
            else{
                node* curr=head;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=new node(data);
            }
            size++;
        }
        void fix(){
            int count=0;
            for()
        }
        void print(){
            node* curr=head;
            while(curr!=NULL){
                cout<<curr->data<<" ";
                curr=curr->next;
            }
        }

};

int main()
{
    ifstream input;
    input.open("foo.txt");
    vector<int> nums;
    string delimiter=" ";
    string str;
      while (true)
    {
    	// Try to retrieve a line from the
    	// file.

    	getline(input, str);

    	// If this operation causes the variable
    	// to go into a failure state, this means
    	// we already read everything from the file.
    	if (input.fail())
    	{
    		break;
    	}

    	// Otherwise, print what we read!
    	//cout << str << endl;
    }
    input.close();


    /*
         vector<string> v;
     ifstream input;
     input.open("a.txt");
     while(true){
        string line;
        getline(input,line);
        v.push_back(line);
        if (input.fail())
    	{
    		break;
    	}

     }
    input.close();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    */
    
    
    cout<<str;
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    for(int i=0;i<str.size();i++)
    {
        char c=str[i];
        int num=(c-'0');
       // cout<<num<<'!';
        nums.push_back(num);
    }
    cout<<"=========="<<endl;
    cout<<"vector: "<<endl;
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    LinkedList l(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        l.insert(nums[i]);
    }
    cout<<endl;
    cout<<"list:"<<endl;
    l.print();

    return 0;
}

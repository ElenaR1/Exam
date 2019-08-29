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
        v.push_back((char)input.peek());
        cout<<(char)input.peek()<<endl;
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


    return 0;
}

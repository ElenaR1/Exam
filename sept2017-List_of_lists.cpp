#include <iostream>

using namespace std;

template <typename T>
struct box
{
    T data;
    box<T> *next;
    box (const T& d, box<T> *n):data(d),next(n) {}
};

template <typename T>
class List
{
private:
    box<T> *first;

public:
    int a=5;
    List ()
    {
        first = NULL;
    }

    List (const List<T>& other)
    {
        box<T> *crr = other.first, *previous;

        if (other.first == NULL)
        {
            first = NULL;
            return;

        }

        first = new box<T> (crr->data,NULL);
        previous = first;
        crr = crr->next;

        while (crr != NULL)
        {

            previous->next = new box<T> (crr->data,NULL);
            previous = previous->next;

            crr = crr->next;

        }
    }

    List<T>& push (const T &newElemValue)
    {
        first = new box<T> (newElemValue,first);//vseli put slagame noviq element otpred i toi sochi kum tekushtata glava i posle toi stava head
        return *this;
    }

    T pop ()
    {
        box<T> *crr = first;
        T tmp = crr->data;
        first = first->next;
        delete crr;
        return tmp;
    }

    int size() const
    {
        box<T>* crr=first;
        int s=0;

        while(crr!=NULL)
        {
            s++;
            crr=crr->next;
        }

        return s;
    }

    ~List()
    {
        box<T> *crr = first, *save;

        while (crr != NULL)
        {

            save = crr;
            crr = crr->next;

            delete save;
        }
    }

    void print()
    {
        box<T> *crr = first;
        while(crr != NULL)
        {
            cout<<crr->data<<" ";
            crr=crr->next;
        }
        cout<<endl;
    }

    box<T>& get_ith(int n)
    {
        box<T> *crr=first;
        int x=0;
        while(x<n)
        {
            crr=crr->next;
            x++;
        }
        return *crr;
    }

    bool isSorted()
    {
        if(first == NULL)
        {
            return false;
        }
        box<T> *crr = first;
        while(crr->next != NULL)
        {
            if(crr->data > crr->next->data)
            {
                return false;
            }
            crr=crr->next;
        }
        return true;
    }
    void sorting(){
        box<T>* cur1 = first;
        box<T>* cur2 = first;

       for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size() - 1; j++) {
            if (cur1->data < cur2->data) {
                cout<<i<<"-"<<cur1->data<<"- "<<cur2->data<<endl;
                int temp = cur1->data;
                cur1->data = cur2->data;
                cur2->data = temp;

            }
            cur2 = cur2->next;
        }
         cur2 = first;
         cur1 = first->next;
         for (int k = 0; k < i; k++) {
                cur1 = cur1->next;
         }
    }
    print();
}
};

void doStuff(List<List<int> > arg)
{
    List<List<int> > onlySortedOnes;
    int onlySortedOnesTotalSize = 0;
    for(int i=0; i<arg.size(); i++)
    {

        List<int> tmp = arg.get_ith(i).data;
        cout<<"print: ";
        tmp.print();
        if(tmp.isSorted())
        {
            onlySortedOnesTotalSize += tmp.size();
            onlySortedOnes.push(tmp);
        }
        else{
            tmp.sorting();
            onlySortedOnesTotalSize += tmp.size();
            onlySortedOnes.push(tmp);
        }
    }

    for(int i=0; i<onlySortedOnes.size(); i++)
    {
        List<int> tmp = onlySortedOnes.get_ith(i).data;
        cout<<"elems in onlySortedOnes: ["<<i<<"]"<<endl;
        tmp.print();
    }

    List<int> sorted;
    while(sorted.size() < onlySortedOnesTotalSize)
    {

        int minIdx = 0;
         List<int> first_list_in_onlySortedOnes=onlySortedOnes.get_ith(0).data;
        int minimum = first_list_in_onlySortedOnes.get_ith(0).data;//1

        for(int i=0; i<onlySortedOnes.size(); i++)
        {
            List<int> ith_list_in_onlySortedOnes=onlySortedOnes.get_ith(i).data;
            cout<<minimum<<" - "<<ith_list_in_onlySortedOnes.get_ith(0).data<<endl;
            if(minimum > ith_list_in_onlySortedOnes.get_ith(0).data)
            {
                minimum =   ith_list_in_onlySortedOnes.get_ith(0).data;//2
                minIdx = i;
            }
        }
         cout<<"min: "<<minimum<<endl;
        sorted.push(minimum);
        onlySortedOnes.get_ith(minIdx).data.pop();//tuk mahame edinicata
        while(onlySortedOnes.size() > 0 && onlySortedOnes.get_ith(0).data.size() == 0)
        {
            onlySortedOnes.pop();
        }
        //cout<<sorted.size();
    }

    for(int i=0; i<sorted.size(); i++)
    {
        cout<<sorted.get_ith(i).data<<" ";
    }
}

int main()
{
box<int> b(5,NULL);
box<int> *ptr=new box<int>(6,NULL);
cout<<ptr->data<<endl;
    cout<<b.data<<endl;
     List<int> l;
     l.push(1);
     l.push(3);
     l.push(4);
     l.print();
     cout<<l.a<<endl;
     l.sorting();

    List<int> myList;
    myList.push(3);
    myList.push(4);
    myList.push(1);
     myList.print();

    List<int> secondList;
    secondList.push(6);
    secondList.push(5);
    secondList.push(2);
     secondList.print();

    // cout<<myList.pop()<<endl;
    //myList.print();


    List<List<int> > listOfLists;
    listOfLists.push(myList);
    listOfLists.push(secondList);

    doStuff(listOfLists);
    /*
        printList(listOfLists);

        cout<<myList.isSorted();
        isSorted(listOfLists);*/
}

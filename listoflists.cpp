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
        first = new box<T> (newElemValue,first);
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
};

void doStuff(List<List<int> > arg)
{
    List<List<int> > onlySortedOnes;
    int onlySortedOnesTotalSize = 0;
    for(int i=0; i<arg.size(); i++)
    {
        List<int> tmp = arg.get_ith(i).data;
        if(tmp.isSorted())
        {
            onlySortedOnesTotalSize += tmp.size();
            onlySortedOnes.push(tmp);
        }
    }

    for(int i=0; i<onlySortedOnes.size(); i++)
    {
        List<int> tmp = onlySortedOnes.get_ith(i).data;
        tmp.print();
    }

    List<int> sorted;
    while(sorted.size() < onlySortedOnesTotalSize)
    {

        int minIdx = 0;
        int minimum = onlySortedOnes.get_ith(0).data.get_ith(0).data;

        for(int i=0; i<onlySortedOnes.size(); i++)
        {
            if(minimum >  onlySortedOnes.get_ith(i).data.get_ith(0).data)
            {
                minimum =  onlySortedOnes.get_ith(i).data.get_ith(0).data;
                minIdx = i;
            }
        }
        // cout<<minimum<<endl;
        sorted.push(minimum);
        onlySortedOnes.get_ith(minIdx).data.pop();
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
    List<int> myList;
    myList.push(4);
    myList.push(3);
    myList.push(1);
    // myList.print();

    List<int> secondList;
    secondList.push(6);
    secondList.push(5);
    secondList.push(2);
    // secondList.print();

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

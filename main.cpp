#include <iostream>

using namespace std;

struct cell
{
    int data;
    cell* next;
};

class LinkedList
{
private:
    struct cell *first = NULL , *last = NULL;
    int counter = 0 ;
public:
    cell* GetFirst()
    {
        return first;
    }
    cell* GetLast()
    {
        return last;
    }
    //////////////////////////// Insert Section Start ////////////////////////////
    void insert_first(int d)
    {
        struct cell *temp = new cell();
        temp->data = d;
        if(first == NULL)
        {
            temp->next = NULL;
            last = temp;
        }
        else
        {
            temp->next = first;
        }
        first = temp;
        counter++;
    }
    void insert_last(int d)
    {
        struct cell *temp = new cell();
        temp->data = d;
        temp->next = NULL;
        if(first == NULL)
        {
            first = temp;
        }
        else
        {
            last->next = temp;
        }
        last = temp;
        counter++;
    }
    void insert_order(int d)
    {
        int order = 0;
        for(cell* i=GetFirst() ; i!=NULL ; i=i->next)
        {
            if( (d) > (i->data) )   order++;
            else                    break;
        }
        insert_index(d,order);
    }
    void insert_index(int d, int index)
    {
        if(index < 0)               cout<<"Error..!!!"<<endl;
        else if(index == 0)         insert_first(d);
        else if(index == counter)   insert_last(d);
        else if(index > counter)    cout<<"Error..!!!"<<endl;
        else
        {
            struct cell *pre = new cell();
            pre = first;
            for(int i=0 ; i<index-1 ; i++)
            {
                pre = pre->next;
            }
            struct cell *temp = new cell();
            temp->data = d;
            temp->next = pre->next;
            pre->next = temp;
            counter++;
        }
    }
    ///////////////////////////// Insert Section End /////////////////////////////

    //////////////////////////// Delete Section Start ////////////////////////////
    void delete_first()
    {
        if(first == NULL)   cout<<"List is empty..!!!"<<endl;
        else
        {
            cell* temp;
            temp  = first;
            first = first->next;
            delete temp;
            counter--;
        }
    }
    void delete_last()
    {
        struct cell *pre_last = new cell();
        pre_last = first;
        for(int i=0 ; i<counter-2 ; i++)
        {
            pre_last = pre_last->next;
        }
        cell* temp;
        temp  = last;
        last = pre_last;
        last->next = NULL;
        delete temp;
        counter--;
    }
    void delete_index(int index)
    {
        if(index < 0)                   cout<<"Error..!!!"<<endl;
        else if (index == 0)            delete_first();
        else if(index == counter-1)     delete_last();
        else if(index >= counter)       cout<<"Error..!!!"<<endl;
        else
        {
            struct cell *pre_del = new cell();
            struct cell *del = new cell();
            pre_del = first;
            for(int i=0 ; i<index-1 ; i++)
            {
                pre_del = pre_del->next;
            }
            del = first;
            for(int i=0 ; i<index ; i++)
            {
                del = del->next;
            }
            cell* temp;
            temp  = del;
            pre_del->next = del->next;
            delete temp;
            counter--;
        }
    }
    void delete_data(int d)
    {
        int index = find_index(d);
        if(index == -1) cout<<"Data not found..!!!"<<endl;
        else            delete_index(index);
    }
    void Clear()
    {
        while(first != NULL)
        {
            cell* temp;
            temp  = first;
            first = first->next;
            delete temp;
            counter--;
        }
    }
    ///////////////////////////// Delete Section End /////////////////////////////

    ///////////////////////////// Read Section Start /////////////////////////////
    int read_first()
    {
        if(first == NULL)
        {
            cout<<"List is empty..!!!"<<endl;
            return 0;
        }
        return first->data;
    }
    int read_last()
    {
        if(last == NULL)
        {
            cout<<"List is empty..!!!"<<endl;
            return 0;
        }
        return last->data;
    }
    int read_index(int index)
    {
        if(index < 0)                   cout<<"Error..!!!!" <<endl;
        else if(index == 0)             read_first();
        else if(index == counter-1)     read_last();
        else if(index >= counter)       cout <<"Error..!!!!" <<endl;
        else
        {
            struct cell *read = new cell();
            read = first;
            for(int i=0 ; i<index ; i++)
            {
                read = read->next;
            }
            return read->data;
        }

    }
    ///////////////////////////// Read Section End   /////////////////////////////

    ///////////////////////////// Find Section Start /////////////////////////////
    int find_index(int d)    //return the index of the first found data.
    {
        cell* temp = first;
        for(int i=0 ; i<counter ; i++)
        {
            if(d == temp->data)      return i;
            temp = temp->next;
        }
        return -1;
    }
    ///////////////////////////// Find Section End   /////////////////////////////

    int get_max()
    {
        int Max = GetFirst()->data;
        for(cell* temp = GetFirst() ; temp!=NULL ; temp = temp->next)
        {
            if(Max < temp->data)    Max = temp->data;
        }
        return Max;
    }
    int get_min()
    {
        int Min = GetFirst()->data;
        for(cell* temp = GetFirst() ; temp!=NULL ; temp = temp->next)
        {
            if(Min > temp->data)    Min = temp->data;
        }
        return Min;
    }

    int get_sum()
    {
        int Sum = 0;
        for(cell* temp = GetFirst() ; temp!=NULL ; temp = temp->next)
        {
            Sum+= temp->data;
        }
        return Sum;
    }

    float get_average()
    {
        return 1.0*get_sum()/get_number_of_elements();
    }

    int get_number_of_elements()
    {
        return counter;
    }
    void PrintLinkedList()
    {
        cout<<"Linked list : "<<endl;
        for(cell* temp = first ; temp!=NULL ; temp = temp->next)
        {
            cout<<temp->data<<"    ";
        }
    }
};

int main()
{
    LinkedList List;
    int x;
    for(int i=0 ; i<10 ; i++)
    {
        cout<<"Enter value number "<< i+1 << " : ";
        cin>>x;
        List.insert_last(x);
    }
    cout<<"Enter ordered value: ";
    cin>>x;
    List.insert_order(x);
    List.PrintLinkedList();
    cout<<endl;
    cout<<"Number of elements = "<<List.get_number_of_elements()<<endl;
    cout<<endl;
    cout << "Min = "<<List.get_min()<<endl;
    cout << "Max = "<<List.get_max()<<endl;
    cout << "Sum = "<<List.get_sum()<<endl;
    cout << "Avg = "<<List.get_average()<<endl;
    return 0;
}

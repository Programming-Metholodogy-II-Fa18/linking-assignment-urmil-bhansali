
template <class Object>
class Node
{
public:
    Node *next;
    Object object;
};

template<class Object>
class ArbitraryQueue
{
private:
    Node<Object> *head;
    Node<Object> *tail;
public:
    ArbitraryQueue();
    void push (Object object);
    Object pop();
    void display();
    bool isEmpty();
    void Enqueue(int);
    Object Dequeue();
    Object Traverse(int);
    
};


template<class Object>
ArbitraryQueue<Object>::ArbitraryQueue()
{
    
    head = NULL;
    tail= head;
    
}



template<class Object>
bool ArbitraryQueue<Object>:: isEmpty()
{
    return( head == NULL);
}


template<class Object>
void ArbitraryQueue<Object>:: push(Object object)
{
    Node<Object> *temp= head;
    head = new Node<Object>;
    head -> object= object;
    head -> next= temp;
    delete temp;
}




template<class Object>
Object ArbitraryQueue<Object>:: pop()
{
    try
    {
        if( head == NULL )
            
            throw("You have accessed a Null Pointer. There exist no objects in your ArbitraryQueue, and hence you cannot perform the 'pop' operation.");
        else
        {
            Node<Object>* temp = head;
            Object ans= temp-> object;
            head= temp->next;
            return ans;
        }
        
    }
    catch (const char* msg)
    {
        cout<<msg<<endl;
        return 0;
        
    }
    
}






template< class Object>
void ArbitraryQueue<Object> ::Enqueue(int new_Guy)
{
    tail= head;
    
    
    while(!isEmpty() && tail->next!= NULL)
    {
        tail= tail->next;
    }
    tail->next = new Node<Object>;
    tail=tail->next;
    tail->object= new_Guy;
    tail->next=NULL;
}




template<class Object>
Object ArbitraryQueue<Object> ::Dequeue()
{
    Node<Object> *prev = head;
    Node<Object> *last= head;
    Object ans;
    int counter=0;
    try
    {
        if(isEmpty())
        {
            throw("You have accessed a Null Pointer. There exist no objects in your ArbitraryQueue, and hence you cannot perform the 'Dequeue' operation.");
        }
        
        else if(head-> next == NULL)
        {
            return head-> object;
            head = NULL;
            last = NULL;
        }
        else
        {
            while(last->next!= NULL)
            {
                last= last-> next;
                counter ++;
            }
            for(int i=1; i<counter; i++)
            {
                prev= prev->next;
            }
            ans= last->object;
            prev->next= NULL;
            last= prev;
            return ans;
        }
    }
    catch (const char* msg)
    {
        cout<<msg<<endl;
        return 0;
    }
}

template <class Object>
Object ArbitraryQueue<Object> ::Traverse(int index)
{
    int ctr=0;
    Node<Object> *temp= head;
    
    while(temp->next!= NULL)
    {
        temp=temp->next;
        ctr++;
    }
    if(isEmpty())
    {
        cout<<"Nothing to return, queue is empty";
        return 0;
    }
    else if (head->next == NULL)
        return head-> object;
    
    else if (index<= ctr)
    {
        
        temp= head;
        for(int i=0; i<index; i++)
        {
            temp= temp->next;
        }
        return temp-> object;
        
    }
    else
    {
        cout<<"Invalid Index";
        return 0;
        
    }
    
}



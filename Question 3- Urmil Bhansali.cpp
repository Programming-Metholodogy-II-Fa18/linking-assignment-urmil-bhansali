

class Node
{
public:
    Node *next;
    Node *previous;
    int data;
};


class List
{
private:
    Node *head;
    int data;
public:
    List();
    void push (int data);
    int pop();
    void display();
    int peek();
    int pastPeek();
    void InsertionSort();
    
};



List::List()
{
    
    head = NULL;
}



void List :: display()
{
    if(head == NULL)
    {
        cout<<"Nothing to Display";
    }
    else
    {
        Node* printer= head;
        while(printer != NULL)
        {
            cout<< printer -> data<<",";
            printer= printer ->next;
        }
        cout<<"NULL"<<endl;
    }
}


void List:: push(int NewData)
{
    if(head==NULL)
    {
        head = new Node;
        head -> data= NewData;
        head -> next= NULL;
        head -> previous = NULL;
    }
    else
    {
    Node *old_head= head;
    head = new Node;
    head -> data= NewData;
    head -> next= old_head;
    head -> previous = NULL;
    old_head-> previous= head;
    old_head-> next= NULL;
        
   }
}




int List:: pop()
{
    if(head != NULL)
    {
        Node* temp= head;
        int popped_data= head-> data;
        head= temp->next;
        head-> next= temp->next;
        head -> previous= NULL;
        delete temp;
        return popped_data;
    }
    else
    {
        cout<<"Nothing to pop"<<endl;
        exit(1);
    }
}

void List:: InsertionSort()
    {
        if(head==NULL)
        {
            cout<<"No elements to sort"<<endl;
            return;
        }
        else if(head->next == NULL)
        {
            cout<<"Only 1 element in the list. Nothing to sort"<<endl;
            return;
        }

        else
        {
            Node * curr= head-> next;
            Node * prev=head;
           if(curr-> data > prev -> data)
            {
                Node *temp= curr;
                curr->next= prev;
                prev-> next= temp->next;
                prev-> previous= curr;
                curr-> previous= NULL;
                curr=temp-> next;
                
            }
        
        while(curr->next != NULL)
    {
        Node *temp_next= curr->next;
        while (prev-> previous!= NULL)
        {
            Node *temp2= prev;
            if(curr-> data< prev-> data)
            {
                prev-> next= curr-> next;
                prev-> previous= curr;
                curr-> previous= temp2-> previous;
                curr-> next= temp2;
            }
            prev= temp2-> previous;
        }
        curr= temp_next;
    }
}
        
}



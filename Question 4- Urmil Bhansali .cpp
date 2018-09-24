

class Node
{
public:
    char ch;
    Node *next;
};

class Reverse
{
private:

    void Push(string);
    public :
    void ProblemFourA( string str, int );
    Node *head;
    Reverse()
    {
        head= NULL;
    }
    
    
};

void Reverse:: ProblemFourA(string str, int length )
{
    ;
    
    for(int i=0; i<length; i++)
    {
        Node *temp= head;
        head = new Node;
        head-> ch= str[i];
        head-> next= temp;
        
    }
    for(int i=0;i<length; i++)
    {
        cout<<head->ch;
        head= head-> next;
    }
    
}







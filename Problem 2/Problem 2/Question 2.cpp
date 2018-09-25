


template <class Object>
class ArbitraryQueueArray
{
private:
    Object arr[5];
    int n;
    int top;
    int end;
    void Copy(int);
public:
    ArbitraryQueueArray();
    void Push(Object);
    Object Pop();
    void Enqueue(Object);
    Object Dequeue();
    Object Traverse(int);
    
};

template<class Object>
ArbitraryQueueArray<Object> ::ArbitraryQueueArray()
{
    n=0;
    top=-1;
    end=0;
}





template<class Object>
void ArbitraryQueueArray<Object> ::Copy(int size)
{
    Object big[size];
    for(int i=0;i<size;i++)
    {
        big[i]= arr[i];
       
    }
     memcpy(arr, big, sizeof(big));
}




template<class Object>
void ArbitraryQueueArray<Object> ::Push(Object object)
{
    if(n==sizeof(arr))
    {
        Copy( 2* sizeof(arr));
    }
    else
    {
        arr[++top]= object;
        n++;
    }
    
}

template<class Object>
Object ArbitraryQueueArray<Object> ::Pop()
{
    try
    {
        if(n==0)
        {
            throw("You have accessed a Null Value. There exist no objects in your ArbitraryQueueArray, and hence you cannot perform the 'pop' operation.");
            
        }
        else if(n>0 && n==(sizeof(arr)/4))
        {
            Copy(sizeof(arr)/2);
        }
    }
        catch (const char* msg)
        {
            cout<<msg<<endl;
            return 0;
        }
    Object object= arr[top--];;
    n--;
    return object;
}

template<class Object>
void ArbitraryQueueArray<Object> ::Enqueue(Object object)
{
    if(n==sizeof(arr))
    {
        Copy( 2* sizeof(arr));
    }
    else
    {
        int temp=n;
        while(temp>0)
        {
            arr[temp]=arr[temp-1];
            temp--;
        }
        arr[end]= object;
        top++;
        n++;
    }
    
}

template<class Object>
Object ArbitraryQueueArray<Object> ::Dequeue()
{
    Object object;
    if(end<=top)
    {
        object= arr[end];
        arr[end]= NULL;
        end++;
        n--;
        return object;
    }
    else
    {
        cout<<"Nothing to dequeue"<<endl;
        return 0;
    }
}

template <class Object>
Object ArbitraryQueueArray<Object>:: Traverse(int index)
{
   try
    {
        if(index<n)
        return arr[index];
    else
    {
        throw("Invalid index. Please enter a number between 0 and");
    }
       
    }
    catch(const char* msg)
        {
            cout<<msg<<" "<<n-1<<endl;
            return 0;
        }
    
}














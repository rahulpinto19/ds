struct node
{
    int data;
    node*next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class MyCircularDeque {
public:
    int size,currsize = 0;
    node*root = NULL;
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value)
    {
        if(isFull())
        {
            return 0;
        }
        if(!root)
        {
            root = new node(value);
        }    
        else
        {
            node*ptr = new node(value);
            ptr->next = root;
            root = ptr;
        }
        currsize++;
        return 1;
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
        {
            return 0;
        }    
        if(!root)
        {
            root = new node(value);
        }
        else
        {
            node*ptr = root;
            while(ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->next = new node(value);
        }
        currsize++;
        return 1;
    }
    
    bool deleteFront() 
    {
        if(isEmpty())
        {
            return 0;
        }    
        else
        {
            root = root->next;
            currsize--;
        }
        return 1;
    }
    
    bool deleteLast() 
    {
        if(isEmpty())
        {
            return 0;
        }    
        else
        {
            currsize--;
            if(root->next == NULL)
            {
                root = NULL;
                return 1;
            }
            node*prev = NULL;
            node*curr = root;
            while(curr->next)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
        }
        return 1;
    }
    
    int getFront() 
    {
        if(isEmpty())
        {
            return -1;
        }    
        else
        {
            return root->data;
        }
    }
    
    int getRear() 
    {
        if(isEmpty())
        {
            return -1;
        }   
        else 
        {
            node*ptr = root;
            while(ptr->next)
            {
                ptr = ptr->next;
            }
            return ptr->data;
        }
    }
    
    bool isEmpty() 
    {
        return currsize == 0 ;      
    }
    
    bool isFull() 
    {
        return currsize == size;    
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
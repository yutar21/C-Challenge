#include <iostream>
#include <conio.h>
 
class PTLinkedList
{
    struct Node    
    {
        int data_;
        Node* p_next_;
    };
 
public:
    PTLinkedList() { p_head_ = NULL; }
    ~PTLinkedList()
    {
        Node* head = p_head_;
        while (head)
        {
            Node* temp = head;
            head = head->p_next_;
            delete temp;
            temp = NULL;
        }
    }
 
    void AddValue(int val)  
    {
        Node* new_node = new Node();
        new_node->data_ = val;
        new_node->p_next_ = p_head_;
        p_head_ = new_node;
    }
    void Remove()  
    {
    	/*for(Node* temp=p_head_;p_head_!=NULL;temp=temp->p_next_){
    		if(temp%2==0)
    		{
    			delete temp;
    		}
    	}*/
        if (p_head_ != NULL)
        {
            Node* temp = p_head_;
            p_head_ = p_head_->p_next_;
            delete temp;
        }
    }
    void SortList()
    {
    	for(Node* temp=p_head_;temp!=NULL;temp=temp->p_next_)
    	{
    		for(Node* temp2=temp->p_next_;temp!=NULL;temp2->p_next_)
			{
				if(temp->data_>temp2->data_)
				{
					int tmp=temp->data_;
                    temp->data_=temp2->data_;
                    temp2->data_=tmp;
				}
				break;
			}
    	}
    }
    
    void Show()  
    {
        Node* temp = p_head_;
        while (temp != NULL)
        {
            int value = temp->data_;
            std::cout << "  " << value;
            temp = temp->p_next_;
        }
    }
private:
    Node* p_head_;   
}; 

int main()
{
    PTLinkedList data_list;
    data_list.AddValue(5);
    data_list.AddValue(6);
    data_list.AddValue(7);
    data_list.AddValue(8);
    data_list.AddValue(9);
 
    data_list.Show();
 
    data_list.SortList();
 
    std::cout << std::endl;
    data_list.Show();
 
    return 0;
}
 

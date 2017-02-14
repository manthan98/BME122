#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
    next = NULL;
    prev = NULL;
    value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* temp = head_;
    if(size_ == 0)
    {
        // do nothing
    } else if(size_ == 1)
    {
        delete(temp);
    } else
    {
        Node* temp2 = temp->next;
        while(temp->next != NULL)
        {
            delete(temp);
            temp = temp2;
            temp2 = temp2->next;
        }
        delete(temp);
        delete(temp2);
    }
}

bool DoublyLinkedList::empty() const
{
    if(size_ == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

void DoublyLinkedList::print() const
{
    Node* temp = head_;
    while(temp != NULL)
    {
        std::cout << temp->value;
        temp = temp->next;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    if(full())
    {
        return false;
    }
    if(size_ == 0)
    {
        Node* temp = new Node(value);
        head_ = temp;
        tail_ = temp;
        size_++;
        return true;
    } else
    {
        Node* newNode = new Node(value);
        Node* temp = head_;
        newNode->next = temp;
        temp->prev = newNode;
        head_ = newNode;
        size_++;
        return true;
    }
}

bool DoublyLinkedList::remove_front()
{
    if(size_ == 0)
    {
        return false;
    } else if(size_ == 1)
    {
        Node* temp = head_;
        temp->next = NULL;
        temp->prev = NULL;
        head_ = NULL;
        tail_ = NULL;
        delete temp;
        size_--;
        return true;
    } else
    {
        Node* temp = head_;
        temp->next->prev = NULL;
        head_ = temp->next;
        delete temp;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::insert_back(DataType value)
{
    if(full())
    {
        return false;
    }
    
    if(size_ == 0)
    {
        Node* newNode = new Node(value);
        head_ = newNode;
        tail_ = newNode;
        size_++;
        return true;
    } else
    {
        Node* newNode = new Node(value);
        Node* temp = tail_;
        temp->next = newNode;
        newNode->prev = temp;
        tail_ = newNode;
        size_++;
        return true;
    }
}

bool DoublyLinkedList::remove_back()
{
    if(size_ == 0)
    {
        return false;
    } else if(size_ == 1)
    {
        Node* temp = tail_;
        head_ = NULL;
        tail_ = NULL;
        delete temp;
        size_--;
        return true;
    } else
    {
        Node* temp = tail_;
        temp->prev->next = NULL;
        tail_ = temp->prev;
        delete temp;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if(index > size_ || full())
    {
        return false;
    }
    
    if (index == 0)
    {
        insert_front(value);
        return true;
    } else if(index == size_)
    {
        insert_back(value);
        return true;
    } else
    {
        Node* newNode = new Node(value);
        Node* temp = head_;
        for(unsigned int i=0; i<index-1; i++)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        size_++;
        
        return true;
    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if(index > size_ - 1)
    {
        return false;
    } else if(index == 0)
    {
        // WHY????
        
        //remove_front();
        return false;
    } else if(index == size_ - 1)
    {
        remove_back();
        return true;
    } else
    {
        Node* temp = head_;
        Node* temp3 = head_;
        for(int i = 0; i < index; i++)
        {
            temp = temp->next;
            temp3 = temp->next->next;
        }
        Node* temp2 = temp->next;
        temp2->next = NULL;
        temp2->prev = NULL;
        delete(temp2);
        temp->next = temp3;
        temp3->prev = temp;
        
        size_--;
        return true;
    }
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    if(DoublyLinkedList::empty())
    {
        return size_;
    } else
    {
        Node* temp = head_;
        for(unsigned int i = 0; i < size_; i++)
        {
            if(temp->value == value)
            {
                return i;
            } else
            {
                temp = temp->next;
            }
        }
        return size_;
    }
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if(size_ == 0)
    {
        return false;
    } else if(index > size_ - 1)
    {
        return tail_->value;
    } else
    {
        Node* temp = head_;
        for(unsigned int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if(size_ == 0 || index > size_ - 1)
    {
        return false;
    }
    
    if(index == 0)
    {
        Node* newNode = new Node(value);
        Node* temp = head_;
        head_ = newNode;
        newNode->next = temp->next;
        temp->next->prev = NULL;
        delete temp;
        return true;
    } else if(index == size_ - 1)
    {
        Node* newNode = new Node(value);
        Node* temp = tail_;
        tail_ = newNode;
        temp->prev->next = newNode;
        temp->prev = NULL;
        delete temp;
        return true;
    } else
    {
        Node* newNode = new Node(value);
        Node* temp = head_;
        for(int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        Node* temp3 = temp2->next;
        temp->next = newNode;
        newNode->prev = temp;
        temp3->prev = newNode;
        newNode->next = temp3;
        temp2->next = NULL;
        temp2->prev = NULL;
        delete temp2;
        return true;
    }
}

bool DoublyLinkedList::full() const
{
    if(size_ == CAPACITY)
    {
        return true;
    } else
    {
        return false;
    }
}

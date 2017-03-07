#include<iostream>
#include<string>
#include "DynamicStack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    items_ = new StackItem[16];
    capacity_ = 16;
    size_ = 0;
    init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    if(capacity == 0)
    {
        DynamicStack();
    } else
    {
        items_ = new StackItem[capacity];
        capacity_ = capacity;
        size_ = 0;
        init_capacity_ = capacity;
    }
}

DynamicStack::~DynamicStack()
{
    delete[] items_;
    size_ = 0;
}

bool DynamicStack::empty() const
{
    if(size_ == 0)
        return true;
    return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    /*if(size_ == capacity_)
    {
        capacity_ = capacity_ * 2;
        StackItem* temp = new StackItem[capacity_];
        for(unsigned int i = 0; i < size_; i ++)
        {
            temp[i] = items_[i];
        }
        delete[] items_;
        items_ = temp;
    }
    items_[size_] = value;
    size_++;*/
    
    if(size_==capacity_)
    {
        capacity_=capacity_*2;
        StackItem* temp=new StackItem [capacity_];
        for(unsigned int i=0; i<size_; i++)
        {
            temp[i]=items_[i];
        }
        delete[](items_);
        items_=temp;
        
    }
    items_[size_]=value;
    size_++;
}

StackItem DynamicStack::pop()
{
    if(size_ == 0)
    {
        return EMPTY_STACK;
    }
    
    StackItem val = items_[size_ - 1];
    size_--;
    
    if(size_ <= (capacity_/4))
    {
        if((capacity_ / 2) < init_capacity_)
        {
            // do nothing
        }
        else
        {
            capacity_ = capacity_ / 2;
            StackItem* temp = new StackItem[capacity_];
            for(unsigned int i = 0; i < size_; i ++)
            {
                temp[i] = items_[i];
            }
            delete [] items_;
            items_ = temp;
        }
    }
    return val;
}

StackItem DynamicStack::peek() const
{
    if(size_ != 0)
    {
        return items_[size_ - 1];
    }
    return EMPTY_STACK;
}

void DynamicStack::print() const
{
    for(int i = 0; i < size_; i ++)
    {
        cout << items_[i];
    }
}

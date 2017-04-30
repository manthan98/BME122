#include "PriorityQueue.hpp"
#include<cstring>
#include<iostream>

using namespace std;
typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
    heap_ = new DataType[capacity + 1];
    capacity_ = capacity;
    size_ = 0;
}

PriorityQueue::~PriorityQueue()
{
    delete[] (heap_);
    size_ = 0;
    heap_ = NULL;
}

unsigned int PriorityQueue::size() const
{
    return size_;
}

bool PriorityQueue::full() const
{
    if(size_ == capacity_)
    {
        return true;
    } else
    {
        return false;
    }
}

bool PriorityQueue::empty() const
{
    if(size_ == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

PriorityQueue::DataType PriorityQueue::max() const
{
    if(empty())
    {
        return -999;
    } else
    {
        return heap_[1];
    }
}

bool PriorityQueue::enqueue(DataType val)
{
    if(full())
    {
        return false;
    } else if(empty())
    {
        heap_[1] = val;
        size_++;
        return true;
    } else
    {
        heap_[size_ + 1] = val;
        int current = size_ + 1;
        DataType parent;
        while(heap_[current] > heap_[current / 2] && current != 1)
        {
            parent = heap_[current / 2];
            heap_[current / 2] = heap_[current];
            heap_[current] = parent;
            current = current / 2;
        }
        size_++;
        return true;
    }
}

bool PriorityQueue::dequeue()
{
    if (PriorityQueue::empty())
    {
        return false;
    }
    else if(size_ == 1)
    {
        size_--;
        return true;
    }
    else
    {
        heap_[1]=heap_[size_];
        size_--;
        int current = 1;
        DataType temp_;
        while (size_>=2*current)
        {
            if(2*current<size_ && 2*current+1<=size_)
            {
                if(heap_[2*current]>heap_[2*current+1])
                {
                    if(heap_[2*current]>heap_[current])
                    {
                        temp_ = heap_[current];
                        heap_[current] = heap_[2*current];
                        heap_[2*current] = temp_;
                        current = 2*current;
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    if(heap_[2*current+1]>heap_[current])
                    {
                        temp_ = heap_[current];
                        heap_[current] = heap_[2*current+1];
                        heap_[2*current+1] = temp_;
                        current = 2*current+1;
                    }
                    else
                    {
                        return true;
                    }
                }	
            }
            else
            {
                if(heap_[2*current]>heap_[current])
                {
                    temp_ = heap_[current];
                    heap_[current] = heap_[2*current];
                    heap_[2*current] = temp_;
                    current = 2*current;
                }
                else
                {
                    return true;
                }
            }
            
        }
        return true;
    }
}

void PriorityQueue::print() const
{
    if(size_ == 0)
    {
        // do nothing
    } else
    {
        for(int i = 1; i <= size_; i ++)
        {
            cout << heap_[i] << endl;
        }
    }
}
















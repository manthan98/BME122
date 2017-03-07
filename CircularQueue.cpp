#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    capacity_ = 16;
    items_ = new QueueItem[16];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    items_ = new QueueItem[capacity];
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;
    size_ = 0;
}

CircularQueue::~CircularQueue()
{
    delete[] items_;
    /*head_ = NULL;
    tail_ = NULL;
    capacity_ = 0;
    size_ = 0;*/
}

bool CircularQueue::empty() const
{
    if(size_ == 0)
    {
        return true;
    }
    return false;
}

bool CircularQueue::full() const
{
    if(size_ == capacity_)
    {
        return true;
    }
    return false;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if(!full())
    {
        items_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
        size_++;
        return true;
    }
    return false;
}

QueueItem CircularQueue::dequeue()
{
    if(size_ == 0)
    {
        return EMPTY_QUEUE;
    } else
    {
        QueueItem val = items_[head_];
        head_ = (head_ + 1) % capacity_;
        size_--;
        return val;
    }
}

QueueItem CircularQueue::peek() const
{
    if(empty())
    {
        return EMPTY_QUEUE;
    }
    return items_[head_];
}

void CircularQueue::print() const
{
    for(int i = head_; i < size_; i ++)
    {
        std::cout << items_[i];
    }
}

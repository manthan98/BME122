#include "SequentialList.hpp"
#include <iostream
#include <string>

SequentialList::SequentialList(unsigned int cap)
{
	data_ = new DataType[cap];
	capacity_ = cap;
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete [] (data_);
	data_ = NULL;
	capacity_ = 0;
	size_ = 0;
}

bool SequentialList::empty() const
{
	if(size_ == 0)
	{
		return true;
	} else
	{
		return false;
	}
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	if(size_ == capacity_)
	{
		return true;
	} else
	{
		return false;
	}
}

void SequentialList::print() const
{
	for(int i = 0; i < size_; i++)
	{
        std::cout << data_[i];
	}
}

bool SequentialList::insert_front(DataType val)
{
    if(full() == false)
    {
        for(int i = size_ - 1; i > 0; i--)
        {
            data_[i + 1] = data_[i];
        }
        data_[1] = data_[0];
        data_[0] = val;
        size_++;
        return true;
    } else if(size_ == 0)
    {
        data_[0] = val;
        size_++;
        return true;
    } else
    {
        return false;
    }
}

bool SequentialList::remove_front()
{
    if(size_ != 0)
    {
        for(int i = 0; i < size_; i++)
        {
            data_[i] = data_[i+1];
        }
        data_[size_-1] = NULL;
        size_--;
        return true;
    } else
    {
        return false;
    }
}

bool SequentialList::insert_back(DataType val)
{
    if(!full())
    {
        data_[size_] = val;
        size_++;
        return true;
    } else
    {
        return false;
    }
}

bool SequentialList::remove_back()
{
    if(empty())
    {
        return false;
    } else
    {
        data_[size_] = NULL;
        size_--;
        return true;
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if(full() || index > size_)
    {
        return false;
    } else if(size_ == 0)
    {
        data_[0] = val;
        return true;
    } else if(index == 0)
    {
        insert_front(val);
        return true;
    } else if(index == size_)
    {
        insert_back(val);
        return true;
    } else
    {
        for(int i = size_ - 1; i > index - 1; i--)
        {
            data_[i + 1] = data_[i];
        }
        data_[index] = val;
        size_++;
        return true;
    }
}

bool SequentialList::remove(unsigned int index)
{
    if(size_ == 0 || index > capacity_ - 1)
    {
        return false;
    } else if(index == 0)
    {
        remove_front();
        return true;
    } else if(index == size_-1)
    {
        remove_back();
        return true;
    } else
    {
        for(int i = index; i < size_; i ++)
        {
            data_[i] = data_[i + 1];
        }
        size_--;
        return true;
    }
}

unsigned int SequentialList::search(DataType val) const
{
    for(int i = 0; i < size_; i++)
    {
        if(data_[i] == val)
        {
            return i;
        }
    }
    return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if(size_ == 0)
    {
        return false;
    } else if(index > capacity_-1 || index < 0)
    {
        return data_[size_-1];
    } else
    {
        return data_[index];
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index > 0 && index <= size_-1)
    {
        data_[index] = val;
        return true;
    } else
    {
        return false;
    }
}

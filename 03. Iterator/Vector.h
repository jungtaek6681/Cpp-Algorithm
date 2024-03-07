#pragma once

using namespace std;

template <typename T>
class Vector
{
public:
    Vector();
    Vector(int count);
    virtual ~Vector();

    int Size();
    int Capacity();

    void PushBack(const T& data);
    void PopBack();
    void Clear();
    bool Empty();

    T& operator[](int index);

private:
    T* dataArray;
    int size;
    int capacity;

    void Grow();

public:
    class Iterator
    {
        friend Vector;
    public:
        Iterator(Vector* vector, T* dataArray, int index);
        virtual ~Iterator();

        T& operator*();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        Iterator& operator+=(int count);
        Iterator& operator-=(int count);
        T& operator[](int index);

        bool operator==(const Iterator& other);
        bool operator!=(const Iterator& other);

    private:
        Vector* vector;
        T* dataArray;
        int index;
    };

    Iterator Begin();
    Iterator End();
    Iterator Insert(Iterator iter, const T& value);
    Iterator Erase(Iterator iter);
};

template<typename T>
Vector<T>::Vector()
{
    dataArray = new T[4];
    size = 0;
    capacity = 4;
}

template<typename T>
inline Vector<T>::Vector(int count)
{
    dataArray = new T[count];
    size = count;
    capacity = count;
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] dataArray;
}

template<typename T>
int Vector<T>::Size()
{
    return size;
}

template<typename T>
int Vector<T>::Capacity()
{
    return capacity;
}

template<typename T>
void Vector<T>::PushBack(const T& data)
{
    if (size >= capacity)
    {
        Grow();
    }

    dataArray[size++] = data;
}

template<typename T>
void Vector<T>::PopBack()
{
    if (0 == size)
        throw exception("Vector is empty");

    size--;
}

template<typename T>
void Vector<T>::Clear()
{
    size = 0;
}

template<typename T>
bool Vector<T>::Empty()
{
    return 0 == size;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
    if (index >= size)
        throw exception("Vector subscript out of range");

    return dataArray[index];
}

template<typename T>
void Vector<T>::Grow()
{
    int newCapacity = capacity * 2;
    T* newArray = new T[newCapacity];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = dataArray[i];
    }

    delete[] dataArray;
    dataArray = newArray;
    capacity = newCapacity;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Begin()
{
    return Iterator(this, dataArray, 0);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::End()
{
    return Iterator(this, dataArray, size);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Insert(Iterator iter, const T& value)
{
    if (iter->vector != this)
        throw exception("Vector emplace iterator outside range");
    
    if (iter->dataArray != this->dataArray)
        throw exception("Vector emplace iterator outside range");

    PushBack(0);
    int index = iter->index;
    for (int i = size - 1; i > index; i--)
    {
        dataArray[i] = dataArray[i - 1];
    }
    dataArray[index] = value;

    return Iterator(this, dataArray, index);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Erase(Iterator iter)
{
    if (iter->vector != this)
        throw exception("Vector emplace iterator outside range");

    if (iter->dataArray != this->dataArray)
        throw exception("Vector emplace iterator outside range");

    PopBack();
    int index = iter->index;
    for (int i = index; i < size - 1; i++)
    {
        dataArray[i] = dataArray[i + 1];
    }

    return Iterator(this, dataArray, index);
}

template<typename T>
Vector<T>::Iterator::Iterator(Vector* vector, T* dataArray, int index)
{
    this->vector = vector;
    this->dataArray = dataArray;
    this->index = index;
}

template<typename T>
Vector<T>::Iterator::~Iterator()
{
}

template<typename T>
T& Vector<T>::Iterator::operator*()
{
    if (vector->dataArray != dataArray)
        throw exception("Can not dereference invalidated vector iterator");

    return vector[index];
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()
{
    if (vector->dataArray != dataArray)
        throw exception("Can not dereference invalidated vector iterator");
    if (vector->size == index)
        throw exception("Can not increment vector iterator past end");

    index++;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
{
    Iterator iter = *this;
    ++(*this);
    return iter;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--()
{
    if (vector->dataArray != dataArray)
        throw exception("Can not dereference invalidated vector iterator");
    if (0 == index)
        throw exception("Can not decrement vector iterator before begin");

    index--;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int)
{
    Iterator iter = *this;
    --(*this);
    return iter;
}

template<typename T>
typename T& Vector<T>::Iterator::operator[](int index)
{
    if (vector->dataArray != dataArray)
        throw exception("Can not dereference invalidated vector iterator");
    if (index < 0)
        throw exception("Can not decrement vector iterator before begin");
    if (vector->size < index)
        throw exception("Can not increment vector iterator past end");

    return dataArray[index];
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator+=(int count)
{
    for (int i = 0; i < count; i++)
    {
        ++(*this);
    }
    return *this;
}

template<typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator-=(int count)
{
    for (int i = 0; i < count; i++)
    {
        --(*this);
    }
    return *this;
}

template<typename T>
bool Vector<T>::Iterator::operator==(const Iterator& other)
{
    if (this->vector == other.vector &&
        this->dataArray == other.dataArray &&
        this->index == other.index)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& other)
{
    return !(*this == other);
}

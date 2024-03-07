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

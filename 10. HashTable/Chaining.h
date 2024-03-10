#pragma once
#include <list>

using namespace std;

namespace Chaining
{
template <typename TKey, typename TValue>
class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    struct Entry
    {
        TKey key;
        TValue value;
    };

    int Size();
    bool Empty();
    void Clear();

    void Insert(const TKey& key, const TValue& value);
    void Erase(const TKey& key);
    bool Contain(const TKey& key);

    TValue& operator[](const TKey& key);

private:
    list<Entry>* table;
    int size;
    int capacity;

    hash<TKey> hashFunc;
};

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable()
{
    table = new list<Entry>[1000];
    size = 0;
    capacity = 1000;
}

template<typename TKey, typename TValue>
HashTable<TKey, TValue>::~HashTable()
{
    delete[] table;
}

template<typename TKey, typename TValue>
int HashTable<TKey, TValue>::Size()
{
    return size;
}

template<typename TKey, typename TValue>
bool HashTable<TKey, TValue>::Empty()
{
    return 0 == size;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::Clear()
{
    delete[] table;

    table = new list<Entry>[1000];
    size = 0;
    capacity = 1000;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::Insert(const TKey& key, const TValue& value)
{
    int index = hashFunc(key) % capacity;

    list<Entry>& bucket = table[index];
    for (auto iter = bucket.begin(); iter != bucket.end(); iter++)
    {
        if (iter->key == key)
            return;
    }

    Entry entry = Entry();
    entry.key = key;
    entry.value = value;
    bucket.push_back(entry);
    size++;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::Erase(const TKey& key)
{
    int index = hashFunc(key) % capacity;

    list<Entry>& bucket = table[index];
    for (auto iter = bucket.begin(); iter != bucket.end(); iter++)
    {
        if (iter->key == key)
        {
            bucket.erase(iter);
            size--;
            return;
        }
    }
}

template<typename TKey, typename TValue>
bool HashTable<TKey, TValue>::Contain(const TKey& key)
{
    int index = hashFunc(key) % capacity;

    list<Entry>& bucket = table[index];
    for (auto iter = bucket.begin(); iter != bucket.end(); iter++)
    {
        if (iter->key == key)
            return true;
    }

    return false;
}

template<typename TKey, typename TValue>
TValue& HashTable<TKey, TValue>::operator[](const TKey& key)
{
    int index = hashFunc(key) % capacity;

    list<Entry>& bucket = table[index];
    for (auto iter = bucket.begin(); iter != bucket.end(); iter++)
    {
        if (iter->key == key)
        {
            return iter->value;
        }
    }

    Entry entry = Entry();
    entry.key = key;
    entry.value = TValue();
    auto iter = bucket.insert(bucket.end(), entry);
    size++;

    return iter->value;
}
}
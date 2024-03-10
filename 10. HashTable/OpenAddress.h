#pragma once
#include <utility>

using namespace std;

namespace OpenAddress
{
template <typename TKey, typename TValue>
class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    struct Entry
    {
        enum class State { None, Using, Deleted };

        State state = State::None;
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
    Entry* table;
    int usedSize;
    int deletedSize;
    int capacity;

    hash<TKey> hashFunc;
    void ReHashing();

    pair<bool, int> TryFind(TKey key);
};


template<typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable()
{
    table = new Entry[1000];
    usedSize = 0;
    deletedSize = 0;
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
    return usedSize;
}

template<typename TKey, typename TValue>
bool HashTable<TKey, TValue>::Empty()
{
    return 0 == usedSize;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::Clear()
{
    delete[] table;

    table = new Entry[1000];
    usedSize = 0;
    deletedSize = 0;
    capacity = 1000;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::Insert(const TKey& key, const TValue& value)
{
    pair<bool, int> find = TryFind(key);
    bool exist = find.first;
    int index = find.second;

    if (exist)
        return;

    if (usedSize + deletedSize > capacity * 0.5f)
    {
        ReHashing();
    }

    Entry entry = Entry();
    entry.state = Entry::State::Using;
    entry.key = key;
    entry.value = value;
    table[index] = entry;
    usedSize++;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::Erase(const TKey& key)
{
    pair<bool, int> find = TryFind(key);
    bool exist = find.first;
    int index = find.second;

    if (!exist)
        return;

    table[index].state = Entry::State::Deleted;
    usedSize--;
    deletedSize++;
}

template<typename TKey, typename TValue>
bool HashTable<TKey, TValue>::Contain(const TKey& key)
{
    pair<bool, int> find = TryFind(key);
    bool exist = find.first;

    return exist;
}

template<typename TKey, typename TValue>
TValue& HashTable<TKey, TValue>::operator[](const TKey& key)
{
    pair<bool, int> find = TryFind(key);
    bool exist = find.first;
    int index = find.second;

    if (exist)
        return table[index].value;

    Entry entry = Entry();
    entry.state = Entry::State::None;
    entry.key = key;
    entry.value = TValue();
    table[index] = entry;
    usedSize++;

    return table[index].value;
}

template<typename TKey, typename TValue>
void HashTable<TKey, TValue>::ReHashing()
{
    Entry* oldTable = table;
    table = new Entry[capacity * 2];
    usedSize = 0;
    deletedSize = 0;

    for (int i = 0; i < capacity; i++)
    {
        Entry entry = oldTable[i];
        if (entry.state == Entry::State::Using)
        {
            Insert(entry.key, entry.value);
        }
    }

    delete[] oldTable;
    capacity = capacity * 2;
}

template<typename TKey, typename TValue>
pair<bool, int> HashTable<TKey, TValue>::TryFind(TKey key)
{
    int index = hashFunc(key) % capacity;

    for (int i = 0; i < capacity; i++)
    {
        if (table[index].state == Entry::State::None)
        {
            return make_pair(false, index);
        }
        else if (table[index].state == Entry::State::Using)
        {
            if (table[index].key == key)
            {
                return make_pair(true, index);
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
        else
        {
            if (table[index].key == key)
            {
                return make_pair(false, index);
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
    }

    throw exception("Invalid operation");
}
}

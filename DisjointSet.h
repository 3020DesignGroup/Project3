//DisjointSet.h
//Wyatt Emery
//Talon Marquard
//Project 3 - Job scheduling
//COSC 3020 Spring 2016
//3/21/16


#include<map>
#include<string>
#include"Job.h"
using namespace std;


#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

template<typename T>
class DisjointSet
{
private:
    map<T, int> _data;
    int _size;
public:
    DisjointSet();
    explicit DisjointSet(vector<T> data);
    void insert(T value);
    void insert(T value, int set);
    void merge(int set1, int set2);
    int  getSize() const;
    int find(T value) const;
        
};

#endif // !DISJOINT_SET


template<typename T>
inline DisjointSet<T>::DisjointSet() : _size(0)
{
}

template<typename T>
inline DisjointSet<T>::DisjointSet(vector<T> data) : _size(0)
{
}

template<typename T>
inline void DisjointSet<T>::insert(T value)
{
}

template<typename T>
inline void DisjointSet<T>::insert(T value, int set)
{
}

template<typename T>
inline void DisjointSet<T>::merge(int set1, int set2)
{
}

template<typename T>
inline int DisjointSet<T>::getSize() const
{
    return 0;
}

template<typename T>
inline int DisjointSet<T>::find(T value) const
{
    return 0;
}

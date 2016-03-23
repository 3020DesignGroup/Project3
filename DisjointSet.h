//DisjointSet.h
//Wyatt Emery
//Talon Marquard
//Project 3 - Job scheduling
//COSC 3020 Spring 2016
//3/21/16

/*
    Implements the Disjoint set Data structure. because the class is a templated class
    it will accept all types of input for use. the union and find are implemented such
    that both have complexity log(n).
    both the set and value types are the same because the sets are just an illusion.
    one T object "points" to another T object and the root or set name is the T object
    that points to itself.
    In most cases O(log(n)) refers to n being the height of the specific tree of values,
    which will be kept to a minimum.
*/


#include<map>
#include<string>
#include<vector>

using namespace std;

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

template<typename T>
class DisjointSet
{
private:
    //this maintains the data in the Disjoint set data structure
    //the first T is the value and the second T is the value it points to
    map<T, T> _parent;
    int _size;
    //this will keep track of the height of each tree.
    map<T, int> _treeHeight;
public:

    DisjointSet();

    DisjointSet(vector<T> data);

    void insert(T value); //O(1)

    void insert(T value, T set); //O(log(n))

    void merge(T set1, T set2); //O(log(n))

    int  getSize() const;

    T find(T value) const; //O(log(n))

    void print() const;//O(n)
private:
    //helper function
    T findRoot(T value); //O(log(n))
};


template<typename T>
DisjointSet<T>::DisjointSet() : _size(0)
{}

template<typename T>
DisjointSet<T>::DisjointSet(vector<T> data) : _size(0)
{
    for (auto t : data)
    {
        _parent[t] = t;
        _treeHeight[t] = 1;
        _size++;
    }
}

template<typename T>
void DisjointSet<T>::insert(T value)
{
    _parent[value] = value;
    _size++;
}

/*
    value will be placed in the set specified. the height
    of the tree will not grow unless the set currently being
    added to has height = 1
    //O(log(n))
*/
template<typename T>
void DisjointSet<T>::insert(T value, T set)
{
    _parent[value] = value;
    merge(value, set);
    _size++;
}

/*
    set1 will be merged with set2. the height of the tree  of the 
    larger set will not grow unless both sets have the same tree height
    //O(log(n))
*/
template<typename T>
void DisjointSet<T>::merge(T set1, T set2)
{
    T set1Root = findRoot(set1);
    T set2Root = findRoot(set2);
    if (_treeHeight[set1Root] > _treeHeight[set2Root])
    {
        _parent[set2Root] = set1Root;
    }
    else if(_treeHeight[set1Root] < _treeHeight[set2Root])
    {
        _parent[set1Root] = set2Root;
    }
    else
    {
        _parent[set1Root] = set2Root;
        _treeHeight[set2Root] += _treeHeight[set1Root];
    }
}

template<typename T>
int DisjointSet<T>::getSize() const
{
    return _size;
}

/*
    returns the root of the set that value belongs to via a T object
    Makes use of the find function in the stl map class which is O(log(n))
    //O(log(n))
*/
template<typename T>
T DisjointSet<T>::find(T value) const
{
        return _parent.find(value)->second;
}

template<typename T>
 void DisjointSet<T>::print() const
{
    cout << "item\tset" << endl;
    auto it = _parent.begin();
    while (it != _parent.end())
    {
        cout << it->first << ":\t" << it->second << endl;
        it++;
    }
}

 /*
    Helper function.
    simply locates and returns the root of the tree that any given value
    belongs to. 
    //O(log(n))
 */
 template<typename T>
T DisjointSet<T>::findRoot(T value)
 {
     T* rootptr = &value;
     while (*rootptr != _parent[*rootptr])
     {
         rootptr = &_parent[*rootptr];
     }
     return *rootptr;
 }

#endif // !DISJOINT_SET



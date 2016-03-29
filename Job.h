//Job.h
//Wyatt Emery
//Talon Marquard
//Project 3 - Job scheduling
//COSC 3020 Spring 2016
//3/21/16

#include<string>
using namespace std;

#ifndef JOB_H
#define JOB_H

class Job
{
private:
	string _name;
	double _value;
	int _dueDate;
public:
	Job();
	Job(string name, double value, int dueDate);
	string getName() const;
	int getDueDate() const;
	int getValue() const;
    bool empty() const;
};

Job::Job() : _name(""), _value(0), _dueDate(1)
{
}

Job::Job(string name, double value, int dueDate) : _name(""), _value(0), _dueDate(1)
{
	_name = name;
	if (value >= 0) _value = value;
	if (dueDate > 0) _dueDate = dueDate;
}

string Job::getName() const
{
	return _name;
}

int Job::getDueDate() const
{
	return _dueDate;
}

int Job::getValue() const
{
	return _value;
}
bool Job::empty() const
{
    if (_name == "")
        return true;
    return false;
}
#endif
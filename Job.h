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
	Job(double value, int dueDate, string name);
    string getName() const;
	int getDueDate() const;
	int getValue() const;
};

Job::Job()
{
}

Job::Job(double value, int dueDate, string name)
{
}

string Job::getName() const
{
    return string();
}

int Job::getDueDate() const
{
    return 0;
}

int Job::getValue() const
{
    return 0;
}
#endif
//JobScheduler.h
//Wyatt Emery
//Talon Marquard
//Project 3 - Job scheduling
//COSC 3020 Spring 2016
//3/21/16

#include<string>
#include"Job.h"
#include"DisjointSet.h"
#include<vector>

#ifndef JOB_SCHEDULER_H
#define JOB_SCHEDULER_H

class JobScheduler
{
private:
    vector<Job> Jobs;
    DisjointSet<Job> jobSet;
public:
    void addJob(Job job);
    void compute();
    string toString();
};


void JobScheduler::addJob(Job job)
{
}

void JobScheduler::compute()
{
}

string JobScheduler::toString()
{
    return string();
}

#endif // !JOB_SCHEDULER_H


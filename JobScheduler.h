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
    vector<Job> _jobs;
    DisjointSet<Job> _jobSet;
    vector<Job> _orderedJobs;
public:
    void addJob(Job job);
    void compute();
    string toString();
    vector<Job> getJobs() const;
};


void JobScheduler::addJob(Job job)
{
    _jobs.push_back(job);
}

void JobScheduler::compute()
{
}

string JobScheduler::toString()
{
    return string();
}
vector<Job> JobScheduler::getJobs() const
{
    return _jobs;
}

#endif // !JOB_SCHEDULER_H


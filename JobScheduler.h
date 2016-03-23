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

class JobScheduler
{
private:
	vector<Job> Jobs;
	vector<DisjointSet<Job>> jobSets;
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
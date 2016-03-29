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
#include<algorithm>
#include<iostream>

#ifndef JOB_SCHEDULER_H
#define JOB_SCHEDULER_H

class JobScheduler
{
private:
	vector<Job> _jobs;
	DisjointSet<Job> _jobSet;
	vector<Job> _orderedJobs;
	vector<string> _orderedByName;
public:
	void addJob(Job job);
	void compute();
	void computeSlow();
	string toString();
	vector<Job> getJobs() const;
};


void JobScheduler::addJob(Job job)
{
	_jobs.push_back(job);
}

bool byValues(Job i, Job j)
{
	return (i.getValue() > j.getValue());
}
// this worked with a few test cases. I dont see any problems
void JobScheduler::compute()
{

	Job job;
	int due = 0;
	bool findPlace = true;
	_orderedJobs.resize(_jobs.size());
	_orderedByName.resize(_jobs.size());
	
	std::sort(_jobs.begin(), _jobs.end(), byValues);

	for each(job in _jobs)
	{
		findPlace = true;
		due = job.getDueDate() - 1;
		/*if (due > _jobs.size())
		{
			due = _jobs.size();
		}*/
		while (findPlace)
		{
			if (!_orderedByName[due].empty())
			{
				due--;
				if (due < 0)
				{
					//the job is not going to be done
					findPlace = false;
				}
			}
			else
			{
				//orderedByName is if we decide to output differently. It is also helps simplify a few things.
				_orderedJobs[due] = job;
				_orderedByName[due] = job.getName();
				findPlace = false;
			}
		}
	}
}

// this may or may not be working. it is untested
void JobScheduler::computeSlow()
{
	Job job("0",0,0);
	int value = 0;
	int place = 0;
	int maxvalue = 0;
	int due = 0;
	bool findPlace = true;
	_orderedJobs.resize(_jobs.size());
	for (int i = 0; i <= _jobs.size(); i++)
	{
		for (int j = 0; j < _jobs.size(); j++)
		{
			value = job.getValue();
			if (maxvalue < value)
			{
				maxvalue = value;
				place = j;
			}
		}
		due = _jobs[place].getDueDate();
		findPlace = true;
		while (findPlace)
		{
			if (_orderedJobs[due].getValue() != 0)
			{
				if (due < 0)
				{
					//the job is not going to be done
					findPlace = false;
				}
				due--;
			}
			else
			{
				_orderedJobs[due-1] = _jobs[place];
				_jobs[place] = job;
				findPlace = false;
			}
		}

	}
}

string JobScheduler::toString()
{
	return string();
}
vector<Job> JobScheduler::getJobs() const
{
	//return _jobs;
	return _orderedJobs;
}

#endif // !JOB_SCHEDULER_H


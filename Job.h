//Job.h
//Wyatt Emery
//Talon Marquard
//Project 3 - Job scheduling
//COSC 3020 Spring 2016
//3/21/16


#ifndef JOB_H
#define JOB_H

class Job
{
private:
	double value;
	int dueDate;
public:
	Job();
	Job(double value, int dueDate);
	int getDueDate() const;
	int getValue() const;
};

Job::Job()
{
}

Job::Job(double value, int dueDate)
{
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
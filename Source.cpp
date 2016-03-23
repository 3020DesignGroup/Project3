//Wyatt Emery
//Talon Marquard
//Project 3 - Job scheduling
//COSC 3020 Spring 2016
//3/21/16

#include"JobScheduler.h"
#include"RandomUtilities.h"
#include"winTimer.h"
#include"DisjointSet.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool getInput(JobScheduler& scheduler);

void randBuildScheduler(JobScheduler& scheduler, int size);

void fileBuildScheduler(JobScheduler& scheduler, ifstream& infile);

int main()
{
	while (false)
	{
		JobScheduler scheduler;
		int longestPath;
		bool going = getInput(scheduler);
		while (!going)
		{
			going = getInput(scheduler);
		}

		Timer timer;
		timer.start();
		scheduler.compute();
		timer.stop();

		cout << "\n the best order for jobs is : " << scheduler.toString() << "\nand was found in " << timer() << " seconds" << endl << endl;

	}

	return 0;
}

bool getInput(JobScheduler & scheduler)
{
	return false;
}

void randBuildScheduler(JobScheduler & scheduler, int size)
{
}

void fileBuildScheduler(JobScheduler & scheduler, ifstream & infile)
{
}


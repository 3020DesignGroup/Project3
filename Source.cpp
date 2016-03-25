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
	int size;
	string filename;
	ifstream infile;
	string option;
	randomizeSeed();

	//prompt for random or file entry.
	cout << "Enter r for random creation of Jobs. Enter f for input via external file: ";
	cin >> option;
	if (option == "r")
	{
		//prompt for size
		cout << "please enter desired size: ";
		cin >> size;

		randBuildScheduler(scheduler, size);
		return true;
	}

	// fill the graph by file input
	else if (option == "f")
	{
		//prompt for file
		cout << "enter filename: ";
		cin >> filename;

		//open file
		infile.open(filename);
		if (!(infile.is_open()))
		{
			cerr << "File not found!" << endl << endl;
			return false;
		}

		fileBuildScheduler(scheduler, infile);
		return true;
	}
	else
	{
		cerr << "unrecognized input. Please enter \"r\" or \"f\"" << endl << endl;
		return false;
	}
	return true;
}

}

void randBuildScheduler(JobScheduler & scheduler, int size)
{
}

void fileBuildScheduler(JobScheduler & scheduler, ifstream & infile)
{
}


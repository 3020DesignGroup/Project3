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
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

bool getInput(JobScheduler& scheduler);

void randBuildScheduler(JobScheduler & scheduler, int size, int minVal, int maxVal, int minDate, int maxDate);

void fileBuildScheduler(JobScheduler& scheduler, ifstream& infile);

void printJobs(JobScheduler& scheduler);

string intToString(int intConvert);

int main()
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

        //debug function
        printJobs(scheduler);

	return 0;
}

bool getInput(JobScheduler & scheduler)
{
	
	string filename;
	ifstream infile;
	string option;
	randomizeSeed();

	//prompt for random or file entry.
	cout << "Enter r for random creation of Jobs. Enter f for input via external file: ";
	cin >> option;
	if (option == "r")
	{
		//prompt for size and other desired values
        int size = 0;
        int minVal = 0;
        int maxVal = 0;
        int minDate = 0;
        int maxDate = 0;
		cout << "please enter desired size: ";
		cin >> size;
        cout << "enter min Job Value: ";
        cin >> minVal;
        cout << "enter max Job Value: ";
        cin >> maxVal;
        cout << "enter min Job Due Date: ";
        cin >> minDate;
        cout << "enter max Job Due Date";
        cin >> maxDate;

		randBuildScheduler(scheduler, size, minVal, maxVal, minDate, maxDate);
        cout << size << "Jobs were created" << endl;

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



void randBuildScheduler(JobScheduler & scheduler, int size, int minVal, int maxVal, int minDate, int maxDate)
{
    randomizeSeed();
    string name = "";
    int value = 0;
    int dueDate = 1;
    for (int i = 0; i < size; i++)
    {
        name = intToString(i + 1);
        value = randInt(minVal, maxVal);
        dueDate = randInt(minDate, maxDate);
        Job job(name, value, dueDate);
        scheduler.addJob(job);
    }
}

/*
    The syntax for the file goes as follows:
    #ofJobs
    jobName JobValue JobDueDate
    etc...
    E.G.
    3
    1 10 1
    2 20 2
    3 30 3
*/
void fileBuildScheduler(JobScheduler & scheduler, ifstream & infile)
{
    int size = 0;
    int value = 0;
    int dueDate = 1;
    string name = "";
    infile >> size;

    for (int i = 0; i < size; i++)
    {
        infile >> name;
        infile >> value;
        infile >> dueDate;
        Job job(name, value, dueDate);
        scheduler.addJob(job);
    }
}

void printJobs(JobScheduler& scheduler)
{
    vector<Job> jobs = scheduler.getJobs();
    cout << "Job Name\tValue\t\tDueDate" << endl;
    for (int i = 0; i < jobs.size(); i++)
    {
        cout << jobs[i].getName() << "\t\t" << jobs[i].getValue()  << "\t\t" << jobs[i].getDueDate() << endl;
    }
}

string intToString(int intConvert)
{
    std::ostringstream cstr;  //create the stream
    cstr << intConvert;  //put integer into the stream
    return cstr.str();  //put out the string
}
#pragma once


//Libraries
#include <vector>
#include <tuple>
#include <fstream>
#include <string>
#include <stdio.h>
//Files
#include "task.h"


//Operation class
struct Operation {
	int tasksAmount=0;
	int machinesAmount=0;
	std::vector<Task> Tasks;
	void getDataFromFile(const std::string fileName);
	void showOperation();
};

struct Result{
	Operation outcome;
	int result = _MAX_INT_DIG;;
	void Cmax(Operation data);
	void BruteForce(Operation data);
};
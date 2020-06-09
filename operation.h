#pragma once
//Libraries
#include <climits>
#include <vector>
#include <tuple>
#include <fstream>
#include <string>
#include <stdio.h>
#include <tuple>
#include <chrono>
#include <string>
//Files
#include "task.h"



//Operation class
struct Operation {
	int tasksAmount=0;
	int machinesAmount=0;
	std::vector<Task> Tasks;
	void getDataFromFile(const std::string fileName);
	void showOperation();
	std::tuple<int, int> findArgMin();
	void removeTask(int taskIndex);
};

struct Result{
	Operation outcome;
	//int result = _MAX_INT_DIG;
	int result = INT_MAX;
	void Cmax(Operation data);
	void BruteForce(Operation data);
	void Johnson(Operation data);
	void timeJohnson(Operation data);
	void timeBruteForce(Operation data);
	void timeCmax(Operation data);
	void timeNEH(Operation data, std::string filename);
	void NEH(Operation& data);
	void indexes();
};
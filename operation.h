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
	int tasksAmount;
	int machinesAmount;
	std::vector<Task> Tasks;
	void getDataFromFile(const std::string fileName);
	void showOperation();
};
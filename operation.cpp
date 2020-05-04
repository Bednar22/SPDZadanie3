#include "operation.h"


void Operation::getDataFromFile(const std::string fileName)
{
	int tmp;
	Task tmpTask;
	int machineCheck;
	std::ifstream file;
	file.open(fileName);
	file >> this->tasksAmount;
	file >> this->machinesAmount;

	for (int i = 0; i < this->tasksAmount; i++) {
		for (int j = 0; j < this->machinesAmount; j++) {
			file >> machineCheck;
			file >> tmp;
			tmpTask.tasks.push_back(tmp);
		}
		this->Tasks.push_back(tmpTask);
		tmpTask.tasks.clear();
	}

	file.close();
}


void Operation::showOperation() {
	for (int i = 0; i < this->tasksAmount; i++) {
		this->Tasks[i].showTask();
	}
}
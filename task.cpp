#include "task.h"


void Task::showTask() {
	for (int i = 0; i < this->tasks.size(); i++) {
		std::cout << " " <<this->tasks[i] << " ";
	}
	std::cout << std::endl;

}
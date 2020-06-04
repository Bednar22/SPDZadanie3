#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

struct Task {
	std::vector<int> tasks;
	int indeks;
	int alltasks = 0;
	void showTask();
	bool operator()(const Task& a, const Task& b) const;
};
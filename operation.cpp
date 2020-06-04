#include "operation.h"

void Result::timeJohnson(Operation data){
	auto start = std::chrono::high_resolution_clock::now();
	Result tmp;
	tmp.Johnson(data);
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	std::cout << "Czas Johnson:" << duration.count() << std::endl;
	
}

void Result::timeCmax(Operation data){
	auto start = std::chrono::high_resolution_clock::now();
	Result tmp;
	tmp.Cmax(data);
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	std::cout << "Czas Cmax:" << duration.count() << std::endl;
	
}

void Result::timeBruteForce(Operation data){
	auto start = std::chrono::high_resolution_clock::now();
	Result tmp;
	tmp.BruteForce(data);
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	std::cout << "Czas Brute Force:" << duration.count() << std::endl;
	
}


void Operation::getDataFromFile(const std::string fileName)
{
	int tmp;
	Task tmpTask;
	int machineCheck;
	std::ifstream file;
	file.open(fileName);
	if (!file)
	{
		std::cerr << "Brak pliku";
		exit(1);
	}
	file >> this->tasksAmount;
	file >> this->machinesAmount;

	for (int i = 0; i < this->tasksAmount; i++) {
		for (int j = 0; j < this->machinesAmount; j++) {
			file >> machineCheck;
			file >> tmp;
			tmpTask.tasks.push_back(tmp);
			tmpTask.alltasks += tmp;
		}
		tmpTask.indeks = i;
		this->Tasks.push_back(tmpTask);
		tmpTask.tasks.clear();
		tmpTask.alltasks = 0;
		
	}

	file.close();
}


void Operation::showOperation() {
	for (int i = 0; i < this->Tasks.size(); i++) {
		this->Tasks[i].showTask();
	}
}

// seraches for Task with minimum value
std::tuple<int, int> Operation::findArgMin(){
	int minVal = 1000000;
	int minI, minJ;
	for(int i=0; i<tasksAmount; i++){
		for(int j=0; j<machinesAmount; j++){
			if(Tasks[i].tasks[j] < minVal){
				minVal= Tasks[i].tasks[j];
				minI=i;
				minJ=j;
			}
		}
	}
	return std::make_tuple(minI,minJ);
}

void Operation::removeTask(int taskIndex){
	Tasks.erase(Tasks.begin() + taskIndex );
	tasksAmount = tasksAmount -1;
}


void Result::Cmax(Operation data)
{
	int **S = new int *[data.tasksAmount];
	int **C = new int *[data.tasksAmount];
	for (int i = 0; i < data.tasksAmount; ++i) {
		S[i] = new int[data.machinesAmount];
		C[i] = new int[data.machinesAmount];
	}

	C[0][0] = data.Tasks[0].tasks[0];

	for (int i = 0; i<data.tasksAmount; i++)
		for (int j = 0; j < data.machinesAmount; j++)
		{
			if (i == 0 && j == 0)
				S[0][0] = 0;
			else if (i == 0)
				S[i][j] = C[i][j - 1];
			else if (j == 0)
				S[i][j] = C[i - 1][j];
			else
				S[i][j] = std::max(C[i - 1][j], C[i][j - 1]);
			C[i][j] = S[i][j] + data.Tasks[i].tasks[j];

		}


	result = C[data.tasksAmount-1][data.machinesAmount-1];

	for (int i = 0; i < data.tasksAmount; i++)
	{
		delete[] S[i];
		delete[] C[i];
	}
	delete[] S;
	delete[] C;
}
/*
void Result::Cmax(Operation data)
{
	int** S = new int* [data.machinesAmount];
	int** C = new int* [data.machinesAmount];
	for (int i = 0; i < data.machinesAmount; ++i) {
		S[i] = new int[data.tasksAmount];
		C[i] = new int[data.tasksAmount];
	}

	C[0][0] = data.Tasks[0].tasks[0];

	for (int i = 0; i < data.machinesAmount; i++)
		for (int j = 0; j < data.tasksAmount; j++)
		{
			if (i == 0 && j == 0)
				S[0][0] = 0;
			else if (i == 0)
				S[i][j] = C[i][j - 1];
			else if (j == 0)
				S[i][j] = C[i - 1][j];
			else
				S[i][j] = std::max(C[i - 1][j], C[i][j - 1]);
			C[i][j] = S[i][j] + data.Tasks[i].tasks[j];

		}


	result = C[data.machinesAmount - 1][data.tasksAmount - 1];

	for (int i = 0; i < data.machinesAmount; i++)
	{
		delete[] S[i];
		delete[] C[i];
	}
	delete[] S;
	delete[] C;
}
*/
void Result::BruteForce(Operation data)
{
	Operation kopia = data;
	Result tmp;

	do
	{
		tmp.Cmax(kopia);
		if (tmp.result < this->result)
		{
			this->result = tmp.result;
			this->outcome = kopia;
		}
	} while (std::next_permutation(kopia.Tasks.begin(), kopia.Tasks.end(),
		[](const auto& lhs, const auto& rhs)
		{ return lhs.indeks < rhs.indeks; }));
}

void Result::Johnson(Operation data){
	int i_star, j_star;
	int l = 0;
	int k = data.tasksAmount - 1;
	Operation tmp=data;

	while(data.Tasks.empty()==false){
		
		std::tie(i_star, j_star) = data.findArgMin();
		if(data.Tasks[i_star].tasks[0]<data.Tasks[i_star].tasks[1]){
			tmp.Tasks[l]=data.Tasks[i_star];
			l=l+1;
		} else {
			tmp.Tasks[k] = data.Tasks[i_star];
			k=k-1;
		}
	data.removeTask(i_star);
	}	
	Cmax(tmp);
	std::cout << "Johnson algorytm CMAX: " << result << std::endl;
}

/*
void Result::NEH(Operation& data)
{
	Result tmpresult;

	Operation tmp1, tmp2;
	tmp1 = data;// tmp2.Tasks.resize(tmp1.machinesAmount);
	Task tmptask1,tmptask2;

	sort(tmp1.Tasks.rbegin(), tmp1.Tasks.rend(), Task());


	tmptask1 = tmp1.Tasks[0];
	tmp2.Tasks.push_back(tmptask1);
	tmp2.tasksAmount++;
	tmp2.machinesAmount = tmptask1.tasks.size();
	for (int k = 1; k < tmp1.tasksAmount; k++)
	{
		tmptask1 = tmp1.Tasks[k];
		tmp2.Tasks.push_back(tmptask1);
		tmp2.tasksAmount++;
		tmpresult.outcome = tmp2;
		this->Cmax(tmp2);
		for (int i = 0; i < k; i++)
		{
			std::rotate(tmp2.Tasks.begin()+i, tmp2.Tasks.begin()+tmp2.Tasks.size(), tmp2.Tasks.end());
			tmpresult.Cmax(tmp2);
				if (tmpresult.result <= this->result)
				{
					this->result = tmpresult.result;
					this->outcome = tmp2;
				}

		}
		tmp2 = this->outcome;
	}
}
*/

void Result::NEH(Operation& data)
{
	Result tmpresult;

	Operation tmp1, tmp2;
	tmp1 = data;// tmp2.Tasks.resize(tmp1.machinesAmount);
	Task tmptask1, tmptask2;

	sort(tmp1.Tasks.rbegin(), tmp1.Tasks.rend(), Task());

	tmptask1 = tmp1.Tasks[0];
	tmp2.Tasks.push_back(tmptask1);
	tmp2.tasksAmount++;
	tmp2.machinesAmount = tmptask1.tasks.size();

	for (int k = 1; k < tmp1.tasksAmount; k++)
	{
		tmptask1 = tmp1.Tasks[k];
		tmp2.Tasks.push_back(tmptask1);
		tmp2.tasksAmount++;
		//tmpresult.outcome = tmp2;
		this->Cmax(tmp2);
		this->outcome = tmp2;

		for (int i = k; i > 0; i--)
		{
			std::swap(tmp2.Tasks[i], tmp2.Tasks[i-1]);
			tmpresult.Cmax(tmp2);
			if (tmpresult.result <= this->result)
			{
				this->result = tmpresult.result;
				this->outcome = tmp2;
			}
			//tmp2 = tmpresult.outcome;
		}
		tmp2 = this->outcome;
	}
}
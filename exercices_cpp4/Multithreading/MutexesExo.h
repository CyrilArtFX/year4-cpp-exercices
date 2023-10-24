#pragma once

#include <IExercice.h>
#include <vector>

class MutexesExo : public IExercice
{
public:
	MutexesExo() {}
	~MutexesExo() {}

	void Execute() override;

private:
	int sumTableSequential(std::vector<int> table);
	void sumTableThreadedLocal(std::vector<int> dividedSum, std::vector<int>& returnSum);
	void sumTableThreadedGlobal(std::vector<int> dividedSum, int& returnSum);

	void naiveEvenNumbers();
	void naiveOddNumbers();
	void mutexEvenNumbers();
	void mutexOddNumbers();
};


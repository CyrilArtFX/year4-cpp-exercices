#pragma once
#include <IExercice.h>

class ParallelismExo : public IExercice
{
public:
	ParallelismExo() {}
	~ParallelismExo() {}

	void Execute() override;

private:
	void helloWorld();
	void goodbyeWorld();
};


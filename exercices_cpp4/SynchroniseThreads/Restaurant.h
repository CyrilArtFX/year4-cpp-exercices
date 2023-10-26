#pragma once
#include <IExercice.h>

class Restaurant : public IExercice
{
public:
	Restaurant() {}
	~Restaurant() {}

	void Execute() override;

private:

};


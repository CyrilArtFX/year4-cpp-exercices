#pragma once
#include <IExercice.h>

class TravelerTestOOP : public IExercice
{
public:
	TravelerTestOOP() {}
	~TravelerTestOOP() {}

	void Execute() override;
};


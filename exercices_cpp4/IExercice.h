#pragma once

class IExercice
{
public:
	virtual ~IExercice() {}

	virtual void Execute() = 0;
};
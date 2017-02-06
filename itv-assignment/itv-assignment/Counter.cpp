#include "stdafx.h"
#include "Counter.h"


Counter::Counter() : mCount(0)
{
}

Counter::~Counter()
{
}

void Counter::incrementCount(int increment)
{
	std::lock_guard<std::mutex> guard(mCounterMutex); //protect mCount from races
	mCount += increment;
}

int Counter::getCount()
{
	return mCount;
}

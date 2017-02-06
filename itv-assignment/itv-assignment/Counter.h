#pragma once

#include <mutex>

class Counter
{
public:
	
	Counter();
	~Counter();

	int getCount();
	void incrementCount(int increment);
	
private:

	int mCount;
	std::mutex mCounterMutex;
};


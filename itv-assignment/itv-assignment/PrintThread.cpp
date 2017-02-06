
#include "stdafx.h"
#include "PrintThread.h"

#include <mutex>

std::mutex PrintThread::_mutexPrint{};

PrintThread::~PrintThread()
{
	std::lock_guard<std::mutex> guard(_mutexPrint);
	std::cout << this->str();
}

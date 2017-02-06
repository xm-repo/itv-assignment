#pragma once

#include "Counter.h"
#include "FilesQueue.h"

#include <string>
#include <vector>

class WordCounter
{
public:
	
	WordCounter(FilesQueue & const filesQueue, Counter & const counter);
	~WordCounter();

	void CountWords();

private:

	Counter & const mCounter;
	FilesQueue & const mFilesQueue;
	
	int CountWordsInFile(const std::string &file);
};


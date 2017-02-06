
#include "stdafx.h"
#include "constants.h"

#include "WordCounter.h"
#include "PrintThread.h"

#include <string>
#include <thread>
#include <iostream>
#include <fstream>
#include <iterator> 
#include <algorithm>

WordCounter::WordCounter(FilesQueue & const filesQueue, Counter & const counter)
	: mFilesQueue(filesQueue), mCounter(counter)
{
}

WordCounter::~WordCounter() 
{
}

int WordCounter::CountWordsInFile(const std::string &file) 
{
	std::ifstream inFile(file);

	std::istream_iterator<std::string> begin(inFile), end;
	int wordsCount = std::distance(begin, end);

	return wordsCount;
}

void WordCounter::CountWords() {

	std::string file;

	while (mFilesQueue.getFile(file)) {
		int wordsCount = CountWordsInFile(file);
		mCounter.incrementCount(wordsCount);
#if DEBUG
		PrintThread{} << "[" << std::this_thread::get_id() << "] "
			<< file << " " << wordsCount << std::endl;
#endif
	}
}

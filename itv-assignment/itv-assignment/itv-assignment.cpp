// itv-assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "constants.h"

#include "FilesQueue.h"
#include "WordCounter.h"

#include <windows.h>
#include <vector>
#include <string> 
#include <iostream>
#include <thread>

int main(int argc, char** argv)
{

	if (argc < 2) {
		return 0;
	} 

	std::string directory = argv[1];
	FilesQueue filesQueue(directory);

	Counter counter;

	std::vector<std::thread> wordCounters;
	wordCounters.reserve(THREADS_COUNT);
	
	for (int i = 0; i < THREADS_COUNT; ++i) {
		std::thread wordCounterThread(&WordCounter::CountWords, WordCounter(filesQueue, counter));
		wordCounters.push_back(std::move(wordCounterThread));
	}

	for (int i = 0; i < THREADS_COUNT; ++i) {
		wordCounters[i].join();
	}

	std::cout << "word count: " << counter.getCount() << std::endl;

	return 0;
}


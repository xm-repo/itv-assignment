#pragma once

#include <string>
#include <queue>
#include <mutex>

class FilesQueue
{
public:

	FilesQueue(const std::string & directory);
	~FilesQueue();

	bool getFile(std::string &file);

private:

	std::mutex mFilesQueueMutex;
	std::queue<std::string> mFilesQueue;

	void FindFilesInDirectory(const std::string &directory);
};


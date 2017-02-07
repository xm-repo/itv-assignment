
#include "stdafx.h"
#include "constants.h"

#include "FilesQueue.h"

#include <iostream>
#include <windows.h>

FilesQueue::FilesQueue(const std::string & directory)
{
	FindFilesInDirectory(directory);
}

FilesQueue::~FilesQueue()
{
}

bool FilesQueue::getFile(std::string & file)
{
	std::lock_guard<std::mutex> guard(mFilesQueueMutex); //protect mFilesQueue from races

	if(!mFilesQueue.empty()) {
		file = mFilesQueue.front(); //?
		mFilesQueue.pop();
		return true;
	}

	return false;
}

void FilesQueue::FindFilesInDirectory(const std::string & directory)
{
	HANDLE hFind;
	WIN32_FIND_DATAA file_data;

	hFind = FindFirstFileA((directory + "/*").c_str(), &file_data);
	if (hFind == INVALID_HANDLE_VALUE) {
		return; /* No files found */
	}

	do {

		const std::string file_name = file_data.cFileName;
		const std::string full_file_name = directory + "\\" + file_name;

		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
		if (!is_directory) {
			mFilesQueue.push(full_file_name); //?
#if DEBUG
			std::cout << full_file_name << std::endl;
#endif
		}

	} while (FindNextFileA(hFind, &file_data) != 0);

	FindClose(hFind);
}

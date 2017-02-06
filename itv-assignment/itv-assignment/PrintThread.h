#pragma once

#include <sstream>
#include <iostream>
#include <mutex>

/** Thread safe cout class
* Exemple of use:
*    PrintThread{} << "Hello world!" << std::endl;
*/

class PrintThread : public std::ostringstream
{
public:

	PrintThread() = default;
	~PrintThread();

private:

	static std::mutex _mutexPrint;
};

#ifndef EXTERNAL_COMMAND_H
#define EXTERNAL_COMMAND_H

#include <mutex>
#include <ctime>


class ExternalCommand {
public:
	ExternalCommand(time_t timestamp, bool autorun, int rudderCommand, int sailCommand);
	~ExternalCommand() {};

	bool setData(time_t timestamp, bool autorun, int rudderCommand, int sailCommand);
	
	bool getAutorun();
	int getRudderCommand();
	int getSailCommand();

private:
	std::mutex mtx; // mutex for critical section

	time_t m_timestamp;
	bool m_autorun;
	int m_rudderCommand;
	int m_sailCommand;
};

#endif

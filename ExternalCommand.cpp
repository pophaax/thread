#include "ExternalCommand.h"


ExternalCommand::ExternalCommand(time_t timestamp, bool autorun, int rudderCommand, int sailCommand) {
  m_timestamp = timestamp;
  m_autorun = autorun;
  m_rudderCommand = rudderCommand;
  m_sailCommand = sailCommand;
}

bool ExternalCommand::setData(time_t timestamp, bool autorun, int rudderCommand, int sailCommand) {
  // critical section (exclusive access by locking mtx):
  bool isNewData = false;
  mtx.lock();
  if(m_timestamp < timestamp) {
      m_timestamp = timestamp;
      m_autorun = autorun;
      m_rudderCommand = rudderCommand;
      m_sailCommand = sailCommand;
      isNewData = true;
  }
  mtx.unlock();
  return isNewData;
}

bool ExternalCommand::getAutorun() {
  // critical section (exclusive access by locking mtx):
  mtx.lock();
  bool get = m_autorun;
  mtx.unlock();

  return get;
}

int ExternalCommand::getRudderCommand() {
  // critical section (exclusive access by locking mtx):
  mtx.lock();
  int get = m_rudderCommand;
  mtx.unlock();

  return get;
}

int ExternalCommand::getSailCommand() {
  // critical section (exclusive access by locking mtx):
  mtx.lock();
  int get = m_sailCommand;
  mtx.unlock();

  return get;
}
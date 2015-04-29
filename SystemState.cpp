#include "SystemState.h"

void SystemState::setData(SystemStateModel model)
{
	m_mutex.lock();
	m_model = model;
	m_mutex.unlock();
}

void SystemState::getData(SystemStateModel *model)
{
	m_mutex.lock();
	*model = m_model;
	m_mutex.unlock();
}
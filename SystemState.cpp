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

void SystemState::setGPSModel(GPSModel gpsModel)
{
	m_mutex.lock();
	m_model.gpsModel = gpsModel;
	m_mutex.unlock();
}

void SystemState::setWindsensorModel(WindsensorModel windsensorModel)
{
	m_mutex.lock();
	m_model.windsensorModel = windsensorModel;
	m_mutex.unlock();
}

void SystemState::setCompassModel(CompassModel compassModel)
{
	m_mutex.lock();
	m_model.compassModel = compassModel;
	m_mutex.unlock();
}
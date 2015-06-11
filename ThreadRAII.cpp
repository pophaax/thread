#include "ThreadRAII.h"



	
ThreadRAII::ThreadRAII(std::thread&& t, DtorAction a)
: action(a), t(std::move(t)){}

ThreadRAII::~ThreadRAII()
{
	if(t.joinable()){
		if(action == DtorAction::join){
			m_t.join();
		}
		else{
			m_t.detach();
		}
	}
}

std::thread& ThreadRAII::get() 
{ 
	return m_t; 
}




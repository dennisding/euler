#include "engine.hpp"

#include <utils/thread_mgr.hpp>

void engine::init()
{
	thread_mgr::instance().init();
}

void engine::tick(float delta)
{

}

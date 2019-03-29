#include "thread_mgr.hpp"

struct io {};
struct logic {};

void thread_mgr::init()
{
	// create 2 io thread
	add_worker<thread::io>();
	add_worker<thread::io>();
}


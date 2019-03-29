#pragma once

#include <utils/singleton.hpp>

class engine : public singleton<engine>
{
public:
	void init();
	void tick(float delta = 0);
};

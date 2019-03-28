#pragma once

#include <utils/singleton.hpp>

#include <iostream>

class res_mgr : public singleton<res_mgr>
{
public:

	void test()
	{
		std::cout << "hello world!!!!!!!!" << std::endl;
	}

};

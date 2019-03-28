#include <cstdio>

#include <res_mgr/res_mgr.hpp>

int main(int argc, const char **argv)
{
	res_mgr::instance().test();
	printf("hello world!\n");
}

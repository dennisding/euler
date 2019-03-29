#include <iostream>

#include <engine/engine.hpp>

#include <GLFW/glfw3.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

static void tick()
{
	engine::instance().tick(0.f);
}

#endif


int main(int argc, const char **argv)
{
	engine::instance().init();

#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(tick, 60, 1);
#endif
}



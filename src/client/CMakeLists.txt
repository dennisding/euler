
add_executable(client client.cpp)

set_target_properties(client PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s USE_WEBGL2=1 -s FULL_ES3=1")



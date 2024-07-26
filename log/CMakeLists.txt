
file(GLOB LOG_SRC_FILES "src/*.cpp")

add_library(LOG_LIB SHARED ${LOG_SRC_FILES})
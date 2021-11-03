set(TARGET web_api)
file(GLOB_RECURSE SRC_CPP ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_executable(${TARGET} ${SRC_CPP})
set(CMAKE_EXECUTABLE_SUFFIX ".js")

# libutil.a is located in "./cpp/lib"
# libdemo.a is built with cpp files in "./cpp/src"
target_link_libraries(${TARGET}
  PRIVATE
    util
    demo
)

# Set target options
# "./cpp/lib" has cpp libraries
target_link_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/cpp/lib)
target_include_directories(${TARGET} PRIVATE (${CMAKE_SOURCE_DIR}/cpp/lib))
# add "--no-entry" because web_api.cpp doesn't have main function
target_link_options(${TARGET} PRIVATE "--no-entry")

set(WEB_OUTUPT_DIR ${CMAKE_BINARY_DIR}/html)
file(MAKE_DIRECTORY ${WEB_OUTUPT_DIR})
set_target_properties(${TARGET} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${WEB_OUTUPT_DIR}
)

# Copy js and html files to output folder
add_custom_command(
  TARGET ${TARGET} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/index.html ${WEB_OUTUPT_DIR}
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/html ${WEB_OUTUPT_DIR}/html
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/js ${WEB_OUTUPT_DIR}/js
)


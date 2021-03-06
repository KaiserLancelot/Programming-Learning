if(CPP_FORMAT)
  message(STATUS "Format code using clang-format and cmake-format")

  find_program(CLANG_FORMAT_EXECUTABLE clang-format)
  find_program(CMAKE_FORMAT_EXECUTABLE cmake-format)

  if(NOT CLANG_FORMAT_EXECUTABLE)
    message(FATAL_ERROR "Can not find clang-format")
  endif()

  if(NOT CMAKE_FORMAT_EXECUTABLE)
    message(FATAL_ERROR "Can not find cmake-format")
  endif()

  file(
    GLOB_RECURSE
    CLANG_FORMAT_SRC
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/cpp_primer/*.h"
    "${CMAKE_SOURCE_DIR}/cpp_primer/*.cpp"
    "${CMAKE_SOURCE_DIR}/library/*.h"
    "${CMAKE_SOURCE_DIR}/library/*.cpp"
    "${CMAKE_SOURCE_DIR}/new_features/*.h"
    "${CMAKE_SOURCE_DIR}/new_features/*.cpp"
    "${CMAKE_SOURCE_DIR}/notes/*.h"
    "${CMAKE_SOURCE_DIR}/notes/*.cpp")

  file(
    GLOB_RECURSE
    CMAKE_FORMAT_SRC
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/CMakeLists.txt"
    "${CMAKE_SOURCE_DIR}/cmake/*.cmake"
    "${CMAKE_SOURCE_DIR}/cpp_primer/CMakeLists.txt"
    "${CMAKE_SOURCE_DIR}/library/CMakeLists.txt"
    "${CMAKE_SOURCE_DIR}/new_features/CMakeLists.txt"
    "${CMAKE_SOURCE_DIR}/notes/CMakeLists.txt")

  add_custom_target(
    code_format
    COMMAND ${CLANG_FORMAT_EXECUTABLE} -i ${CLANG_FORMAT_SRC}
    COMMAND ${CMAKE_FORMAT_EXECUTABLE} -i ${CMAKE_FORMAT_SRC}
    COMMENT "Start formatting code")
endif()

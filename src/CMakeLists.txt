add_subdirectory(expr)
add_subdirectory(IO)
add_subdirectory(graphics)
add_subdirectory(solver)

set(TEST_SRC tests/eval_test.cpp)

add_executable(${PROJECT_NAME} ${TEST_SRC} main.cpp)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_link_libraries(
    ${PROJECT_NAME} 
      PRIVATE 
      stdc++exp
  )
endif()

target_link_libraries(
  ${PROJECT_NAME} 
  PRIVATE 
  Expr
  Graphics
  Solver
  IO
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${INCLUDE_DIR}
)

target_compile_definitions(
  ${PROJECT_NAME}
  PRIVATE
  SHADER_PATH="${CMAKE_SOURCE_DIR}/shader"
)
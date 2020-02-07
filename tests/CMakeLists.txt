file(GLOB TESTS "*.cpp")	

set(test_files ${TESTS})
set(TARGET_NAME chops_tests)	

message("Building tests...")

add_executable(${TARGET_NAME} ${test_files})
target_link_libraries(${TARGET_NAME} PRIVATE chops)
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
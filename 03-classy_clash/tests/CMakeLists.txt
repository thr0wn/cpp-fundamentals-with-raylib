set(TEST_MAIN "unit-tests")
set(TEST_SOURCES
 "main.cc"
)

add_executable(${TEST_MAIN} ${TEST_SOURCES})
target_link_libraries(${TEST_MAIN} PUBLIC ${LIBRARY_NAME} Catch2::Catch2WithMain)

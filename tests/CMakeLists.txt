set(TESTS
    arena
    strings 
)

foreach(test IN LISTS TESTS)
    add_executable(test_${test} test_${test}.c)
    target_link_libraries(test_${test} PRIVATE tyrlib)
    add_test(NAME ${test} COMMAND test_${test})
endforeach()

add_executable(test_arena
    test_arena.c
)

target_link_libraries(test_arena PRIVATE tyrlib)

add_test(
    NAME arena
    COMMAND test_arena
)

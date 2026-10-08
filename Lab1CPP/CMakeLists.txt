add_executable(Lab1CPP_task1 task1.cpp)
target_include_directories(Lab1CPP_task1 PUBLIC ../LibraryCPP)
target_link_libraries(Lab1CPP_task1 LibraryCPP)

add_executable(Lab1CPP_task2 task2.cpp)
target_include_directories(Lab1CPP_task2 PUBLIC ../LibraryCPP)
target_link_libraries(Lab1CPP_task2 LibraryCPP)

add_test(NAME Task1_Test COMMAND Lab1CPP_task1 ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)
set_property(TEST Task1_Test PROPERTY PASS_REGULAR_EXPRESSION "positive: 9, negative: 0, zero: 1\\.")

add_test(NAME Task2_Test COMMAND Lab1CPP_task2 ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)
set_property(TEST Task2_Test PROPERTY PASS_REGULAR_EXPRESSION "unique: 1 2 3 4 5 6 7 8 9 0\\.")
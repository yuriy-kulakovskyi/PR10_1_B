add_test([=[CountTest.HandleCount]=]  [==[/Users/yura_kulakovskyi/Documents/C++/AP/PR10/PR10_1_B/cmake-build-debug/PR10_1_tests]==] [==[--gtest_filter=CountTest.HandleCount]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CountTest.HandleCount]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/yura_kulakovskyi/Documents/C++/AP/PR10/PR10_1_B/cmake-build-debug]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  PR10_1_tests_TESTS CountTest.HandleCount)

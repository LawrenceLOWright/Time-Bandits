add_test([=[HelloTest.BasicAssertions]=]  [==[C:/Users/gasca681/Documents/TB13/Time-Bandits/out/build/x64-debug/Time Bandits/hello_test.exe]==] [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY [==[C:/Users/gasca681/Documents/TB13/Time-Bandits/out/build/x64-debug/Time Bandits]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hello_test_TESTS HelloTest.BasicAssertions)

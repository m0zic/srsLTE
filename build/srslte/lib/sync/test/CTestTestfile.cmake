# CMake generated Testfile for 
# Source directory: /home/orange/srslte_m/srslte/lib/sync/test
# Build directory: /home/orange/srslte_m/build/srslte/lib/sync/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(sync_test_100 "sync_test" "-o" "100" "-p" "50" "-c" "501")
ADD_TEST(sync_test_400 "sync_test" "-o" "400" "-p" "50" "-c" "500")
ADD_TEST(sync_test_100_e "sync_test" "-o" "100" "-e" "-p" "50" "-c" "133")
ADD_TEST(sync_test_400_e "sync_test" "-o" "400" "-e" "-p" "50" "-c" "123")
ADD_TEST(cfo_test_1 "cfo_test" "-f" "0.12345" "-n" "1000")
ADD_TEST(cfo_test_2 "cfo_test" "-f" "0.99849" "-n" "1000")

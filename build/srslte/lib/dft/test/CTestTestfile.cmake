# CMake generated Testfile for 
# Source directory: /home/orange/srslte_m/srslte/lib/dft/test
# Build directory: /home/orange/srslte_m/build/srslte/lib/dft/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(ofdm_normal "ofdm_test")
ADD_TEST(ofdm_extended "ofdm_test" "-e")
ADD_TEST(ofdm_normal_single "ofdm_test" "-n" "6")
ADD_TEST(ofdm_extended_single "ofdm_test" "-e" "-n" "6")

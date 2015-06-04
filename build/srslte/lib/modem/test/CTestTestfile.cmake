# CMake generated Testfile for 
# Source directory: /home/orange/srslte_m/srslte/lib/modem/test
# Build directory: /home/orange/srslte_m/build/srslte/lib/modem/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(modem_bpsk "modem_test" "-n" "1020" "-m" "1")
ADD_TEST(modem_qpsk "modem_test" "-n" "1020" "-m" "2")
ADD_TEST(modem_qam16 "modem_test" "-n" "1020" "-m" "4")
ADD_TEST(modem_qam64 "modem_test" "-n" "1020" "-m" "6")
ADD_TEST(modem_bpsk_soft "modem_test" "-n" "1020" "-m" "1" "-s")
ADD_TEST(modem_qpsk_soft "modem_test" "-n" "1020" "-m" "2" "-s")
ADD_TEST(modem_qam16_soft "modem_test" "-n" "1020" "-m" "4" "-s")
ADD_TEST(modem_qam64_soft "modem_test" "-n" "1020" "-m" "6" "-s")
ADD_TEST(modem_bpsk_soft_approx "soft_demod_test" "-n" "1020" "-m" "1")
ADD_TEST(modem_qpsk_soft_approx "soft_demod_test" "-n" "1020" "-m" "2")
ADD_TEST(modem_qam16_soft_approx "soft_demod_test" "-n" "1020" "-m" "4")
ADD_TEST(modem_qam64_soft_approx "soft_demod_test" "-n" "1020" "-m" "6")

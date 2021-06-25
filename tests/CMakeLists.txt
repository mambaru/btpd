# Проверка конфигов для сервера btp

wci_test(
  NAME test-btp-conf
  COMMAND btpd --check-config=btp.conf
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  NO_MEMCHECK
)



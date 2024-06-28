# Проверка конфигов для сервера btp

wci_test(
  NAME btp-front.conf
  COMMAND btpd --check-config=./configurations/wwwnew/btp-front.conf
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  NO_MEMCHECK
)


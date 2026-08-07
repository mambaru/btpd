# Проверка конфигов для сервера btp

wci_test(
  NAME wwwnew
  COMMAND btpd --check-config=./configurations/wwwnew/btp-front.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-front
  COMMAND btpd --check-config=./configurations/btp-front/btp-front.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag
  COMMAND btpd --check-config=./configurations/btp-ag/btp-ag.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-hub
  COMMAND btpd --check-config=./configurations/btp-hub/btp-hub.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

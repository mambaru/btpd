# Проверка конфигов для сервера btp

wci_test(
  NAME btp-ag5s-1
  COMMAND btpd --check-config=configurations/btp/ag5s-1/ag5s-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag5s-2
  COMMAND btpd --check-config=configurations/btp/ag5s-2/ag5s-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag1m-1
  COMMAND btpd --check-config=configurations/btp/ag1m-1/ag1m-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag1m-2
  COMMAND btpd --check-config=configurations/btp/ag1m-2/ag1m-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag7m-1
  COMMAND btpd --check-config=configurations/btp/ag7m-1/ag7m-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag7m-2
  COMMAND btpd --check-config=configurations/btp/ag7m-2/ag7m-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag1h-1
  COMMAND btpd --check-config=configurations/btp/ag1h-1/ag1h-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag1h-2
  COMMAND btpd --check-config=configurations/btp/ag1h-2/ag1h-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag1d-1
  COMMAND btpd --check-config=configurations/btp/ag1d-1/ag1d-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-ag1d-2
  COMMAND btpd --check-config=configurations/btp/ag1d-2/ag1d-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-rt-hub-1
  COMMAND btpd --check-config=configurations/btp/rt-hub-1/rt-hub-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-rt-hub-2
  COMMAND btpd --check-config=configurations/btp/rt-hub-2/rt-hub-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

# Проверка конфигов для сервера cdaemon14

wci_test(
  NAME cdaemon14-rt-1
  COMMAND btpd --check-config=configurations/cdaemon14/rt-1/rt-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME cdaemon14-rt-2
  COMMAND btpd --check-config=configurations/cdaemon14/rt-2/rt-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

# Проверка конфигов для сервера btp-backup

wci_test(
  NAME btp-backup-ag5s-1
  COMMAND btpd --check-config=configurations/btp-backup/ag5s-1/ag5s-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag5s-2
  COMMAND btpd --check-config=configurations/btp-backup/ag5s-2/ag5s-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag1m-1
  COMMAND btpd --check-config=configurations/btp-backup/ag1m-1/ag1m-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag1m-2
  COMMAND btpd --check-config=configurations/btp-backup/ag1m-2/ag1m-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag7m-1
  COMMAND btpd --check-config=configurations/btp-backup/ag7m-1/ag7m-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag7m-2
  COMMAND btpd --check-config=configurations/btp-backup/ag7m-2/ag7m-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag1h-1
  COMMAND btpd --check-config=configurations/btp-backup/ag1h-1/ag1h-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag1h-2
  COMMAND btpd --check-config=configurations/btp-backup/ag1h-2/ag1h-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag1d-1
  COMMAND btpd --check-config=configurations/btp-backup/ag1d-1/ag1d-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-ag1d-2
  COMMAND btpd --check-config=configurations/btp-backup/ag1d-2/ag1d-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-rt-hub-1
  COMMAND btpd --check-config=configurations/btp-backup/rt-hub-1/rt-hub-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-backup-rt-hub-2
  COMMAND btpd --check-config=configurations/btp-backup/rt-hub-2/rt-hub-2.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)


# Проверка конфигов для сервера btp-client

wci_test(
  NAME btp-client-ag5s-1
  COMMAND btpd --check-config=configurations/btp-client/ag5s-1/ag5s-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-client-ag1m-1
  COMMAND btpd --check-config=configurations/btp-client/ag1m-1/ag1m-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-client-ag7m-1
  COMMAND btpd --check-config=configurations/btp-client/ag7m-1/ag7m-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-client-ag1h-1
  COMMAND btpd --check-config=configurations/btp-client/ag1h-1/ag1h-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-client-ag1d-1
  COMMAND btpd --check-config=configurations/btp-client/ag1d-1/ag1d-1.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

# Проверка конфигов для сервера btp-mamba-stat3

wci_test(
  NAME btp-mamba-stat3-rt-hub
  COMMAND btpd --check-config=configurations/btp-mamba-stat3/rt-hub/rt-hub.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-mamba-stat3-ag1h
  COMMAND btpd --check-config=configurations/btp-mamba-stat3/ag1h/ag1h.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

wci_test(
  NAME btp-mamba-stat3-ag1d
  COMMAND btpd --check-config=configurations/btp-mamba-stat3/ag1d/ag1d.conf
  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
  NO_MEMCHECK
)

# Проверка конфигов для сервера btp-mamba-stat3

#message(WARNING "Тесты для btp-mamba-stat3 (rr) отключены, нужно обновление базы с перекачкой")
#wci_test(
#  NAME btp-mamba-rr-rt
#  COMMAND btpd --check-config=configurations/btp-mamba-rr/rt/rt.conf
#  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
#  NO_MEMCHECK
#)

#wci_test(
#  NAME btp-mamba-rr-ag1d
#  COMMAND btpd --check-config=configurations/btp-mamba-rr/ag1d/ag1d.conf
#  WORKING_DIRECTORY ${btpd_SOURCE_DIR}
#  NO_MEMCHECK
#)

Сборка и запуск
======

Требования для сборки:
* g++ или clang++ (с поддержкой 17 стандарта)
* cmake (3.13)
* git

```sh
sudo apt install g++ cmake git
git clone https://github.com/mambaru/btpd.git
cd btpd
make release
./build/bin/btpd -V examples/simple/btp.conf
```

Последняя команда запускает проверку конфигурации на валидность. В случае ошибки выведет конфиг с пометкой ">>>" места ошибки.
Примеры запуска:

```sh
# Простой запуск с выводом цветного лога на экран, выход по ^C
./build/bin/btpd -C examples/simple/btp.conf

# Запуск в режиме демона
./build/bin/btpd -d -C examples/simple/btp.conf

# В режиме демона со следящим процессом, который перезапустит основной,
# если тот аварийно завершит работу проработав более 600 секунд
./build/bin/btpd -a 600 -d -C examples/simple/btp.conf

# Перезапускает в любом случае, в том числе после корректного завершения работы
./build/bin/btpd -A -a 600 -d -C examples/simple/btp.conf

# Перезапускает в любом случае, в том числе после корректного завершения работы
./build/bin/btpd -w /path/to/working/directory -d -C examples/simple/btp.conf

# Запуск под пользователем
sudo ./build/bin/btpd -u wwwrun -d -C examples/simple/btp.conf
```
В случае успешного запуска в рабочей директории будет создана директория `./btp` с пятью базами: ag5s, ag1m, ag7m, ag1h, ag1d
и директория `./logs` с файлом btp.log. Измените соответствующие значения в файле btp.ini на нужные вам абсолютные пути.

В директории `./examples/simple/` вариант конфигурации когда модуль real-time агрегации и модули хранилищ запускаются
в одном процессе. Состоит из четырех файлов:
* btp.conf - основной файл конфигурации
* btp.ini - дополнительный файл конфигурации с опциями которые скорее всего потребуют правки
* rocksdb-keys.ini - настройки RocksDB для хранилища ключей
* rocksdb-data.ini - настройки RocksDB для хранилища данных

В директории `./examples/multiple/` такой-же вариант конфигурации, но разбитый для удобства на несколько файлов.
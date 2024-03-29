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

В представленых конфигурациях определены следующие порты:
* **38000(tcp/udp)** - real-time аггрегатор входящего траффика
* **38001(tcp/udp)** - real-time аггрегатор входящего траффика для compact api (см. [JSONRPC-API](docs-md/api.md))
* **37000(tcp)** - получение данных для 5-секундного хранилища **ag5s**
* **37001(tcp)** - **ag1m** - минутного хранилища
* **37002(tcp)** - **ag7m** - 7-минутного
* **37003(tcp)** - **ag1h** - часового
* **37004(tcp)** - **ag1d** - дневного

Сборка займет достаточно времени (от 40 мин и более), но в основном за счет того, что система сборки автоматически
загрузит и скомпилирует нужные версии boost и rocksdb. Если у вас установлены boost 1.76 и rocksdb, то можно ускорить
сборку:
```sh
BOOST_ROOT=/path/to/boost ROCKSDB_ROOT=/path/to/rocksdb make release
```

### Проверка работоспособности

Запускаем демон:

```sh
./build/bin/btpd -d -W -C examples/multiple/btp.conf
```
Опция `-W` возвращает управление над консолью, только после полной инициалализации и запуска демона,
а не сразу после демонизации. Это гарантирует, что к моменту выполнения следующей команды, порты будут открыты.

После получения консоли, запускаем танк, который накидает в демон немного данных:
```sh
./build/bin/btpd -C examples/tank/tank.conf
```
Время работы танка порядка 10 секунд. После завершения его работы запускаем `telnet` и подключаемся к
5-секундному хранилищу:

```sh
telnet 0.0.0.0 37000
```
Отправляем запрос:
```json
{ "method":"get", "params":{"name":"script~~MyScript~~MyService~~MyOp"}, "id":1}
```
Должны получить ответ похожий на этот:
```sh
{"jsonrpc":"2.0","result":{"counters":[[1664234138698304,200,0,200,200,200,200,200,200,200,0],[1664234143698304,200,0,200,200,200,200,200,200,200,0]]},"id":1}
```
Чтобы получить данные из других хранилищ, нужно повторно запустить танк через минуту, 7 минут и т.д. На самом
деле это зависит от опции `aggregate_last_point` которая установлена только для часового и дневных графиков - это
исключительно для удобства отображения.

Остановить работающий демон можно так:
```sh
killall btpd
```
или так:
```sh
kill $(cat btpd-btp.conf.pid)
```

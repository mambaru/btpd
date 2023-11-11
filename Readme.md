[![tag](https://img.shields.io/github/v/tag/mambaru/btpd.svg?sort=semver)](https://github.com/mambaru/btpd/tree/master)

[![Build Status](https://github.com/mambaru/btpd/workflows/C++%20CI/badge.svg?branch=master)](https://github.com/mambaru/btpd/tree/master)
[![Build Status](https://github.com/mambaru/btpd/workflows/C++%20CI/badge.svg?branch=mambaru)](https://github.com/mambaru/btpd/tree/mambaru)
[![codecov](https://codecov.io/gh/mambaru/btpd/branch/master/graph/badge.svg)](https://codecov.io/gh/mambaru/btpd)

BTPD
=========

![](btp-graph.png)

# Высокопроизводительный демон для сбора, аггрегации и хранения больших объемов статистических данных

На данный момент в продакшене на одном сервере принимается и агрегируется до 6.2 млн. значений в секунду (около полутриллиона в день) дня нескольких сотен тысяч счетчиков (графиков).

![](docs-md/images/btpd-5s-1.png)

В хранилище на базе RocksDB сохраняются уже агрегированные данные, а сама агрегация производиться в реальном времени. Для каждого масштаба агрегации нужно настроить отдельное хранилище. У нас исторически используются: 5s, 1m, 7m, 1h, 1d (на графиках одна точка - это агрегация он пяти секунд до одного дня, соответственно). Для конкретных счетчиков процедур инициализации не предусмотрено, просто отправляете данные на сервер, графики появятся автоматически. К сожалению, инструментов для отображения графиков для btpd в свободном доступе нет и в ближайшее время не предвидится. Демон предоставляет JSON-RPC для построения графиков на базе собственных решений с использованием общедоступных библиотек.

* [Build](docs-md/build.md)
* [JSONRPC-API](docs-md/api.md)

## На github.com

* Репозитарий на [github.com](https://github.com/mambaru/btpd)
* Документация [doxygen](https://mambaru.github.io/btpd/index.html)
* Отчет [coverage](https://mambaru.github.io/btpd/cov-report/index.html)


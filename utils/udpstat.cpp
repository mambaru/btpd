#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Открываем файл /proc/net/udp для чтения
    std::ifstream file("/proc/net/udp");
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла /proc/net/udp" << std::endl;
        return 1;
    }

    // Пропускаем заголовок файла
    std::string line;
    std::getline(file, line);

    // Инициализируем счетчики
    int receivedPackets = 0;
    int sentPackets = 0;
    int droppedPackets = 0;

    // Читаем строки файла и обрабатываем статистику
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        int count = 0;

        // Разбиваем строку на токены
        while (std::getline(iss, token, ' ')) {
            if (token.empty()) {
                continue;
            }

            // Получаем значение счетчика
            if (count == 8) {
                receivedPackets += std::stoi(token);
            } else if (count == 9) {
                droppedPackets += std::stoi(token);
            } else if (count == 10) {
                sentPackets += std::stoi(token);
            }

            count++;
        }
    }

    // Выводим статистику
    std::cout << "Статистика по UDP:" << std::endl;
    std::cout << "Получено пакетов: " << receivedPackets << std::endl;
    std::cout << "Отправлено пакетов: " << sentPackets << std::endl;
    std::cout << "Потеряно пакетов: " << droppedPackets << std::endl;

    // Закрываем файл
    file.close();

    return 0;
}

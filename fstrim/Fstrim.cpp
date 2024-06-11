#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string productName;
    int quantity;
    double price;

    std::cout << "Введите название продукта: ";
    std::cin >> productName;
    std::cout << "Введите ко-во: ";
    std::cin >> quantity;
    std::cout << "Введите цену: ";
    std::cin >> price;

    file << productName << " " << quantity << " " << price << std::endl;
    file.close();
}

void readAndDisplayFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::cout << "Id имя ко-во цена" << std::endl;
    int id = 1;
    std::string productName;
    int quantity;
    double price;

    while (file >> productName >> quantity >> price) {
        std::cout << id << ") " << productName << " " << quantity << " " << price << std::endl;
        id++;
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "ru");
    std::string filename;
    int choice;

    std::cout << "Введите имя файла для работы: ";
    std::cin >> filename;

    do {
        std::cout << "меню:\n1. записать в файл\n2. Чтение и отображение файла\n3. выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            writeToFile(filename);
            break;
        case 2:
            readAndDisplayFile(filename);
            break;
        case 3:
            std::cout << "выход." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор.Попробуйте ещё раз." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

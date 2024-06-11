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

    std::cout << "������� �������� ��������: ";
    std::cin >> productName;
    std::cout << "������� ��-��: ";
    std::cin >> quantity;
    std::cout << "������� ����: ";
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

    std::cout << "Id ��� ��-�� ����" << std::endl;
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

    std::cout << "������� ��� ����� ��� ������: ";
    std::cin >> filename;

    do {
        std::cout << "����:\n1. �������� � ����\n2. ������ � ����������� �����\n3. �����\n";
        std::cout << "������� ��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            writeToFile(filename);
            break;
        case 2:
            readAndDisplayFile(filename);
            break;
        case 3:
            std::cout << "�����." << std::endl;
            break;
        default:
            std::cout << "�������� �����.���������� ��� ���." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

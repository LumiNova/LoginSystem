#include <iostream>
#include <fstream>
#include <string>

int choice;

std::string name;
std::string password;

void loginA();
void registerA();

void start() {

	std::cout << "---- Login System ----" << std::endl;
	std::cout << "{ 1 } - Login" << std::endl;
	std::cout << "{ 2 } - Register" << std::endl;
	std::cout << "{ 3 } - Exit" << std::endl;
	std::cout << "----------------------" << std::endl << std::endl;

	std::cout << "Enter your choice: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		loginA();
		break;
	case 2:
		registerA();
		break;
	case 3:
		std::cout << std::endl << "Exiting..." << std::endl;
		exit(0);
		break;
	default:
		std::cout << "Invalid choice!" << std::endl;
		break;
	}
}

void loginA() {

	system("cls");

	bool success = 0;

	std::ifstream file("login.txt");

	std::string storedName, storedPassword;

	std::cout << "---- Login ----" << std::endl;
	std::cout << "Enter your name: ";
	std::cin >> name;

	std::cout << "Enter your password: ";
	std::cin >> password;

	while (file >> storedName >> storedPassword) {

		if (storedName == name && storedPassword == password) {

			system("cls");

			std::cout << "Access granted!" << std::endl << std::endl;
		}

		else {

			system("cls");
			
			std::cout << "Access denied!" << std::endl << std::endl;
		}
	}

	start();

}

void registerA() {

	system("cls");

	std::ofstream file("login.txt");

	std::cout << "---- Registration ----" << std::endl;
	std::cout << "Enter your name: ";
	std::cin >> name;

	file << name << std::endl;

	std::cout << "Enter your password: ";
	std::cin >> password;

	file << password << std::endl;

	file.close();

	system("cls");

	start();
}

int main() {

	start();

	return 0;
}
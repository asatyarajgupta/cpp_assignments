#include <iostream>
#include <vector>
#include <algorithm> // For std::remove

void createArray(std::vector<int>& arr) {
    arr.clear(); // Clear the array to start fresh
}

void display(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insert(std::vector<int>& arr, int num) {
    arr.push_back(num);
}

void del(std::vector<int>& arr, int num) {
    arr.erase(std::remove(arr.begin(), arr.end(), num), arr.end());
}

int search(const std::vector<int>& arr, int num) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr;
    int choice, num;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Create Array\n";
        std::cout << "2. Display Array\n";
        std::cout << "3. Insert Element\n";
        std::cout << "4. Delete Element\n";
        std::cout << "5. Search Element\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                createArray(arr);
                std::cout << "Array created.\n";
                break;
            case 2:
                display(arr);
                break;
            case 3:
                std::cout << "Enter number to insert: ";
                std::cin >> num;
                insert(arr, num);
                std::cout << "Number inserted.\n";
                break;
            case 4:
                std::cout << "Enter number to delete: ";
                std::cin >> num;
                del(arr, num);
                std::cout << "Number deleted.\n";
                break;
            case 5:
                std::cout << "Enter number to search: ";
                std::cin >> num;
                {
                    int index = search(arr, num);
                    if (index != -1) {
                        std::cout << "Number found at p978 " << index +1 << "Position" << "\n";
                    } else {
                        std::cout << "Number not found.\n";
                    }
                }
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
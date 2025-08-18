#include <iostream>


int main() {
    int limit; // for the limit of the array
    std::cout << "Enter limit for the array: ";
    std::cin >> limit;

    int arr[200];
    int a = 0;

    int choice;
    while (true) {
        std::cout << "1. CREATE\n";
        std::cout << "2. DISPLAY\n";
        std::cout << "3. INSERT\n";
        std::cout << "4. DELETE\n";
        std::cout << "5. LINEAR SEARCH\n";
        std::cout << "6. EXIT\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter number of elements: ";
            std::cin >> a;
            if (a > limit) {
                std::cout << "out of limit!\n";
                a = limit;
            }
            std::cout << "Enter elements: ";
            for (int i = 0; i < a; i++)
                std::cin >> arr[i];
        }
        else if (choice == 2) {
            std::cout << "Array: ";
            for (int i = 0; i < a; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
        else if (choice == 3) {
            int pos, v;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cout << "Enter value: ";
            std::cin >> v;

            if (pos < 0 || pos > a || a >= limit) {
                std::cout << "Invalid position or array full!\n";
            } else {
                for (int i = a; i > pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos] = v;
                a++;
            }
        }
        else if (choice == 4) {
            int pos;
            std::cout << "Enter position (0-based): ";
            std::cin >> pos;
            if (pos < 0 || pos >= a) {
                std::cout << "Invalid position!\n";
            } else {
                for (int i = pos; i < a - 1; i++)
                    arr[i] = arr[i + 1];
                a--;
            }
        }
        else if (choice == 5) {
            int v, found = 0;
            std::cout << "Enter value to search: ";
            std::cin >> v;
            for (int i = 0; i < a; i++) {
                if (arr[i] == v) {
                    std::cout << "Found at index " << i << std::endl;
                    found = 1;
                    break;
                }
            }
            if (!found)
                std::cout << "Not found\n";
        }
        else if (choice == 6) {
            break;
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}

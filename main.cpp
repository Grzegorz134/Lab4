#include <iostream>
#include "rectangle/rectangle.h"
#include "trapezoid/trapezoid.h"
#include "windows.h"
#include "vector"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::vector <figure*> safe;

    unsigned short operation;

    std::cout << "1. Добавить прямоугольник в множество" << std::endl;
    std::cout << "2. Добавить равнобедренную трапецию в множество" << std::endl;
    std::cout << "3. Отобразить информацию о фигуре" << std::endl;
    std::cout << "4. Сумма площадей всех фигур" << std::endl;
    std::cout << "5. Сумма периметров всех фигур" << std::endl;
    std::cout << "6. Центр масс всей системы" << std::endl;
    std::cout << "7. Память, занимаемая всеми фигурами" << std::endl;


    while (true)
    {
        std::cout << ">> ";
        std::cin >> operation;

        if (operation == 0)
            return 0;

        if (operation == 1)
        {
            figure *object = new rectangle();

            object->initFromDialog();

            safe.push_back(object);
            std::cout << "--------------------------------------------" << std::endl;
        }

        if (operation == 2)
        {
            figure *object = new trapezoid();

            object->initFromDialog();

            safe.push_back(object);
            std::cout << "--------------------------------------------" << std::endl;
        }

        if (operation == 3)
        {
            for (int i = 0; i < safe.size(); i++)
            {
                std::cout << "#" << i << " ";
                safe[i]->draw();

                std::cout << std::endl;
            }
            std::cout << "--------------------------------------------" << std::endl;
        }

        if (operation == 4)
        {
            int sum = 0;
            for (int i = 0; i < safe.size(); i++)
                sum += safe[i]->square();

            std::cout << "Сумма всех площадей - " << sum << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
        }

        if (operation == 5)
        {
            int sum = 0;

            for (int i = 0; i < safe.size(); i++)
                sum += safe[i]->perimeter();
            std::cout << "Сумма всех периметров - " << sum << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
        }

        if (operation == 7)
        {
            int sum = 0;

            for (int i = 0; i < safe.size(); i++)
                sum += safe[i]->size();

            std::cout << sum << " байт" << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
        }
    }
}
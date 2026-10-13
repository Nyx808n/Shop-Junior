#include <iostream>
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choose_cat = 0, count = 1, choose = 0, boyar_count = 0;
    int parsley_count = 0, onion_count = 0;

    const double apple_price = 124.9, orange_price = 100.0, abricos_price = 186.9, pear_price = 159.9;
    const double tomat_price = 10.0, onion_price = 41.9, cucumber_price = 68.0;
    const double garlic_price = 201.9, parsley_price = 222.9, boyar_price = 300.0;

    double sum = 0, parsley_sum = 0, boyar_sum = 0, fruit_sum = 0;

    std::cout << "\t\tДобро пожаловать в магаз\n";
    std::cout << "Наш ассортимент:\n1. Фруктовые: яблочный, апельсиновый, абрикосовый, грушевый\n2. Овощные: томатный, луковый, огуречный\n3. Чаи: чесночный, петрушевый\n4. Боярышник\n";
    std::cout << "\nЕсли вы закончили покупки введите 0 при выборе категории товаров";

    while (true) {
        std::cout << "\n\tВыберите категорию товаров (введите цифру от 1 до 4): ";
        std::cin >> choose_cat;

        if (choose_cat == 0) {
            break;
        }
        if (choose_cat < 0 || choose_cat > 4) {
            std::cout << "Некорректный ввод, попробуйте еще раз";
            std::cin >> choose_cat;
        }

        if (choose_cat == 1) {
            std::cout << "1. Яблочный 2. Апельсиновый 3. Абрикосовый 4. Грушевый\n";
            std::cout << "Если закончили покупки в этой категории введите 0 при выборе сока\n";

            while (true) {
                std::cout << "Внимание! При покупке фруктового сока аннулируется покупка боярышника.\nЕсли вы этого не хотите, то введите 0 при выборе сока для выхода из категории";
                
                std::cout << "Введите цифру от 1 до 4 для выбора сока или 0 для выхода: ";
                std::cin >> choose;

                if (boyar_sum > 0) {
                    boyar_sum = 0;
                }

                if (choose == 0)
                    break;
                if (choose < 0 || choose > 4) {
                    std::cout << "Некорректный ввод, попробуйте еще раз";
                    std::cout << "Введите цифру от 1 до 4 для выбора сока или 0 для выхода: ";
                    std::cin >> choose;
                }

                std::cout << "Введите количество выбранного товара (в одной упаковке 1л): ";
                std::cin >> count;
                std::cout << "\n";

                if (choose == 1) {
                    fruit_sum += apple_price * count;
                }
                else if (choose == 2) {
                    fruit_sum += orange_price * count;
                }
                else if (choose == 3) {
                    fruit_sum += abricos_price * count;
                }
                else if (choose == 4) {
                    fruit_sum += pear_price * count;
                }
            }
        }


        if (choose_cat == 2) {
            std::cout << "1. Томатный 2. Луковый 3. Огуречный\n";
            std::cout << "Если закончили покупки в этой категории введите 0 при выборе сока\n";

            while (true) {
                std::cout << "\nВведите цифру от 1 до 3 для выбора сока или 0 для выхода: ";
                std::cin >> choose;
                if (choose < 0 || choose > 4) {
                    std::cout << "Некорректный ввод, попробуйте еще раз";
                    std::cout << "\nВведите цифру от 1 до 3 для выбора сока или 0 для выхода: ";
                    std::cin >> choose;
                }
                if (choose == 0)
                    break;
                std::cout << "Введите количество выбранного товара (в одной упаковке 1л): ";
                std::cin >> count;
                std::cout << "\n";

                if (choose == 1)
                    sum += tomat_price * count;
                else if (choose == 2) {
                    sum += onion_price * count;
                    onion_count += count;
                }
                else if (choose == 3)
                    sum += cucumber_price * count;
            }
        }

        if (choose_cat == 3) {
            std::cout << "1. Чесночный 2. Петрушечный\n";
            std::cout << "Если закончили покупки в этой категории введите 0 при выборе чая\n";

            while (true) {
                std::cout << "Введите цифру от 1 до 2 для выбора чая или 0 для выхода: ";
                std::cin >> choose;
                if (choose < 0 || choose > 4) {
                    std::cout << "Некорректный ввод, попробуйте еще раз";
                    std::cout << "Введите цифру от 1 до 2 для выбора чая или 0 для выхода: ";
                    std::cin >> choose;
                }
                if (choose == 0)
                    break;
                std::cout << "Введите количество выбранного товара (в одной упаковке 1л): ";
                std::cin >> count;
                std::cout << "\n";

                if (choose == 1)
                    sum += garlic_price * count;
                if (choose == 2) {
                    parsley_sum += parsley_price * count;
                    parsley_count += count;
                }
                
            }
        }
        if (choose_cat == 4) {
            std::cout << "Боярышник\n";
            std::cout << "Если закончили покупки в этой категории введите 0 при выборе количества товара\n";
            if (fruit_sum > 0) {
                std::cout << "Извините, доступ к покупке боярышника заблокирован из-за покупки фруктового сока.\n";
            }

            while (true) {
                std::cout << "Введите количество выбранного товара (в одной упаковке 1л) или 0 для выхода: ";
                std::cin >> count;
                std::cout << "\n";

                if (count == 0)
                    break;
                else {
                    boyar_sum += count * boyar_price;
                }
            }
        }
    }

    system("cls");
    std::cout << "Итоговая сумма без учета скидок и акций составляет: " << sum << "\n";
    std::cout << "Идет подсчет скидок";
    Sleep(2000);
    system("cls");

    sum += boyar_sum;
    sum += fruit_sum;

    if (parsley_count >= 3) {
        parsley_sum -= (parsley_sum / 100) * 5;
        sum += parsley_sum;
        std::cout << "\nВам предоставлена скидка 5% на петрушевый чай\n";
    }
    if (onion_count % 4 == 0 && onion_count != 0) {
        sum -= ((onion_count / 4) * onion_price);
        std::cout << "Акция! Каждый 4л лукового сока в подарок\n";
        std::cout << "У вас " << onion_count / 4 << " подарочных литров сока";
    }
    if (sum >= 750) {
        std::cout << "\nВам предоставлена скидка 13% на всю покупку\n";
        sum = sum - (sum / 100) * 13;
    }

    std::cout << "\n\t\tИтоговая сумма с учетом всех скидок и акций: " << sum;

}


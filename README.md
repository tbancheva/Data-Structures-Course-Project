# Проект по Структури от Данни

### Йерархия от контейнери

Да се реализира **хетерогенен свързан списък** от състоящ се от n контейнера. Числото
n се въвежда от потребителя. Всеки контейнер може да е шаблон на **двусвързан
списък, стек или опашка** и притежава операция bool member(T const& x), която
проверява дали даден елемент x се среща в контейнера.

За хетерогенния списък да се реализира следната **функционалност**:
* Нека е даден файл с n реда от цели числа, да се реализира **извличане на всеки
ред от файла** и въвеждане на числата в него в съответен контейнер. Числата
предназначени за един контейнер се намират на един ред, а в началото на
реда е отбелязан вида на съответния контейнер
* За всеки от контейнерите да се поддържат подходящи функции за **включване и
изключване** на елементи.
* Да се реализира **проверка дали даден елемент се среща** в някой от елементите
на хетерогенния списък.
* Да се реализират функция за добавяне на елемент към хетерогенния списък
реализираща **равномерно разпределение** на елементите (load balancing) —
елементът да се добавя към контейнера с най-малка големина.
* Да се напише функция, която проверява дали в контейнер се среща елемент,
отговарящ на дадено условие, като условието е дефинирано като using
Condition = bool (*)(T const&);
* Да се напише функция за **филтрация**, която изтрива от всички контейнери в
хетерогенния списък всички елементи отговарящи на дадено условие.
* Да се напише функция, която **сортира** (поотделно) всички контейнери в
хетерогенния списък. Могат да бъдат използвани помощни структури, ако е
нужно.
* Да се реализира функция **визуализираща съдържанието** на хетерогенния
списък по подходящ начин.
* Да се напише функция, реализираща **обратното записване във файл** на
променения хетерогенен списък, в същия формат, който се използва за
извличането му.

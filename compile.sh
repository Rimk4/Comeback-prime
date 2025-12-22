#!/bin/bash

# Проверяем, передан ли аргумент с номером задачи
if [ $# -eq 0 ]; then
    echo "Ошибка: Не указан номер задачи"
    echo "Использование: $0 <номер_задачи>"
    echo "Пример: $0 5"
    exit 1
fi

task_number=$1

# Проверяем существование папки с задачей
if [ ! -d "$task_number" ]; then
    echo "Ошибка: Папка '$task_number' не найдена"
    exit 1
fi

# Ищем файл .cpp в папке (по шаблону "номер_задачи.*.cpp")
# Например: 5.*.cpp найдет 5.longest-palindromic-substring.cpp
cpp_file=$(find "$task_number" -name "${task_number}.*.cpp" -type f | head -n 1)

# Если не нашли по шаблону с точкой, ищем просто по номеру в начале
if [ -z "$cpp_file" ]; then
    cpp_file=$(find "$task_number" -name "${task_number}*.cpp" -type f | head -n 1)
fi

if [ -z "$cpp_file" ]; then
    echo "Ошибка: В папке '$task_number' не найден файл .cpp, начинающийся с '$task_number'"
    exit 1
fi

# Создаем папку build, если она не существует
mkdir -p build

# Имя выходного файла
output_file="build/${task_number}_solution"

# Компилируем
echo "Компиляция: $cpp_file -> $output_file"
g++ "$cpp_file" -g -o "$output_file"

# Проверяем успешность компиляции
if [ $? -eq 0 ]; then
    echo "Успешно скомпилировано: $output_file"
    echo "Для запуска выполните: ./$output_file"
else
    echo "Ошибка компиляции"
    exit 1
fi
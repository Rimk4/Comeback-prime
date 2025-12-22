#!/bin/bash

echo "Очистка проекта..."

# Удаляем папку build
if [ -d "build" ]; then
    echo "Удаляю папку build/"
    rm -rf build/
else
    echo "Папка build/ не найдена"
fi

echo "Очистка завершена"

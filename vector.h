#ifndef __VECTOR__
#define __VECTOR__

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void append(Vector *vector, int value); //добавить value в конец массива
void insert(Vector *vector, size_t pos, int value); //вставить value на позицию pos и сдвинуть элементы справа
void erase(Vector *vector, size_t pos); // удалить элемент на позиции pos и сдвинуть элементы справа
int indexOf(Vector *vector, int value); // возвратить индекс элемента со значением value
void reserve(Vector *vector, size_t newCap); // устанавить значение capacity большее
                                //или равное newCap, если newCap < capacity ничего не делать
void squeeze(Vector *vector); // изменить размер выделенной памяти так, чтобы он соответствовал
                                // количеству элементов, если size = 0, вызвать free
void clear(Vector *vector); // заполнить массив нулями и изменить size
void print(Vector *vector);  // вывести в консоль элементы массива
void deleteSome(Vector *vector, int a, int b);

#endif

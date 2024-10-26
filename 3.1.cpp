#include <iostream>
using namespace std;

struct subvector {
     int *mas;
     unsigned int top; 
     unsigned int capacity;
};

void init(subvector *qv) {
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
} // инициализация пустого недовектора (top и capacity по нулям, а mas это NULL)
void push_back(subvector *qv, int d) {
    if (qv->mas) {
        if (qv->top + 1 <= qv->capacity) {
        qv->top++;
        qv->mas[qv->top-1] = d;
        } else {
            qv->capacity = qv->capacity * 2;
            int *new_mas = new int[qv->capacity];
            for (int i = 0; i < qv->top; i++) {
                new_mas[i] = qv->mas[i];
            }
            qv->top++;
            new_mas[qv->top-1] = d;
            delete[]qv->mas;
            qv->mas = new_mas;
        }
    } else {
        qv->capacity = (qv->capacity + 10) * 2;
        int *new_mas = new int[qv->capacity];
        new_mas[qv->top] = d;
        qv->top++;
        qv->mas = new_mas;
    }
} // добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости
int pop_back(subvector *qv) {
    if (qv->top) {
        qv->top--;
        return qv->mas[qv->top];
    } else {
        return 0;
    }
} // удаление элемента с конца недовектора, значение удаленного элемента вернуть (если недовектор пустой, вернуть ноль)
void resize(subvector *qv, unsigned int new_capacity) {
    qv->capacity = new_capacity;
    int *new_mas = new int[qv->capacity];
    if (qv->top > qv->capacity) {
        qv->top = qv->capacity;
    }
    for (int i = 0; i < qv->top; i++) {
        new_mas[i] = qv->mas[i];
    }
    delete[]qv->mas;
    qv->mas = new_mas;
} // увеличить емкость недовектора (можно использовать и для уменьшения - тогда, в рамках данной реализации, если top меньше новой capacity, то копируем только то, что влезает, и уменьшаем top до capacity)
void shrink_to_fit(subvector *qv) {
    qv->capacity = qv->top;
    int *new_mas = new int[qv->top];
    for (int i = 0; i < qv->top; i++) {
        new_mas[i] = qv->mas[i];
    }
    delete[]qv->mas;
    qv->mas = new_mas;        
} // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top
void clear(subvector *qv) {
    qv->top = 0;
} // очистить содержимое недовектора, занимаемое место при этом не меняется
void destructor(subvector *qv) {
    delete[]qv->mas;
    init(qv);
} // очистить всю используемую память, инициализировать недовектор как пустой

int main() {
    subvector *qv = new subvector();
    init(qv);

    //push back test
    // for (int i = 0; i < 30; i++) {
    //     push_back(qv, i);
    //     cout<<qv->capacity<<' '<<qv->mas[i]<<'\n';
    // }
    
    //pop back test
    // push_back(qv, 10);
    // cout<<pop_back(qv)<<' '<<qv->top;

    //shrink_to_fit test 
    // for (int i = 0; i < 30; i++) {
    //     push_back(qv, i);
    // }
    // shrink_to_fit(qv);
    // cout<<qv->capacity;

    //resize test
    // resize(qv, 10);
    // for (int i = 0; i < 30; i++) {
    //     push_back(qv, i);
    // }
    // for (int i = 0; i< qv->top; i++) {
    //     cout<<qv->mas[i];
    // }
    // cout<<'\n';
    // resize(qv, 10);
    // for (int i = 0; i< qv->top; i++) {
    //     cout<<qv->mas[i];
    // }

    //clear and destraction test
    // for (int i = 0; i < 30; i++) {
    //     push_back(qv, i);
    // }
    // clear(qv);
    // cout<<qv->top<<' '<<qv->capacity<<'\n';
    // destructor(qv);
    // cout<<qv->top<<' '<<qv->capacity<<'\n';
}
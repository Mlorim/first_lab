#include <iostream>
using namespace std;

struct subforwardlist {
     int data;
     subforwardlist* next;
};


// Список функций к реализации, вместо "@" нужно всатвить столько звездочек, сколько необходимо вам для реализации
bool init(subforwardlist **sfl) {
    *sfl = nullptr;
}	//инициализация пустого недосписка 
bool push_back(subforwardlist **sfl, int d) {
    if (*sfl) {
        subforwardlist *curr = *sfl;
        while (curr->next) {
            curr = curr->next;
        }
        subforwardlist *new_nod = new subforwardlist;
        new_nod->data = d;
        new_nod->next = nullptr;
        curr->next = new_nod;
    } else {
        subforwardlist *new_nod = new subforwardlist;
        new_nod->data = d;
        new_nod->next = nullptr;
        *sfl = new_nod;
    }

} 	//добавление элемента в конец недосписка				
int pop_back(subforwardlist **sfl) {
    if (!*sfl) {
        return 0;
    } else {
        subforwardlist *curr = *sfl;
        subforwardlist *prev = *sfl;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        if (prev==curr) {
            int res = curr->data;
            delete curr;
            init(sfl);
            return res;
        } else {
            int res = curr->data;
            subforwardlist *temp = prev->next;
            prev->next = nullptr;
            delete temp;
            return res;
        }

    }
} 	//удаление элемента с конца недосписка, если пустой - возвращать 0
void push_forward(subforwardlist **sfl, int d) {
    subforwardlist *prev_first = *sfl;
    subforwardlist *new_first = new subforwardlist();
    new_first->data = d;
    new_first->next = prev_first;
    *sfl = new_first;
} 	//добавление элемента в начало недосписка				
int pop_forward(subforwardlist **sfl) {
    if (!*sfl) {
        return 0;
    } else {
        subforwardlist *first = *sfl;
        int res = first->data;
        *sfl=first->next;
        delete first;
        return res;
    }
} 	//удаление элемента из начала недосписка, если пустой - возвращать 0
bool push_where(subforwardlist **sfl, unsigned int where, int d) {
    if (!where) {
        push_forward(sfl, d);
    } else {
        subforwardlist *curr = *sfl;
        int counter = 0;
        while (curr->next) {
            if (counter == where-1) {
                break;
            }
            curr = curr->next;
            counter++;
        }
        if (counter != where-1) {
            return 0;
        }
        subforwardlist *new_nod = new subforwardlist();
        new_nod->data = d;
        new_nod->next = curr->next;
        curr->next = new_nod;   
    }
    
} //добавление элемента с порядковым номером where		
int erase_where(subforwardlist **sfl, unsigned int where) {
    if (!where) {
        pop_forward(sfl);
    } else {
        subforwardlist *curr = *sfl;
        int counter = 0;
        while (curr->next) {
            if (counter == where - 1) {
                break;
            }
            curr = curr->next;
            counter++;
        }
        if (!curr->next) {
            return 0;
        } else {
            subforwardlist *deleted = curr->next;
            int res = deleted->data;
            curr->next = deleted->next;
            delete deleted;
            return res;
        }
    }
  
}	//удаление элемента с порядковым номером where, если пустой - возвращать 0

unsigned int size(subforwardlist  **sfl) {
    if (*sfl) {
        int res = 1;
        subforwardlist *curr = *sfl;
        while (curr->next) {
            curr = curr->next;
            res++;
        }
        return res;
    } else {
        return 0;
    }
}	//определить размер недосписка

void clear(subforwardlist  **sfl) {
    while (*sfl) {
        subforwardlist *prev = *sfl;
        subforwardlist *curr = *sfl;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        if (prev==curr) {
            delete curr;
            init(sfl);
            break;
        }
        prev->next = nullptr;
        delete curr;
    }

}	//очистить содержимое недосписка

void print_list(subforwardlist  **sfl) {
    subforwardlist *curr = *sfl;
    while (curr->next) {
        cout<<curr->data<<' ';
        curr = curr->next;
    }
    cout<<curr->data<<'\n';
}

int main() {
    subforwardlist *sfl =  new subforwardlist();
    init(&sfl);

    // push_back and pop_back test
    // push_back(&sfl, 10);
    // push_back(&sfl, 20);
    // print_list(&sfl);
    // cout<<pop_back(&sfl)<<'\n';
    // print_list(&sfl);

    //push_forward and pop_forward test
    // push_forward(&sfl, 10);
    // push_forward(&sfl, 20);
    // print_list(&sfl);
    // cout<<pop_forward(&sfl)<<'\n';
    // print_list(&sfl);

    //push_where and erase_where
    // push_back(&sfl, 10);
    // push_back(&sfl, 20);
    // push_back(&sfl, 30);
    // print_list(&sfl);
    // push_where(&sfl, 1, 0);
    // push_where(&sfl, 4, 40);
    // print_list(&sfl);
    // erase_where(&sfl, 1);
    // erase_where(&sfl, 3);
    // print_list(&sfl);

    //size test
    // cout<<size(&sfl)<<'\n';
    // push_back(&sfl, 10);
    // push_back(&sfl, 20);
    // push_back(&sfl, 30);
    // pop_back(&sfl);
    // pop_back(&sfl);
    // pop_back(&sfl);
    // cout<<size(&sfl);

    //clear test
    // push_back(&sfl, 10);
    // push_back(&sfl, 20);
    // push_back(&sfl, 30);
    // clear(&sfl);
    // push_back(&sfl, 100);
    // print_list(&sfl);

}
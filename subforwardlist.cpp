struct subforwardlist {
    int data;
    subforwardlist* next;
};


bool init(subforwardlist **sfl) {//инициализация пустого недосписка
    *sfl = nullptr;
    return true;
}
bool push_back(subforwardlist **sfl, int d){//добавление элемента в конец недосписка
    subforwardlist* p = new subforwardlist;
    p -> data = d;
    p -> next = nullptr;
    if (*sfl == nullptr) *sfl = p;
    else {
        subforwardlist* k = *sfl;
        while (k -> next != nullptr) k = k -> next;
        k -> next = p;
    }
    return true;
}

int pop_back(subforwardlist **sfl) {//удаление элемента с конца недосписка
    if (*sfl != nullptr){
        subforwardlist* curr = *sfl;
        subforwardlist* prev = nullptr;
        while (curr -> next != nullptr){
            prev = curr;
            curr = curr -> next;
        }
        int d = curr -> data;
        delete curr;
        if (prev == nullptr) *sfl = nullptr;
        else prev -> next = nullptr;
        return d;
    }
    return 0;
}

bool push_forward(subforwardlist **sfl, int d){//добавление элемента в начало недосписка
    subforwardlist* k = new subforwardlist;
    k->data = d;
    k->next = *sfl;
    *sfl = k;
    return true;
}
int pop_forward(subforwardlist **sfl){//удаление элемента из начала недосписка
    if (*sfl != nullptr){
        int d = (*sfl) -> data;
        subforwardlist* k = (*sfl) -> next;
        delete *sfl;
        *sfl = k;
        return d;
    }
    return 0;
}

unsigned int size(subforwardlist** sfl){//определить размер недосписка
    int cnt = 1;
    subforwardlist* p = *sfl;
    while (p != nullptr) {
        p = p -> next;
        cnt += 1;
    }
    return cnt - 1;
}


bool push_where(subforwardlist **sfl, unsigned int where, int d) { //добавление элемента с порядковым номером where
    where += 1;
    if(where <= size(sfl) + 1){
        if (where == 1) push_forward(sfl, d);
        else if (where == size(sfl) + 1) push_back(sfl, d);
        else {
            subforwardlist* k = *sfl;
            for (unsigned i = 1; i < where - 1; i ++) k = k -> next;
            subforwardlist* p = new subforwardlist;
            p -> data = d;
            p -> next = k -> next;
            k -> next = p;
        }
    }
    return true;
}

bool erase_where(subforwardlist **sfl, unsigned int where){//удаление элемента с порядковым номером where
    where += 1;
    if((where <= size(sfl))&&(*sfl != nullptr)){
        subforwardlist *k = *sfl;
        for (unsigned i = 1; i < where - 1; i ++) k = k -> next;
        subforwardlist* p = (k -> next) -> next;
        delete k -> next;
        k -> next = p;
    }
    return 1;
}


void clear(subforwardlist **sfl){//очистить содержимое недосписка
    while (*sfl != nullptr){
        subforwardlist* k = (*sfl) -> next;
        delete *sfl;
        *sfl = k;
    }
}

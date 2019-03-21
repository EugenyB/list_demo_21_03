#include <iostream>

using namespace std;

struct element {
    int x;
    element * next;
};

element * head;
element * tail;

void addInHead(int value) {
    element * t = new element;
    t->x = value;
    t->next = head;
    head = t;
}

void addInTail(int value) {
    element * t = new element;
    t->x = value;
    t->next = nullptr;
    if (tail) {
        tail->next = t;
    } else {
        head = t;
    }
    tail = t;
}

void print(element * head) {
    element * t = head;
    while (t) {
        cout << t->x << endl;
        t = t->next;
    }
}

element * find(element * head, int value) {
    element * t;
    t = head;
    while (t) {
        if (t->x == value) {
            break;
        } else {
            t = t->next;
        }
    }
    return t;
}

void addAfter(element * f, int value) {
    //1
    element * t = new element;
    t->x = value;
    //2
    t->next = f->next;
    //3
    f->next = t;
}

void deleteAfter(element * f) {
    element * t = f->next;
    f->next = f->next->next; //t->next
    delete t;
}

void addBefore(element * f, int value) {
    //1
    element * t = new element;
    //2
    t->next = f->next;
    //3
    f->next = t;

    //4
    t->x = f->x;
    f->x = value;
}

void deleteElement(element * f) {
    element * t = f->next;
    f->x = t->x;
    f->next = f->next->next;
    delete t;
}


int main() {
    head = nullptr;
    addInTail(1);
    addInTail(2);
    addInTail(3);
    addInTail(4);
    addInTail(5);

    print(head);

    element * p ;
    if ((p = find(head, 3))) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

//    addBefore(p, 17);
    deleteAfter(p);
    print(head);

    return 0;
}
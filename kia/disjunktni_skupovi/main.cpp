#include <iostream>
#include <vector>

using namespace std;

int ID = 0;

class Set;
class Element;

class Element {
public:
    char id;
    Set *set = nullptr;
    Element *next = nullptr;
};

class Set {
public:
    int id;
    Element *head = nullptr;
    Element *tail = nullptr;
};

void make_set(Element *x)
{
    auto new_set = new Set();

    new_set->id = ID++;
    new_set->head = x;
    new_set->tail = x;

    x->set = new_set;
}

Element *find_set(Element *x)
{
    return x->set->head;
}

void union_set(Element *x, Element *y)
{
    auto x_set = find_set(x)->set;
    auto y_set = find_set(y)->set;

    x_set->tail->next = y_set->head;
    x_set->tail = y_set->tail;

    auto y_head = y_set->head;
    while (y_head != nullptr) {
        y_head->set = x_set;
        y_head = y_head->next;
    }
}

void print_element(Element *x)
{
    cout << x->id << " ";
}

void print_set(Set *s)
{
    cout << s->id << " [ ";
    auto head = s->head;
    while (head != nullptr) {
        print_element(head);
        head = head->next;
    }
    cout << "]" << endl;
}

int main(void)
{
    auto a = new Element(); a->id = 'a';
    auto b = new Element(); b->id = 'b';
    auto c = new Element(); c->id = 'c';
    auto d = new Element(); d->id = 'd';
    auto e = new Element(); e->id = 'e';
    auto f = new Element(); f->id = 'f';
    auto g = new Element(); g->id = 'g';

    make_set(a);
    make_set(b);
    make_set(c);
    make_set(d);
    make_set(e);
    make_set(f);
    make_set(g);

    union_set(a, b);
    union_set(a, c);
    union_set(d, e);
    union_set(d, f);
    union_set(d, g);

    print_set(a->set);
    print_set(f->set);

    union_set(a, f);

    print_set(a->set);

    delete find_set(a);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;

    return 0;
}
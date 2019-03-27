#include "Multime.h"

using namespace std;

Multime::Multime()//Constructorul fara parametru, initializam multimea cu 0
{
    elemente *aux;
    M = new elemente;
    aux = M;
    aux->info = 0;
    aux->next = NULL;
}

Multime::Multime(int value)//Constructorul cu parametru, initializam multimea cu value
{
    elemente *aux;
    M = new elemente;
    aux = M;
    aux->info = value;
    aux->next = NULL;
}

Multime::Multime(const Multime &other)//Constructorul de copiere
{
    elemente *aux = new elemente, *aux1;
    M = new elemente;
    aux = other.M;
    elemente *p = new elemente;
    p->info = aux->info;
    p->next = NULL;
    M->next = p;
    M = p;
    aux = aux->next;
    aux1 = M;
    if (aux == NULL)
        M->next = NULL;
    else
        while (aux != NULL) {
            elemente *p = new elemente;
            p->info = aux->info;
            p->next = NULL;
            aux1->next = p;
            aux1 = p;
            aux = aux->next;
        }
}

Multime::~Multime()//Destructorul
{
    elemente *curent = M;
    elemente *aux;
    while (curent != NULL) {
        aux = curent->next;
        delete (curent);
        curent = aux;
    }
    M = NULL;
}

void Multime::Inserare(int value)//Inserarea unei valori, daca value era in multime nu o mai punem
{
    elemente *aux = M;
    elemente *nou = new elemente;
    if (aux->next == NULL) {
        if (aux->info > value) {
            nou->info = value;
            nou->next = M;
            M = nou;
        } else if (aux->info != value) {
            nou->info = value;
            nou->next = aux->next;
            aux->next = nou;
        }
    } else if (aux->info > value) {
        nou->info = value;
        nou->next = M;
        M = nou;
    } else {
        while (aux->next->info <= value && aux->next->next != NULL)
            aux = aux->next;
        if (aux->info < value && aux->next->info <= value)
            aux = aux->next;
        if (aux->info != value) {
            nou->info = value;
            nou->next = aux->next;
            aux->next = nou;
        }
    }
}

void Multime::Sterge(int value)//Stergerea unei valori
{
    elemente *aux = M;
    elemente *ultimu = new elemente;
    while (aux != NULL && aux->info != value) {
        ultimu = aux;
        aux = aux->next;
    }
    if (aux == NULL) {
        //cout<<"Nu apare valoarea "<<value<<endl;//daca valoare nu face parte din multime putem afisa un mesaj
        return;
    }
    if (aux == M) {
        M = M->next;
        delete aux;
    } else {
        ultimu->next = aux->next;
        delete aux;
    }
}

int Multime::Cautare(int value)//Cautarea unui element, intoarcem pozitia pe care se afla value
{
    elemente *aux = M;
    int k = 0;
    while (aux) {
        if (aux->info == value)
            return k;
        aux = aux->next;
        k++;
    }
    //cout<<"Nu apare elementul "<<value;//daca value nu face parte din multime putem afisa un mesaj
}

int Multime::Numar() const//Numarul de elemente ale multimii
{
    int k = 0;
    elemente *aux = new elemente;
    aux = M;
    while (aux) {
        k++;
        aux = aux->next;
    }
    return k;
}

Multime &Multime::operator=(const Multime &other)//supraincarcarea operatorului=
{
    if (other.M == NULL)//caz special pentru multime vida
    {
        M = NULL;
        return *this;
    }
    if (&other != this) {
        elemente *aux2 = new elemente;
        aux2 = other.M;
        elemente *aux1 = M;
        M->info = aux2->info;
        M->next = NULL;
        aux2 = aux2->next;
        while (aux2 != NULL) {
            elemente *p = new elemente;
            p->info = aux2->info;
            p->next = NULL;
            aux1->next = p;
            aux1 = p;
            aux2 = aux2->next;
        }
    }
    return *this;
}

int &Multime::operator[](int pos)//supraincarcarea operatorului [], intoarecem valoarea de la pozitia pos
{
    int k = 0;
    elemente *aux = M;
    while (aux != NULL) {
        if (k == pos)
            return aux->info;
        aux = aux->next;
        k++;
    }
    //cout<<"Multimea nu are elementul "<<pos<<endl;//putem afisa un mesaj daca multimea nu are pos elemente
}

bool Multime::operator<(const Multime &other)//supraincarcarea operatorului <
{
    int aux1 = Numar(), aux2 = other.Numar();
    return aux1 < aux2;
}

bool Multime::operator>(const Multime &other)//supraincarcarea operatorului >
{
    int aux1 = Numar(), aux2 = other.Numar();
    return aux1 > aux2;
}

Multime Multime::operator+(Multime &other)//supraincarcarea operatorului +, vom folosi metoda de Inserare
{
    Multime aux;
    elemente *aux1 = M, *aux2 = other.M;
    aux.M->info = aux1->info;
    aux.M->next = NULL;
    aux1 = aux1->next;
    while (aux1) {
        aux.Inserare(aux1->info);
        aux1 = aux1->next;
    }
    while (aux2) {
        aux.Inserare(aux2->info);
        aux2 = aux2->next;
    }
    return aux;
}

Multime Multime::operator-(Multime &other)//supraincarcarea operatorului -, vom folosi metoda de Inserare si Stergere
{
    Multime aux;
    elemente *aux1 = M, *aux2 = other.M;
    aux.M->info = aux1->info;
    aux.M->next = NULL;
    aux1 = aux1->next;
    while (aux1)//Inseram prima multime
    {
        aux.Inserare(aux1->info);
        aux1 = aux1->next;
    }
    while (aux2)//Stergem elementele care apar in prima si in a doua multime
    {
        if (aux.M == NULL)
            break;
        aux.Sterge(aux2->info);
        aux2 = aux2->next;
    }
    return aux;

}

std::ostream &operator<<(std::ostream &out, const Multime &mul)//supraincarcarea operatorului <<
{
    Multime aux = mul;
    out << aux.M->info;
    return out;
}

std::istream &operator>>(std::istream &in, Multime &mul)//supraincarcarea operatorului >>
{
    int nr;
    in >> nr;
    mul.Inserare(nr);//vom insera in multime elementul citit
    return in;
}

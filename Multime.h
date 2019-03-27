#ifndef TEMA2_MULTIME_H
#define TEMA2_MULTIME_H

#include <iostream>

class Multime {
    struct elemente {
        int info;
        elemente *next;
    };
public:
    elemente *M;

    Multime();

    Multime(int value);

    Multime(const Multime &other);

    ~Multime();

    int &operator[](int pos);

    Multime &operator=(const Multime &other);

    Multime operator+(Multime &other);

    Multime operator-(Multime &other);

    bool operator>(const Multime &other);

    bool operator<(const Multime &other);

    void Inserare(int value);

    void Sterge(int value);

    int Numar() const;

    int Cautare(int value);
};

std::ostream &operator<<(std::ostream &, const Multime &);

std::istream &operator>>(std::istream &, Multime &);

#endif //TEMA2_MULTIME_H

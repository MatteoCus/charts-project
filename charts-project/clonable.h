#ifndef CLONABLE_H
#define CLONABLE_H


class Clonable
{
public:
    Clonable() = default;
    virtual Clonable* clone() const = 0;
};

#endif // CLONABLE_H

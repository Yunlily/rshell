#ifndef Base_h
#define Base_h

//Base class
class Base {
public:
    Base() {}
    virtual bool execute() = 0;
};
#endif
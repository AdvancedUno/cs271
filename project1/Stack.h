//=========================
// EunHo Lee
//=========================



#ifndef STACK_H
#define STACK_H

#include "List.h"

template<typename T>
class Stack{

    private:

        List<T> list;


    public:
                Stack           (void);
                Stack           (const Stack<T> &s);

                ~Stack          (void);

    Stack<T>    operator=       (const Stack<T> &s);
    void        push            (const T &item);
    T           pop             (void);
    T           peak            (void);
    int         size            (void);
    bool        empty           (void);
    void        clear           (void);



};





#include "Stack.cpp"


#endif


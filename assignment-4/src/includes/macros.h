#ifndef MACROS_H
#define MACROS_H

#define ERROR_OUTPUT           \
    {                          \
        cout << "-1\nError\n"; \
        return;                \
    }

#define SUCCESS_OUTPUT \
    {                  \
        cout << "0\n"; \
        return;        \
    }

#endif
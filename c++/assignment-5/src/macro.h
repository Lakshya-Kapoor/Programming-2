#ifndef MACRO_H
#define MACRO_H

#define ERROR(msg)                        \
    {                                     \
        cout << "Error: " << msg << endl; \
        return;                           \
    }

#define SUCCESS(msg)                        \
    {                                       \
        cout << "SUCCESS: " << msg << endl; \
        return;                             \
    }

#endif
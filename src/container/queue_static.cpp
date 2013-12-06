#include "queue_static.h"

/*********************************************************************************
    constructor
**********************************************************************************/
template<typename T>
QueueStatic<T>::QueueStatic()
{
    size    =   0;
    head    =   0;
    tail    =   0;
    *data   =   NULL;
}



/*********************************************************************************
    constructor
**********************************************************************************/
template<typename T>
QueueStatic<T>::QueueStatic( int _size )
{
    size    =   _size;
    head    =   0;
    tail    =   0;
    
    *data   =   new T[size];
    
    ErrorExceptionMacro( data != NULL );
}
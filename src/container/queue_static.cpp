#include "queue_static.h"



namespace   hidog
{
namespace   container
{




/*********************************************************************************
    constructor
**********************************************************************************/
template<typename T>
QueueStatic<T>::QueueStatic()
{
    num     =   0;
    _size    =   0;
    head    =   0;
    tail    =   0;
    data   =   NULL;
}



/*********************************************************************************
    constructor
**********************************************************************************/
template<typename T>
QueueStatic<T>::QueueStatic( int s )
{
    num     =   0;
    _size   =   s;
    head    =   0;
    tail    =   0;
    
    data   =   new T[_size];
    
    ErrorExceptionMacro( data != NULL );
}


/*********************************************************************************
    destructor
 **********************************************************************************/
template<typename T>
QueueStatic<T>::~QueueStatic()
{
    delete  []  data;
    data    =   NULL;
    
    num     =   0;
    head    =   0;
    tail    =   0;
    _size    =   0;
}




/*********************************************************************************
    回傳循環的下一個位置
**********************************************************************************/
template<typename T>
int     QueueStatic<T>::next_index( int index )
{
    return  (index+1) % _size;
}


/*********************************************************************************
    push
 **********************************************************************************/
template<typename T>
bool    QueueStatic<T>::push( T d )
{
    if( num < _size )
    {
        data[tail]  =   d;
        tail        =   next_index( tail );
        return  true;
    }
    else
    {
        error_msg( "queue is full." );
        return  false;
    }
}


/*********************************************************************************
     init
**********************************************************************************/
template<typename T>
void    QueueStatic<T>::init( int s )
{
    _size   =   s;
    head    =   0;
    tail    =   0;
    
    data    =   new T[_size];
    
    ErrorExceptionMacro( data != NULL );
}
    
    
    
/*********************************************************************************
    destroy
**********************************************************************************/
template<typename T>
void    QueueStatic<T>::destroy()
{
    delete  []  data;
    data    =   NULL;
    
    _size   =   0;
    head    =   0;
    tail    =   0;
}
    
    
    
    
/*********************************************************************************
     pop
**********************************************************************************/
template<typename T>
T   QueueStatic<T>::pop()
{
    if( _size <= 0 )
    {
        error_msg( "queue is empty." );
        return  0;
    }
    
    T   tmp;
    
    tmp     =   data[head];
    head    =   next_index( head );
    
    return  tmp;
}
    
    

/*********************************************************************************
    top
 **********************************************************************************/
template<typename T>
T    QueueStatic<T>::top( )
{
    ErrorExceptionMacro( _size > 0 );
    
    return  data[ head ];
}



    
    
// use macro to general
template class	QueueStatic<int>;



    
    
}   // end namespace container
}   // end namespace hidog



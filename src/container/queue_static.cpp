#include "queue_static.h"

/*********************************************************************************
    constructor
**********************************************************************************/
//template<typename T>
QueueStatic/*<T>*/::QueueStatic()
{
    num     =   0;
    size    =   0;
    head    =   0;
    tail    =   0;
    *data   =   NULL;
}



/*********************************************************************************
    constructor
**********************************************************************************/
//template<typename T>
QueueStatic/*<T>*/::QueueStatic( int _size )
{
    num     =   0;
    size    =   _size;
    head    =   0;
    tail    =   0;
    
    data   =   new int[size];
    
   // ErrorExceptionMacro( data != NULL );
}


/*********************************************************************************
    destructor
 **********************************************************************************/
//template<typename T>
QueueStatic/*<T>*/::~QueueStatic()
{
    delete  []  data;
    data    =   NULL;
    
    num     =   0;
    head    =   0;
    tail    =   0;
    size    =   0;
}




/*********************************************************************************
    回傳循環的下一個位置
**********************************************************************************/
//template<typename T>
int     QueueStatic/*<T>*/::next_index( int index )
{
    return  (index+1) % size;
}


/*********************************************************************************
    push
 **********************************************************************************/
//template<typename T>
bool    QueueStatic/*<T>*/::push( int d )
{
    if( num < size )
    {
        data[tail]  =   d;
        tail        =   next_index( tail );
        return  true;
    }
    else
    {
        //error_msg( "queue is full." );
        return  false;
    }
}




/*********************************************************************************
    top
 **********************************************************************************/
//template<typename T>
int    QueueStatic/*<T>*/::top( )
{
    return  data[head];
}



//template class	QueueStatic<int>;






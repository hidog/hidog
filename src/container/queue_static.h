/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
    利用array來實作queue
    沒辦法動態調整空間
 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#ifndef _QUEUE_STATIC_H
#define _QUEUE_STATIC_H



#include <iostream>
#include "../shared.h"


namespace   hidog
{
namespace   container
{





template< typename T>
class   QueueStatic
{

public:
    QueueStatic();
    QueueStatic( int s );           // constructor
    ~QueueStatic();
    
    void    init( int s );
    void    destroy();
    bool    push( T d );            // push
    T       top();
    T       pop();
    
    
private:
    int     num;                    // 元素數量
    int     _size;                   // 總數量
    int     head;                   // 利用頭尾 創造出循環的queue
    int     tail;
    
    T       *data;
    
    int     next_index( int index );     // 回傳循環的下一個位置
    
};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 利用macro來產生實體 俱現化等等
#define	hcQueueStaticTypeDefineMacro( type ) \
    template class	QueueStatic<type>; 


    

}   // end namespace container
}   // end namespace hidog
    
    

#endif
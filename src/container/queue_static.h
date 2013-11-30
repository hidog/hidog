/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
    利用array來實作queue
    沒辦法動態調整空間
 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>



template< typename T>
class   QueueStatic
{

public:
    QueueStatic();
    QueueStatic( int _size );       // constructor
    ~QueueStatic();
    
private:
    int     size;                   // 總大小
    int     head;                   // 利用頭尾 創造出循環的queue
    int     tail;
    
    T       *data;
    
};



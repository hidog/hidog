#include "vector_test.h"
#include "numeric/vector.h"


bool	vector_obj_test( int id )
{
	bool	is	=	false;
	int		i;

	switch(id)
	{
		case	0:
		{
			hidog::numeric::vector<int>		v(10);
			
			for( i = 0; i < 10; i++ )
				v(i)	=	i;

			is	=	true;
			for( i = 0; i < 10; i++ )
			{
				if( v(i) != i )
				{
					is	=	false;
					break;
				}
			}
			break;
		}

		case	1:
		{
			hidog::numeric::vector<int>		v1,	v2,	v3;

			v1.resize(10);
			v2.resize(10);
			for( i = 0; i < 10; i++ )
			{
				v1(i)	=	i;
				v2(i)	=	i;
			}

			v3	=	v1 + v2;

			is	=	true;
			for( i = 0; i < 10; i++ )
			{
				if( v3(i) != i+i )
				{
					is	=	false;
					break;
				}
			}
			break;
		}

		default:
			is	=	false;
	}

	return	is;
}



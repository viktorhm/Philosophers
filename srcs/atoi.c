
#include "philosophers.h"


int ft_atoi(char *str)
{
	int  i = 0 ;
	int result = 0 ;

	while(str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}

	if (result > 2147483647 || result < -2147483647)
		{
			return(ft_erreur());
		}

	return(result);
}
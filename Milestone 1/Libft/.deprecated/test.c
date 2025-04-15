#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
int	main()
{
	char	str[100] = "hello";
	char	*ptr;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char)*(len + 1));
	while(str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	printf("%s\n", ptr);
	//free(ptr);
}

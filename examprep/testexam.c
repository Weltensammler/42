#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	used[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		j = 1;
		while (j < 3)
		{
			i = 0;
			while (argv[j][i])
			{
				if (!used[(unsigned char)argv[j][i]])
				{
					used[(unsigned char)argv[j][i]] = 1;
					write(1, &argv[j][i], 1);
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

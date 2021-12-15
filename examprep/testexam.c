#include <unistd.h>

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned char	used[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		j = 2;
		while (j > 0)
		{
			i = 0;
			while (argv[j][i])
			{
				if (!used[(unsigned char)argv[j][i]] && j == 2)
					used[(unsigned char)argv[j][i]] = 1;
				if (used[(unsigned char)argv[j][i]] == 1 && j == 1)
				{
					used[(unsigned char)argv[j][i]] = 2;
					write(1, &argv[j][i], 1);
				}
				i++;
			}
			j--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

# include <unistd.h>
# include <stdio.h>

// void	bubblesort(int *array, int size)
// {
// 	int	a;
// 	int	b;
// 	int temp;

// 	a = 0;
// 	b = 1;
// 	while (a < size)
// 		printf("%i\n", array[a++]);
// 	a = 0;
// 	while (b != 0)
// 	{
// 		b = 0;
// 		while (a < size)
// 		{
// 			if (array[a] > array[a + 1] && a + 1 < size)
// 			{
// 				temp = array[a + 1];
// 				array[a + 1] = array[a];
// 				array[a] = temp;
// 				b++;
// 			}
// 			a++;
// 		}
// 		a = 0;
// 	}
// }

// int	main(void)
// {
// 	int	j;
// 	int	arraya[] = {200, 10, -500, 30, 23, 66, -700, 800, 5, 9};
// 	int	arrayb[] = {200, 10, -500, 30, 23, 66, -700, 800, 5, 9};

// 	j = 0;
// 	while (j < 10)
// 	{
// 		printf("%i	%i\n", arrayb[j], arraya[j]);
// 		j++;
// 	}
// 	j = 0;
// 	bubblesort(arrayb, (10));
// 	while (j < 10)
// 	{
// 		printf("%i	%i\n", arrayb[j], arraya[j]);
// 		j++;
// 	}
// }

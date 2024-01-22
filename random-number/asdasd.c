#include "header.h"

void random_sayi_uret(float dizi[], int boyut)
{
    int i = 0;
    time_t t;
    srand((unsigned int)time(&t));
    while(i < boyut)
    {
        dizi[i] = -1.0 + (float)rand() / RAND_MAX * 2.0;
        i++;
    }
}

void bubble_sort(float dizi[], int boyut)
{
	float temp;
	int i = 0;
	while (i < boyut - 1)
	{
    	int j = 0;
		while (j < boyut - i - 1)
		{
      		if (dizi[j] > dizi[j + 1])
			{
        	temp = dizi[j];
        	dizi[j] = dizi[j + 1];
        	dizi[j + 1] = temp;
      	}
      	j++;
    }
    i++;
  }
}

void uret_ve_sirala(float dizi[], int boyut)
{
	random_sayi_uret(dizi, boyut);
	bubble_sort(dizi, boyut);
}

int main(int argc, char *argv[])
{
	int boyut;
	float *dizi;
	FILE *dosya;
	int	i = 0;

	if (argc != 3)
	{
  		printf("Kullanim Su Sekildedir: %s <eleman_sayisi> <bosluk> <dosya_adi>\n", argv[0]);
  		return 1;
	}
	
	boyut = atoi(argv[1]);
	dizi = (float *)malloc(boyut * sizeof(float));
	uret_ve_sirala(dizi, boyut);
	dosya = fopen(argv[2], "w");

	while (i < boyut)
	{
		fprintf(dosya, "%.2f\n", dizi[i]);
		i++;
	}

	fclose(dosya);
	free(dizi);
	return 0;
}
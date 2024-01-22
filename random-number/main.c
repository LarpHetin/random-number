#include "header.h"

void random_sayi_uret(float dizi[], int boyut)
/*C'de rastgele sayı üretmek için rand() fonksiyonunu kullanırız. rand() fonksiyonu 0 ve RAND_MAX aralığında rastgele üretir
srand() fonksiyonu, rand() fonksiyonunun üreteceği rastgele sayı dizisini başlatmak için kullanılır.
Bu fonksiyona, rastgele sayı dizisini başlatmak için kullanmak istediğimiz değeri veririz.*/
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
/*Bubble sort, dizideki iki elemanı karşılaştırır ve büyük olan eleman küçük olan elemanın önüne geçer. Bu sekilde dizinin tamamını ikili ikili kontrol ederek sıralama yapar.*/
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
/*Üret ve sirala fonksiyonu sırasıyla sayı üretme fonksiyonumuzu ve ardından üretilen sayıları sıralayacak olan Bubble Sort fonksiyonumuzu çağırır.*/
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
	/*atoi() fonksiyonu, komut satırından gelen stringi bir tam sayıya dönüştürmek için kullanılır. Bu kodda, argc değişkeni, komut satırından gelen argüman sayısını belirtir. 
	argc değişkeninin değeri 3 ise, argv[1] değişkeni, dizinin eleman sayısını belirtir. argv[1] değişkeni, bir stringdir. 
	atoi() fonksiyonunu kullanarak, argv[1] değişkenini bir tam sayıya dönüştürebiliriz. Ayrıca açılımı "ASCII to Integer"dır*/
	boyut = atoi(argv[1]);
	dizi = (float *)malloc(boyut * sizeof(float));
	uret_ve_sirala(dizi, boyut);
	dosya = fopen(argv[2], "w");
	/*fopen() fonksiyonu, bir dosya açmak için kullanılır. Bu fonksiyona, dosyanın adını ve açmak istediğimiz dosyanın modunu veririz.
	Burada, fopen() fonksiyonuna, "w" modu verdik. "w" modu, dosyayı yazmak için kullanılır.
	Bu nedenle, bu kod, argv[2] değişkenindeki değeri kullanarak, "w" modunda bir dosya açar.
	Örneğin, argv[2] değişkeninin değeri "dosya.txt" ise, fopen() fonksiyonu, dosya.txt dosyasını açar. Bu dosya, içerisine veri yazmak için kullanılabilir.*/
	while (i < boyut)
	{
		fprintf(dosya, "%.2f\n", dizi[i]);
		i++;
	}

	fclose(dosya);
	free(dizi);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* Korisnik_Format_IN = "%[^|]|%[^|]|%[^|\n]\n";
const char* Korisnik_Format_OUT = "%s|%s|%s\n";


typedef struct
{
	char ime[20];
	char prezime[20];
	char broj[20];

}TKontakt;

int main()
{

TKontakt prvi =
{

   "Milan",
   "Milanko",
   "0648453740"

};

FILE *file;

file = fopen("Kontakti.txt", "w+");

if(file == 0)
{
	return 1;
}

fprintf(file, Korisnik_Format_OUT, prvi.ime, prvi.prezime, prvi.broj);
fseek(file, 0, SEEK_SET);
fscanf(file, Korisnik_Format_IN, prvi.ime, 20, prvi.prezime, prvi.broj);

}

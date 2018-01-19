#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

void hilangplus(char* text, char* tambah)
// Menghilangkan tanda plus
{
  int c, d;
  c = 0; d = 0;

  while(text[c] != '\0')
  {
    while ((text[c] == '+') && (text[c] != '\0'))
    {
      c++;
    }
    tambah[d] = text[c];
    c++;
    d++;
  }
  tambah[d] = '\0';
  strcpy(text, tambah);
}

void hilangduplikat(char* text, char* temp)
// Menghilangkan duplikasi huruf pada suatu string string
{
  int i, j, k;

  i = 0; k = 0;
  while(i <= strlen(text)-1)
  {
    j = 0;
    while (j < i)
    {
      if ((text[i] == text[j]) && (i <= strlen(text)-1))
      {
        i++;
        j=0;
      }
      else
      {
        j++;
      }
    }
    if (i <= strlen(text)-1)
    {
      temp[k] = text[i];
      k++;
      i++;
    }
  }
  temp[k] = '\0';
  strcpy(text, temp);
}

void sambung(char* huruf, char a[])
// Menyambungkan 2 huruf dan menghilangkan duplikasi huruf
{
  char temp[10];
  strcat(huruf, a);
  hilangduplikat(huruf, temp);
}

void swap(int *a, int *b)
// Menukarkan 2 integer
{
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}

bool blmselesai(int a[], int n)
{
// Menentukan apakah semua kemungkinan permutasi sudah dilakukan
 int i;
 for(i=0; i<n; i++)
 {
   if (a[i] < a[i+1])
   {
     return true;
   }
 }
 return false;
}

void get_i_j (int a[], int *i, int *j, int n)
// menentukan indeks "i" dan "j" sebuah indeks yang akan digunakan dalam permutasi
{
 int k;
 *i = 0;
 *j = 0;

 for (k = 0; k < n; k++)
 {
   if (a[k] < a[k+1])
   {
     *i = k;
   }
 }

 for(k = *i+1; k <= n; k++)
 {
   if (a[*i] < a[k])
   {
     *j = k;
   }
 }
}

void reverse (int a[], int i, int n)
// Membalikkan angka-angka dalam suatu array dari indeks ke "i" sampai "n"
{
 int b[10];
 int j, k, pivot;

 k = i;
 j = n;
 while(k < j)
 {
   swap(a[k], a[j]);
   k++;
   j--;
 }
}

int hitung(char a[], char huruf[], int id[])
// Mengonversi huruf menjadi angka
{
  int id_a[10];
  int i, j, k, sum;
  sum = 0;
  for(i = 0; i <= strlen(a)-1; i++)
  {
    j = 0;
    while(a[i] != huruf[j])
    {
      j++;
    }
    id_a[i] = id[j];
    sum = sum * 10 + id_a[i];
  }
  return sum;
}

bool tidaknol(char a[], char huruf[], int id[])
// Mengecek apakah hasil konversi dari char paling awal dari "huruf" tidak bernilai 0
{
  bool kode;
  int i;
  i=0;
  kode = true;
  while(a[0] != huruf[i])
  {
    i++;
  }
  if (id[i]==0)
  {
    kode = false;
  }
  return kode;
}
void permutasi(int count, char soal1[], char soal2[], char soal3[], char soal4[], char soal5[], char hasil[], char huruf[], int id[])
// Melakukan operasi permutasi dan mencari solusi dari persoalan cryptarithmetic
{
  int i, j;
  bool ketemu;
  ketemu = false;

  while ((blmselesai(id, 9)) && (!ketemu))
  {
    get_i_j (id, &i, &j, 9);
    swap(id[i], id[j]);
    reverse(id, i+1, 9);
    if (count == 5)
    {
      if (hitung(soal1, huruf, id) + hitung(soal2, huruf, id) + hitung(soal3, huruf, id) + hitung(soal4, huruf, id) +
      hitung(soal5, huruf, id) == hitung(hasil, huruf, id) && tidaknol(soal1, huruf, id) && tidaknol(soal2, huruf, id) &&
      tidaknol(soal3, huruf, id) && tidaknol(soal4, huruf, id) && tidaknol(soal5, huruf, id) && tidaknol(hasil, huruf, id))
      {
        ketemu = true;
      }
    }
    else if (count == 4)
    {
      if (hitung(soal1, huruf, id) + hitung(soal2, huruf, id) + hitung(soal3, huruf, id) + hitung(soal4, huruf, id) ==
      hitung(hasil, huruf, id) && tidaknol(soal1, huruf, id) && tidaknol(soal2, huruf, id) && tidaknol(soal3, huruf, id)
      && tidaknol(soal4, huruf, id) && tidaknol(hasil, huruf, id))
      {
        ketemu = true;
      }
    }
    else if (count == 3)
    {
      if (hitung(soal1, huruf, id) + hitung(soal2, huruf, id) + hitung(soal3, huruf, id) == hitung(hasil, huruf, id)
      && tidaknol(soal1, huruf, id) && tidaknol(soal2, huruf, id) && tidaknol(soal3, huruf, id) && tidaknol(hasil, huruf, id))
      {
        ketemu = true;
      }
    }
    else
    {
      if (hitung(soal1, huruf, id) + hitung(soal2, huruf, id) == hitung(hasil, huruf, id) &&
      tidaknol(soal1, huruf, id) && tidaknol(soal2, huruf, id) && tidaknol(hasil, huruf, id))
      {
        ketemu = true;
      }
    }
  }
  if(ketemu)
  {
    cout<<"Solusi dari soal : "<<endl;
    cout<<hitung(soal1, huruf, id)<<endl;
    cout<<hitung(soal2, huruf, id)<<endl;
    if(count >= 3)
    {
      cout<<hitung(soal3, huruf, id)<<endl;
      if(count >= 4)
      {
        cout<<hitung(soal4, huruf, id)<<endl;
        if(count >= 5)
        {
          cout<<hitung(soal5, huruf, id)<<endl;
        }
      }
    }
    cout<<endl;
    cout<<hitung(hasil, huruf, id)<<endl;
    for(i=0; i<=strlen(huruf)-1; i++)
    {
      cout<<huruf[i]<<" = "<<id[i];
      cout<<endl;
    }
  }
  else
  {
    cout<<"Tidak ada solusi"<<endl;
  }
}

int main ()
{
  clock_t tStart = clock();
  int k;
  char soal1[10], soal2[10], soal3[10], soal4[10], soal5[10];
  char hasil[10], huruf[10], temp[10];
  int count; // untuk menghitung banyaknya "kata" yang dijumlahkan
  int id[10];
  ifstream infile;

  infile.open("input1.txt");
  infile >> soal1;
  infile >> soal2;

  count = 2;
  // mengolah kata yang terdapat pada file eksternal
  // asumsi jumlah maksimal kata yang dijumlahkan ada 5
  if (soal2[strlen(soal2)-1] == '+')
  {
    hilangplus(soal2, temp);
  }
  else
  {
    infile >> soal3;
    if (soal3[strlen(soal3)-1] == '+')
    {
      hilangplus(soal3, temp);
      count = 3;
    }
    else
    {
      infile >> soal4;
      if (soal4[strlen(soal4)-1] == '+')
      {
        hilangplus(soal4, temp);
        count = 4;
      }
      else
      {
        infile >> soal5;
        hilangplus(soal5, temp);
        count = 5;
      }
    }
  }

  infile >> hasil;
  infile >> hasil;
  // inisialisasi id dengan 0 1 2 3 4 5 6 7 8 9
  for(k=0; k<=9; k++)
  {
    id[k]=k;
  }
  strcpy(huruf, soal1);
  sambung(huruf, soal2);
  if (count == 3)
  {
    sambung(huruf, soal3);
  }
  else if (count == 4)
  {
    sambung(huruf, soal3);
    sambung(huruf, soal4);
  }
  else if (count == 5)
  {
    sambung(huruf, soal3);
    sambung(huruf, soal4);
    sambung(huruf, soal5);
  }
  sambung(huruf, hasil);
  permutasi(count, soal1, soal2, soal3, soal4, soal5, hasil, huruf, id);

  cout<<"Waktu eksekusi : "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<" detik."<<endl;
  infile.close();

  return 0;
}

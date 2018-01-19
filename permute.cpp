#include <iostream>
#include <cstring>

using namespace std;

 void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

bool blmselesai(int a[], int n)
{
  int i;
  for(i=0; i<=n; i++)
  {
    if (a[i] < a[i+1])
    {
      return true;
    }
  }
  return false;
}

void get_i_j (int a[], int *i, int *j, int n)
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

int main ()
{
  int data[10];
  int i, j, k, count;

  data[0]=1; data[1]=0;
  for(k=2; k<=9; k++)
  {
    data[k]=k;
  }
  count = 1;
  while (blmselesai(data, 9))
  {
    count++;
    for(k=0; k<=9; k++)
    {
      cout<<data[k];
    }
    cout<<endl;
    get_i_j (data, &i, &j, 9);
    swap(data[i], data[j]);
    reverse(data, i+1, 9);
  }
  cout<<count<<endl;
  cout<<strlen("")<<endl;
}

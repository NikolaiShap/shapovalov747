#include <stdio.h>
double quickSort(int *numbers, int left, int right)
{
  int pivot; 
  int l_hold = left;
  int r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right)){
      right--;        
    }
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right)){
      left++;

    }
    
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}
int main()
{
    int f =0;
scanf("%d",&f);
int n[f];
for (int j = 0;j <f;j++)
{
scanf("%d",&n[j]);
} 
quickSort(n,0,f - 1);

for (int i = 0; i < f;i++)
printf("%d ",n[i]);
}


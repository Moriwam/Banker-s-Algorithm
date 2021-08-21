#include <stdio.h>
#include<stdlib.h>
int C[5][5], Mxcl[5][5], A[5];
int a[5] ;
int Mxrc[5], R[5], safe=0;
int c = 0, i, j, e, r, p, k = 1;
int main()
{
freopen("input.txt","r",stdin);
scanf("%d", &p);
for (i = 0; i < p; i++) {
R[i] = 1;
c++;
}
scanf("%d", &r);
for (i = 0; i < r; i++) {
scanf("%d", &Mxrc[i]);
}
for (i = 0; i < p; i++) {
for(j = 0; j < r; j++) {
scanf("%d", &Mxcl[i][j]);
}
}
for (i = 0; i < p; i++) {
for(j = 0; j < r; j++) {
scanf("%d", &C[i][j]);
}
}
printf("The resource of instances: ");
for (i = 0; i < r; i++) {
printf("%d ", Mxrc[i]);
}
printf("\n\nThe allocated resource table:\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
printf("%d\t", C[i][j]);
}

printf("\n");
}
printf("\n\nThe maximum resource table:\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
printf("%d\t", Mxcl[i][j]);
}
printf("\n");
}
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
a[j] += C[i][j];
}
}
printf("\nAllocated resources: ");
for (i = 0; i < r; i++) {
printf("%d\t", a[i]);
}
for (i = 0; i < r; i++) {
A[i] = Mxrc[i] - a[i];
}
printf("\nAvailable resources: ");
for (i = 0; i < r; i++) {
printf("%d\t", A[i]);
}
//checking for unsafe state.
while (c != 0)
{
safe = 0;
for (i = 0; i < p; i++)
{
if (R[i])
{
e = 1;
for (j = 0; j < r; j++)
{
if (Mxcl[i][j] - C[i][j] > A[j])
{
e = 0;
break;

}
}
if (e)
{
printf("\n\n\nProcess%d is executing ", i + 1);
R[i] = 0;
c--;
safe = 1;
for (j = 0; j < r; j++)
{
A[j] += C[i][j];
}
break;
}
}
}
if (!safe)
{
printf("\nThe processes are in unsafe state.\n\n");
break;
}
else
{
printf("and the process is in safe state");
printf("\nSafe sequence is: ");
for (i = 0; i < r; i++)
{
printf("%d\t", A[i]);
}
}
}
printf("\n\n");
return 0;
}
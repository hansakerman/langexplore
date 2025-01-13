/* for.c */
#include<stdio.h>
#include<assert.h>
#define F fflush(stdout)
#define P printf

void multi(int t, int v)
{
  int result;
  
  result = t * v;
  P("%d x %d = %d\n",t,v,result);
  return;
}
int main()
{
  int x, table;
  
  P("Select multuplication table: ");F;
  scanf("%d",&table);
  // Fault handling and check some business logic 
  assert((table<13)&&(table>0));

  for(x=0; x<13; x++)
    {
      multi(table,x);
    }

  return 0;
}

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	    int pno;
	        int pri;
		    int btime;
		        int wtime;
} sp;
int main()
{
	    int i,j,n;
	        int tbm=0,totwtime=0,totttime=0;
		    sp *p,t;
		        printf("\nPRIORITY SCHEDULING : \n");
			    printf("\nEnter the no of process :-\n");
			        scanf("%d",&n);
				    p=(sp*)malloc(sizeof(sp));
				        printf("Enter the burst time and priority : - \n");
					    for(i=0; i<n; i++)
						        {
								        printf("P%d:",i+1);
									               scanf("%d%d",&p[i].btime,&p[i].pri);
										                      p[i].pno=i+1;
												                     p[i].wtime=0;
														                }
					            for(i=0;i<n;i++)
							            {
									                   for(j=0;j<n;j++)
												                   {
															                   if(p[i].pri < p[j].pri) //Lower number == Higher Priority
																		                   {
																					                       t=p[i];
																							                           p[i]=p[j];
																										                       p[j]=t;
																												                       }
																	                   }
											           }
						                   printf("\nProcess#\tBurst time\tWaiting time\tTurnaround time\tPriority#\n");
								                  for(i=0;i<n;i++)
											              {
													                     totwtime+=p[i].wtime=tbm;
															                    tbm+=p[i].btime;
																	                   printf("\n%d\t\t%d",p[i].pno,p[i].btime);
																			                  printf("\t\t%d\t\t%d\t\t%d",p[i].wtime,p[i].wtime+p[i].btime,p[i].pri);
																					              }
										          totttime=tbm+totwtime;
											          printf("\nTotal waiting time:%d",totwtime);
												          printf("\nAverage waiting time:%f",(float)totwtime/n);
													          printf("\nTotal turnaround time:%d",totttime);
														          printf("\nAvg turnaround time:%f\n",(float)totttime/n);
															      return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int upol(int,int);

int main(int argc, char *argv[]) {
		int hour,timer,a,total,i,n,theseis,parking,used_theseis;
	char onoma[10],epitheto[15],car[20],number[9],apanthsh,reader;
	char buf[1000];
    char filename[40];
    char ch;
    int delete_line, temp = 1;
    used_theseis=0;
theseis=0;
parking=20;
	apanthsh='y';
while (apanthsh=='y')
{
    printf("                        #################################################\n");
	printf("                        ##                 CARS PARKING                ##\n");
	printf("                        #################################################\n");
	printf("                        ##                                             ##\n");
	printf("                        ##      1. gia kataxwrhsh                      ##\n");
	printf("                        ##                                             ##\n");
	printf("                        ##      2. gia diagrafh                        ##\n");
	printf("                        ##                                             ##\n");
	printf("                        ##      3. piasmenes theseis                   ##\n");
	printf("                        ##                                             ##\n");
    printf("                        ##      4. kataxwrhmenes theseis               ##\n");
    printf("                        ##                                             ##\n");
    printf("                        ##      5. emfanish 8esewn parkarismenwn       ##\n");
	printf("                        #################################################\n\n");
    printf("to parking exei %d theseis stathmeushs!!! \n\n",parking);
    printf("dialekse mia apo tis parapanw epiloges:");
      scanf("%d",&a);
      getchar();

      while((a==0) || (a>5))
        {
        printf("-------------------------------------------------\n");
        printf("lathos epilogh prospathhse ksana..\n");
        printf("-------------------------------------------------\n");
            printf("dialekse mia apo tis parapanw epiloges:");
      scanf("%d",&a);
      getchar();
        printf("-------------------------------------------------\n");
        }

      if(a==1){
                used_theseis++;
            parking--;
	FILE *fl;
	fl=fopen("car.txt","a+");
	printf("----------------------\n");
    printf("kataxwrhsh stoixeiwn\n");
    printf("----------------------\n");
      printf("onoma: ");
           fgets(onoma,10,stdin);
	  printf("epitheto: ");
	       fgets(epitheto,15,stdin);
   	  printf("marka autokinhtou: ");
	       fgets(car,20,stdin);
	  printf("aritmos pinakidas: ");
           fgets(number,9,stdin);
      printf("poses wres thele na xrhsimopoihsete to parking?\n");
           scanf("%d", &hour);
      total=upol(timer,hour);
      printf("h xrewsh gia autes tis wres einai: %d\n",total);

    time_t t;
	   n = 1;
	char ch='0';

	srand((unsigned) time(&t));
	   for( i =0 ; i < n ; i++ )
      printf("\n"); 
	  ch=getchar();
        fprintf(fl,"***************************************************\n");
    	fprintf(fl,"onoma: %s\n",onoma);
    	fprintf(fl,"epitheto: %s",epitheto);
    	fprintf(fl,"marka autokinhtou: %s\n",car);
    	fprintf(fl,"aritmos pinakidas: %s\n",number);
    	fprintf(fl,"oi wres pou epilekse einai %d\n",hour);
    	fprintf(fl,"h xrewsh gia autes tis wres einai: %d\n",total);
        fprintf(fl,"to autokinhto einai sthn thesh %d \n", rand() % 20);
        fprintf(fl,"***************************************************\n");
            fclose(fl);
            }
      else if(a==2){

	FILE *fl,*fl2;
    printf("Enter file name: ");
    scanf("%s", filename);
    //open file in read mode
    fl = fopen(filename, "r");
    ch = getc(fl);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fl);
    }
    rewind(fl);
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    fl2 = fopen("replica.c", "w");
    ch = 'a';
    while (ch != EOF)
    {
        ch = getc(fl);
        if (ch == '\n')
        {
            temp++;
        }
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fl2);
        }
    }
    fclose(fl);
    fclose(fl2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fl = fopen(filename, "r");
    ch = getc(fl);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fl);
    }
    fclose(fl);
      }
      //piasmenes theseis
 else if (a==3){
        theseis=parking-used_theseis;
        printf("oi piasmenes theseis einai %d\n",used_theseis);
        printf("oi eleutheres theseis einai %d\n",theseis);
}
     //kataxwrhmenes theseis
 else if (a==4){
        FILE *fl;
	fl=fopen("car.txt","r");

if (!fl){
    return 1;
}
while (fgets(buf,1000, fl)!=NULL)
    printf("%s",buf);
         fclose(fl);
}
 else if(a==5){
FILE *fl;
char filename[]="car.txt",line[200],search_string[]="thesh";
fl=fopen(filename,"r");
if(!fl)
{
perror("could not find the file");
exit(0);
}
while ( fgets ( line, 200, fl ) != NULL ){
if(strstr(line,search_string))
fputs ( line, stdout );
}
fclose ( fl );
 }
        printf("thes na sunexisoume: (y,n) \n");
scanf("%c",&apanthsh);
getchar();
}
{
      printf("euxaristoume polu!! antio..\n");
}

		 return 0;


}


	int upol(int timer, int hour)
	{
	if ((hour>=1) && (hour<=3)){
    	timer=hour * 3;
	}
	   else if (hour>=4){
		 timer=hour * 4;
	}
	return timer;
	}



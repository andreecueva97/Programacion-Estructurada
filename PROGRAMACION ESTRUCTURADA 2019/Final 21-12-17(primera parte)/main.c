#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void unificar (char *am,char *bm);
int main()
{
    unificar("comisionAM.csv","comisionBM.csv");
    return 0;
}
int algo(int numero_registro,char*);
void unificar (char *am,char *bm)///como tenia que hacer con el archivo y la estrucutura d edonde venia ?/// como lo conecto con la estructura?
{
    int i=0,j=0;
    char cA=0,cB=0;
    int nadaA=0;
    int nadaB=0;

    int nro_registroA=0;
    char *nombreA=NULL;
    char *apellidoA=NULL;

     int nro_registroB=0;
    char *nombreB=NULL;
    char *apellidoB=NULL;

    FILE*AM=fopen(am,"r");
    FILE*BM=fopen(bm,"r");
    FILE*arch=fopen("comisonABM.csv","w");

    if(arch==NULL||AM==NULL||BM==NULL)
    {
        return ;
    }

        fscanf(AM,"%d,",&nro_registroA);
        fscanf(BM,"%d,",&nro_registroB);

    while(nadaA!=EOF&&nadaB!=EOF)
    {


        if(((nro_registroA<nro_registroB||nro_registroA==nro_registroB)&&nadaA!=EOF)||nadaB==EOF)
        {
            if(algo(nro_registroA,"comisionABM.csv")!=1)
              {
              i=0;
              cA=getc(AM);
              nombreA = malloc(sizeof(char));
                      while(cA!=',')
                        {
                            *(nombreA+i)=cA;
                            i++;
                            nombreA=realloc(nombreA,sizeof(char)*(i+1));
                            cA=fgetc(AM);
                        }

                            *(nombreA+i)='\0';


                          i=0;
                          cA=fgetc(AM);
                          apellidoA= malloc(sizeof(char));
                        while(cA!='\n')
                            {

                            *(apellidoA+i)=cA;
                            i++;
                            apellidoA=realloc(apellidoA,sizeof(char)*(i+1));
                            cA=fgetc(AM);
                            }
                            *(apellidoA+i)='\0';

                fprintf(arch ,"%d,%s,%s\n",nro_registroA,nombreA,apellidoA);

                if(nro_registroA==nro_registroB)
                {
                    while(cB!='\n')
                    {
                        cB=getc(BM);
                    }
                    fscanf(BM,"%d,",&nro_registroB);
                }


                nadaA=fscanf(AM,"%d,",&nro_registroA);

              }

        }
        else
        if((nro_registroA>nro_registroB&&nadaB!=EOF)||nadaA==EOF)
        {
            if(algo(nro_registroB,"comisionABM.csv")!=1)
            {
                 j=0;
                 cB=getc(BM);
                 nombreB= malloc(sizeof(char));

            while(cB!=','&&cB!='\0')
            {
                *(nombreB+j)=cB;
                j++;
                nombreB=realloc(nombreB,sizeof(char)*(j+1));
                cB=fgetc(BM);
            }
            *(nombreB+j)='\0';


                j=0;
                cB=fgetc(BM);
                apellidoB= malloc(sizeof(char));

            while(cB!='\n')
            {

                *(apellidoB+j)=cB;
                j++;
                apellidoB=realloc(apellidoB,sizeof(char)*(j+1));
                cB=fgetc(BM);
            }
            *(apellidoB+j)='\0';

        fprintf(arch ,"%d,%s,%s\n",nro_registroB,nombreB,apellidoB);
        nadaB=fscanf(BM,"%d,",&nro_registroB);
            }
        }



    }



}

int algo(int numero_registro,char*arch)
{

    int nro_registroABM=0;
    FILE*AB=fopen(arch,"r");

 fscanf(AB,"%d,",&nro_registroABM);
    while(nro_registroABM!=EOF&&nro_registroABM!=0)
    {

            getc(AB);
            while((fgetc(AB))!='\n'||fgetc(AB)!='\0')
            {
             fgetc(AB);
            }

        if(numero_registro==nro_registroABM)
        {
            return 1;
        }
         fscanf(AB,"%d,",&nro_registroABM);
    }
    return 0;
}

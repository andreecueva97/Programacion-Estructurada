#include <stdio.h>
#include <stdlib.h>
/**
struct alumno{
    int registro;char*nombre;char*apellido;
};
struct s_nodo{
    struct alumno alumno;   struct s_nodo* izq;     struct s_nodo* der;
};typedef struct s_nodo* t_nodo;
void inorder(t_nodo arbol,FILE* archabm);
void agregar(t_nodo*arbol,struct alumno alumno);
int esta(t_nodo arbol,int alumno);
void unificar(char*am,char*bm);
int main()
{
    char*am="am.txt";
    char*bm="bm.txt";
    unificar(am,bm);
    return 0;
}

void unificar(char*am,char*bm){
    FILE* archam=NULL;archam=fopen(am,"r");
    t_nodo arbol=NULL;
    FILE* archbm=NULL;archbm=fopen(bm,"r");
    struct alumno alumnocomun;
    int c,i,n;char *pal=NULL;char*pal2=NULL;
    //para comision AM
    fscanf(archam,"%d,",&n);
    while(!feof(archam)){
        c=fgetc(archam);
        alumnocomun.registro=n;
        i=0;
        pal=malloc(sizeof(char));
        while(c!=','){
            pal[i]=c;
            i++;
            pal=realloc(pal,sizeof(char)*(i+1));
            c=fgetc(archam);
        }
        pal[i]='\0';
        printf("\n%s",pal);
        alumnocomun.nombre=pal;
        free(pal);
        //ahora con el apellido;
        c=fgetc(archam);
        i=0;
        pal=malloc(sizeof(char));
        while(c!='\n'){
            pal[i]=c;
            i++;
            pal=realloc(pal,sizeof(char)*(i+1));
            c=fgetc(archam);
        }
        pal[i]='\0';
        alumnocomun.apellido=pal;
        agregar(&arbol,alumnocomun);
        fscanf(archam,"%d,",&n);
    }
    fclose(archam);
    //PARA COMISION BM TENGO QUE VERIFICAR QUE NO ESTE EN ARBOL
    fscanf(archbm,"%d,",&n);
    while(!feof(archbm)){
        c=fgetc(archam);
        alumnocomun.registro=n;
        i=0;
        pal=malloc(sizeof(char));
        while(c!=','){
            pal[i]=c;
            i++;
            pal=realloc(pal,sizeof(char)*(i+1));
            c=fgetc(archam);
        }
        pal[i]='\0';
        printf("\n%s",pal);
        alumnocomun.nombre=pal;
        //ahora con el apellido;
        c=fgetc(archam);
        i=0;
        pal2=malloc(sizeof(char));
        while(c!='\n'){
            pal[i]=c;
            i++;
            pal2=realloc(pal2,sizeof(char)*(i+1));
            c=fgetc(archam);
        }
        pal2[i]='\0';
        printf("%s",pal2);
        alumnocomun.apellido=pal2;
        free(pal2);//o falso           1 verdadero
        if(esta(arbol,n)== 0){
            agregar(&arbol,alumnocomun);
        }
        fscanf(archbm,"%d,",&n);
    }
    printf("aca");
    fclose(archbm);
    FILE*archabm=NULL;archabm=fopen("comisionABM.txt","w");
    inorder(arbol,archabm);
    fclose(archabm);
}
void inorder(t_nodo arbol,FILE* archabm){
    if(arbol!=NULL){
        inorder(arbol->izq,archabm);
        fwrite(&(arbol->alumno).registro,sizeof(int),1,archabm);
        fprintf(archabm,",");
        fwrite((arbol->alumno).nombre,sizeof((arbol->alumno).nombre),1,archabm);
        fprintf(archabm,",");
        fwrite((arbol->alumno).apellido,sizeof((arbol->alumno).apellido),1,archabm);
        fprintf(archabm,"\n");
        inorder(arbol->der,archabm);
    }
}
void agregar(t_nodo*arbol,struct alumno alumno){
    if(*arbol==NULL){
        *arbol=malloc(sizeof(t_nodo));
        (*arbol)->alumno=alumno;
        (*arbol)->der=NULL;
        (*arbol)->izq=NULL;
    }
    else{
        if(alumno.registro<(((*arbol)->alumno).registro))
            agregar(&(*arbol)->izq,alumno);
        else{
            agregar(&(*arbol)->der,alumno);
        }
    }
}
int esta(t_nodo arbol,int alumno){
    if(arbol==NULL){
        return 0;
    }
    else{
        if(alumno==(arbol->alumno).registro)
            return 1;
        else{
            if(alumno<(arbol->alumno).registro)
                return esta(arbol->izq,alumno);
            else
                return esta(arbol->der,alumno);
        }
    }
}**/
/**3 .2 **//**
struct s_nota{
    int valor;
    strcut s_nota*sig;
};typedef struct s_nota* t_nota;

struct s_alu{
    char*apellido;
    t_nota lstNota;
    struct s_alu*sig;
};typedef struct s_alu* t_alu;

void listado(t_alu listadoalumnos){
    t_alu listadonuevo=NULL;
    modificar(&listadonuevo,listadoalumnos)
    imprimir();
}
void modificar(t_alu* listadonuevo,t_alu listadoalumnos){
    if(listadoalumnos!=NULL){
        int sum=0;int cant=0;
        sum=suma(listadoalumnos->lstNota);
        cant=cantidad(listadoalumnos->lstNota);
        insertar(listadonuevo,sum/cant,listadoalumnos.apellido);
        modificar(listadonuevo,listadoalumnos->sig);
    }
}
int suma(t_nota notas){
    if(notas!=NULL){
        return notas.valor+ suma(notas->sig);
    }
    else{
        return 0;
    }
}
int cantidad(t_nota notas){
    if(notas!=NULL){
        return 1+ suma(notas->sig);
    }
    else{
        return 0;
    }
}**/
/**                 2.1              **/
/****/
    /**                          **//**
struct vendedor{
    int id;
    char nombre[30];
    int obj;
    double sueldoanual;
};
struct snodo{
    struct vendedor vendedor;
    struct snodo* izq;
    struct snodo* der;
};typedef struct snodo* t_nodo;
void cargarArbolVendedores(t_nodo* arbol,FILE* fVende);
void agregar(t_nodo* arbol,struct vendedor persona);
void inorder(t_nodo arbol);
int main(){
    FILE*fVende=NULL;
    fVende=fopen("vendedores.txt","r");
    t_nodo arbol=NULL;
    cargarArbolVendedores(&arbol,fVende);
    inorder(arbol);
    return 0;
}
void cargarArbolVendedores(t_nodo* arbol,FILE* fVende){
    struct vendedor persona;
    int n,c,i;double k;
    fscanf(fVende,"%d,",&n);
    while(n!=EOF){
        printf("%d",n);
        i=0;
        persona.id=n;
        c=fgetc(fVende);
        while(n!=','){
            (persona.nombre)[i]=c;
            i++;
            c=fgetc(fVende);
        }
        (persona.nombre)[i]='\0';
        fscanf(fVende,"%d,",&c);persona.obj=c;
        fscanf(fVende,"%lf\n",&k);
        (persona.sueldoanual)=k;
        agregar(arbol,persona);
        fscanf(fVende,"%d,",&n);
    }
    fclose(fVende);
}
void agregar(t_nodo* arbol,struct vendedor persona){
    if(*arbol==NULL){
        *arbol=malloc(sizeof(t_nodo));
        (*arbol)->vendedor=persona;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }else{
        if(persona.id<((*arbol)->vendedor).id){
            agregar(&(*arbol)->izq,persona);
        }
        else{
            agregar(&(*arbol)->der,persona);
        }
    }
}
void inorder(t_nodo arbol){
    printf("aca");
    if(arbol!=NULL){
        printf("aca1");
        inorder(arbol->izq);
        printf("%d",(arbol->vendedor).id);
        inorder(arbol->der);
    }
}
**/
/****//**
int liquidar(t_nodo arbol, int idVen){
    FILE* arch=NULL;arch=fopen("ventas.dat","rb");
    struct vendedores a;int i=0;
    fread(&a,sizeof(struct vendedores),1,arch);
    while(!feof(arch)){
        if(a.id==idVen){
            i=i+a.cantidadTarjetas;
        }
        fread(&a,sizeof(struct vendedores),1,arch);
    }
    buscarVendedor(idVen,i,arbol);
}
void buscarVendedor(idVen,i,arbol){
    if(arbol!=NULL){
        buscarVendedor(idVen,i,arbol->izq);
        if((arbol->vendedor).id==idVen){
            //printf
        }
        buscarVendedor(idVen,i,arbol->der);
    }
}**/
/**            3.1            **/
           /**    **//**
struct s_indice{
    int ini;
    int fin;
};typedef struct s_indice t_indice;
t_indice buscarSub(char* str,char* sub){
    int band=1;t_indice val;//true
    int i=0,e;
    while(str[i]!='\0'){
        if(str[i]==sub[0]){
            printf("aca");
            band=1;e=0;
            while(sub[e]!='\0'){
                if(sub[e]!=str[i+e]){
                    band=0;//false
                }
                e++;
            }
            if(band==1){
                val.ini=i;val.fin=e+i-1;
                return val;
            }
        }
        i++;
    }
    val.ini=-1;val.fin=-1;
    return val;
}
int main(){
    char*str="la verdad absoluta no existe, y esto es absolutamente cierto.";
    char*sub="r";
    printf("\n%d,%d",buscarSub(str,sub).ini,buscarSub(str,sub).fin);
    return 0;
}
**/
/**      febrero 2011    **/
/**
struct pa{
    int pelicod,actorcod;
};
funcion(int actorcod){
    FILE* arch=fopen("peliculas_actores.txt","r");
    struct pa valor;int *arr=NULL;
    fscanf(arch,"%d,%d\n",&valor.pelicod,&valor.actorcod);
    arr=malloc(sizeof(int));int i=0;
    while(!feof(arch)){
        if(valor.actorcod==actorcod){
            arr[i]=valor.pelicod;
            i++;
            arr=realloc(arr,sizeof(int)*(i+1));
        }
        fscanf(arch,"%d,%d\n",&valor.pelicod,&valor.actorcod);
    }
    arr[i]=0;int* arrfinal=NULL;arrfinal=malloc(sizeof(int));
    rewind(arch);i=0;int e,k=0;
    while(arr[i]!=0){
        e=0;
        fscanf(arch,"%d,%d\n",&valor.pelicod,&valor.actorcod);
        while(!feof(arch)){
            if(valor.pelicod==arr[i]){
                e++;
            }
            fscanf(arch,"%d,%d\n",&valor.pelicod,&valor.actorcod);
        }
        rewind(arch);
        if(e==1){
            arrfinal[k]=arr[i];
            k++;
            arrfinal=realloc(arrfinal,sizeof(int)*(i+1));
        }
        i++;
    }
    arrfinal[k]=0;
    //imprimir el anio y nombre de pelicula
    fclose(arch);
    FILE*arch2=fopen("peliculas.dat","rb");int a;char n[80];int anio;
    fread(&a,sizeof(int),1,arch2);
    while(!feof(arch2)){
        k=0;
        fread(&n,sizeof(char)*80,1,arch2);
        fread(&anio,sizeof(int),1,arch2);
        while(arrfinal[k]!=0){
            if(a==arrfinal[k]){
                printf("%d",a);
                printf("%s",n);
                printf("%d",anio);
            }
            k++;
        }
        fread(&a,sizeof(int),1,arch2);
    }
}
/**    3.2    **//**
void funcion(char* apellido,int anio){
    int*codpeliculas=NULL;
    FILE*arch=fopen("actores.dat","rb");char* n;int s;
    FILE*arch2=fopen("peliculas_actores.txt","r");

    fread(n,sizeof(char)*50,1,arch);
    while(!feof(arch)){
        fread(n,sizeof(char)*50,1,arch);
        fread(&s,sizeof(int),1,arch);
        if(strcmp(n,apellido)!=0){//si esta ese apellido entra
            //fread(n,sizeof(char)*50,1,arch);
            //fread(&s,sizeof(char)*50,1,arch);
            int a,b;
            fscanf(arch2,"%d,%d\n",&a,&b);
            while(!feof(arch2)){
                if(b==s){//me quedo con a
                    int q,int anioo;char nom[80];
                    fread(&q,sizeof(int),1,arch3);
                    while(!feof(arch3)){
                        fread(&nom,sizeof(char)*80,1,arch3);
                        fread(&anioo,sizeof(int),1,arch3);
                        if(q==a && anioo<=anio){
                            //printf....
                        }
                        fread(&q,sizeof(int),1,arch3);
                    }
                    rewind(arch3);
                }
                fscanf(arch2,"%d,%d\n",&a,&b);
            }
            rewind(arch3);
        }
        fread(n,sizeof(char)*50,1,arch);
    }
}**/
int main(){
    printf("%d",2&&2);
    return 0;
}

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "rlutil.h"

void menu_principal(int vec[], int tam);
void lanzar_dados(int vec[], int tam);
void numeros_aleatorios();
void ordenar_dados();
void ronda(int num, int lanza, char vec[], int puntos);
void dados_v2();
void numeros_dadosv2();
void mostrar_vector(int vec[], int tam);
int puntaje_ronda();
bool funcion_escalera(int vec[], int tam);
bool sextetode6(int vec[], int tam);
bool funcion_sexteto(int vec[], int tam);
int trios (int vec [], int tam);
bool funcion_trios (int vec [], int tam);
int sexteto (int vec[], int tam);
int suma_dados (int vec[], int tam);
int puntaje_tiro(int vec[], int tam);
int puntaje_max_ronda (int vec [], int tam);
void vector0(int vec[], int tam);
bool jugada(int vec[], int tam);
void modo2jug (char vec1[], char vec2[], int tam1, int tam2, int dadosvector[], int tam3, int vec[], int tam);



void menu_principal(int vec[], int tam)
{
    int opcion;
    do
    {
        int escalera=false, sexteto_6=false, i;
        int puntaje[3], y, x, z, game, pto_ronda, puntaje_total=0,
                                                  puntaje_final, puntaje_maximo=0;

        int dados[6];
        char nombre1[15],max_jugador[15];
        char nombre2[15];

        rlutil::cls();
        rlutil::locate(35, 9);
        cout <<(char)218<<"--------------------------------------"<<(char)191<< endl;
        rlutil::locate(35, 11);
        cout <<"   1 - NUEVO JUEGO PARA 1 JUGADOR/A    " << endl;
        rlutil::locate(35, 12);
        cout <<"   2 - NUEVO JUEGO PARA 2 JUGADORES/AS " << endl;
        rlutil::locate(35, 13);
        cout <<"   0 - SALIR                           " << endl;
        rlutil::locate(35, 14);
        cout <<"                                       " << endl;
        rlutil::locate(35, 15);
        cout <<"       MAXIMA PUNTUACION  >> "<<vec[0]<<" pts."<< endl;
        rlutil::locate(35, 16);
        cout <<(char)192<<"--------------------------------------"<<(char)217<< endl;

        rlutil::locate(41, 17);
        cout << ">>";
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;
        rlutil::cls();


        switch (opcion)
        {
        case 0:
            rlutil::locate(35, 13);
            cout << "GRACIAS, VUELVA PRONTOS" << endl << endl;
            rlutil::anykey();
            return;
        case 1:
            rlutil::locate(41, 12);
            cout<<"INGRESE EL NOMBRE DEL JUGADOR/A"<<endl;
            rlutil::locate(41, 13);
            cin>>nombre1;
            rlutil::locate(41, 15);
            cout<<"INGRESE LA CANTIDAD DE RONDAS QUE DESEA JUGAR: "<<endl;
            rlutil::locate(41, 16);
            cin>>game;
            rlutil::cls();

            i=1;
            x=1;
            puntaje_total=0;
            for(y=0; y<game; y++) //rondas
            {
                for(z=0; z<3; z++) //lanzamientos
                {
                    rlutil::cls();
                    ronda(y+1, z+1, nombre1, puntaje_total);
                    lanzar_dados(dados, 6);
                    puntaje[z]=puntaje_tiro(dados, 6);
                    escalera=funcion_escalera(dados, 6);
                    sexteto_6=sextetode6 (dados,6);


                    if(escalera==true)
                    {
                        rlutil::locate(30,20);
                        cout<<"               ESCALERA!"<<endl;
                        rlutil::locate(30,21);
                        cout<<"        HAS GANADO LA PARTIDA!"<<endl;

                        rlutil::locate(1,30);
                        rlutil::anykey();
                        system("pause");
                        return;
                    }

                    if(sexteto_6==true)
                    {
                        rlutil::locate(32,19);
                        cout<<"SEXTETO DE 6. NO SUMAS PUNTOS ESTA RONDA :'("<<endl;
                        rlutil::locate(1,30);
                        system("pause");
                        break;
                    }

                    rlutil::locate(35,15);
                    jugada(dados, 6);

                    rlutil::locate(35,9);
                    cout<<"PUNTAJE DE LANZAMIENTO -- "<<puntaje[z]<<endl;

                    rlutil::locate(1,30);
                    system("pause");

                }//fin ronda

                rlutil::cls();
                pto_ronda=puntaje_max_ronda (puntaje, 3);
                rlutil::locate(30, 10);
                cout<<"---------------------------------------------"<<endl;
                rlutil::locate(30, 12);
                cout<<"PUNTAJE DE RONDA "<<y+1<< " -- "<<pto_ronda<<endl;
                puntaje_total+=pto_ronda;
                rlutil::locate(30, 14);
                cout<<"PUNTAJE ACUMULADO -- "<<puntaje_total;
                rlutil::locate(30, 16);
                cout<<"---------------------------------------------"<<endl;
                vector0(puntaje, 3);
                rlutil::locate(1,30);
                rlutil::anykey();
                system("pause");

                if(puntaje_total>=500)
                {
                    rlutil::locate(30, 8);
                    cout<<"LLEGASTE A 500 PUNTOS. HAS GANADO LA PARTIDA!";
                    rlutil::locate(1,30);
                    rlutil::anykey();
                    system("pause");
                    return;
                }

            }//FIN JUEGO

            rlutil::cls();
            if(vec[0]!=0)
            {
                if(puntaje_total>vec[0])
                {
                    vec[0]=puntaje_total;
                }
            }
            else
            {
                vec[0]=puntaje_total;
            }

            rlutil::locate(30, 10);
            cout<<"--------------------------------"<<endl;
            rlutil::locate(30, 12);
            cout<<nombre1<<endl;
            rlutil::locate(30, 14);
            cout<<"MAXIMO PUNTAJE: "<<puntaje_total<<endl;
            rlutil::locate(30, 16);
            cout<<"--------------------------------"<<endl;
            rlutil::anykey();

            break;

        case 2:
            modo2jug(nombre1, nombre2, 15, 15, dados, 6, vec, tam);
            break;
        default:
            rlutil::cls();
            rlutil::locate(35, 13);
            rlutil::setColor(rlutil::RED);
            cout << "--ESTA OPCION ES INCORRECTA--" << endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::WHITE);
        }
    }
    while(opcion!=0);
}

void numeros_aleatorios(int vec[],int tam)
{
    srand(time(NULL));
    for(int i=0; i<tam; i++)
    {
        vec[i]=1+rand()%6;
    }
/*
        vec[0]=2;
        vec[1]=2;
        vec[2]=2;
        vec[3]=2;
        vec[4]=2;
        vec[5]=2; */
}

void ordenar_dados(int vec[], int tam)
{
    int i, j, aux;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            if(vec[j]>vec[j+1])
            {
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
    }
}

void dados_v2(int x, int y) // Dibuja marco dados
{
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(x, y);
    cout<<(char)201<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)187<<endl;
    y++;
    rlutil::locate(x, y);
    cout<<(char)186<<"       "<<(char)186<<endl;
    y++;
    rlutil::locate(x, y);
    cout<<(char)186<<"       "<<(char)186<<endl;
    y++;
    rlutil::locate(x, y);
    cout<<(char)186<<"       "<<(char)186<<endl;
    y++;
    rlutil::locate(x, y);
    cout<<(char)200<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)188<<endl;
    x+=10;
}

void numeros_dadosv2(int num, int i, int j) //Dibuja numeros
{
    switch (num)
    {
    case 1:
        rlutil::setColor(rlutil::RED);
        rlutil::locate(i+2,j+1);
        cout<<"     "<<endl<<endl;
        rlutil::locate(i+2,j+2);
        cout<<"  "<<(char)254<<"  "<<endl;
        rlutil::locate(i+2,j+3);
        cout<<"     "<<endl<<endl;
        break;
    case 2:
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        rlutil::locate(i+2,j+1);
        cout<<(char)254<<endl;
        rlutil::locate(i+2,j+3);
        cout<<"    "<<(char)254<<endl;
        break;
    case 3:
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(i+2,j+1);
        cout<<(char)254<<endl;
        rlutil::locate(i+2,j+2);
        cout<<"  "<<(char)254<<"  "<<endl;
        rlutil::locate(i+2,j+3);
        cout<<"    "<<(char)254<<endl;
        break;
    case 4:
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(i+2,j+1);
        cout<<(char)254<<"   "<<(char)254<<endl;
        rlutil::locate(i+2,j+2);
        cout<<"     "<<endl<<endl;
        rlutil::locate(i+2,j+3);
        cout<<(char)254<<"   "<<(char)254<<endl;
        break;
    case 5:
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(i+2,j+1);
        cout<<(char)254<<"   "<<(char)254<<endl;
        rlutil::locate(i+2,j+2);
        cout<<"  "<<(char)254<<"  "<<endl;
        rlutil::locate(i+2,j+3);
        cout<<(char)254<<"   "<<(char)254<<endl;
        break;
    case 6:
        rlutil::setColor(rlutil::MAGENTA);
        rlutil::locate(i+2,j+1);
        cout<<(char)254<<"   "<<(char)254<<endl;
        rlutil::locate(i+2,j+2);
        cout<<(char)254<<"   "<<(char)254<<endl;
        rlutil::locate(i+2,j+3);
        cout<<(char)254<<"   "<<(char)254<<endl;
        break;
    }
}

void mostrar_vector(int vec[], int tam)//Funcion de control
{
    int a;
    cout<<"mostrando vector--------"<<endl;
    for(a=0; a<tam; a++)
    {
        cout<<vec[a]<<endl;
    }
}

void lanzar_dados(int vec[], int tam)
{
    int num;
    numeros_aleatorios(vec, tam);
    ordenar_dados(vec, tam);
    dados_v2(25, 10);
    numeros_dadosv2(num=vec[0],25,10);
    dados_v2(35, 10);
    numeros_dadosv2(num=vec[1],35,10);
    dados_v2(45, 10);
    numeros_dadosv2(num=vec[2],45,10);
    dados_v2(55, 10);
    numeros_dadosv2(num=vec[3],55,10);
    dados_v2(65, 10);
    numeros_dadosv2(num=vec[4],65,10);
    dados_v2(75, 10);
    numeros_dadosv2(num=vec[5],75,10);

    //ordenar_dados(vec, tam);

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(1, 25);
}

bool funcion_escalera(int vec[], int tam) //Analiza si hay escalera
{
    bool escalera=false;
    for(int i=0; i<tam-1; i++)
    {
        if(vec[i]<vec[i+1])
        {
            escalera=true;
        }
        else
        {
            escalera=false;
            break;
        }
    }

    return escalera;
}

void ronda(int num, int lanza, char vec[], int puntos)//Grafica
{
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(40, 3);
    cout<<"<<<    RONDA: "<<num<<"    >>>"<<endl;
    rlutil::locate(40, 4);
    cout<<"<<<    LANZAMIENTO N"<<(char)248<<lanza<<"    >>>"<<endl;
    rlutil::locate(40, 5);
    cout<<"<<<    TURNO DE "<<vec<<"    >>>"<<endl;
    rlutil::locate(40, 6);
    cout<<"<<<    PUNTAJE ACUMULADO: "<<puntos<<"    >>>"<<endl;
    rlutil::locate(1, 7);
    cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;

}

int trios (int vec [], int tam)//Busca trios, cuartetos, quintetos
{
    int i, j,
        contador,
        repe1 = 0,
        repe2 = 0,
        puntaje = 0;

    for (i = 0; i < tam; i++)
    {
        contador = 0;
        for (j = 0; j < tam; j++)
        {
            if (vec[i] == vec[j])
            {
                contador++;
            }
        }
        if (contador >= 3&& contador<6)
        {
            if (repe1 == 0)
            {
                repe1 = vec[i];
            }
            else if (repe1 != vec[i] && repe2 == 0)
            {
                repe2 = vec[i];
            }
        }
    }
    if (repe2 > repe1)
    {
        puntaje = repe2 * 10;
    }
    else if (repe1 > repe2)
    {
        puntaje = repe1 * 10;
    }

    return puntaje;
}

bool funcion_trios (int vec [], int tam)//Busca trios, cuartetos, quintetos
{
    int i, j, trio=false,
              contador,
              repe1 = 0,
              repe2 = 0;

    for (i = 0; i < tam; i++)
    {
        contador = 0;
        for (j = 0; j < tam; j++)
        {
            if (vec[i] == vec[j])
            {
                contador++;
            }
        }
        if (contador >= 3&& contador<6)
        {
            if (repe1 == 0)
            {
                repe1 = vec[i];
            }
            else if (repe1 != vec[i] && repe2 == 0)
            {
                repe2 = vec[i];
            }
        }
    }
    if (repe2>0||repe1>0)
    {
        trio=true;
    }

    return trio;
}

int sexteto(int vec[], int tam)// puntaje sexteto
{
    int sexteto=false;
    int puntaje=0;

    sexteto = funcion_sexteto(vec, tam);
    if(sexteto==true&&vec[0]!=6)
    {
        puntaje=vec[0]*50;
    }
    else
    {
        puntaje=0;
    }
    return puntaje;
}

bool sextetode6(int vec[], int tam)//Busca seis en sexteto
{
    bool sexteto=false;
    for(int z=0; z<tam-1; z++)
    {
        if(vec[z]==vec[z+1]&&vec[z]==6)
        {
            sexteto=true;
        }
        else
        {
            sexteto=false;
            break;
        }
    }
    return sexteto;

}

bool funcion_sexteto(int vec[], int tam)//Busca seis dados iguales
{
    bool sexteto=false;
    for(int z=0; z<tam-1; z++)
    {
        if(vec[z]==vec[z+1])
        {
            sexteto=true;
        }
        else
        {
            sexteto=false;
            break;
        }
    }
    return sexteto;

}

int suma_dados (int vec[], int tam)//Dados sin combinacion
{
    int puntaje=0;
    int suma=0;
    for(int j=0; j<tam; j++)
    {
        suma+=vec[j];
    }
    puntaje=suma;

    return puntaje;
}

int puntaje_tiro(int vec[], int tam)// Guarda puntaje adecuado
{
    int pto_trio;
    int pto_sexteto;
    int pto_suma;
    int pto_max=0;

    pto_trio=trios(vec,tam);
    pto_sexteto=sexteto(vec,tam);
    pto_suma=suma_dados(vec,tam);

    //corregir
    if(pto_sexteto==300)
    {
        pto_max=0;

    }
    else if(pto_sexteto>pto_trio)
    {
        pto_max=pto_sexteto;

    }
    else
    {
        pto_max=pto_trio;
    }

    if(pto_max>0)
    {
        pto_suma=0;

        //

    }
    else if(pto_suma>pto_max)
    {
        pto_max=pto_suma;
        if (pto_suma==36)
        {
            pto_max=0;
        }
    }
    return pto_max;
}

int puntaje_max_ronda (int vec[], int tam)//Compara puntaje tiros
{
    int max_ronda=vec[0];
    for (int i=1; i<tam; i++)
    {
        if (vec[i]>max_ronda)
        {
            max_ronda=vec[i];
        }
    }
    return max_ronda;
}

bool jugada(int vec[], int tam)
{
    bool jugada1=false, jugada2=false, jugada3=false;

    jugada1=funcion_escalera(vec, tam);
    jugada2=funcion_sexteto(vec, tam);
    jugada3=funcion_trios(vec, tam);

    if(jugada1==true)
    {
        cout<<"ESCALERA"<<endl;
    }
    else if(jugada2==true)
    {
        cout<<"HAS OBTENIDO UN SEXTETO!"<<endl;
    }
    else if(jugada3==true)
    {
        cout<<"HAS OBTENIDO UN TRIO!"<<endl;
    }
    else
    {
        cout<<"JUGADA SIN COMBINACIONES! SUMA LOS DADOS!"<<endl;
    }
}

void vector0(int vec[], int tam)//pone el vector en cero
{
    for (int i=0; i<tam; i++)
    {
        vec[i]=0;
    }
}

void modo2jug (char vec1[], char vec2[], int tam1, int tam2, int dadosvector[], int tam3, int maximo[], int tamax)
{
    int i, j, y;
    int game, escalera=false, sexteto_6=false;
    int puntaje_total1=0, puntaje_total2=0;
    int puntaje1[3], puntaje2[3];
    int pto_ronda;


    rlutil::locate(41, 12);
    cout<<"INGRESE EL NOMBRE DEL JUGADOR/A 1"<<endl;
    rlutil::locate(41, 13);
    cin>>vec1;
    rlutil::locate(41, 15);
    cout<<"INGRESE EL NOMBRE DEL JUGADOR/A 2: "<<endl;
    rlutil::locate(41, 16);
    cin>>vec2;
    rlutil::locate(41, 18);
    cout<<"INGRESE LA CANTIDAD DE RONDAS QUE DESEAN JUGAR: "<<endl;
    rlutil::locate(41, 19);
    cin>>game;
    rlutil::cls();

    for (i=0; i<game; i++)
    {
        for (j=0; j<3; j++)//player 1
        {
            ronda(i+1, j+1, vec1, puntaje_total1);
            lanzar_dados(dadosvector, tam3);

            puntaje1[j]=puntaje_tiro(dadosvector, tam3);
            escalera=funcion_escalera(dadosvector, tam3);
            sexteto_6=sextetode6 (dadosvector, tam3);

            if(escalera==true)
            {
                rlutil::locate(30,20);
                cout<<"               ESCALERA!"<<endl;
                rlutil::locate(34,21);
                cout<<vec1<<"   HA GANADO LA PARTIDA!"<<endl;

                rlutil::locate(1,30);
                rlutil::anykey();
                system("pause");
                return;
            }

            if(sexteto_6==true)
            {
                rlutil::locate(32,19);
                cout<<"SEXTETO DE 6. NO SUMAS PUNTOS ESTA RONDA :'("<<endl;
                rlutil::locate(1,30);
                system("pause");
                break;
            }

            rlutil::locate(35,15);
            jugada(dadosvector, tam3);

            rlutil::locate(35,9);
            cout<<"PUNTAJE DE LANZAMIENTO -- "<<puntaje1[j]<<endl;

            rlutil::locate(1,30);
            system("pause");
            rlutil::cls();
        }

        rlutil::cls();
        pto_ronda=puntaje_max_ronda(puntaje1, 3);
        rlutil::locate(30, 10);
        cout<<"---------------------------------------------"<<endl;
        rlutil::locate(30, 12);
        cout<<"PUNTAJE DE RONDA "<<i+1<< " -- "<<pto_ronda<<endl;
        puntaje_total1+=pto_ronda;
        rlutil::locate(30, 14);
        cout<<"PUNTAJE ACUMULADO -- "<<puntaje_total1;
        rlutil::locate(30, 16);
        cout<<"---------------------------------------------"<<endl;
        vector0(puntaje1, 3);
        rlutil::locate(1,30);
        rlutil::anykey();
        system("pause");

        if(puntaje_total1>=500)
        {
            rlutil::locate(30, 8);
            cout<<"LLEGASTE A 500 PUNTOS. �HAS GANADO LA PARTIDA!";

            rlutil::locate(1,30);
            rlutil::anykey();

            return;
        }
        rlutil::cls();


        for (y=0; y<3; y++)//player 2
        {

            ronda(i+1, y+1, vec2, puntaje_total2);
            lanzar_dados(dadosvector, tam3);

            puntaje2[y]=puntaje_tiro(dadosvector, tam3);
            escalera=funcion_escalera(dadosvector, tam3);
            sexteto_6=sextetode6 (dadosvector, tam3);

            if(escalera==true)
            {
                rlutil::locate(30,20);
                cout<<"               ESCALERA!"<<endl;
                rlutil::locate(34,21);
                cout<<vec2<<"    HA GANADO LA PARTIDA!"<<endl;

                rlutil::locate(1,30);
                rlutil::anykey();
                system("pause");

                return;
            }

            if(sexteto_6==true)
            {
                rlutil::locate(32,19);
                cout<<"SEXTETO DE 6. NO SUMAS PUNTOS ESTA RONDA :'("<<endl;
                rlutil::locate(1,30);
                system("pause");
                break;
            }

            rlutil::locate(35,15);
            jugada(dadosvector, tam3);

            rlutil::locate(35,9);
            cout<<"PUNTAJE DE LANZAMIENTO -- "<<puntaje2[y]<<endl;

            rlutil::locate(1,30);
            system("pause");
            rlutil::cls();
        }

        pto_ronda=puntaje_max_ronda (puntaje2, 3);
        rlutil::locate(30, 10);
        cout<<"---------------------------------------------"<<endl;
        rlutil::locate(30, 12);
        cout<<"PUNTAJE DE RONDA "<<i+1<< " -- "<<pto_ronda<<endl;
        puntaje_total2+=pto_ronda;
        rlutil::locate(30, 14);
        cout<<"PUNTAJE ACUMULADO -- "<<puntaje_total2;
        rlutil::locate(30, 16);
        cout<<"---------------------------------------------"<<endl;
        vector0(puntaje2, 3);
        rlutil::locate(1,30);
        rlutil::anykey();
        system("pause");

        if(puntaje_total2>=500)
        {
            rlutil::locate(30, 8);
            cout<<"LLEGASTE A 500 PUNTOS. HAS GANADO LA PARTIDA!";

            rlutil::locate(1,30);
            rlutil::anykey();
            system("pause");
            return;
        }
        rlutil::cls(); //puntaje preliminar
        rlutil::locate(30, 10);
        cout<<"---------------------------------------------"<<endl;
        rlutil::locate(30, 12);
        cout<<"FINAL DE RONDA "<<i+1<< " -- "<<endl;
        rlutil::locate(30, 14);
        cout<<vec1<<" >> "<<puntaje_total1<<endl;
        rlutil::locate(30, 16);
        cout<<vec2<<" >> "<<puntaje_total2<<endl;
        rlutil::locate(30, 18);
        cout<<"---------------------------------------------"<<endl;
        rlutil::anykey();
        rlutil::cls();
    }

    if(puntaje_total1>puntaje_total2)
    {
        rlutil::locate(35, 11);
        cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O"<<endl;
        rlutil::locate(41, 13);
        cout<<"GANADOR:    ";
        cout<<vec1<<endl;
        rlutil::locate(50, 15);
        cout<<puntaje_total1<<" PTS."<<endl;
        rlutil::locate(35, 17);
        cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O"<<endl;
        rlutil::anykey();
        if(maximo[0]!=0)
            {
                if(puntaje_total1>maximo[0])
                {
                    maximo[0]=puntaje_total1;
                }
            }
            else
            {
                maximo[0]=puntaje_total1;
            }
        rlutil::cls();
    }
    else if(puntaje_total2>puntaje_total1){
        rlutil::locate(35, 11);
        cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O"<<endl;
        rlutil::locate(41, 13);
        cout<<"GANADOR:    ";
        cout<<vec2<<endl;
        rlutil::locate(50, 15);
        cout<<puntaje_total2<<" PTS."<<endl;
        rlutil::locate(35, 17);
        cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O"<<endl;
        rlutil::anykey();
        rlutil::cls();
        if(maximo[0]!=0)
            {
                if(puntaje_total2>maximo[0])
                {
                    maximo[0]=puntaje_total2;
                }
            }
            else
            {
                maximo[0]=puntaje_total2;
            }
    }else{
        rlutil::locate(35, 11);
        cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O"<<endl;
        rlutil::locate(41, 13);
        cout<<"EMPATE!"<<endl;
        rlutil::locate(35, 15);
        cout<<"O-O-O-O-O-O-O-O-O-O-O-O-O-O-O"<<endl;
    }

}
#endif // FUNCIONES_H_INCLUDED


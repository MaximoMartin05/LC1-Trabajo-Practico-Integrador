#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Cliente
{
    int numCuenta;
    char nombre[50];
    int password[4];
    float saldo;
    char estado[10];
}

void main()
{

    struct Cliente clientes[10];
    char nombreingresado[50];
    int numCuentaIngresado, contraIngresada;
    int opcion, i= 0, j=0,  contadorPassword=0;
    int intentoInicioSesion = 3;
    bool encontradoCuenta = false;
    bool encontradoPassword = false;
    strcpy(clientes[0].nombre, "Juan");
    strcpy(clientes[0].password, "juanceto05");
    clientes[0].numCuenta = 101;
    clientes[0].saldo = 150000;
    strcpy(clientes[0].estado, " ");

    strcpy(clientes[1].nombre, "Juan");
    strcpy(clientes[1].password, "juanceto05");
    clientes[1].numCuenta = 110;
    clientes[1].saldo = 150000;
    strcpy(clientes[1].estado, " ");

    strcpy(clientes[2].nombre, "Juan");
    strcpy(clientes[2].password, "juanceto05");
    clientes[2].numCuenta = 120;
    clientes[2].saldo = 150000;
    strcpy(clientes[2].estado, " ");

    strcpy(clientes[3].nombre, "Juan");
    strcpy(clientes[3].password, "juanceto05");
    clientes[3].numCuenta = 130;
    clientes[3].saldo = 150000;
    strcpy(clientes[3].estado, " ");

    strcpy(clientes[4].nombre, "Juan");
    strcpy(clientes[4].password, "juanceto05");
    clientes[4].numCuenta = 140;
    clientes[4].saldo = 150000;
    strcpy(clientes[4].estado, " ");

    strcpy(clientes[5].nombre, "Juan");
    strcpy(clientes[5].password, "juanceto05");
    clientes[5].numCuenta = 150;
    clientes[5].saldo = 150000;
    strcpy(clientes[5].estado, " ");

    strcpy(clientes[6].nombre, "Juan");
    strcpy(clientes[6].password, "juanceto05");
    clientes[6].numCuenta = 160;
    clientes[6].saldo = 150000;
    strcpy(clientes[6].estado, " ");

    
    strcpy(clientes[7].nombre, "Juan");
    strcpy(clientes[7].password, "juanceto05");
    clientes[7].numCuenta = 170;
    clientes[7].saldo = 150000;
    strcpy(clientes[7].estado, " ");

    strcpy(clientes[8].nombre, "Juan");
    strcpy(clientes[8].password, "juanceto05");
    clientes[8].numCuenta = 180;
    clientes[8].saldo = 150000;
    strcpy(clientes[8].estado, " ");

    strcpy(clientes[9].nombre, "Juan");
    strcpy(clientes[9].password, "juanceto05");
    clientes[9].numCuenta = 190;
    clientes[9].saldo = 150000;
    strcpy(clientes[9].estado, " ");


    
    do
    {
        printf("Ingrese su numero de cuenta:\n");
        scanf("%i", &numCuentaIngresado);
        while (i < 10 && !encontradoCuenta )
        {
            if (clientes[i].numCuenta == numCuentaIngresado)
            {
                encontradoCuenta = true;
                printf("Ingrese la contrase%ca\n",165);
                scanf("%i", &contraIngresada);

                while ( !encontradoPassword && contadorPassword<3)
                {
                    if (clientes[i].password == contraIngresada)
                    {
                        encontradoPassword = true;    
                    }
                    contadorPassword++;
                    printf("Ingrese la contrase%ca\n",165);
                    scanf("%i", &contraIngresada);
                }
                

            }
            i++;
        }
        
    
    do
    {



        printf("1. Realizar un Depósito\n");
        printf("2. Realizar una Extracción\n");
        printf("3. Consultar el Saldo de la Cuenta\n");
        printf("4. Realizar una Transferencia entre Cuentas\n");
        printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
        printf("6. Salir de la Sesión\n");
        
        
        switch (opcion)
        {
        case 1:
            printf("Realizar un Depósito\n");

            break;
        case 2:
            printf(" Realizar una Extracción\n");
            break;
        case 3:
            printf("Consultar el Saldo de la Cuenta\n");
            break;
        case 4:
             printf("Realizar una Transferencia entre Cuentas\n");
            break;
        case 5:
             printf("Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
            break;
        
        }
    } while (opcion != 6);
    
    } while
}
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

void llenarVector(int vector[], int total) {
    // Número aleatorios entre 1 y 50000:
    for (int i = 0; i < total; i++)
        vector[i] = 1 + rand() % (50000);
}

void imprimirVector(int vector[], int total) {
    cout << "\nElementos del vector: \n";
    for (int i = 0; i < total; i++)
        cout << vector[i] << " ";
}

void intercambiar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void ordenSecuencial(int vector[], int total) {
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (vector[i] > vector[j])
                intercambiar(vector[i], vector[j]);
        }
    }
}

void OrdenamientoQuicksort(int a[], int primerValor, int ultimoValor) {
    int central, i, j, pivote;
    central = (primerValor + ultimoValor) / 2; //Posicion central del arreglo
    pivote = a[central]; //Capturar el valor medio del arreglo
    i = primerValor;
    j = ultimoValor;
    do {
        //Separando en dos partes el arreglo
        while (a[i] < pivote) i++; //Separando los valores menores al pivote
        while (a[j] > pivote) j--; //Separando los valores mayores al pivote
        if (i <= j) {
            int temporal;
            //Intercambio de valores
            temporal = a[i];
            a[i] = a[j];
            a[j] = temporal;
            i++;
            j--;
        }
    } while (i <= j);
    if (primerValor < j)
        OrdenamientoQuicksort(a, primerValor, j);
    if (i < ultimoValor)
        OrdenamientoQuicksort(a, i, ultimoValor);
}

void ordenShell(int a[], int n) {
    int ints, i, aux;
    bool band;
    ints = n;
    while (ints > 1) {
        ints = ints / 2;
        band = true;
        while (band == true) {
            band = false;
            i = 0;
            while ((i + ints) < n) {
                if (a[i] > a[i + ints]) {
                    aux = a[i];
                    a[i] = a[i + ints];
                    a[i + ints] = aux;
                    band = true;
                }
                i++;
            }
        }
    }
}

void ordenShell2(int a[], int n) {//optimizado
    int i, j, inc;
    int temp;
    for (inc = 1; inc < n; inc = inc * 3 + 1);
    while (inc > 0) {
        for (i = inc; i < n; i++) {
            j = i;
            temp = a[i];
            while ((j >= inc) && (a[j - inc] > temp)) {
                a[j] = a[j - inc];
                j = j - inc;
            }
            a[j] = temp;
        }
        inc = inc / 2;
    }
}

void ordenBurbuja(int v[], int n) {

    int i = 0, j = 0;
    int aux;
    for (i = 1; i < n; i++)
        for (j = 0; j < (n - i); j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
}

void burbujaMejorado(int arreglo[], int tamano) {
    int comparaciones = tamano;
    bool termino = false;
    for (int i = 0; i < (tamano - 1); i++) {
        if (termino)
            break;
        termino = true;
        for (int j = 0; j < comparaciones - 1; j++)
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(arreglo[j], arreglo[j + 1]);
                termino = false;
            }
        comparaciones--;
    }
}

void insercion(int A[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double) (a->QuadPart - b->QuadPart) / (double) freq.QuadPart;
}

//Búsqueda binaria. Si existe devuelve la posición del elemento encontrado.
//caso contario devuelve -1
int busquedaBinaria(int vector[], int tamanio, int num)
{
    int izq=0, der=tamanio;
    int central = (izq+ der)/2;

    while(izq < der && num!=vector[central])
    {
        if(num > vector[central])
            izq=central+1;
        else
            der=central-1;

        central = (izq + der)/2;
    }
    if(vector[central]==num)
        return central+1;
    else
        return -1; //no lo encontró
}

//se tiene un vector de n enteros. Se pide ordenarlos y devolver
//El valor máximo y el valor mínimo del vector.
void maximo_minimo(int vector[], int tamanio, int &max, int &min){
    ordenBurbuja(vector,tamanio);
    max=vector[tamanio-1];
    min=vector[0];
}

//Se tiene un vector que almacena las ciudades del mundo: Quito, Guayaquil, Cali
// Se tiene otro vector que almacena las tempaeraturas de estas cuidades.
//A cada ciudad le corresponde una temperatura
// Quito 17
// Guayaquil 23
// Esmeraldas 28
// Cali 18
// a) Si pide diseñar la función que ordene alfabéticamente por ciudades sin
// Olvidar la temperatura. Resultado esperado de esta ordenación:
// Cali 18
// Esmeraldas 28
// Guayaquil 23
// Quito 17

// b) Se pide diseñar la función que ordene por la temperatura ascendentemente.
// (conservando la ciudad). Resultado esperado:
// Quito 17
// Cali 18
// Guayaquil 23
// Esmeraldas 28
void Ordene_alfabeticamente (string vectora[], int vectorb[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vectora[i].compare(vectora[j]) > 0) {
                swap(vectora[i],vectora[j]);
                swap(vectorb[i], vectorb[j]);
            }
        }
    }
    for(int i=0; i<tamanio; i++){
        cout<<vectora[i]<<" "<<vectorb[i]<<endl;
    }
}
void Ordene_por_temperatura (string vectora[], int vectorb[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vectorb[i]>vectorb[j]) {
                swap(vectorb[i], vectorb[j]);
                swap(vectora[i],vectora[j]);
            }
        }
    }
    for(int i=0; i<tamanio; i++){
        cout<<vectora[i]<<" "<<vectorb[i]<<endl;
    }
}

int main() {
    srand(time(NULL));
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    int total=1000;
    int vectorSec[total];
    int vectorBurbuja[total];
    int vectorBurbujaMe[total];
    int vectorQuicksort[total];
    int vectorShell[total];
    int vectorShell2[total];

    int tam=10;
    int vector[tam]={10,50,7,78,90,8,77,105,221,45};
    ordenBurbuja(vector, 10);
    imprimirVector(vector,10);
    int x= busquedaBinaria(vector,10, 221);
    cout<<endl<<"Posicion del elemento: "<<x;

    int max, min;
    maximo_minimo(vector, tam, max, min);
    cout<<endl<<"Minimo: "<<min<<endl;
    cout<<"Maximo: "<<max<<endl;

    int espacio=4;
    string vectora[espacio]={"Guayaquil", "Esmeraldas", "Cali", "Quito"};
    int vectorb[espacio]={23,28,18,17};
    cout<<"----Orden Alfabeticamente----"<<endl;
    Ordene_alfabeticamente(vectora, vectorb, espacio);
    cout<<"----Orden Por Temperatura----"<<endl;
    Ordene_por_temperatura(vectora, vectorb, espacio);







    // Número aleatorios entre 1 y 50000:
    for (int i = 0; i < total; i++){
        int elemento = 1 + rand() % (50000);
        vectorSec[i]=elemento;
        vectorBurbuja[i]=elemento;
        vectorBurbujaMe[i]=elemento;
        vectorQuicksort[i]=elemento;
        vectorShell[i]=elemento;
        vectorShell2[i]=elemento;
    }

    //Ordenación Secuencial
    QueryPerformanceCounter(&t_ini);
    ordenSecuencial(vectorSec,total);
    QueryPerformanceCounter(&t_fin);
    secs= performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"Tiempo en ordenar el vector con el METODO SECUENCIAL: ";
    cout<<(secs*1000.0);

    //Ordenación Burbuja
    QueryPerformanceCounter(&t_ini);
    ordenBurbuja(vectorBurbuja,total);
    QueryPerformanceCounter(&t_fin);
    secs= performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"Tiempo en ordenar el vector con el METODO BURBUJA: ";
    cout<<(secs*1000.0);

    //Ordenación Burbuja Mejorado
    QueryPerformanceCounter(&t_ini);
    burbujaMejorado(vectorBurbujaMe,total);
    QueryPerformanceCounter(&t_fin);
    secs= performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"Tiempo en ordenar el vector con el METODO BURBUJA MEJORADO: ";
    cout<<(secs*1000.0);

    //Ordenación Quicksort
    QueryPerformanceCounter(&t_ini);
    OrdenamientoQuicksort(vectorQuicksort,0,total-1);
    QueryPerformanceCounter(&t_fin);
    secs= performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"Tiempo en ordenar el vector con el METODO QUICKSORT: ";
    cout<<(secs*1000.0);

    //Ordenación Shell
    QueryPerformanceCounter(&t_ini);
    ordenShell(vectorShell,total);
    QueryPerformanceCounter(&t_fin);
    secs= performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"Tiempo en ordenar el vector con el METODO SHELL: ";
    cout<<(secs*1000.0);

    //Ordenación Shell Optimizado
    QueryPerformanceCounter(&t_ini);
    ordenShell2(vectorShell2,total);
    QueryPerformanceCounter(&t_fin);
    secs= performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"Tiempo en ordenar el vector con el METODO SHELL OPTIMIZADO: ";
    cout<<(secs*1000.0);





    cout<<endl<<"ALGORITMOS DE ORDENACION"<<endl;
    return 0;
}

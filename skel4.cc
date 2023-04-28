#include <iostream>

void print_vec(float V[], int v, char space) {
  for(int i = 0; i < v; ++i) {
    std::cout << V[i] << " ";
  } 
  std::cout << std::endl;
}

void change_elto(float V[], int index, float dato) {
  V[index] = dato;
}

void swap(float V[], int index, int index2) {
  float aux = V[index];
  V[index] = V[index2];
  V[index2] = aux;
}

void mirror(float V[], int v) {
  if(v <= 1) {
    return;
  }
  swap(V,0,v-1);
  mirror(V+1, v-2);
}

float mult_add(float a, float b, float c) {
  return a * b + c;
}

float prod_esc(float V1[], float V2[], int n) {
  float result{0.0};
  for(int i = 0; i < n; ++i) {
    result = mult_add(V1[i], V2[i],result);
  }
  std::cout << result << std::endl;
  return result;
}

int main() {
  int v1 = 40, v2 = 40, index = 0, index2 = 0, tam = 0;
  char space = ' ';
  float V1[v1];  
  float V2[v2];
  float dato{0.0}, result;
  unsigned opcion, opcion2;

  std::cout << "\nPractica 4 de Principios de Computadores. Subrutinas.\n";
    for(int i = 0; i < v1; ++i) {
      V1[i] = i + 10;
    }
    for(int i = 0; i < v2; ++i) {
      V2[i] = 40-i;
    }
  while (true) {
    std::cout << "\nVector con dimension " << v1 << "\n";
    print_vec(V1,v1,space);
    std::cout << "\nVector con dimension " << v2 << "\n";
    print_vec(V2,v2,space);
    std::cout << "\n(1) Cambiar dimension de un vector\n(2) Cambiar un elemento de un vector\n(3) Invertir un vector\n(4) Calcular el producto escalar de dos vectores\n(0) Salir\n\nElija opcion: ";
    std::cin >> opcion;
    switch (opcion) {
    case 0:
      std::cout << "\nFIN DEL PROGRAMA." << std::endl;
      return 0;
    
    case 1:
      std::cout << "Elija el vector para realizar la operacion (1) para v1 (2) para v2: ";
      std::cin >> opcion2;
      std::cout << "Introduzca nueva dimension para el vector (1-40): ";
      std::cin >> tam;
      if(opcion2 == 1) {
        v1 = tam;
      } 
      else {
        v2 = tam;
      }
      break;

    case 2:
      std::cout << "Elija el vector para realizar la operacion (1) para v1 (2) para v2: ";
      std::cin >> opcion2;
      if(opcion2 >= 3 || opcion2 <= 0) {
        std::cout << "Error: opcion incorrecta.\n";
        continue;
      }
      std::cout << "Elija el indice del elemento a cambiar: ";
      std::cin >> index;
      if(index >= 40 || index < 0) {
        std::cout << "Error: indice incorrecto\n";
        continue;
      }
      std::cout << "Introduce el nuevo valor para el elemento elegido: ";
      std::cin >> dato;
      if(opcion2 == 1) {
        change_elto(V1,index,dato);
      }
      else {
        change_elto(V2,index,dato);
      }
      break;

    case 3:
      std::cout << "Elija el vector para realizar la operacion (1) para v1 (2) para v2: ";
      std::cin >> opcion2;
      if(opcion2 >= 3 || opcion2 <= 0) {
        std::cout << "Error: opcion incorrecta.\n";
        continue;
      }
      if(opcion2 == 1) {
        mirror(V1,v1);
      }
      else {
        mirror(V2,v2);
      }
      break;
    
    case 4:
      if(v1 != v2) {
        std::cout << "Error: los vectores tienen distinta dimension\n";
        continue;
      }
      prod_esc(V1,V2,v1);
      std::cout << "El producto escalar de los vectores es: " << result << std::endl;
      break;

    default:
      break;
    }
  }
  return 0;
}
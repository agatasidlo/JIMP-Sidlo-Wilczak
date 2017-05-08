#include <iostream>
#include "Point3d.h"

using namespace datastructures;

int main() {
    std::cout << "Start programu" << std::endl;
    //zadanie 5
    Point3d p1;
    Point3d p2(3.0, 2.1, 4.7);
    std::cout << p2.distance(p1) << std::endl;

    //zadanie 6
    Point point2d(1, 2);
    Point3d point3d(4, 4, 5);
    std::cout << point2d.distance(point3d) << std::endl;

    //zadanie 7
    Point p2d(1, 2);
    std::cout << p2d << std::endl;

    Point3d p3d(1, 2, 3);
    std::cout << p3d << std::endl;
    return 0;
}

/*----------------------------------------------------------------------------------------------
 *
 *          odpowiedź na zadanie 5
 * 1. Konstruktor bezparametrowy Point (klasa bazowa) obiekt p1
 * 2. Konstruktor bezparametrowy Point3d (klasa pochodna) obiekt p1
 *
 * 3. Konstruktor bezparametrowy Point  (klasa bazowa) obiekt p2
 * 4. Konstruktor parametrowy Point3d (klasa pochodna) obiekt p2
 *
 * 5. Destruktor Point3d
 * 6. Destruktor Point
 * 7. Destruktor Point3d
 * 8. Destruktor Point
 *
 * Klasa pochodna Point3d bazuje na klasie Point (Point jest jej częścią),
 * więc tworząc obiekt klasy Point3d musi już istnieć klasa Point dla tego obiektu.
 *
 * Tworzenie każdej klasy polega na utworzeniu każdej składowej tej klasy. W przypadku Point
 * jest to inicjalizacja x_ oraz y_. Natomiast przy deklaracji obiektu klasy Point3d najpierw
 * wywołany zostaje konstruktor Point, później utworzone zostaną składowe Point3d (np. z),
 * a na samym końcu składowe te zostają zamknięte w obiekcie Point3d.
 *
 * Destruktor "rozsypuje" obiekt i usuwa niezależne od siebie po rozsypaniu elementy klasy Point3d,
 * między innymi klasę Point (przez destruktor Point).
 *
 *
 *-----------------------------------------------------------------------------------------------
 *
 *          odpowiedź na zadanie 6:
 * Wywołanie point2d.distance(point3d):
 * Funkcja distance z klasy point2d przyjmuje jako argument inny obiekt tej samej klasy.
 * W powyższym wywołaniu argumentem jest obiekt klasy point3d zawierający klasę bazową
 * point2d. Funkcja distance, żeby dopasować argument używa tylko składowych klasy bazowej point2d.
 *
 *-----------------------------------------------------------------------------------------------
 *
 *          odpowiedź na zadanie 7:
 * Po wywołaniu cout<<p3d<<endl; zostanie przeszukana klasa point3d, w celu odnalezienia przeciążenia
 * operatora <<. Gdy jednak przeciążenie to nie zostanie znalezione, następne w kolejności są klasy bazowe.
 * W klasie bazowej point2d jest przeciążony operator <<, więc program wykorzysta go. Zgodnie z nim, zostaną
 * wypisane na ekran tylko składowe x_ oraz y_.
 *
 */
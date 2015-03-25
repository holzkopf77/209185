LAB 3 - TESTOWANIE STRUKTUR DANYCH - 209186
----------
Obsługa następujących struktur danych:

1. Stos
  
  - push: wrzucenie danych na góre stosu, gdy brak miejsca, dodaje jedno miejsce
  
  - push_prc: wrzucenie danych na góre stosu, gdy brak miejsca, podwaja stos
  
  - pop: ściągnięcie + zwrócenie danych z góry stosu
  
  - size: rozmiar stosu
  
  Obsługuje wszystkie typu danych (szablony).

2.Lista

  - push: wrzucenie danych na koniec listy
  
  - push_front: wrzucenie danych na początek listy
  
  - pop: usunięcie + zwrócenie elementu z końca listy

  - pop_front: usunięcie + zwrócenie elementu z początku listy
  
  - size: rozmiar listy

 Obsługuje wszystkie typu danych (szablony).
 
3.Kolejka
 
  - push: wrzucenie danych na początek kolejki
  
  - pop: usunięcie danych z końca kolejki

  - size: rozmiar kolejki
  
  Kolejka automatycznie zwiększa liczbę miejsc, jeśli pełna i wszystko zapełnione.

  Kolejka automatycznie dodaje element na wolne miejsce, jeśli jest pełna i jest coś wolnego.
  
  Kolejka nie usuwa miejsca po zwróceniu elementu, wsadza tam 0, a miejsce obsługuje kolejne dane.

 Obsługuje wszystkie typu danych (szablony).
 
4.Drzewo binarne
 
  - push: wrzucenie elementu do drzewa

  - pop: usuwanie węzła z argumentem podanym w wyłowaniu funkcji (aktualnie usuwa poprawnie tylko węzły bez dzieci) 
  
  - size: ilość węzłów drzewie (romiar drzewa)
  
  - show_tree: pokazanie zawartości pierwszych 3 poziomów drzewa
  
  - is_empty: sprawdzenie czy drzewo jest puste

 Obsługuje wszystkie typu danych (szablony).

--

Benchmark:
  
    test: sprawdza czas wypełniania sturuktury danymi z wygenerowanych plikow ( każdy test wykonuje 10 razy i uśrednia wynik)

--
Wywołanie:
  ./nazwa_programu [1 10 100 100 ... ]
  
  1 10 100 ... to rozmiary kolejnych wygenerowanych plików z losowymi wartościami całkowitymi
--

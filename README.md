## Członkowie zespołu
 - Filip Żołek - zapisywanie html/css do pliku, funkcja testowa
 - Wojciech Konowrocki - interpretacja wczytanych danych, generowanie CSS
 - Kamil Sabat - tworzenie pliku danych wpisanych ręcznie, generowanie HTML

## WebsiteGenerator
Program służy do generowania strony internetowej. 

Wynikiem działania programu sa dwa pliki: pierwszy z rozszerzeniem **html** i drugi z rozszerzeniem **css**.
 
Użytkownik podczas działania programu lub w pliku **dane.txt** definiuje następujące elementy strony www w poszczególnych liniach

1. Kolor tła strony *(format #rrggbb)*
2. Ścieżka do pliku graficznego tła strony *(W przypadku braku grafiki, należy wpisać **BRAK**)*
3. Opcje tła oddzielone średnikami *(W przypadku braku grafiki, należy wpisać **NIE**, reszta opcji jest ignorowana)*
4. Tytuł strony wyświetlany w górnej części strony. 
5. Rozmiar czcionki tytułu strony
6. Kolor czcionki tytułu strony. *(format #rrggbb)*
7. Liczbę kolumn zawartych w głównej części strony *(od 1 do 4)*
8. Treść poszczególnych kolumn *(oddzielne średnikami, **<br>** tworzy nową linię)*
9. Rozmiar czcionki w poszczególnych kolumnach *(oddzielane średnikami)*
10. Kolor czcionki w poszczególnych kolumnach *(oddzielane średnikami)*
11. Kolor tła poszczególnych kolumn *(format #rrggbb, oddzielane średnikami)*
12. Ścieżki do plików graficznych teł poszczególnych kolumn *(w przypadku braku tła w danej kolumnie należy wpisać **BRAK**, oddzielane średnikami)
13. Opcje teł oddzielone średnikami *(W przypadku braku grafiki, należy wpisać **NIE**, reszta opcji jest ignorowana, opcje kazdej kolumny należy oddzielić znakiem **-**)*
14. Promień zaokrąglenia narożników poszczególnych kolumn.
15. Kolor tła stopki strony. *(format #rrggbb)*
16. Ścieżka do pliku graficznego tła stopki *(W przypadku braku grafiki, należy wpisać **BRAK**)*
17. Opcje tła stopki oddzielone średnikami *(W przypadku braku grafiki, należy wpisać **NIE**, reszta opcji jest ignorowana)*
18. Kolor czcionki w stopce strony *(format #rrggbb)*
19. Rozmiar czcionki w stopce strony
20. Treść stopki strony.


## Opcje tła
|Opcja|Opis opcji|
|--|--|
|**NIE**|brak grafiki jako tło|
|**RY_TAK** lub **RY_NIE**|powtarzanie w pionie|
|**RX_TAK** lub **RX_NIE**|powtarzanie w poziomie|
|**ROZ_TAK** lub **ROZ_NIE**|rozciąganie grafiki|
|**FIX_TAK** lub **FIX_NIE** |zablokowanie przewijania grafiki|

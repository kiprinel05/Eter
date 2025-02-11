# Eter

Eter este un joc de strategie pentru doi jucători, inspirat din jocurile clasice „X și O” și „Connect 4”, dar cu mecanici inovatoare care adaugă elemente strategice suplimentare. Jocul implică plasarea și suprapunerea cărților numerotate pe o tablă dinamică, utilizând și puteri magice pentru a influența desfășurarea partidei.
<br><br>
[Videoclip de prezentare](https://www.youtube.com/watch?v=rY9JToN2-tw)
## Regulile de bază
- **Tabla de joc** este o matrice dinamică de 3x3 sau 4x4.
- Fiecare jucător are un set de cărți numerotate de la 1 la 4, plus o carte specială „Eter”.
- Cărțile pot fi plasate pe tablă în două moduri:
  - **Pe un spațiu gol** (dacă este adiacent unei alte cărți deja plasate pe tablă).
  - **Deasupra altei cărți**, dacă valoarea acesteia este strict mai mare.
- Cartea „Eter” are valoarea 1, nu poate fi acoperită și participă la condițiile de câștig.
- **Jocul se termină** când:
  - Un jucător creează un rând, o coloană sau o diagonală cu cărțile sale vizibile.
  - Tabla este complet ocupată.
  - Un jucător nu mai are cărți disponibile de jucat.
  - În caz contrar, câștigătorul este cel cu cele mai multe puncte din cărțile vizibile.

## Caracteristici principale
- **Moduri de joc:**
  - Duel of Wizards (duel strategic între doi jucători cu puteri magice).
  - Training Mode (pentru antrenament și testare mecanici).
- **Puterile magice ale vrăjitorilor:**
  - Eliminarea cărților adversarului.
  - Eliminarea unei linii de pe tablă.
  - Acoperirea cărților adversarului.
  - Crearea unei gropi pe tablă.
  - Mutarea propriului teanc de cărți.
  - Mutarea teancului adversarului.
  - Mutarea unei margini a tablei.
- **Mecanică de explozie:** Dacă tabla devine prea aglomerată, jucătorii pot declanșa explozii strategice care modifică poziția cărților și schimbă dinamica jocului.

## Dependențe
- Qt Framework (pentru interfața grafică).
- Standard Template Library (STL) pentru gestionarea datelor și a jocului.

## Structura proiectului
- **`Eter.cpp`** - Inițializarea interfeței grafice și gestionarea meniului principal.
- **`Game.cpp`** - Gestionarea logicii jocului, a jucătorilor și a regulilor de câștig.
- **`DuelOfWizards.cpp`** - Implementarea modului de joc "Duel of Wizards", incluzând folosirea puterilor magice.
- **`Card.h`** - Definiția clasei `Card`, care reprezintă cărțile utilizate în joc.
- **`Explosion.cpp`** - Implementarea mecanicii de explozie care influențează tabla de joc.
- **`Gamemode.h`** - Definiția clasei `Gamemode`, care gestionează modurile de joc disponibile și mecanicile specifice fiecăruia.
- **`Match.h`** - Gestionarea unei partide de joc, inclusiv starea tablei și jucătorul curent.
- **`Player.h`** - Reprezentarea jucătorilor, a scorurilor acestora și a cărților pe care le dețin.
- **`Table.h`** - Implementarea tablei de joc și a interacțiunii cu cărțile și marginile acesteia.

## Cum se joacă
1. Lansează jocul și selectează modul de joc.
2. Fiecare jucător își folosește cărțile și puterile magice pentru a domina tabla de joc.
3. Scopul este de a elimina cărțile adversarului și de a câștiga prin strategie.

## Autor
Proiect realizat de [Numele tău sau echipa ta].


Video YouTube:


#include <string>
#include "screen.h"

void main()
{
  using namespace std;

  Screen screen;
  screen.clear();

  string begin ("Die Schatzsuche kann beginnen :)");
  screen.print(begin);

  string intro ("Ihr habt die Schatztruhe gefunden und den Hinweis verstanden. Sehr gut! "
    "Was euch jetzt noch fehlt ist der passende Schluessel.");
  screen.print(intro);

  string intro2 ("In der Truhe sind geheime Schaetze verborgen. Folgt meinen Anweisungen um die Truhe zu oeffnen.");
  screen.print(intro2);

  string expl ("Ich werde euch nun 3 Aufgaben stellen. Jeder von euch soll eine davon loesen. "
    "Nur wenn ihr alle 3 Aufgaben gemeistert habt, werdet ihr den Schluessel zum Schatz finden.");
  screen.print(expl);

  string expl2 ("Lest zuerst eure Aufgaben sorgfaeltig durch und helft euch dabei gegenseitig. "
    "Dann erst geht los und loest eure Aufgaben.");
  screen.print(expl2);

  screen.clear();
  
  string job1 ("Pablo, gehe in dein Zimmer. Obwohl dich die Sonne gerade nicht blendet, suche Schutz "
    "fuer deine Augen.");
  screen.printParagraph(job1);

  string job2 ("Dario, gehe auch du in dein Zimmer. Ein Auto, das sich verwandeln kann, kann dir "
    "bei der Schatzsuche helfen.");
  screen.printParagraph(job2);

  string job3 ("Lisa, deine Aufgabe kannst du im Wohnzimmer loesen. Das Buch der Woerter kennt "
    "die Loesung. Noch ein kleiner Tipp: Es ist so aehnlich wie beim Schach, 1 mal rauf, 4 mal rechts.");
  screen.printParagraph(job3);

  screen.promptToContinue();
}

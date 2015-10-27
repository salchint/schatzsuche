#include <string>
#include <cstdio>
#include "screen.h"

void main()
{
  using namespace std;

  Screen screen;

  string intro ("Ihr habt die Schatztruhe gefunden und den Hinweis verstanden. Was euch fehlt ist "
    "der passende Schlüssel. Folgt meinen Anweisungen um die Schatztruhe zu öffnen.");

  screen.print(intro);
}

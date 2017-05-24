/*
   Eine für Profan² nutzbare DLL
   Quellcode von René Bühling 2003
   http://devlib.reboo.com
*/

#include <windows.h>
#include <string>

using namespace std; //nötig, damit zb. string funktioniert


int x=0;

STDAPI_(int) test(void)
{
	return 1234;
}


STDAPI_(int) xset(int i)
{
	x=i;
	return 1;
}

STDAPI_(int) xget(void)
{
	return x;
}

//--- Hilfsfunktion: ---
	void override(char* c, string s) //Char*-Inhalt mit String-Inhalt überschreiben, ohne die Adresse des chars zu verändern
	{
		int i=0;
		for (; i<s.size();i++)
		{
			c[i]=s[i];
		}
		c[i]='\0';
	}
//----------------------

// übergebenen String überschreiben:
STDAPI_(int) print(char* s)
{
	string test="Überschrieben.";
	override(s,test);
	return 0;
}

Dieses Beispiel zeigt, wie die ProAX.dll auch mit Profan 7.5 verwendet werden kann. 
Die Dateien m�ssen einfach in das Verzeichnis zu den Ressourcen aus dem Download 
f�r die XProfan 10-Version erg�nzt werden.

Durch die Einschr�nkungen, die in der 7.5-Profan-Version noch vorliegen, 
ist alles ein wenig umst�ndlicher. 

Mit dem hier vorliegenden Code kann nur ein FlashPlayer gleichzeitig verwendet werden.
Durch eine entsprechende Umformulierung von proAX75.inc m�sste die Verwendung mehrerer
Player aber auch m�glich sein, da in erster Linie nur die Handles der Player verwaltet
werden m�ssen. 

Zudem enthalten im Augenblick die vom FlashPlayer erhaltenen FSCommand-Argumente noch
Sonderzeichen am String-Ende, die noch behandelt werden m�ssen. 

Im Gro�en und Ganzen funktionieren die Befehle aber genauso wie bei der Klassenvariante
f�r XProfan 10.



Ren� B�hling, www.buehling.org, 10.06.2008 01:29
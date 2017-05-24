Dieses Beispiel zeigt, wie die ProAX.dll auch mit Profan 7.5 verwendet werden kann. 
Die Dateien müssen einfach in das Verzeichnis zu den Ressourcen aus dem Download 
für die XProfan 10-Version ergänzt werden.

Durch die Einschränkungen, die in der 7.5-Profan-Version noch vorliegen, 
ist alles ein wenig umständlicher. 

Mit dem hier vorliegenden Code kann nur ein FlashPlayer gleichzeitig verwendet werden.
Durch eine entsprechende Umformulierung von proAX75.inc müsste die Verwendung mehrerer
Player aber auch möglich sein, da in erster Linie nur die Handles der Player verwaltet
werden müssen. 

Zudem enthalten im Augenblick die vom FlashPlayer erhaltenen FSCommand-Argumente noch
Sonderzeichen am String-Ende, die noch behandelt werden müssen. 

Im Großen und Ganzen funktionieren die Befehle aber genauso wie bei der Klassenvariante
für XProfan 10.



René Bühling, www.buehling.org, 10.06.2008 01:29
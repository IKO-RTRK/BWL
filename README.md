**pocistite sve sto nije potrebno**
- npr. backup fajlovi (*.*~)
- *.o fajlovi ne treba da budu na GIT-u
- isto tako executable fajlovi
- ...

Na gitu uvijek stoji samo code i eventualno neke vazne stvari za projekat a nikako medjufajlovi koji su garbage od builda.

Posto mi je frka ovde i puno vremena mi "trosi", necu se moci posvetiti gledanju svega sto ste napravili, kako sam zamislio da cu moci, bar ne danas i vjerovatno sutra... nadam se da ce petak biti "laksi"... Ali ovo sto sam do sada pregledao je ok. Vise paznje obratiti u refactoring. Svaki dio koda koji se ponavlja makar jednom, treba ici u helper funkciju. Tu spada i refactoring TDD testova.

Pogledao sam funkcionalnost GUI-a i super izgleda :-) ali jos uvijek nije funkcionalno sve kao igrica.

Treba napraviti makefile koji ce napraviti biblioteku od backend dijela i nju linkati sa frontend dijelom, tako da jednim make ja mogu dobiti funkcionalno sve. 

Posto ste rijesili backend dio, evo vam sada mali hint koji ce vam pomoci oko pogleda na bowling stats, na REFACTORING(!), kao i na pravi book-example kako se TDD-om rjesava taj problem. http://www.slideshare.net/amritayan/test-driven-development-in-c



# Bowling Project

Kao što smo se dogovorili danas na sastanku, ovdje svako treba da napiše šta će da radi (ime - zadatak). Potrebno se podjeliti u grupe (2,3 člana) i izvršiti refaktoring koda i napisati dokumentaciju za taj fajl. Takođe, treba još dovršiti neke funkcije, ali otprilike svako zna šta treba.

### Zaduženja
- Stefan Končar - pravljenje biblioteka i pisanje glavnog programa koji će koristiti te biblioteke
- Nikola Nikolic, Bojan Djukic, Stefan Savic, Mladen Antonic - Refactoring i documentation za bowling_stats.c
- Bojan Gajic, Srdjan Micin, Nebojsa Markovic, Sinisa Djuric - Refactoring za bowling_gui.c
- Mladen Stupar, Branka Pekez - Refactoring i pisanje dokumetacije
- Saša Mihajlica - Ispis rezultata na ekran i testovi za rušenje čunjeva
-Asim Šabić - Prepravka testova "bowling_test.c"

output: main.o assassin.o Barbarian.o blackmage.o cryomancer.o cultist.o headhunter.o oathbreaker.o airwizard.o FireWizard.o Hulk.o Player.o Valkyrie.o Warrior.o Wizard.o WaterWizard.o
	g++ main.o assassin.o Barbarian.o blackmage.o cryomancer.o cultist.o headhunter.o oathbreaker.o airwizard.o FireWizard.o Hulk.o Player.o Valkyrie.o Warrior.o Wizard.o WaterWizard.o -o output

main.o: main.cpp
	g++ -c main.cpp

assassin.o: assassin.cpp Assassin.h
	g++ -c assassin.cpp

Barbarian.o: Barbarian.cpp Barbarian.h
	g++ -c Barbarian.cpp
	
blackmage.o: blackmage.cpp Blackmage.h
	g++ -c blackmage.cpp

cryomancer.o: cryomancer.cpp Cryomancer.h
	g++ -c cryomancer.cpp

cultist.o: cultist.cpp Cultist.h
	g++ -c cultist.cpp

headhunter.o: headhunter.cpp Headhunter.h
	g++ -c headhunter.cpp

oathbreaker.o: oathbreaker.cpp Oathbreaker.h
	g++ -c oathbreaker.cpp

airwizard.o: airwizard.cpp AirWizard.h
	g++ -c airwizard.cpp

FireWizard.o: FireWizard.cpp FireWizard.h
	g++ -c FireWizard.cpp

Hulk.o: Hulk.cpp Hulk.h
	g++ -c Hulk.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Valkyrie.o: Valkyrie.cpp Valkyrie.h
	g++ -c Valkyrie.cpp

Warrior.o: Warrior.cpp Warrior.h
	g++ -c Warrior.cpp

Wizard.o: Wizard.cpp Wizard.h
	g++ -c Wizard.cpp

WaterWizard.o: Wizard.cpp Wizard.h
	g++ -c WaterWizard.cpp
	
clean:
	rm *.o
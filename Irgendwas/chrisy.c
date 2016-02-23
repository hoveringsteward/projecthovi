#include <stdio.h>

void ziffernAnalysieren(int zahl){
		
	int summe = 0, anzahl = 0, temp = 0;
	int ganzezahl[6];
	
	while(zahl > 0){
		
		temp = zahl%10;
		
		summe = summe + temp;
		
		ganzezahl[anzahl] = temp;
		anzahl ++;
		
		
		zahl = (zahl - temp)/10;
	}
	
	for(int stelle = 0; stelle < anzahl; stelle++) {
		printf("Stelle %d bin da drin, %d \n", stelle, ganzezahl[stelle]);
	}
	
	printf("Die Summe ist: %d \n", summe);
	printf("Die Anzahl ist: %d \n", anzahl);
}
	
	
int	main(){
		
		int eineZahl;
		
		while(1){
			
			printf("Gib eine zahl ein: ");
			scanf("%d", &eineZahl);
			
			if(eineZahl < 0){
				break;
			}else{
				ziffernAnalysieren(eineZahl);
				eineZahl = 0;
			}
			
		}
		
		system("PAUSE");
		return 0;
	}

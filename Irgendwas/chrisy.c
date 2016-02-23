#include <stdio.h>

void ziffernAnalysieren(int zahl){
		
	int summe = 0, anzahl = 0, temp = 0;
	
	while(zahl > 0){
		
		temp = zahl%100;
		
		summe = summe + temp;
		
		
		printf("bin da drin \n, %d", temp);
		anzahl ++;
		
		
		zahl = (zahl - temp)/100;
	}
	
	printf("Die Summe ist: %d", summe);
	printf("Die Anzahl ist: %d", anzahl);
}
	
	
int	main(){
		
		int eineZahl;
		
		while(1){
			
			printf("Gib eine zahl ein");
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

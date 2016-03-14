#include <stdio.h>

unsigned char send_info[5];

void UartSend(unsigned char data) {
	printf("Senden von: %c \n\n", data);
}

void UartSendX(unsigned char data) {
	printf("%c", data);
}

void UartSendAscii(unsigned char data) {
	printf("Senden von: %d \n", data);
}

void SendDebugInfo(unsigned int debug_info) {
    for(unsigned char debug_info_counter = 0; debug_info_counter < 5; debug_info_counter++) {
    	
        send_info[debug_info_counter] = debug_info % 10;
        debug_info = (debug_info - send_info[debug_info_counter]) / 10;
    }
    for(signed char debug_send_counter = 4; debug_send_counter >= 0; debug_send_counter--) {
        unsigned char send = send_info[debug_send_counter];
        UartSendAscii(send);
    }
    UartSend(';');
    for(unsigned char c = 0; c < 10; c++) {
	
    	UartSendX(0x0D);
    }
}

int main() {
	int time_height;
		
		while(1){
			
			printf("Gib die time_height ein: ");
			scanf("%d", &time_height);
			//printf("\n");
			
			if(time_height < 0){
				break;
			}else{
				SendDebugInfo(time_height);
				time_height = 0;
			}
			
		}
		
		system("PAUSE");
		return 0;
}

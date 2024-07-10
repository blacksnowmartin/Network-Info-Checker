#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    char base_ip[] = "192.168.1.";
    int start_ip = 1;
    int end_ip = 255;

    struct sockaddr_in sa;
    int result;

    for (int i = start_ip; i <= end_ip; i++) {
        char target_ip[16];
        sprintf(target_ip, "%s%d", base_ip, i);

        memset(&sa, 0, sizeof(struct sockaddr_in));
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = inet_addr(target_ip);

        result = connect(sd, (struct sockaddr *)&sa, sizeof(struct sockaddr_in));

        if (result == 0) {
            printf("Host %s is active\n", target_ip);
        }
    }

    return 0;
}

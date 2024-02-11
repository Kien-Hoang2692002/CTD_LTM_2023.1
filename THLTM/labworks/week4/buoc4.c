#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main()
{
    char *EIDYyd2FiQpFIrc = "1.16.64.256";
    struct sockaddr_in *zN91BCLnXvyl2q4 = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    
    int BKmuAjTwA40iboL = inet_aton(EIDYyd2FiQpFIrc, &zN91BCLnXvyl2q4->sin_addr);
    
    printf("%d\n", BKmuAjTwA40iboL);
    
    char *Ywxmglg693Yp2lT = inet_ntoa(zN91BCLnXvyl2q4->sin_addr);
    
    printf("\n%s\n", EIDYyd2FiQpFIrc);
    printf("%s\n", Ywxmglg693Yp2lT);
    
    in_addr_t aGeNPEcNyW4G8Wj = inet_addr(EIDYyd2FiQpFIrc);
    
    printf("\n%d\n", zN91BCLnXvyl2q4->sin_addr.s_addr);
}

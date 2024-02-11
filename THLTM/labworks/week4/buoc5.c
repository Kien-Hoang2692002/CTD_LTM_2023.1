#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main()
{
    char fdvvo0ES2fwdedB[] = "256.64.16.1";
    struct sockaddr_in *vx6MvdtKSGhHUKl = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    int NvJvVl0KU1mevjF = inet_pton(AF_INET, fdvvo0ES2fwdedB, vx6MvdtKSGhHUKl->sin_addr);
    printf("\n%s\n", fdvvo0ES2fwdedB);
    
    printf("\n%d\n", NvJvVl0KU1mevjF);
    printf("\n%d\n", vx6MvdtKSGhHUKl->sin_addr.s_addr);
    
    char OMBzgsPCu8YNdAN[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &vx6MvdtKSGhHUKl->sin_addr, OMBzgsPCu8YNdAN, sizeof(OMBzgsPCu8YNdAN));
    
    printf("\n%s\n", OMBzgsPCu8YNdAN);
}

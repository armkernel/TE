#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>

// Packet 
// len(2):temp(4):cds(4)

int main() {

	int csock = socket(PF_INET, SOCK_STREAM, 0);

	if (csock == -1) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	saddr.sin_port = htons(5000);

	if (connect(csock, (struct sockaddr *)&saddr, sizeof saddr) == -1) {
		perror("connect");
		return 1;
	}

	printf("연결이 시작되었습니다..\n");

	char buf[64];
	int ret;

	int i, j;
	int len;

	for (i = 0; i < 100; i++) {
		int cds = 42;
		int temp = 100;

		char *p = buf;
		*(int *)p = htonl(temp);
		p += sizeof(int);
		*(int *)p = htonl(cds);
		p += sizeof(int);
		
		len = p - buf;
		write(csock, buf, p-buf);
		getchar();
	}


	close(csock);
	return 0;
}

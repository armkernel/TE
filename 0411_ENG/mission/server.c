#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <stdio.h>

int main() {

	int ssock = socket(PF_INET, SOCK_STREAM, 0);
	if (ssock == -1) {
		perror("error");
		return 1;
	}

	int option = 1;
	setsockopt(ssock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof option);

	struct sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(5000);
	if (bind(ssock, (struct sockaddr *)&saddr, sizeof saddr) == -1) {
		perror("bind");
		return 1;
	}

	if (listen(ssock, SOMAXCONN) == -1) {
		perror("listen");
		return 1;
	}

	while (1) {
	
		struct sockaddr_in caddr = {0, };
		socklen_t caddrlen = sizeof caddr;
		int csock = accept(ssock, (struct sockaddr *)&caddr, &caddrlen);
		if (csock == -1) {
			perror("accept");
			return 1;
		}

		printf("client %s\n", inet_ntoa(caddr.sin_addr));

		int ret;
		char buf[8];
		int i = 0;

		while ((ret = read(csock, buf, sizeof buf)) > 0) {
			char *p = buf;
			int temp = ntohl(*(int *)p);
			p += sizeof(int);
			
			int cds = ntohl(*(int *)p);
			p += sizeof(int);
			printf("%d - temp: %d, cds: %d\n", ++i, temp, cds);
		}

		close(csock);
		printf("클라이언트와 연결이 종료되었습니다..\n");
	}

	close(ssock);
	return 0;
}






















































































































































































































































































































#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

void *read_image( const char *filepath );

int main( int argc, const char* argv[] ) {

	void *buff = read_image(argv[1]);

	if(buff == NULL){

		printf("Unable to open file\n");
		return 0;
	}

	if(ntohl(*(uint64_t*)buff) == 0x89504E470D0A1A0A){

		printf("Unable to parse file\n");
		return 0;
	}

	buff += 8;

	while(1){

		uint32_t header_length = ntohl(*(uint32_t*)buff);
		buff +=4;
		uint32_t header_type = ntohl(*(uint32_t*)buff);
		buff +=4;
		
		if(header_type == 0x49484452){
			break;
		}

		buff += 4+ header_length;
		
	}

	printf("PNG image width: %d\n", ntohl(*(uint32_t*)buff));
	buff +=4;
	printf("PNG image height: %d\n", ntohl(*(uint32_t*)buff));

	return 0;

}

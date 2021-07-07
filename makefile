postRequestExample: postRequestExample.c post_request.c
	gcc -Wall -lcurl postRequestExample.c post_request.c -o postRequestExample

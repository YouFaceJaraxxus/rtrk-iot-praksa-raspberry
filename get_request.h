#ifndef GET_REQUEST_H
#define GET_REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#define BUFFER_SIZE 10240 //10 kB
#define VALUE_STRING_SIZE 20 //10 kB
#define DEVICE_ID_STRING_SIZE 10 //10 kB

typedef struct get_response {
  char *response;
  int measurementValue;
  int deviceId;
} get_response;


void initializeGetResponse(get_response *response);
void free_response(get_response *response);
size_t writeFunc(void *ptr, size_t size, size_t nmemb, get_response *response);

#endif /* GET_REQUEST_H */

